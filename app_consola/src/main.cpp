/**
 * @class main
 * @brief Class to run the program with the main method
 *
 * The main class runs the program and connect to the database
 */

#include "sensor.h"
#include "control_db.h"
#include <ctime>
#include <csignal>
#include <unistd.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

/**
 * @brief Difference between a date and the actual date.
 *
 * This method receive a date in format 'Month Day HH:MM:SS' and returns its difference between itself and the starting date
 *
 * @param fecha_y_hora_anterior Second date.
 * @return Difference between itself and the starting date.
 */
string restar_fechas( const unsigned char* fecha_y_hora_anterior ){
    time_t marca_tiempo = time(nullptr);
    string fecha_y_hora = ctime(&marca_tiempo); 

    char hora1[9];
    strncpy(hora1, reinterpret_cast<const char*>(fecha_y_hora_anterior) + 11, 8);
    hora1[8] = '\0'; 

    char hora2[9];
    strncpy(hora2, fecha_y_hora.c_str() + 11, 8);
    hora2[8] = '\0'; 

    int h1, m1, s1;
    sscanf(hora1, "%d:%d:%d", &h1, &m1, &s1);

    int h2, m2, s2;
    sscanf(hora2, "%d:%d:%d", &h2, &m2, &s2);

    int difHoras = (h2 - h1 >= 0) ? h2 - h1 : -(h2 - h1);
    int difMinutos = (m2 - m1 >= 0) ? m2 - m1 : -(m2 - m1);
    int difSegundos = (s2 - s1 >= 0) ? s2 - s1 : -(s2 - s1);
    difHoras = difHoras * 3600;
    difMinutos = difMinutos * 60;
    difSegundos = difSegundos + difMinutos + difHoras;
    string reloj;
    if ((difSegundos >= 3600)){
        int hora = difSegundos / 3600; reloj = (hora > 9) ? (to_string(hora) + ":") : ("0"+ to_string(hora) +":");
    }
    else{
        reloj = "";
    }
    int minutos = (difSegundos % 3600) / 60;
	int segundos = difSegundos % 60;
	string reloj0 = (minutos > 9) ? (to_string(minutos) + ":") : ("0"+ to_string(minutos)+":");
	string reloj1 = (segundos > 9) ? (""+ to_string(segundos)) : ("0"+ to_string(segundos));
	
    return reloj+reloj0+reloj1;
}

/**
 * @brief Close the app and the connection with the database
 *
 * This method close the app and the connetion with the database
 *
 * @param signal close signal launced by main
 */
void cerrar( int signal ) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;
    sqlite3_stmt *stmt;

    /* Open database */
    rc = sqlite3_open( Control_db::nombre, &db );

    if( rc ) {
      fprintf( stderr, "Can't open database: %s\n", sqlite3_errmsg(db) );
    }

    sql = "SELECT fecha_y_hora_de_ejecucion FROM Datos WHERE tiempo_transcurrido_ejecucion IS NULL;";
    rc = sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt, 0 );

    const unsigned char* fecha_y_hora_anterior;

    if ( rc != SQLITE_OK ) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg( db ) << endl;
    } else {
        /* Execute the statement and fetch the result */
        rc = sqlite3_step( stmt );
        if ( rc == SQLITE_ROW ) {
            fecha_y_hora_anterior = sqlite3_column_text( stmt, 0 );
        } else {
            cerr << "Failed to retrieve data: " << sqlite3_errmsg( db ) << endl;
        }
    }

    /* Finalize the statement to release resources */
    sqlite3_finalize( stmt );

    
    sql = "UPDATE Datos SET tiempo_transcurrido_ejecucion = '" +restar_fechas( fecha_y_hora_anterior )+ "' WHERE tiempo_transcurrido_ejecucion IS NULL;";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    /* Close the database connection */
    sqlite3_close( db );
    
    exit(signal);
}

/**
 * @brief main method
 *
 * runs the program
 *
 * @param argc 3 elements
 * @param argv program, database, period
 * @return 0 to close the program.
 */
int main( int argc, char *argv[] ){ 

    if( stoi(argv[2]) < 5 || stoi(argv[2]) > 20 ){
        cout << "ERROR: You must introduce a period value between 5 and 12.\nClosing app..." << endl;
        return 0;
    }

    double segundos_transcurridos;
    time_t marca_tiempo = time( nullptr );
    string fecha_y_hora = ctime( &marca_tiempo );

    signal( SIGINT, cerrar ); 
    signal( SIGTERM, cerrar );

    Control_db::nombre = argv[1];
    Control_db db;
    db.introducir_db( "INSERT INTO Datos (fecha_y_hora_de_ejecucion)"\
    "VALUES ( '" +fecha_y_hora+ "' );" );

    int _periodo = stoi( argv[2] );
    Sensor temperatura( 1, {10, 45} );
    Sensor humedad( 2, {0, 100} );
    Sensor humedad_suelo( 3, {0, 100} );
    Sensor velocidad( 4, {0, 40} );
    Sensor direccion_viento( 5, {-180,180} );
    Sensor precipitacion( 6, {0, 200} );
    Sensor intensidad_luz( 7, {0, 4000} );

    segundos_transcurridos = 1;
    sleep( 1 );

    while (true) {

        if ( fmod( segundos_transcurridos, static_cast<double>(_periodo) ) == 0){
            temperatura.trabajar_datos();
            humedad.trabajar_datos();
            humedad_suelo.trabajar_datos();
            velocidad.trabajar_datos();
            direccion_viento.trabajar_datos();
            precipitacion.trabajar_datos();
            intensidad_luz.trabajar_datos();
        }

        if ( fmod( segundos_transcurridos, 60.0 ) == 0 ){ 
            cout << "Introducir" << endl;
            db.introducir_db( temperatura.introducir_datos_db( db.getId_ejecucion() ) );
            db.introducir_db( humedad.introducir_datos_db( db.getId_ejecucion() ) );
            db.introducir_db( humedad_suelo.introducir_datos_db( db.getId_ejecucion() ) );
            db.introducir_db( velocidad.introducir_datos_db( db.getId_ejecucion() ) );
            db.introducir_db( direccion_viento.introducir_datos_db( db.getId_ejecucion() ) );
            db.introducir_db( precipitacion.introducir_datos_db( db.getId_ejecucion() ) );
            db.introducir_db( intensidad_luz.introducir_datos_db( db.getId_ejecucion() ) );
        }

        sleep ( 1 );
        segundos_transcurridos = segundos_transcurridos + 1;
        }
}
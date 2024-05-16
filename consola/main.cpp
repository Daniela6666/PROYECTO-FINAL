#include "sensores.h"
#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <cmath>
#include <csignal>

using namespace std;

clock_t inicio = clock(); 
double segundos_transcurridos;
string fecha_y_hora;
char* db_enviada;

void cerrar(int signal) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;

    /* Open database */
    rc = sqlite3_open(db_enviada, &db);
   
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    cout << "Antes de abrir" << endl;
    /* Create SQL statement */
    sql = "INSERT INTO Datos(fecha_y_hora_de_ejecucion, tiempo_transcurrido_ejecución)"\
    "VALUES( '" +fecha_y_hora+ "' ," +to_string(segundos_transcurridos)+ ");";
    cout << "Despues de abrir" << endl;
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);

    exit(signal);
}

int main( int argc, char *argv[] ){
    time_t marca_tiempo = time(nullptr);
    fecha_y_hora = ctime(&marca_tiempo);
    db_enviada = argv[1];

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    string sql;
    sqlite3_stmt *stmt;

    signal(SIGINT, cerrar); 
    signal(SIGTERM, cerrar);

    rc = sqlite3_open( argv[1], &db );
    
    if( rc != 0 ){
        fprintf( stderr, "Can't open database: %s\n", sqlite3_errmsg(db) );
        return(1);
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS Datos("\
      "id_ejecucion INTEGER,"\
      "fecha_y_hora_de_ejecucion TEXT NOT NULL,"\
      "tiempo_transcurrido_ejecución TEXT NOT NULL,"\
      "PRIMARY KEY ( id_ejecucion AUTOINCREMENT )"\
    ")";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
    }

   sqlstr = "CREATE TABLE IF NOT EXISTS Mediciones("\
      "id INTEGER,"\
      "id_ejecucion INTEGER,"\
      "id_sensor TEXT NOT NULL,"\
      "minimo INTEGER NOT NULL,"\
      "maximo INTEGER NOT NULL,"\
      "promedio REAL NOT NULL,"\
      "FOREIGN KEY ( id_ejecucion ) REFERENCES datos( id_ejecucion ),"\
      "FOREIGN KEY ( id_sensor ) REFERENCES sensores( id_sensor ),"\
      "PRIMARY KEY ( id AUTOINCREMENT )"\
    ")";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (3);
    } 

   sqlstr = "CREATE TABLE IF NOT EXISTS Sensores("\
      "id_sensor INTEGER,"\
      "nombre TEXT NOT NULL,"\
      "PRIMARY KEY ( id_sensor AUTOINCREMENT )"\
    ")";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (4);
    } 

    /* Create SQL statement */
   sql = "INSERT INTO Sensores(nombre)"\
    "SELECT 'temperatura'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'temperatura');"\
    "INSERT INTO Sensores(nombre)"\
    "SELECT 'humedad'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'humedad');"\
    "INSERT INTO Sensores(nombre)"\
    "SELECT 'humedad_del_suelo'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'humedad_del_suelo');"\
    "INSERT INTO Sensores(nombre)"\
    "SELECT 'velocidad'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'velocidad');"\
    "INSERT INTO Sensores(nombre)"\
    "SELECT 'direccion_del_viento'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'direccion_del_viento');"\
    "INSERT INTO Sensores(nombre)"\
    "SELECT 'precipitacion'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'precipitacion');"\
    "INSERT INTO Sensores(nombre)"\
    "SELECT 'intensidad_de_luz'"\
    "WHERE NOT EXISTS (SELECT 1 FROM Sensores WHERE nombre = 'intensidad_de_luz');";

    /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }    

    int id_ejecucion = 0;

    /* Prepare SQL statement to get max_id_ejecucion */
    sql = "SELECT COALESCE(MAX(id_ejecucion) + 1, 1) AS max_id_ejecucion FROM Datos;";
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << endl;
    } else {
        /* Execute the statement and fetch the result */
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW) {
            id_ejecucion = sqlite3_column_int(stmt, 0);
        } else {
            cerr << "Failed to retrieve data: " << sqlite3_errmsg(db) << endl;
        }
    }
    /* Finalize the statement to release resources */
    sqlite3_finalize(stmt);

    /* Close the database connection */
    sqlite3_close(db);

    int _periodo = stoi(argv[2]);
    Sensores temperatura( 1, {10, 45} );
    Sensores humedad( 2, {0, 100} );
    Sensores humedad_suelo( 3, {0, 100} );
    Sensores velocidad( 4, {0, 40} );
    Sensores direccion_viento( 5, {-180,180} );
    Sensores precipitacion( 6, {0, 200} );
    Sensores intensidad_luz( 7, {0, 4000} );

    while (true) {
        segundos_transcurridos = (clock() - inicio) / (double) CLOCKS_PER_SEC;

        if ( fmod( segundos_transcurridos, static_cast<double>(_periodo) ) == 0){
            temperatura.trabajar_datos();
            humedad.trabajar_datos();
            humedad_suelo.trabajar_datos();
            velocidad.trabajar_datos();
            direccion_viento.trabajar_datos();
            precipitacion.trabajar_datos();
            intensidad_luz.trabajar_datos();
            }

        if ( fmod( segundos_transcurridos, 10.0 ) == 0 ){ //60.0
            cout << "Introducir" << endl;
            temperatura.introducir_db( argv[1], id_ejecucion );
            humedad.introducir_db( argv[1], id_ejecucion );
            humedad_suelo.introducir_db( argv[1], id_ejecucion );
            velocidad.introducir_db( argv[1], id_ejecucion );
            direccion_viento.introducir_db( argv[1], id_ejecucion );
            precipitacion.introducir_db( argv[1], id_ejecucion );
            intensidad_luz.introducir_db( argv[1], id_ejecucion );
            }

        }
    return 0;
}
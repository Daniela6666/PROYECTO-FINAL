#include "sensores.h"
#include <ctime>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

int main( int argc, char *argv[] ){
    clock_t tiempo;
    tiempo = clock();

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;
    sqlite3_stmt *stmt;

    /* Open database */
    rc = sqlite3_open(argv[0], &db);
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
            cout << "max_id_ejecucion: " << id_ejecucion << endl;
        } else {
            cerr << "Failed to retrieve data: " << sqlite3_errmsg(db) << endl;
        }
    }
    /* Finalize the statement to release resources */
    sqlite3_finalize(stmt);

    /* Close the database connection */
    sqlite3_close(db);

    int _periodo = stoi(argv[1]);
    Sensores temperatura( 1, {10, 45} );
    Sensores humedad( 2, {0, 100} );
    Sensores humedad_suelo( 3, {0, 100} );
    Sensores velocidad( 4, {0, 40} );
    Sensores direccion_viento( 5, {-180,180} );
    Sensores precipitacion( 6, {0, 200} );
    Sensores intensidad_luz( 7, {0, 4000} );

    while( true ){
        while( tiempo%_periodo == 0 ){
            temperatura.trabajar_datos();
            humedad.trabajar_datos();
            humedad_suelo.trabajar_datos();
            velocidad.trabajar_datos();
            direccion_viento.trabajar_datos();
            precipitacion.trabajar_datos();
            intensidad_luz.trabajar_datos();
        }
        while( tiempo%6000 == 0 ){
            temperatura.introducir_db( argv[0], id_ejecucion );
            humedad.introducir_db( argv[0], id_ejecucion );
            humedad_suelo.introducir_db( argv[0], id_ejecucion );
            velocidad.introducir_db( argv[0], id_ejecucion );
            direccion_viento.introducir_db( argv[0], id_ejecucion );
            precipitacion.introducir_db( argv[0], id_ejecucion );
            intensidad_luz.introducir_db( argv[0], id_ejecucion );
        }
    }
    //hacer un try catch si cierran el programa

    return 0;
}
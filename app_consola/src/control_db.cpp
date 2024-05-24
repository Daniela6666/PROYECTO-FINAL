#include "control_db.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

const char* Control_db::nombre = "default_db";

Control_db::Control_db(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    string sql;
    sqlite3_stmt *stmt;

    rc = sqlite3_open( nombre, &db );
    
    if( rc != 0 ){
        fprintf( stderr, "Can't open database: %s\n", sqlite3_errmsg(db) );
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS Datos("\
      "id_ejecucion INTEGER,"\
      "fecha_y_hora_de_ejecucion TEXT NOT NULL,"\
      "tiempo_transcurrido_ejecucion TEXT,"\
      "PRIMARY KEY ( id_ejecucion AUTOINCREMENT )"\
    ")";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );
   
   if( rc != SQLITE_OK ){
      fprintf( stderr, "SQL error: %s\n", zErrMsg );
      sqlite3_free( zErrMsg );
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

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );

   if( rc != SQLITE_OK ){
      fprintf( stderr, "SQL error: %s\n", zErrMsg );
      sqlite3_free( zErrMsg );
    } 

   sqlstr = "CREATE TABLE IF NOT EXISTS Sensores("\
      "id_sensor INTEGER,"\
      "nombre TEXT NOT NULL,"\
      "PRIMARY KEY ( id_sensor AUTOINCREMENT )"\
    ")";

    rc = sqlite3_exec( db, sqlstr.c_str(), 0, 0, &zErrMsg );
   
   if( rc != SQLITE_OK ){
      fprintf( stderr, "SQL error: %s\n", zErrMsg );
      sqlite3_free( zErrMsg );
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
    rc = sqlite3_exec( db, sql.c_str(), 0, 0, &zErrMsg );
   
   if( rc != SQLITE_OK ){
        fprintf( stderr, "SQL error: %s\n", zErrMsg );
        sqlite3_free( zErrMsg );
    }    

    /* Prepare SQL statement to get max_id_ejecucion */
    sql = "SELECT COALESCE(MAX(id_ejecucion) + 1, 1) AS max_id_ejecucion FROM Datos;";
    rc = sqlite3_prepare_v2( db, sql.c_str(), -1, &stmt, 0 );

    if ( rc != SQLITE_OK ) {
        cerr << "Failed to prepare statement: " << sqlite3_errmsg( db ) << endl;
    } else {
        /* Execute the statement and fetch the result */
        rc = sqlite3_step( stmt );
        if ( rc == SQLITE_ROW ) {
            id_ejecucion = sqlite3_column_int( stmt, 0 );
        } else {
            cerr << "Failed to retrieve data: " << sqlite3_errmsg( db ) << endl;
        }
    }
    /* Finalize the statement to release resources */
    sqlite3_finalize( stmt );

    /* Close the database connection */
    sqlite3_close( db );
}

Control_db::~Control_db(){
}

void Control_db::introducir_db( string _sql ){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;

    /* Open database */
    rc = sqlite3_open( nombre, &db);

    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }

    /* Create SQL statement */
    sql = _sql;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
}

void Control_db::setId_ejecucion(int _id_ejecucion){
    id_ejecucion = _id_ejecucion;
}

int Control_db::getId_ejecucion(){
    return id_ejecucion;
}
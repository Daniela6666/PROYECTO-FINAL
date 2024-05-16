#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>

using namespace std;

int main( int argc, char* agrv[] ){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    string sql;

    rc = sqlite3_open( "sensores.db", &db );
    
    if( rc != 0 ){
        fprintf( stderr, "Can't open database: %s\n", sqlite3_errmsg(db) );
        return(1);
    }
    else{
        fprintf( stdout, "Open database successfully\n");
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS Datos("\
      "id_ejecucion INTEGER,"\
      "fecha TEXT NOT NULL,"\
      "hora_inicio_ejecucion TEXT NOT NULL,"\
      "tiempo_transcurrido_ejecución TEXT NOT NULL,"\
      "PRIMARY KEY ( id_ejecucion AUTOINCREMENT )"\
    ")";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return (2);
   } else {
      fprintf(stdout, "Table created successfully\n");
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
   } else {
      fprintf(stdout, "Table created successfully\n");
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
      return (2);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

    /* Create SQL statement */
   sql = "INSERT INTO Sensores(nombre)"\
    "VALUES ('temperatura');"\
    "INSERT INTO Sensores(nombre)"\
    "VALUES ('humedad');"\
    "INSERT INTO Sensores(nombre)"\
    "VALUES ('humedad_del_suelo');"\
    "INSERT INTO Sensores(nombre)"\
    "VALUES ('velocidad');"\
    "INSERT INTO Sensores(nombre)"\
    "VALUES ('direccion_del_viento');"\
    "INSERT INTO Sensores(nombre)"\
    "VALUES ('precipitacion');"\
    "INSERT INTO Sensores(nombre)"\
    "VALUES ('intensidad_de_luz');";

    /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);

   sqlite3_close(db);

   return 0;
   }
}
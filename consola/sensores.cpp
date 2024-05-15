#include "sensores.h"
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

Sensores::Sensores(){
}

Sensores::Sensores( int _id, pair<int, int> _intervalo ){
    id = _id;
    intervalo = _intervalo;
    acumulado_medidas = 0;
    mayor = intervalo.first;
    menor = intervalo.second;
}

int Sensores::generar_aleatorio_entero(){
    return ( intervalo.first + rand() %(intervalo.second-intervalo.first) );
}

void Sensores::trabajar_datos(){
    int dato =  generar_aleatorio_entero();
    acumulado_medidas = acumulado_medidas + dato;
    cont_datos = cont_datos + 1;
    if( dato < menor ){
        menor = dato;
    }
    if( dato > mayor ){
        mayor = dato;
    }
}

void Sensores::introducir_db( char* _db, int _id_ejecucion ){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sql;

    /* Open database */
    rc = sqlite3_open( _db , &db);

    /* Create SQL statement */
    sql = "INSERT INTO mediciones (id_ejecucion, id_sensor, minimo, maximo, promedio)"\
    "VALUES (" +to_string(_id_ejecucion)+ "," +to_string(id)+ "," +to_string(menor)+ "," +to_string(mayor)+ "," +to_string(acumulado_medidas/cont_datos)+ ")";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);

    sqlite3_close(db);

    acumulado_medidas = 0;
    mayor = intervalo.first;
    menor = intervalo.second;
    }
    }
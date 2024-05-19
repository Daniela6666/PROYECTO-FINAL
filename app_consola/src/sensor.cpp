#include "sensor.h"
#include <string>
#include <cstdlib>

using namespace std;

Sensor::Sensor(){   
}

Sensor::Sensor( short _id, pair<short, short> _intervalo ){
    id = _id;
    intervalo = _intervalo;
    acumulado_medidas = 0;
    cont_medidas = 0;
    mayor_medida = intervalo.first;
    menor_medida = intervalo.second;
}

Sensor::~Sensor(){
}

short Sensor::generar_aleatorio_entero(){
    return( intervalo.first + rand() %( intervalo.second-intervalo.first ) );
}

void Sensor::trabajar_datos(){
    short dato = generar_aleatorio_entero();
    acumulado_medidas = acumulado_medidas + dato;
    cont_medidas = cont_medidas + 1;
    if( dato < menor_medida ){
        menor_medida = dato;
    }
    if( dato > mayor_medida ){
        mayor_medida = dato;
    }
}

string Sensor::introducir_datos_db( int _id_ejecucion ){
    string sql = "INSERT INTO Mediciones (id_ejecucion, id_sensor, minimo, maximo, promedio)"\
    "VALUES (" +to_string( _id_ejecucion )+ "," +to_string( id )+ "," +to_string( menor_medida )+ "," +to_string( mayor_medida)+ "," +to_string( acumulado_medidas/cont_medidas )+ ");";
    acumulado_medidas = 0;
    mayor_medida = intervalo.first;
    menor_medida = intervalo.second;
    return sql;
}
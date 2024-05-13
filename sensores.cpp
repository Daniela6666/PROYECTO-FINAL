#include "sensores.h"
#include <cstdlib>
#include <string>

using namespace std;

Sensores::Sensores(){
}

Sensores::Sensores( string _nombre, pair<int, int> _intervalo ){
    nombre = _nombre;
    intervalo = _intervalo;
    acumulado_medidas = 0;
    mayor = intervalo.first;
    menor = intervalo.second;
}

int Sensores::generar_aleatorio(){
    return ( intervalo.first + rand() %(intervalo.second-intervalo.first) );
}

void Sensores::trabajar_datos(){
    int dato =  generar_aleatorio();
    acumulado_medidas = acumulado_medidas + dato;
    cont_datos = cont_datos + 1;
    if( dato < menor ){
        menor = dato;
    }
    if( dato > mayor ){
        mayor = dato;
    }
}

void Sensores::introducir_db(){
    //introducir datos

    acumulado_medidas = 0;
    mayor = intervalo.first;
    menor = intervalo.second;
}
#include "sensores.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char *argv[] ){
    clock_t tiempo;
    tiempo = clock();

    int _periodo = stoi(argv[2]);
    Sensores temperatura( "Temperatura", {10, 45} );
    Sensores humedad( "Humedad", {0, 100} );
    Sensores humedad_suelo( "Humedad del Suelo", {0, 100} );
    Sensores velocidad( "Velocidad", {0, 40});
    Sensores direccion_viento( "Dirección del Viento", {-180,180} );
    Sensores precipitacion( "Precipitacióm", {0, 200} );
    Sensores intensidad_luz( "Intensidad de la Luz", {0, 4000} );

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
            temperatura.introducir_db();
            humedad.introducir_db();
            humedad_suelo.introducir_db();
            velocidad.introducir_db();
            direccion_viento.introducir_db();
            precipitacion.introducir_db();
            intensidad_luz.introducir_db();
        }
    }
    //hacer un try catch si cierran el programa

    return 0;
}
#ifndef SENSOR_H
#define SENSOR_H

#include <string>

using namespace std;

/**
 * @class sensor
 * @brief Class to manage project's sensors
 *
 * This class do any operation about the project's sensors
 */
class Sensor{
    short id;
    pair<short, short> intervalo;
    int acumulado_medidas;
    short cont_medidas;
    short menor_medida;
    short mayor_medida;
    Sensor();
    public:
    /**
     * @brief Sensor's class custom constructor
     *
     * Create a Sensor with a custom id and interval values
     *
     * @param _id sensor's id
     * @param _intervalo sensor's values interval
     */
    Sensor( short _id, pair<short, short> _intervalo );
    /**
     * @brief Delete the sensor
     */
    ~Sensor();
    /**
     * @brief generate a random int between the sensor's interval tho simulate the sensor's functions 
     * @return a random value
     */
    short generar_aleatorio_entero();
    /**
     * @brief manage the sensor's data 
     */
    void trabajar_datos();
    /**
     * @brief introduce sensor's data into the database
     * 
     * @param _id_ejecucion progrtam execution's id
     * @return the sql sentence to fill the database
     */
    string introducir_datos_db( int _id_ejecucion );
};

#endif // SENSOR_H
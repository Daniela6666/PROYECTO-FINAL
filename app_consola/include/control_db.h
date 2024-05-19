#ifndef CONTROL_DB_H
#define CONTROL_DB_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

using namespace std;

/**
 * @class Control_db
 * @brief Class to manage the database
 *
 * This class do any operation about the projet's database
 */
class Control_db{
    int id_ejecucion;
    public:
    static const char* nombre;
    /**
     * @brief Control_db's class custom constructor
     *
     * Creates the class who manage the database
     */
    Control_db();
    /**
     * @brief Delete the Control_db
     */
    ~Control_db();
    /**
     * @brief introduce data into database with a specific statement
     * @param sql sql statement
     */
    void introducir_db( string sql );
    /**
     * @brief set the program execution's id
     * @param _id_ejecucion execuition's id
     */
    void setId_ejecucion( int _id_ejecucion );
    /**
     * @brief get the program execution's id
     * @return execution's id
     */
    int getId_ejecucion();
};

#endif // CONTROL_DB
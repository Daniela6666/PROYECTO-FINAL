#include <string>

using namespace std;

class Sensores{
    int id;
    pair<int, int> intervalo;
    int periodo; //es el mismo para todos
    int acumulado_medidas; 
    int cont_datos;
    int mayor;
    int menor;
    public:
    Sensores();
    Sensores( int _id, pair<int, int> _intervalo );
    float generar_aleatorio_flotante();
    int generar_aleatorio_entero();
    void trabajar_datos();
    void introducir_db( char* _db, int _id_ejecucion );
};
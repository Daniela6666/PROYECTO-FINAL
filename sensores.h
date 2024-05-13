#include <string>

using namespace std;

class Sensores{
    string nombre;
    pair<int, int> intervalo;
    int periodo; //es el mismo para todos
    double acumulado_medidas; 
    int cont_datos;
    double mayor;
    double menor;
    public:
    Sensores();
    Sensores( string _nombre, pair<int, int> _intervalo );
    int generar_aleatorio();
    void trabajar_datos();
    void introducir_db();
};
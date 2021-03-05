#ifndef XMEN_H_INCLUDED
#define XMEN_H_INCLUDED

#include<string>

using namespace std;

struct fecha{

    int dia, mes, anio;
};

struct poderes{
        string nombre_poder;
        char tipo_poder;
        int nivel_de_dominio, cantidad_poderes;
};

struct daticos{

    string nombre_real, alias;
    char sexo, egresado;
    poderes podersitos;
    fecha nacimiento;
};

class Nomina{

    private:
        daticos Estudiantes[100];
        int maximo;

    public:
        Nomina();
        void pedir_registrar_datos();
        void lista_egresados();
        void datos_estudiante();
        int nacidos_antes();
        void nivel_de_poder();
        void porcentaje_mujeres();
        bool buscar_estudiante(string alias);   //para buscar si existe el estudiante
};


#endif // XMEN_H_INCLUDED

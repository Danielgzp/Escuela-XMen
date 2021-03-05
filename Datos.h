#ifndef DATOS_H
#define DATOS_H
#include <iostream>
#include <string>
using namespace std;

struct Fecha{
    int dia, mes, anio;
};

struct Talento {
    string poder;
    string poderTipo;
    int poderDominio;

};

struct Estudiante{
    string nombreReal;
    string alias;
    char sexo;
    char egresado;
    Fecha natal;
    struct Talento poderEstudiante;
};


class Datos
{
    private:
        Estudiante nomina[100];
        int maximo;

    public:
        Datos();
        void PedirRegistrar_Datos();
        bool MostrarEgresados();
        bool MostrarDatosPorAlias();
        int CantEstudiantes2010();
        int CantPoder5();
        float PorcentajeMujeres();
        void Menu();
};

#endif // DATOS_H

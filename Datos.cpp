#include "Datos.h"
#include <iostream>
#include <string>
using namespace std;

Datos::Datos()
{
    Fecha w;
    w.dia = 1; w.mes = 1; w.anio = 1;
    for (int x=0;x<100;x++){
        nomina[x].nombreReal="";
        nomina[x].alias="";
        nomina[x].natal = w;
        nomina[x].sexo='\0';
        nomina[x].poderEstudiante.poder="";
         nomina[x].poderEstudiante.poderTipo="";
          nomina[x].poderEstudiante.poderDominio=1;
        nomina[x].egresado='\0';
    }
    maximo = -1;
}

void Datos::PedirRegistrar_Datos(){
     int contador = maximo;
     int cont_poderes;
     Estudiante pedir;
     if (contador < 99){
            cout << "\n\nREGISTRAR ESTUDIANTES:\n\n";
        do {
            cout << "\nNombre del estudiante: ";
            getline(cin, pedir.nombreReal);
        } while (pedir.nombreReal.length() < 2);
        do {
            cout << "Alias:";
            getline(cin,pedir.alias);
        } while (pedir.alias.length()==0);
        do {
            cout << "Sexo (F/M): ";
            cin >> pedir.sexo;

                if (pedir.sexo != 'F' && pedir.sexo != 'M' && pedir.sexo != 'f' && pedir.sexo != 'm')
                    cout << "ERROR: Tipo de sexo invalido. Solo 'S' o 'N'";

        } while (pedir.sexo != 'F' && pedir.sexo != 'M');
        do {
            cout << "\nFecha de nacimiento: ";
            cout << "\nDia: ";
            cin >> pedir.natal.dia;
            cout << "Mes: ";
            cin >> pedir.natal.mes;
            cout << "Anio: ";
            cin >> pedir.natal.anio;
            if (pedir.natal.dia < 1 || pedir.natal.dia > 31 || pedir.natal.mes < 1 || pedir.natal.mes > 12 || pedir.natal.anio < 0 || pedir.natal.anio > 2020)
                    cout << "ERROR: Fecha invalida.";
        } while (pedir.natal.dia < 1 || pedir.natal.dia > 31 || pedir.natal.mes < 1 || pedir.natal.mes > 12 || pedir.natal.anio < 0 || pedir.natal.anio > 2020);
        do {
            cout << "Estudiante egresado (S/N): ";
            cin >> pedir.egresado;
            if (pedir.egresado != 'S' && pedir.egresado != 'N')
            cout << "\nERROR: Dato invalido. Solo 'S' o 'N'";
        } while (pedir.egresado != 'S' && pedir.egresado != 'N');
        do {
            cout << "\nPODERES DEL ESTUDIANTE:";
            cout << "\nCuantos poderes desea ingresar: ";
            cin >> cont_poderes;
                if (cont_poderes < 1 || cont_poderes > 6) {
                    cout << "\nERROR: Cantidad de poderes invalida.";
                    } else {
                for (int i=0;i<cont_poderes;i++) {
                cout << "\nPoder: ";
                getline(cin,pedir.poderEstudiante.poder);
                cout << "\nTipo de poder (Fisico o Mental)";
                getline(cin,pedir.poderEstudiante.poderTipo);
                cout << "\nNivel de dominio (Entre 1 y 5): ";
                cin >> pedir.poderEstudiante.poderDominio;
                    if (pedir.poderEstudiante.poderDominio < 1 || pedir.poderEstudiante.poderDominio > 5)
                    cout << "ERROR: Nivel de demonio imposible.";}
                }

        } while (pedir.poderEstudiante.poderDominio < 1 || pedir.poderEstudiante.poderDominio > 5 || cont_poderes < 1 || cont_poderes > 6);
    maximo++;
    nomina[maximo] = pedir;
     } else {
        cout << "\ERROR: Nomina de alumnos full.\n";
     }

}

bool Datos::MostrarDatosPorAlias(){
    string alias;
    cout << "\n\nBUSCAR ESTUDIANTE POR SU ALIAS:";
    cout << "Ingrese el alias del estudiante: ";
    cin >> alias;
    bool encontrado = false;
    int contador  = 0;
    while (contador <= maximo && !encontrado){
        if (nomina[contador].alias == alias) encontrado = true;
            contador++;
    } cout << "\nDatos del estudiante: " << nomina[contador].nombreReal;
      cout << "Fecha natal: " << nomina[contador].natal.dia << "/" << nomina[contador].natal.mes << "/ "<< nomina[contador].natal.anio << endl;
      cout << "Sexo: " << nomina[contador].sexo;
      cout << "\nPoderes del estudiante: " << nomina[contador].poderEstudiante.poder;
      cout << "Tipo de poder: " << nomina[contador].poderEstudiante.poderTipo;
      cout << "Dominio de poder: " << nomina[contador].poderEstudiante.poderTipo;
      cout << "Egresado (S/N): " << nomina[contador].egresado;

return encontrado;
}


bool Datos::MostrarEgresados(){
    cout << "\n\nLISTA DE ESTUDIANTES EGRESADOS DEL INSTITUTO: ";
    bool found = false;
    int l = -1;
    while (l <= maximo && !found){
            if (nomina[l].egresado == 'S' || nomina[l].egresado == 's') found = true;
            l++;
        cout << l <<". "<< nomina[l].nombreReal;
    }
    return found;
}

int Datos::CantEstudiantes2010(){
    cout << "\n\nCANTIDAD DE ESTUDIANTES NACIDOS ANTES DEL 2010: ";
    int n=-1;
    while (n<=maximo){
     if (nomina[n].natal.anio < 2010)
        n++;}
     cout << "\n " << n;
    return n;
}

int Datos::CantPoder5(){
    cout << "\n\nCANTIDAD DE ALUMNOS CON ALMENOS UN PODER DOMINADO A NIVEL 5: ";
    int cantidadN5 = 0;
    for (int c=-1; c < maximo;c++) {
    if (nomina[c].poderEstudiante.poderDominio = 5)
        cantidadN5++;
    }
    cout << cantidadN5;
    return cantidadN5;
}

float Datos::PorcentajeMujeres(){
 cout << "\n\n PORCENTAJE DE MUJERES DEL INSTITUTO: ";
 int mujeres = 0;
 float _porcentaje = 0.0;
 for (int m=0; m < maximo; m++){
    if (nomina[m].sexo == 'F') mujeres++;
 } _porcentaje = (mujeres*100)/maximo;
 cout<< _porcentaje;
 return _porcentaje;
}

void Datos::Menu(){
    int opcion = 1;
    int menu_opcion = 1;

    cout << "\n\n***BIENVENIDO AL REGISTRO DE ESTUDIANTES DEL INSTITUTO CHARLES XAVIER***" << endl;

    do {
        cout << "\n¿Que desea hacer?"<<endl;
        cout << "1) Registrar datos de estudiante. "<<endl;
        cout << "2) Mostrar lista general de los estudiantes egresados."<< endl;
        cout << "3) Buscar y mostrar los datos de un estudiante usando su alias."<<endl;
        cout << "4) Mostrar cantidad de estudiantes nacidos antes del 2010."<<endl;
        cout << "5) Mostrar cantidad de estudiantes que dominen un poder al nivel 5"<<endl;
        cout << "6) Mostrar porcentaje de mujeres del instituto"<<endl;
        cout << "\nIngrese opcion (1,2,3,4,5,6): "; cin >> opcion;
        if (opcion < 1 || opcion > 6){
            cout << "\nERROR: Opcion invalida."<<endl;
        }
        } while (opcion < 1 || opcion > 6);

    switch (opcion){
        case 1: PedirRegistrar_Datos();
        break;

        case 2: MostrarEgresados();
        break;

        case 3: MostrarDatosPorAlias();
        break;

        case 4: CantEstudiantes2010();
        break;

        case 5: CantPoder5();
        break;

        case 6: PorcentajeMujeres();
        break;
    }

}






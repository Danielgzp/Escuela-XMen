
#include "XMen.h"
#include<iostream>

using namespace std;

Nomina::Nomina(){


    fecha x;
    x.anio = 0; x.dia = 0; x.mes = 0;
    for(int i = 0; i < 100; i++){

        Estudiantes[i].nombre_real = "";
        Estudiantes[i].alias = "" ;
        Estudiantes[i].nacimiento = x;
        Estudiantes[i].sexo = '\0' ;
        Estudiantes[i].egresado = '\0';
        Estudiantes[i].podersitos.cantidad_poderes = 0;
        Estudiantes[i].podersitos.nombre_poder = "";
        Estudiantes[i].podersitos.tipo_poder = '\0';
        Estudiantes[i].podersitos.nivel_de_dominio = 0;
    }
     maximo = 0;
}

void Nomina::pedir_registrar_datos(){

    int opcion = 0, menu_opcion = 1;
    daticos auxiliar;

    cout<<"                   ///////*LECTURA DE DATOS*\\\\\\\\  "<<endl;
    for(int l = 0; l < 100; l++){

    cout<<"\n________________________________________________________________________________"<<endl;
    do{
    cout<<"\nNombre: "; cin.ignore(); getline(cin, auxiliar.nombre_real);
    if(auxiliar.nombre_real.length() == 0 || auxiliar.nombre_real.length() > 60 ){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.nombre_real.length() == 0 || auxiliar.nombre_real.length() > 60);

    do{
    cout<<"Alias: "; cin.ignore(); getline(cin, auxiliar.alias);
    if(auxiliar.nombre_real.length() == 0 || auxiliar.nombre_real.length() > 20 ){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;
    } }while(auxiliar.nombre_real.length() == 0 || auxiliar.nombre_real.length() > 20);

    do{
    cout<<"\nFecha de nacimiento (dia/mes/anio)"<<endl;
    cout<<"Dia: "; cin>>auxiliar.nacimiento.dia;

    if(auxiliar.nacimiento.dia < 1 || auxiliar.nacimiento.dia > 31){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;
    }} while(auxiliar.nacimiento.dia < 1 || auxiliar.nacimiento.dia > 31);

    do{
    cout<<"Mes: "; cin>>auxiliar.nacimiento.mes;
    if(auxiliar.nacimiento.mes < 1 || auxiliar.nacimiento.mes > 12){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;


    }} while(auxiliar.nacimiento.mes < 1 || auxiliar.nacimiento.mes > 12);

    do{
    cout<<"Anio: "; cin>>auxiliar.nacimiento.anio;
    if(auxiliar.nacimiento.anio > 2020 ){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.nacimiento.anio > 2020);

    do{
    cout<<"\nSexo (H/M): "; cin>>auxiliar.sexo;
    auxiliar.sexo = toupper(auxiliar.sexo);

    if(auxiliar.sexo != 'H' && auxiliar.sexo != 'M'){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.sexo != 'H' && auxiliar.sexo != 'M');

    do{
    cout<<"Egresado (S/N): "; cin>>auxiliar.egresado;
    auxiliar.egresado = toupper(auxiliar.egresado);

    if(auxiliar.egresado != 'S' && auxiliar.egresado != 'N'){

        cout<<"\nERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.egresado != 'S' && auxiliar.egresado != 'N');

    cout<<"\nPODERES: Cada estudiante puede tener un maximo de 6 poderes"<<endl;

    do{
    cout<<"\nIngrese la cantidad de poderes: "; cin>>auxiliar.podersitos.cantidad_poderes;
    if(auxiliar.podersitos.cantidad_poderes < 1 || auxiliar.podersitos.cantidad_poderes > 6){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;
    }} while(auxiliar.podersitos.cantidad_poderes < 1 || auxiliar.podersitos.cantidad_poderes > 6);

    for(int n = 0; n < auxiliar.podersitos.cantidad_poderes; n++){

            cout<<"\nPoder "<<n+1<<endl;

    do{
    cout<<"Nombre del poder: "; cin.ignore(); getline(cin, auxiliar.podersitos.nombre_poder);  //pueden ser varios poderes

    if(auxiliar.podersitos.nombre_poder.length() == 0 || auxiliar.podersitos.nombre_poder.length() > 20){   // do{  } while();

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.podersitos.nombre_poder.length() == 0 || auxiliar.podersitos.nombre_poder.length() > 20);

    do{
    cout<<"Tipo de poder (Fisico/Mental) 'F' si es fisico 'M' si es mental: "; cin>>auxiliar.podersitos.tipo_poder;
    auxiliar.podersitos.tipo_poder = toupper(auxiliar.podersitos.tipo_poder);

    if(auxiliar.podersitos.tipo_poder != 'F' && auxiliar.podersitos.tipo_poder != 'M' ){

        cout<<"\nERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.podersitos.tipo_poder != 'F' && auxiliar.podersitos.tipo_poder != 'M');

    do{
    cout<<"Nivel de dominio: "; cin>>auxiliar.podersitos.nivel_de_dominio;             //le faltan cosas( arreglo de 6)

    if (auxiliar.podersitos.nivel_de_dominio < 1 || auxiliar.podersitos.nivel_de_dominio > 5){

        cout<<"ERROR: Ha ingresado un valor invalido, vuelva a ingresarlo."<<endl;

    }} while(auxiliar.podersitos.nivel_de_dominio < 1 || auxiliar.podersitos.nivel_de_dominio > 5);
    }

    maximo++;
    Estudiantes[maximo] = auxiliar;
    }

    cout<<"\nDatos de la nomina llenos"<<endl;

    while(menu_opcion == 1 ){


    cout<<"\n¿Que accion desea realizar?"<<endl;
    cout<<"\n1- Listado de estudiantes egresados."<<endl;
    cout<<"2- Datos de un estudiante a partir de su Alias."<<endl;
    cout<<"3- Estudiantes nacidos antes de 2010"<<endl;
    cout<<"4- Cantidad de estudiantes con nivel de dominio 5"<<endl;
    cout<<"5- Porcentaje de estudiantes mujeres respecto al total"<<endl;
    cout<<"\nIngrese el modulo que desea ejecutar: "; cin>>opcion;

    if ( opcion < 1 || opcion > 5){

        cout<<"\nError: por favor ingrese una de las opciones disponibles"<<endl;
    }
    switch(opcion){    //menu 1

        case 1: lista_egresados();     break;
        case 2: datos_estudiante();    break;
        case 3: nacidos_antes();       break;
        case 4: nivel_de_poder();      break;
        case 5: porcentaje_mujeres();  break;
    }

            cout<<"\nPara ingresar una nueva opcion presione 1, para salir presione 2: "; cin>>menu_opcion;  //menu 2
    }

    }

void Nomina::lista_egresados(){   //recordar ver si todo se puede ahcer con la variable maximo


    cout<<"\n     LISTA DE ESTUDIANTES EGRESADOS "<<endl;

    for(int p = 0; p < 100; p++){

        if(Estudiantes[p].egresado == 'S'){

            cout<<"\nAlumno: "<<Estudiantes[p].nombre_real<<endl;
        }
    }
}

bool Nomina::buscar_estudiante(string alias){

    bool encontrado = false;
    int contador = 0;
    while(contador <= maximo && !encontrado){

        if(Estudiantes[contador].alias == alias) {

                encontrado = true;
                contador++;
    }
    }

    return encontrado;
}

void Nomina::datos_estudiante(){    //ingresar alias, mostrar datos

    string alias;
    int contador = 0;
    bool encontrado = false;

    do{
        cout<<"Introduzca el alias del alumno a consultar: "; cin.ignore(); getline(cin, alias);

    } while(alias.length() == 0);

    if(buscar_estudiante(alias)){

        contador = 0;
        while(!encontrado){

        if(Estudiantes[contador].alias == alias) {

                encontrado = true;

               } else { contador++;}
               }

               cout<<"\nDATOS DEL ESTUDIANTE: "<<endl;
               cout<<"Nombre: "<<Estudiantes[contador].nombre_real<<endl;;
               cout<<"Alias: "<<Estudiantes[contador].alias<<endl;
               cout<<"\nFecha de nacimiento: " <<Estudiantes[contador].nacimiento.dia<<"/";
               cout<<Estudiantes[contador].nacimiento.mes<<"/"<<Estudiantes[contador].nacimiento.anio<<endl;

               cout<<"Sexo: "<<Estudiantes[contador].sexo;
               switch(Estudiantes[contador].sexo){

                   case 'H': cout<<"Hombre"<<endl;
                             break;
                   case 'M': cout<<"Mujer"<<endl;
                             break;
               }
               cout<<"Egresado: ";
               switch(Estudiantes[contador].egresado){

                   case 'S': cout<<"Es egresado"<<endl;
                             break;
                   case 'N': cout<<"No es egresado"<<endl;
                             break;
               }

               for(int a = 0; a < Estudiantes[contador].podersitos.cantidad_poderes; a++){

               cout<<"\nNombre: "<<Estudiantes[contador].podersitos.nombre_poder<<endl;
               cout<<"Tipo (Fisico/Mental): ";
               switch(Estudiantes[contador].podersitos.tipo_poder){

                   case 'F': cout<<"Fisico"<<endl;
                             break;
                   case 'M': cout<<"Mental"<<endl;
                             break;
               }
               cout<<"Nivel de dominio: "<<Estudiantes[contador].podersitos.nivel_de_dominio<<endl;
    }
}
}

int Nomina::nacidos_antes(){

    int contador3 = 0;

    for( int w = 0; w < 100; w++){

        if(Estudiantes[w].nacimiento.anio < 2010){

            contador3++;
        }
    }

    cout<<"\nLa cantidad de estudiantes nacidos antes de 2010 es: "<<contador3<<endl;

    return contador3;

}

void Nomina::nivel_de_poder(){

    int contador4 = 0;

    for(int t = 0; t < maximo; t++){

        if(Estudiantes[t].podersitos.nivel_de_dominio == 5){

            contador4++;
        }
    }

    cout<<"\nLa cantidad de estudiantes que alcanzan un nivel de dominio de 5 es: "<<contador4<<" alumnos"<<endl;

}

void Nomina::porcentaje_mujeres(){

    int porcentaje = 0, contador5 = 0;

    for(int d = 0; d < 100; d++){

        if(Estudiantes[d].sexo == 'F'){

            contador5++;
        }
    }
    porcentaje = ( contador5* 100) / 100;
    cout<<"\nEl porncetaje de mujeres respecto al total es : "<<porcentaje<<"%"<<endl;
}







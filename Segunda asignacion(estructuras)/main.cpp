/*Se le ha contratado por la Escuela para Jóvenes Talentos del Prof. Charles Xavier, p
ara llevar un registro de sus estudiantes, y en la que se deben manejar los siguientes datos,
para cada estudiante:

-Nombre real del Estudiante.
-Alias del Estudiante.
-Fecha de Nacimiento.
-Sexo (Masculino/Femenino).
-Estudiante egresado (SI/NO).

Ahora, para cada Estudiante se desea llevar el registro de los talentos (poderes) que posee, c
on los datos siguientes:

-Nombre del Poder.
-Tipo de Poder (Físico/Mental)
-Nivel de Dominio (de 1 a 5. siendo 1 el mínimo hacia 5 que es el máximo).

Cada Estudiante puede tener un máximo de 6 poderes diferentes, por lo que se desea llevar en el registro anterior.

Con los Datos planteados anteriormente, se requiere que desarrolle una clase en C++ en la cual
se manejará la nómina de estudiantes, que son de cien (100), entre los que están y los que han pasado
por el instituto. En dicha clase, se deben realizar los siguientes métodos, descritos a continuación:

-Pedir y Registrar los Datos de un Estudiante, tanto de los aspectos de identificación como los poderes que posee.
-Mostrar por cónsola un listado general de los Estudiantes Egresados del instituto.
-Mostrar los datos de un Estudiante dado, enviando de parámetro el Alias del Estudiante.
-Devolver en una función la cantidad de Estudiantes que hayan nacido antes del 2010.
-Mostrar la cantidad de Estudiantes que tengan por lo menos un poder en nivel cinco (5).
-Mostrar el porcentaje de Estudiantes mujeres del instituto, respecto al total planteado anteriormente.

En la clase deben manejarse estructuras y arreglos.*/

#include "XMen.h"
#include <iostream>
#include<conio.h>

using namespace std;

Nomina pruebita;

int main(){

    pruebita.pedir_registrar_datos();

    getch();
    return 0;
}

#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <string.h>
#include <conio.h>

#include "empleado.h"
#include "lsl.h"
#include "cola.h"

using namespace std;

class Empresa
{
private:
    enum{
        menuAlta=1,
        menuMostrar,
        menuMostrarDias,
        menuCambiarDia,
        menuMostraDia,
        menuSalir
    };
    int dia;
    string diasNombre[7]={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};

public:
    LSL<Empleado> trabajadores;
    Cola<Empleado> diasCola[7];
    Empresa();
    void menu();

    void alta();
    void asignar(Empleado,bool[]);

    void mostrar();

    void mostrarDias();
    void mostrarDia(int);

    void mostrarDiaActual();

    void cambiarDia();

    void InsertarOrdenado(Empleado);

    bool buscarId(int);
};

#endif // EMPRESA_H

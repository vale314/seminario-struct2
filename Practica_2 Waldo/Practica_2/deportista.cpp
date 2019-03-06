#include "deportista.h"

Deportista::Deportista(int valorNuevoDeSocio,string valorNombre,int valorEdad,string valorDeporte)
{
    establecerNumeroDeSocio(valorNuevoDeSocio);
    establecerNombre(valorNombre);
    establecerEdad(valorEdad);
    establecerDeporte(valorDeporte);
}

void Deportista::establecerNumeroDeSocio(int numeroDeSocio)
{
    this->NumeroDeSocio = numeroDeSocio;
}

int Deportista::obtenerNumeroDeSocio()
{
    return NumeroDeSocio;
}

void Deportista::establecerNombre(string nombre)
{
    strcpy(this->nombre,nombre.c_str());
}

string Deportista::obtenerNombre()
{
    return nombre;
}

void Deportista::establecerEdad(int edad)
{
    this->edad = edad;
}

int Deportista::obtenerEdad()
{
    return edad;
}

void Deportista::establecerDeporte(string deporte)
{
    strcpy(this->deporte,deporte.c_str());
}

string Deportista::obtenerDeporte()
{
    return deporte;
}

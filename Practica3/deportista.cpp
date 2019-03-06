#include "deportista.h"

Deportista::Deportista()
{

}

void Deportista::establecerNumeroDeSocio(int value)
{
    numeroDeSocio=value;
}

int Deportista::obtenerNumeroDeSocio()
{
    return  numeroDeSocio;
}

void Deportista::establecerNombre(string value)
{
    strcpy(nombre,value.c_str());
}

string Deportista::obtenerNombre()
{
    return nombre;
}

void Deportista::establecerEdad(int value)
{
    edad=value;
}

int Deportista::obtenerEdad()
{
    return edad;
}

void Deportista::establecerDeporte(string value)
{
    //char *charValue = new char[value.length()+1];
    strcpy(deporte,value.c_str());
    //deporte=value;
}

string Deportista::obtenerDeporte()
{
    return deporte;
}

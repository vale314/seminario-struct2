#include "deportista.h"

Deportista::Deportista(int valorNuevoDeSocio,string valorNombre,int valorEdad,string valorDeporte)
{
    establecerNumeroDeSocio(valorNuevoDeSocio);
    establecerNombre(valorNombre);
    establecerEdad(valorEdad);
    establecerDeporte(valorDeporte);
}//Constructor

void Deportista::establecerNumeroDeSocio(int numeroDeSocio)
{
    this->NumeroDeSocio = numeroDeSocio;
}//Set numeroSocio

int Deportista::obtenerNumeroDeSocio()
{
    return NumeroDeSocio;
}//get NumerSocio

void Deportista::establecerNombre(string nombre)
{
    strcpy(this->nombre,nombre.c_str());
}//set Nombre

string Deportista::obtenerNombre()
{
    return nombre;
}//get Nombre

void Deportista::establecerEdad(int edad)
{
    this->edad = edad;
}//set Edad

int Deportista::obtenerEdad()
{
    return edad;
}//get Edad

void Deportista::establecerDeporte(string deporte)
{
    strcpy(this->deporte,deporte.c_str());
}//Set Deporte

string Deportista::obtenerDeporte()
{
    return deporte;
}//get Deporte

ostream& operator<<(ostream& os,Deportista& d)
{
    os<<left<<setw(5)<<d.obtenerNumeroDeSocio()<<setw(13)<<d.obtenerNombre()<<setw(5)<<d.obtenerEdad()<<setw(5)<<d.obtenerDeporte()<<endl;
    return os;
}

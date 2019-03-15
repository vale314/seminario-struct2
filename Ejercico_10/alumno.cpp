#include "alumno.h"

Alumno::Alumno():nombre("X"), edad(0), sexo("Y")
{

}

string Alumno::getNombre() const
{
    return nombre;
}

void Alumno::setNombre(const string &value)
{
    nombre = value;
}

int Alumno::getEdad() const
{
    return edad;
}

void Alumno::setEdad(int value)
{
    edad = value;
}

string Alumno::getSexo() const
{
    return sexo;
}

void Alumno::setSexo(const string &value)
{
    sexo = value;
}


ostream& operator<<(ostream& os, Alumno& al)
{
    os<<left<<setw(10)<<al.getNombre()<<setw(10)<<al.getEdad()<<setw(10)<<al.getSexo()<<endl;
    return os;
}

void Alumno::toString()
{
    cout<<left<<setw(10)<<nombre<<setw(10)<<edad<<setw(10)<<sexo<<endl;
}

#include "empleado.h"

int Empleado::getNss() const
{
    return nss;
}

void Empleado::setNss(int value)
{
    nss = value;
}

string Empleado::getNombre() const
{
    return nombre;
}

void Empleado::setNombre(const string &value)
{
    nombre = value;
}

int Empleado::getTotal() const
{
    return total;
}

void Empleado::setTotal(int value)
{
    total = value;
}

Empleado::Empleado()
{
    nss=0;
    total=0;
    nombre="";
}

ostream& operator<<(ostream& os,Empleado& p)
{
    os<<"Nombre: "<<p.getNombre()<<" Nss: "<<p.getNss()<<" Total: "<<p.getTotal()<<endl;
    return os;
}//sobre cargado  de <<

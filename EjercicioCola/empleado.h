#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <iostream>

using namespace std;

class Empleado
{
private:
    int nss;
    string nombre;
    int total;

public:
    Empleado();
    int getNss() const;
    void setNss(int value);
    string getNombre() const;
    void setNombre(const string &value);
    int getTotal() const;
    void setTotal(int value);

    friend ostream& operator<<(ostream& os,Empleado& p);

};

#endif // EMPLEADO_H

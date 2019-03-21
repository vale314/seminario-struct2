#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <iomanip>

using namespace std;

class Alumno
{
public:
    Alumno();

    string getNombre() const;
    void setNombre(const string &value);

    int getEdad() const;
    void setEdad(int value);

    string getSexo() const;
    void setSexo(const string &value);

    friend ostream& operator<<(ostream& os, Alumno& al);
    void toString();
private:
    string nombre;
    int edad;
    string sexo;
};

#endif // ALUMNO_H

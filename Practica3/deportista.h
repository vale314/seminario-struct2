#ifndef DEPORTISTA_H
#define DEPORTISTA_H
#include <string>
#include <string.h>

using namespace std;


class Deportista
{
public:
    Deportista();
    //Deportista(int=0,string=" ",int=0,string=" ");
    void establecerNumeroDeSocio(int);
    int obtenerNumeroDeSocio();
    void establecerNombre(string);
    string obtenerNombre();
    void establecerEdad(int);
    int obtenerEdad();
    void establecerDeporte(string);
    string obtenerDeporte();

private:
    int numeroDeSocio;
    char nombre[15];
    int edad;
    char deporte[15];
};

#endif // DEPORTISTA_H

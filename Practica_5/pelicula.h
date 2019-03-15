#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Pelicula
{
public:
    Pelicula();

    string getId() const;
    void setId(const string &value);

    string getNombre() const;
    void setNombre(const string &value);

    string getProtagonista() const;
    void setProtagonista(const string &value);

    string getGenero() const;
    void setGenero(const string &value);

    string getDirector() const;
    void setDirector(const string &value);

    friend istream& operator>>(istream& in,Pelicula& p);
    friend ostream& operator<<(ostream& os,Pelicula& p);
    void toString() const;
    void toString2() const;


private:
    string id;
    string nombre;
    string protagonista;
    string genero;
    string director;
};

#endif // PELICULA_H

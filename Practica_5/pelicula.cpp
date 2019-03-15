#include "pelicula.h"

Pelicula::Pelicula() : id("XXXX"), nombre("Y"),protagonista("x"),genero("w"), director("Z")
{

}

string Pelicula::getNombre() const
{
    return nombre;
}

void Pelicula::setNombre(const string &value)
{
    nombre = value;
}

string Pelicula::getProtagonista() const
{
    return protagonista;
}

void Pelicula::setProtagonista(const string &value)
{
    protagonista = value;
}

string Pelicula::getGenero() const
{
    return genero;
}

void Pelicula::setGenero(const string &value)
{
    genero = value;
}

string Pelicula::getDirector() const
{
    return director;
}

void Pelicula::setDirector(const string &value)
{
    director = value;
}

string Pelicula::getId() const
{
    return id;
}

void Pelicula::setId(const string &value)
{
    id = value;
}

istream& operator>>(istream& in,Pelicula& p)
{
    char* buffer;
    string tam;
    int size;

    if(in.peek() == -1)
    {
        in.get();
        return in;
    }//evalua uno antes del fin del archivo.

    getline(in,tam,' ');
    size = stoi(tam) + 1;
    buffer = new char[size];
    in.get(buffer,size);
    p.setNombre(string(buffer));
    delete[] buffer;

    getline(in,tam,' ');
    size = stoi(tam) + 1;
    buffer = new char[size];
    in.get(buffer,size);
    p.setProtagonista(string(buffer));
    delete[] buffer;

    getline(in,tam,' ');
    size = stoi(tam) + 1;
    buffer = new char[size];
    in.get(buffer,size);
    p.setGenero(string(buffer));
    delete[] buffer;

    getline(in,tam,' ');
    size = stoi(tam) + 1;
    buffer = new char[size];
    in.get(buffer,size);
    p.setDirector(string(buffer));
    delete[] buffer;

    if(getline(in,tam,'#'))
        return in;

}//sobre cargado  de >>

ostream& operator<<(ostream& os,Pelicula& p)
{
    os<<p.nombre.size()            <<" "<<p.nombre
      <<p.protagonista.size()      <<" "<<p.protagonista
      <<p.genero.size()            <<" "<<p.genero
      <<p.director.size()          <<" "<<p.director<<'#';

    return os;
}//sobre cargado  de <<

void Pelicula::toString() const
{
    cout<<left<<setw(25)<<nombre<<setw(15)<<protagonista<<setw(15)<<genero<<setw(15)<<director/*.substr(0,director.size()-1)*/<<endl;
    //return nombre + "\t|\t" + protagonista + "\t|\t" + genero + "\t|\t" + director;
}//funcion toString para imprimir el registro en el almacenamiento primario


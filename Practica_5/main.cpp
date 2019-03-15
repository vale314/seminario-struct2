/*
Practica n°5

 López Martínez Ballardo Axel
 Ruiz Ortiz Valentin Alejandro
 Silva Ruiz Diego Adan
 Perez Meza Eduardo
 Waldo Salazar Alejandro

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "pelicula.h"

using namespace std;

enum opc{
    opc_al = 1,
    opc_ci,
    opc_cg,
    opc_s
};//enum de menu

void menu(fstream &pelicula);
void alta(fstream& pelicula);
string llave(Pelicula& p);
void consultai(fstream& pelicula);
void consultag(fstream& pelicula);
void head();

int main()
{
    fstream pelicula;
    pelicula.open("peliculas.dat",ios::in|ios::app);
    if(not pelicula.is_open())
    {
        cerr<<"No se pudo abrir el archivo exitosamente"<<endl;
        exit(1);
    }
    menu(pelicula);

    pelicula.close();

    return 0;

}//main

void menu(fstream& pelicula)
{
    string opc;
    while(true)
    {
        pelicula.clear();
        pelicula.seekg(0);
        system("cls");
        cout<<setw(40)<<"Menu - Peliculas"<<endl
           <<opc_al<<") Alta de Pelicula"<<endl
          <<opc_ci<<") Consulta Individual"<<endl
         <<opc_cg<<") Consulta General"<<endl
        <<opc_s<<") Salir"<<endl
        <<">> ";
        getline(cin,opc);
        if(opc == "1"){
            alta(pelicula);
        }else if(opc == "2"){
            consultai(pelicula);
        }else if(opc == "3"){
            consultag(pelicula);
        }else if(opc == "4"){
            break;
        }
        else{
            cout<<"Opcion Incorrecta"<<endl;
        }//llaves del menu
        system("pause");
    }//while
}//menu

void alta(fstream& pelicula)
{
    system("cls");
    string linea;
    Pelicula p,temp;
    cout<<setw(40)<<"[*ALTA DE PELICULA*]"<<endl
       <<"Nombre: "; getline(cin,linea);
    p.setNombre(linea);
    cout<<"Protagonista: "; getline(cin,linea);
    p.setProtagonista(linea);
    cout<<"Genero: "; getline(cin,linea);
    p.setGenero(linea);
    cout<<"Director: "; getline(cin,linea);
    p.setDirector(linea);
    cout<<endl;
    head();
    p.toString();
    //Guarda
    pelicula << p;
}//alta

string llave(Pelicula& p)
{
    string linea = p.getNombre()+p.getProtagonista();
    for(auto & c : linea) c = toupper(c);

    return linea;
}//llave (ID)

void consultai(fstream& pelicula)
{
    system("cls");
    Pelicula temp;
    string linea,aux;
    bool band = false;
    /*Genera la llave a buscar con un objeto temporal*/
    cout<<"\t[*CONSULTA INDIVIDUAL*]"<<endl
       <<left<<"NOTA: Para encontrar la pelicula debes de ingresar el nombre y el protagonista"<<endl<<"(No te preocupes por las mayusuclas o minusculas)"<<endl<<endl
      <<"Nombre: "; getline(cin,linea);
    temp.setNombre(linea);
    cout<<"Protagonista: "; getline(cin,linea);
    temp.setProtagonista(linea);
    linea = llave(temp);

    while (pelicula >> temp) {

        aux = llave(temp);
        if(linea == aux){
            system("cls");
            cout<<"\t\t[*PELICULA ENCONTRADA*]"<<endl;
            head();
            temp.toString();
            band = true;
            break;
        }//if
    }//while

    if(band == false)
    cout<<"\n[*No se encontro ninguna pelicula*]"<<endl<<endl;
}//Consulta individual

void consultag(fstream& pelicula)
{
    system("cls");
    Pelicula p;

    cout<<"\t\t[*PELICULAS EN EL CATALOGO*]"<<endl;
    head();
    while(pelicula >> p)
    {
        p.toString();
    }//while
    cout<<endl<<endl;
}//Consuta general

void head()
{
    cout<<left<<setw(25)<<"NOMBRE"<<setw(15)<<"PROTAGONISTA"
       <<setw(15)<<"GENERO"<<setw(15)<<"DIRECTOR"<<endl;
}//head

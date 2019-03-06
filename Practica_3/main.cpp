#include <iostream>
#include <fstream>
#include <iomanip>
#include "deportista.h"

using namespace std;

enum menu
{
    menu_i=1,
    menu_g,
    menu_s
};//enum

void menu();
void SearchIn(ifstream& archDeportEntrada,Deportista& d);
void SearchGn(ifstream& archDeportEntrada,Deportista& d);
void head();

int main()
{
    menu();
    return 0;
}//main

void menu()
{
    ifstream archDeportEntrada;
    Deportista d;
    archDeportEntrada.open("deportista.dat",ios::in|ios::binary);
    if(!archDeportEntrada.is_open())
    {
        cerr<<"No se pudo abrir el archivo con exito"<<endl;
        exit(1);
    }//if
    int opc;
    do{
    archDeportEntrada.clear();
    archDeportEntrada.seekg(0);
    cout<<setw(50)<<"Menu - Asociacion de Deportistas Tapatios"<<endl
       <<menu_i<<". Consulta Individual (Numero de Socio)"<<endl
      <<menu_g<<". Consulta General"<<endl
     <<menu_s<<". Salir"<<endl
    <<"Eliga su opcion: ";
    cin>>opc;
    switch (opc) {
    case menu_i:
        SearchIn(archDeportEntrada,d);
        break;
    case menu_g:
        SearchGn(archDeportEntrada,d);
        break;
    case menu_s:
        break;
    default:
        cout<<"Opcion Incorrecta"<<endl;
    }//switch
    }while(opc!=menu_s);//do{}while

    archDeportEntrada.close();
}//menu

void SearchIn(ifstream& archDeportEntrada,Deportista& d)
{
    system("cls");
    int numeroSocio,band = 0;
    cout<<"Ingresa el numero de socio a buscar: ";
    cin>>numeroSocio;
    while(!archDeportEntrada.eof()){
        archDeportEntrada.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
        if(numeroSocio==d.obtenerNumeroDeSocio()){
            head();
            cout<<d<<endl;
            band = 1;
            break;
        }//if
    }//while
    if(band==0)
        cout<<"No se encontro a ningun deportista con ese numero de socio"<<endl<<endl;
    band = 0;
    system("pause");
    system("cls");
}//SearchIn

void SearchGn(ifstream& archDeportEntrada,Deportista& d)
{
    system("cls");
    int band = 0;
    bool cond = true;
    while(cond){
        archDeportEntrada.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
        if(!archDeportEntrada.eof()){
            if(d.obtenerEdad()!=0){
                if(band==0)
                    head();
                cout<<d<<endl;
                band=1;
            }//if
        }//if Condicional final de linea
        else
            cond = false;

    }//while
    system("pause");
    system("cls");
}//SearchGn

void head()
{
    cout<<left<<setw(6)<<"ID"<<setw(10)<<"Nombre"<<setw(8)<<"Edad"<<setw(10)<<"Deporte"<<endl<<endl;
}//head

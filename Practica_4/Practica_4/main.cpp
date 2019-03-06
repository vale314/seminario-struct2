#include <iostream>
#include <fstream>
#include <iomanip>
#include "deportista.h"
#include <conio.h>
#include <windows.h>

using namespace std;

enum menu
{
    menu_a=1,
    menu_b,
    menu_c,
    menu_ci,
    menu_cg,
    menu_s
};

static Deportista d;

void menu();
void alta(fstream& archDeportEntradaSalida);
void baja(fstream& archDeportEntradaSalida);
void cambios(fstream& archDeportEntradaSalida);
void searchIn(fstream& archDeportEntradaSalida);
void searchGn(fstream& archDeportEntradaSalida);
void head();

int main()
{
    menu();
    return 0;
}

void menu()
{
    fstream archDeportEntradaSalida;
    archDeportEntradaSalida.open("deportista.dat",ios::in|ios::out);
    if(!archDeportEntradaSalida)
    {
        cerr<<"No se pudo abrir el archivo con exito"<<endl;
        exit(1);
    }
    int opc;
    do {
        system("cls");
        archDeportEntradaSalida.clear();
        archDeportEntradaSalida.seekg(0);
        cout<<setw(50)<<"Menu - Asociacion de Deportistas Tapatios"<<endl
           <<menu_a<<". Alta"<<endl
          <<menu_b<<". Baja"<<endl
         <<menu_c<<". Cambios"<<endl
        <<menu_ci<<". Consultas Individuales (Numero de Socio)"<<endl
        <<menu_cg<<". Consuta General"<<endl
        <<menu_s<<". Salir"<<endl
        <<"Elige tu opcion: ";
        cin>>opc;
        switch (opc) {
        case menu_a:
            alta(archDeportEntradaSalida);
            break;
        case menu_b:
            baja(archDeportEntradaSalida);
            break;
        case menu_c:
            cambios(archDeportEntradaSalida);
            break;
        case menu_ci:
            searchIn(archDeportEntradaSalida);
            break;
        case menu_cg:
            searchGn(archDeportEntradaSalida);
            break;
        case menu_s:
            break;
        default:
            cout<<"Opcion Incorrecta"<<endl<<endl;
        }
    } while (opc != menu_s);
}

void alta(fstream& archDeportEntradaSalida)
{
    int numeroSocioTemp;
    char cadenaTemp[15];
    int edad;
    cout<<setw(15)<<"Alta Deportista"<<endl;
    cout<<"Ingrese el numero de socio: ";
    cin>>numeroSocioTemp;
    while(!archDeportEntradaSalida.eof()){
        archDeportEntradaSalida.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
        if(numeroSocioTemp == d.obtenerNumeroDeSocio()){
            cout<<"Numero de Socio Existente"<<endl
               <<"Nuevo numero de Soico: "; cin>>numeroSocioTemp;
            archDeportEntradaSalida.clear();
            archDeportEntradaSalida.seekg(0);
        }
    }//while
    archDeportEntradaSalida.clear();
    archDeportEntradaSalida.seekg(0);
    d.establecerNumeroDeSocio(numeroSocioTemp);
    cout<<"Teclea Nombre, Edad y Deporte"<<endl;
    cin>>setw(15)>>cadenaTemp;
    d.establecerNombre(cadenaTemp);
    cin>>setw(15)>>edad;
    d.establecerEdad(edad);
    cin>>setw(15)>>cadenaTemp;
    d.establecerDeporte(cadenaTemp);

    archDeportEntradaSalida.seekp((d.obtenerNumeroDeSocio()-1) * sizeof (Deportista));
    archDeportEntradaSalida.write(reinterpret_cast<const char*>(&d),sizeof (Deportista));
}
void baja(fstream& archDeportEntradaSalida)
{
    int numeroSocioTemp;
    Deportista blanco;
    cout<<"Ingrese el numero de socio a eliminar: ";
    cin>>numeroSocioTemp;
    archDeportEntradaSalida.seekg(sizeof(Deportista)*(numeroSocioTemp-1));
    archDeportEntradaSalida.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
    if(d.obtenerNumeroDeSocio() == numeroSocioTemp)
    {
        archDeportEntradaSalida.seekp((numeroSocioTemp-1) * sizeof (Deportista));
        archDeportEntradaSalida.write(reinterpret_cast<const char*>(&blanco),sizeof (Deportista));
        getch();
        cout<<"Deportista eliminado exitosamente"<<endl;
    }
    else{
        cout<<"No habia ningun deportista con ese numero de socio"<<endl;
        getch();
    }

}

void cambios(fstream& archDeportEntradaSalida)
{
    int numeroSocioTemp;
    char cadenaTemp[15];
    int edad;
    cout<<"Numero de Socio a Modificar: ";
    cin>>numeroSocioTemp;

    archDeportEntradaSalida.seekg(sizeof(Deportista)*(numeroSocioTemp-1));
    archDeportEntradaSalida.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
    if(d.obtenerNumeroDeSocio() == numeroSocioTemp)
    {
        cout<<"Teclea Nombre, Edad y Deporte"<<endl;
        cin>>setw(15)>>cadenaTemp;
        d.establecerNombre(cadenaTemp);
        cin>>setw(15)>>edad;
        d.establecerEdad(edad);
        cin>>setw(15)>>cadenaTemp;
        d.establecerDeporte(cadenaTemp);
        d.establecerNumeroDeSocio(numeroSocioTemp);

        archDeportEntradaSalida.seekp(sizeof(Deportista)*(numeroSocioTemp-1));

        archDeportEntradaSalida.write(reinterpret_cast<char*>(&d),sizeof(Deportista));

        cout<<"Modificado Exitosamente Deportista"<<endl;
        getch();
    }else{
        cout<<"Numero de Soico No Registrado"<<endl;
        getch();
    }

}

void searchIn(fstream& archDeportEntradaSalida)
{
    system("cls");
    int numeroSocio,band = 0;
    cout<<"Ingresa el numero de socio a buscar: ";
    cin>>numeroSocio;
    while(!archDeportEntradaSalida.eof()){
        archDeportEntradaSalida.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
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

void searchGn(fstream& archDeportEntradaSalida)
{
    system("cls");
    int band = 0;
    bool cond = true;
    while(cond){
        archDeportEntradaSalida.read(reinterpret_cast<char*>(&d),sizeof (Deportista));
        if(!archDeportEntradaSalida.eof()){
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

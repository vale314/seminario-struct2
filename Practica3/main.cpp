#include <iostream>
#include <fstream>
#include <iomanip>
#include "deportista.h"

using namespace std;

enum menu{
    menuConsultaI=1,
    menuConsultaG,
    menuSalir
};

void consultaIndividual(ifstream &archDeportEntrada);

void consultaGeneral(ifstream &archDeportEntrada);

void menu();

void imprimirDeportista(Deportista *deportistaAux);

void imprimirCabeceras();

int main()
{
    menu();
    return 0;
}

void menu(){
    int opc;
    ifstream archDeportEntrada;
    archDeportEntrada.open("C:\\Users\\LENOVO\\Documents\\proyects\\Seminario Struct 2\\seminario-struct2\\build-practica2Mejorada-Desktop_Qt_5_11_2_MinGW_32bit-Debug\\deportista.dat",ios::in|ios::binary);
    if(!archDeportEntrada.good()){
        cerr <<"Error "<<endl;
        exit(1);
    }
    do{
       archDeportEntrada.seekg(0);
       cout<<menuConsultaI<<". Consulta Individual(num de socio)"<<endl
           <<menuConsultaG<<". Consulta General"<<endl
           <<menuSalir<<". Salir"<<endl
           <<"Elige Una Opcion"<<endl;
       cin>>opc;
       switch (opc) {
        case menuConsultaI:
           consultaIndividual(archDeportEntrada);
           break;
       case menuConsultaG:
           break;
       case menuSalir:
           break;
       }
    }while(opc!=menuSalir);
}

void consultaIndividual(ifstream &archDeportEntrada){
    int numSocio;
    int encontrado=0;
    Deportista deportistaAux;
    cout<<"Ingrese el Id a buscar:"<<endl;
    cin>>numSocio;

    while(!archDeportEntrada.eof()){
        archDeportEntrada.read(reinterpret_cast<char*>(&deportistaAux),sizeof(Deportista));
        cout<<"Id "<<deportistaAux.obtenerNumeroDeSocio()<<endl;
        archDeportEntrada.clear();
        archDeportEntrada.seekg(50);
        if(deportistaAux.obtenerNumeroDeSocio()==numSocio){
            encontrado=1;
            break;
        }
    }

    if(encontrado){
        imprimirCabeceras();
        imprimirDeportista(&deportistaAux);
    }
    else
        cout<<"No Encontrado"<<endl;

}

void imprimirDeportista(Deportista *deportistaAux){
    cout<<left<<setw(15)<<deportistaAux->obtenerNombre()<<setw(15)<<deportistaAux->obtenerEdad()<<setw(15)<<deportistaAux->obtenerDeporte()<<setw(15)<<deportistaAux->obtenerNumeroDeSocio()<<endl;
}

void imprimirCabeceras(){
    cout<<left<<setw(15)<<"Nombre"<<setw(15)<<"Edad"<<setw(15)<<"Deporte"<<setw(15)<<"Id"<<endl;
}

void consultaGeneral(ifstream &archDeportEntrada){

}

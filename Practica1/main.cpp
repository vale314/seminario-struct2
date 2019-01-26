#include <iostream>
#include <fstream>
#include <cstdlib>//exit
#include <iomanip>

using namespace std;

struct deportistas
{
    string nombre;
    string edad;
    string deporte;
};

struct edad
{
    int menor;
    int mayor;
};

void mostrarLinea(deportistas *deportista){
    cout<<left<<setw(10)<<deportista->nombre<<setw(13)<<deportista->edad<<setw(7)<<deportista->deporte<<endl;
}

void menoresdeedad(ifstream &archivoDeportistasEntrada,edad edades){
    deportistas deportista;
    archivoDeportistasEntrada.clear();
    archivoDeportistasEntrada.seekg(0,ios::beg);
    while (archivoDeportistasEntrada>>deportista.nombre>>deportista.edad>>deportista.deporte){
     if(!archivoDeportistasEntrada.eof()&& stoi(deportista.edad) >= edades.menor && stoi(deportista.edad) <=edades.mayor)
        mostrarLinea(&deportista);
    }
}

int main()
{
    ifstream archivoDeportistaEntrada;
    archivoDeportistaEntrada.open("C:\\Users\\LENOVO\\Documents\\proyects\\Seminario Struct 2\\seminario-struct2\\build-Tarea1_crearArchivo-Desktop_Qt_5_11_2_MinGW_32bit-Debug\\Deportista.txt",ios::in);
    if(!archivoDeportistaEntrada){
        cerr<<"No se puede abrir el archivo"<<endl;
        exit(1);
    }
    int op;
    edad edades;
    do{
        cout<<"\tMenu"<<endl
           <<"1)Mostrar deportistas menores de edad(5-17)"<<endl
          <<"2)Mostrar deportistas mayores de edad(18-59)"<<endl
         <<"3)Mostrar deportistas mayores de edad (60-85)"<<endl
        <<"4)Salir"<<endl
        <<">> ";
        cin>>op;
        switch (op) {
        case 1:
            edades.menor=5;
            edades.mayor=17;
            menoresdeedad(archivoDeportistaEntrada,edades);
            break;
        case 2:
            edades.menor=18;
            edades.mayor=59;
            menoresdeedad(archivoDeportistaEntrada,edades);
            break;
        case 3:
            edades.menor=60;
            edades.mayor=85;
            menoresdeedad(archivoDeportistaEntrada,edades);
            break;
        case 4:
            break;
        }
    }while(op!=4);

    archivoDeportistaEntrada.close();
    return 0;
}

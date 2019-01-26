/*
    Olivares Matos Cliserio Jose
    Ruiz Ortiz Valentin Alejandro
    Silvia Ruiz Digo Adam
    Waldo Salazar Alejandro

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>//exit

using namespace std;

void mostrarLinea(const char* const, int, const char* const);

int main()
{
    char nombre[30];
    int edad;
    char deporte[20];

    ifstream archivoDeportistaEntrada;//archivo logico
    archivoDeportistaEntrada.open("C:\\Users\\LENOVO\\Documents\\proyects\\Seminario Struct 2\\seminario-struct2\\build-Tarea1_crearArchivo-Desktop_Qt_5_11_2_MinGW_32bit-Debug\\Deportista.txt",ios::in);

    if(!archivoDeportistaEntrada){
        cerr<<"No se puede abrir el archivo"<<endl;
        exit(1);
    }

    cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;

    while (archivoDeportistaEntrada>>nombre>>edad>>deporte)
        mostrarLinea(nombre,edad,deporte);

    archivoDeportistaEntrada.close();

    return 0;
}

void mostrarLinea(const char* const nombre, int edad, const char* const deporte){
    cout<<left<<setw(10)<<nombre<<setw(13)<<edad<<setw(7)<<deporte<<endl;
}

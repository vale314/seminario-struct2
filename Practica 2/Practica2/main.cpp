#include <iostream>
#include <deportista.h>
#include <fstream>

using namespace std;

int main()
{

    ofstream archivoDeportistaSalida("deportista.txt",ios::binary);
    if(!archivoDeportistaSalida){
        cerr<<"No Se Pudo Abrir El Archivo"<<endl;
        exit(1);
    }
    Deportista deportistaBlanco;
    deportistaBlanco.establecerNombre("Valentin");
    deportistaBlanco.establecerEdad(20);
    deportistaBlanco.establecerDeporte("Calestenia");
    deportistaBlanco.establecerNumeroDeSocio(1234);


    archivoDeportistaSalida.write(reinterpret_cast<const char*>(&deportistaBlanco),sizeof (Deportista));
    archivoDeportistaSalida.close();

    ifstream archivoDeportistaEntrada("deportista.txt",ios::binary);
    if(!archivoDeportistaEntrada){
        cerr<<"No Se Pudo Abrir El Archivo"<<endl;
        exit(1);
    }

    Deportista deportistaRead;

    archivoDeportistaEntrada.read(reinterpret_cast<char*>(&deportistaRead),sizeof (Deportista));

    cout<<"Nombre: "<<deportistaRead.obtenerNombre()<<endl<<"Edad: "<<deportistaRead.obtenerEdad()
        <<"Deporte: "<<deportistaRead.obtenerDeporte()<<endl<<"Socio: "<<deportistaRead.obtenerNumeroDeSocio()<<endl;


    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "deportista.h"
//#include "deportista.cpp"

using namespace std;

int main()
{
    int numeroDeSocio;
    char nombre[15];
    int edad;
    char deporte[15];

    Deportista d;//Se crea un objeto de la clase Deportista.
    ofstream archDeportSalida; //crea el archivo logico
    archDeportSalida.open("deportista.dat",ios::binary);//abri la conexión con el archivo fisico
    if(!archDeportSalida){//Verifica que si se abrio el la conexión
        cerr<<"No se pudo abrir el archivo."<<endl;
        archDeportSalida.close();
        exit(1);
    }//if

    cout<<"Escirba el numero de socio(De 1 a 100, 0 para terminar la entrada)\n? ";
    cin>>numeroDeSocio;
    d.establecerNumeroDeSocio(numeroDeSocio);
    //El usuario proporciona la informacion que se guardaen el archivo
    while(d.obtenerNumeroDeSocio() >= 1 && d.obtenerNumeroDeSocio() <= 100){
        cout<<"Teclea nombre, edad y deporte\n? ";
        cin>>setw(15)>>nombre;
        cin>>setw(15)>>edad;
        cin>>setw(15)>>deporte;

        //Asigna los valores de nombre, edad y deporte del registro
        d.establecerNombre(nombre);
        d.establecerEdad(edad);
        d.establecerDeporte(deporte);

        //Buscar la posición del registro especificado por el usuario
        //int num = sizeof(Deportista);
        //int cursor = (d.obtenerNumeroDeSocio() - 1) * num;
        archDeportSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof (Deportista));

        //Escribir la información especificada por el usuario en el archivo.
        archDeportSalida.write(reinterpret_cast<const char*>(&d),sizeof (Deportista));

        //Permitir que el usuario especifique otro numero de socio.
        cout<<"Escriba el numero de socio(De 1 a 100, 0 para terminar la entrada\n? ";
        cin>>numeroDeSocio;
        d.establecerNumeroDeSocio(numeroDeSocio);
    }//while
    archDeportSalida.close();
    return 0;
}//main

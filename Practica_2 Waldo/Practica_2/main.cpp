#include <iostream>
#include <fstream>
#include "deportista.h"

using namespace std;

int main()
{
    ofstream deportistaSalida;
    deportistaSalida.open("deportista.txt",ios::binary);

    if(!deportistaSalida)
    {
        cerr<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }//if(verificación de que se creo el archivo fisico)

    Deportista deportistaBlanco;
    for (int i = 0;i < 100;++i)//Escribir 100 registros en blanco
        deportistaSalida.write(reinterpret_cast<const char*>(&deportistaBlanco),sizeof (Deportista));

    deportistaSalida.close();
    return 0;
}//main

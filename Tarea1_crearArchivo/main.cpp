/*
    Olivares Matos Cliserio Jose
    Ruiz Ortiz Valentin Alejandro
    Silvia Ruiz Digo Adam
    Waldo Salazar Alejandro

*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    char nombre[30];
    int edad;
    char deporte[20];


    ofstream archivoDeportistaSalida; //archivo logico
    archivoDeportistaSalida.open("Deportista.txt",ios::out);

    //archivoDeportistaSalida<<nombre<<' '<<edad<<' '<<deporte<<endl; //Sobre cargado del operado <<

    //Salir del programa si no se puede crear el archivo
    if (!archivoDeportistaSalida) {//operador ! sobrecargado
        cerr<<"No se puedo abrir el archivo"<<endl;
        exit(1);
    }

    cout<<"Escriba el nombre, la edad y el deporte."<<endl
       <<"Escriba fin de archivo para terminar la entrada \n?";
    //cin.ignore();
    //Leer nombre,edad,deporte de cin, despúes colocarlo en el archivo
    while (cin>>nombre>>edad>>deporte) {
        archivoDeportistaSalida<<nombre<<' '<<edad<<' '<<deporte<<endl; //Sobrecargado del operator <<
        cout<<"? ";
    }//while

    archivoDeportistaSalida.close();
    return 0;
}

/*
Ejerciosio N°10

 López Martínez Ballardo Axel
 Ruiz Ortiz Valentin Alejandro
 Silva Ruiz Diego Adan
 Perez Meza Eduardo
 Waldo Salazar Alejandro

*/
#include <iostream>
#include <iomanip>
#include "lsl.h"
#include "alumno.h"

using namespace std;

static LSL<Alumno>alumno;

void alta();
void mostrar();
void intercalar();
void head();
void vaciar(size_t band, LSL<Alumno> &list);

enum opc{
    opc_alta=1,
    opc_consulta,
    opc_intercalar,
    opc_salir
};

int main()
{
    string opc;
    while(true){
        system("cls");
        cout<<"[*MENU - INTERCALACION DE ALUMNOS*]"<<endl
           <<opc_alta<<") Alta de Alumno"<<endl
          <<opc_consulta<<") Consulta General"<<endl
         <<opc_intercalar<<") Intercalar"<<endl
        <<opc_salir<<") Salir"<<endl
        <<">> ";
        getline(cin,opc);
        if(opc=="1"){
            alta();
        }else if(opc=="2"){
            if(not alumno.empty()){
                mostrar();
            }else{
                cout<<"No hay elementos en la lista"<<endl;
            }
        }else if(opc=="3"){
            if(not alumno.empty()){
                intercalar();
            }else{
                cout<<"No hay elementos en la lista"<<endl;
            }
        }else if(opc=="4"){
            break;
        }
        system("pause");
    }
    return 0;
}

void alta()
{
    system("cls");
    Alumno al;
    string linea;
    int numero;
    cout<<"[*AGREGAR ALUMNO*]"<<endl
       <<"Nombre: "; getline(cin,linea);
    al.setNombre(linea);
    for(auto& it : linea) it = toupper(it);
    cout<<"Edad: "; cin>>numero;
    al.setEdad(numero);
    cin.ignore();
    cout<<"Sexo: "; getline(cin,linea);
    for(auto& it : linea) it = toupper(it);
    al.setSexo(linea);

    alumno.push_back(al);
}

void mostrar()
{
    system("cls");
    head();
    for (size_t i = 0; i < alumno.size(); ++i) {
        cout<<alumno[i];
    }
}

void intercalar()
{
    system("cls");
    LSL<Alumno>mujer,hombre,intercalada;
    string aux;
    size_t band = 0,k = 0,j = 0,cont=0;
    for (size_t i = 0; i < alumno.size(); ++i) {
        aux = alumno[i].getSexo();
        if(aux == "M"){
            hombre.push_back(alumno[i]);
        }else if(aux == "F"){
            mujer.push_back(alumno[i]);
        }
    }

    if(mujer.empty()){
        head();
        vaciar(hombre.size(),hombre);
    }
    if(hombre.empty()){
        head();
        vaciar(mujer.size(),mujer);
    }
    if(!hombre.empty()&&!mujer.empty()){
        band = 1;
        head();
    }
    for (size_t i = 0; i < alumno.size(); ++i) {
        if(band == 1){
            intercalada.push_back(hombre[k]);
            k++;
            if(j != mujer.size())
                band = 2;
        }else if(band == 2){
            intercalada.push_back(mujer[j]);
            j++;
            if(k != hombre.size())
                band = 1;
        }
        cont++;
    }
    if(cont == intercalada.size())
        vaciar(intercalada.size(),intercalada);

}

void vaciar(size_t band,LSL<Alumno>& list)
{
    for (size_t i = 0; i < band; ++i) {
        cout<<list[i];
    }
}

void head()
{
    cout<<left<<setw(10)<<"NOMBRE"<<setw(10)<<"EDAD"<<setw(10)<<"SEXO"<<endl;
}

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

static LSL<Alumno>lista_aumno;

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
        cout<<"[*MENU - LISTA SIMPLEMNTE LIGADA*]"<<endl
           <<opc_alta<<") Alta de Alumno"<<endl
          <<opc_consulta<<") Consulta General"<<endl
         <<opc_intercalar<<") Intercalar"<<endl
        <<opc_salir<<") Salir"<<endl
        <<">> ";
        getline(cin,opc);
        if(opc=="1"){
            alta();
        }else if(opc=="2"){
            if(not lista_aumno.empty()){
                mostrar();
            }else{
                cout<<"No hay elementos en la lista"<<endl;
            }
        }else if(opc=="3"){
            if(not lista_aumno.empty()){
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

    lista_aumno.push_back(al);
}

void mostrar()
{
    system("cls");
    head();
    for (size_t i = 0; i < lista_aumno.size(); ++i) {
        cout<<lista_aumno[i];
    }
}

void intercalar()
{
    system("cls");
    LSL<Alumno>lista_mujer,lista_hombre,lista_intercalado;
    string aux;
    size_t band = 0,k = 0,j = 0,cont=0;
    for (size_t i = 0; i < lista_aumno.size(); ++i) {
        aux = lista_aumno[i].getSexo();
        if(aux == "M"){
            lista_hombre.push_back(lista_aumno[i]);
        }else if(aux == "F"){
            lista_mujer.push_back(lista_aumno[i]);
        }
    }

    if(lista_mujer.empty()){
        head();
        vaciar(lista_hombre.size(),lista_hombre);
    }
    if(lista_hombre.empty()){
        head();
        vaciar(lista_mujer.size(),lista_mujer);
    }
    if(!lista_hombre.empty()&&!lista_mujer.empty()){
        band = 1;
        head();
    }
    for (size_t i = 0; i < lista_aumno.size(); ++i) {
        if(band == 1){
            lista_intercalado.push_back(lista_hombre[k]);
            k++;
            if(j != lista_mujer.size())
                band = 2;
        }else if(band == 2){
            lista_intercalado.push_back(lista_mujer[j]);
            j++;
            if(k != lista_hombre.size())
                band = 1;
        }
        cont++;
    }
    if(cont == lista_intercalado.size()){
        for(size_t i = 0; i < lista_intercalado.size(); i++)
        lista_aumno[i]=lista_intercalado[i];
        vaciar(lista_aumno.size(),lista_aumno);
    }

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

#include<iostream>
#include <fstream>
#include<string.h>
#include<stdio.h>
#include<ctime>

using namespace std;

int cantidadDatos();
void writeNum();
void dividir();
void mostrarOriginal();
void mostrarAux1();
void mostrarAux2();
int obtenerCantElemAux1();
int obtenerCantElemAux2();
void mezla();


int  cantidadDatos(){
    int NUMDATOS=0;
    char espace;
    int dato=0;
    ifstream original("original.txt",ios::in);
    while (!original.eof()) {
        original.read(reinterpret_cast<char*>(&dato),sizeof (int));
        if(original.eof())
            break;
        NUMDATOS++;
    }
    original.close();
    return NUMDATOS;
}

void writeNum(){

    ofstream original("original.txt",ios::out);
    srand(time(NULL));
    int num=14;
    int dato=0;
    string space=" ";

    while(num){
        dato=(rand()%100)+1;
        original.write(reinterpret_cast<char*>(&dato),sizeof(int));
        num--;
    }
    original.close();
}

void dividir(){

    int cantidad=cantidadDatos();
    ifstream original("original.txt",ios::in);
    ofstream file1Aux("aux1.txt",ios::out);
    ofstream file2Aux("aux2.txt",ios::out);

    int num1;
    original.read(reinterpret_cast<char*>(&num1),sizeof (int));
    cantidad--;

    string space=" ";
    char coma=',';
    int num2;
    while(cantidad){

        original.read(reinterpret_cast<char*>(&num2),sizeof (int));
        cantidad--;
        if(num1<=num2){
            file1Aux.write(reinterpret_cast<char*>(&num1),sizeof(int));
            file1Aux.write(reinterpret_cast<char*>(&space),sizeof (char));
            num1=num2;
        }else{
            file1Aux.write(reinterpret_cast<char*>(&num1),sizeof (int));
            file1Aux.write(reinterpret_cast<char*>(&coma),sizeof (char));

            file2Aux.write(reinterpret_cast<char*>(&num2),sizeof (int));
            file2Aux.write(reinterpret_cast<char*>(&coma),sizeof (char));

            if(cantidad){
                original.read(reinterpret_cast<char*>(&num1),sizeof (int));
                cantidad--;
            }
        }

    }

    original.close();
    file1Aux.close();
    file2Aux.close();

    if(obtenerCantElemAux1()+obtenerCantElemAux2()<cantidadDatos()){
        ofstream file1Aux("aux1.txt",ios::app);
        file1Aux.write(reinterpret_cast<char*>(&num1),sizeof (int));
        file1Aux.write(reinterpret_cast<char*>(&coma),sizeof(char));
        file1Aux.close();

    }
}


void mostrarOriginal(){

    int dato;

    ifstream original("original.txt",ios::in);
    if(!original.good()){
        cout<<"Error Al Abrir Archivo"<<endl;
        return;
    }
    while(!original.eof()){
        original.read(reinterpret_cast<char*>(&dato),sizeof (int));
        if(original.eof())
            break;
        cout<<" "<<dato;
    }
    original.close();
}


void mostrarAux1(){

    int dato;
    char space;
    ifstream fileAux1("aux1.txt",ios::in);
    if(!fileAux1.good()){
        cout<<"Error Al Abrir Archivo"<<endl;
        return;
    }
    while(!fileAux1.eof()){
        fileAux1.read(reinterpret_cast<char*>(&dato),sizeof (int));
        fileAux1.read(reinterpret_cast<char*>(&space),sizeof (char));
        if(fileAux1.eof())
            break;
        cout<<" "<<dato;
    }
    fileAux1.close();
}



void mostrarAux2(){

    int dato;
    char space;

    ifstream fileAux2("aux2.txt",ios::in);
    if(!fileAux2.good()){
        cout<<"Error Al Abrir Archivo"<<endl;
        return;
    }
    while(!fileAux2.eof()){
        fileAux2.read(reinterpret_cast<char*>(&dato),sizeof (int));
        fileAux2.read(reinterpret_cast<char*>(&space),sizeof(char));
        if(fileAux2.eof())
            break;
        cout<<" "<<dato;
    }
    fileAux2.close();
}

int obtenerCantElemAux1(){

    int cant=0;
    int dato=0;
    char coma=' ';

    ifstream fileAux1("aux1.txt",ios::in);
    if(!fileAux1.good()){
        cout<<"Error Al Abrir Archivo"<<endl;
        return -1;
    }

    while(!fileAux1.eof()){
        fileAux1.read(reinterpret_cast<char*>(&dato),sizeof (int));
        fileAux1.read(reinterpret_cast<char*>(&coma),sizeof(char));

        if(fileAux1.eof())
            break;
        cant++;

    }

    fileAux1.close();
    return cant;
}

int obtenerCantElemAux2(){
    int cant=0;
    int dato=0;
    char coma=' ';

    ifstream fileAux2("aux2.txt",ios::in);
    if(!fileAux2.good()){
        cout<<"Error Al Abrir Archivo"<<endl;
        return -1;
    }

    while(!fileAux2.eof()){
        fileAux2.read(reinterpret_cast<char*>(&dato),sizeof (int));
        fileAux2.read(reinterpret_cast<char*>(&coma),sizeof(char));

        if(fileAux2.eof())
            break;
        cant++;

    }

    fileAux2.close();
    return cant;
}

void mezla(){
    ofstream original("original.txt",ios::out);
    ifstream aux1("aux1.txt",ios::in);
    ifstream aux2("aux2.txt",ios::in);


    if(!aux1.good()&&!aux2.good()){
        cout<<"Error Al Abrir el archivo"<<endl;
        original.close();
        return;
    }

    int datoA2=0;
    char comaA2=' ';

    int datoA1=0;
    char comaA1=' ';


    while(!aux2.eof()){
        aux2.read(reinterpret_cast<char*>(&datoA2),sizeof (int));
        aux2.read(reinterpret_cast<char*>(&comaA2),sizeof (char));

        if(aux2.eof())
            break;


        if(comaA2==','){

            while (!aux1.eof()) {
                aux1.read(reinterpret_cast<char*>(&datoA1),sizeof (int));
                aux1.read(reinterpret_cast<char*>(&comaA1),sizeof (char));

                if(aux1.eof()){
                    break;
                }
                if(datoA2<=datoA1){
                    original.write(reinterpret_cast<char*>(&datoA2),sizeof (int));
                    datoA2=datoA1;
                }else{
                    original.write(reinterpret_cast<char*>(&datoA1),sizeof (int));
                }

                if(comaA1==','){
                    original.write(reinterpret_cast<char*>(&datoA1),sizeof (int));
                    break;
                }
            }
        }
    }

    if(!aux1.eof()){
        while(!aux1.eof()){
            aux1.read(reinterpret_cast<char*>(&datoA1),sizeof (int));
            aux1.read(reinterpret_cast<char*>(&comaA1),sizeof (char));

            if(aux1.eof())
                break;

            original.write(reinterpret_cast<char*>(&datoA1),sizeof (int));
        }
    }
    original.close();
    aux1.close();
    aux2.close();

    ofstream auxO2("aux2.txt",ios::trunc);
    auxO2.close();
}


int main()
{
  writeNum();
  cout<<"Algoritmo Mezcla directa"<<endl;
  cout<<"Cantidad De DATOS: "<<cantidadDatos()<<endl;

  cout<<"Datos Original: "<<endl;
  mostrarOriginal();
  cout<<endl;


  dividir();

  do{
      mezla();
      dividir();
  }while(obtenerCantElemAux2());

  cout<<"Datos Originales"<<endl;
  mostrarOriginal();
  cout<<endl;

  cout<<"**************"<<endl;
  cout<<"Se Mezclaron correctamente:"<<endl;
}

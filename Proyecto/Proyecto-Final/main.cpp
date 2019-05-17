/***
    Equipo 5:
        Ruiz Ortiz Valentin Alejandro
****/

#include <iostream>
#include <fstream>
#include<string.h>
#include<stdio.h>
#include<ctime>

using namespace std;
typedef const string nomArch;

nomArch fichero = "origen.txt";
nomArch fileAux1 = "auxiliar1.txt";
nomArch fileAux2 = "auxiliar2.txt";

/*Mezcla Directa*/
void mezclar(nomArch nf1, nomArch nf2, nomArch nf, int& lonSec, int numReg,bool);
int cuentaReg(nomArch nf);
void subSecuencia(ifstream &f, ofstream &t, int longSec);
void mezclaDirecta(nomArch f,bool desc);
void distribuir(nomArch nf, nomArch nf1, nomArch nf2, int lonSec, int numReg);


/*Mezcla Natural*/
int cantidadDatos();
void writeNum();
void dividir();
void mostrarOriginal();
void mostrarAux1();
void mostrarAux2();
int obtenerCantElemAux1();
int obtenerCantElemAux2();
void mezla();

    // función que controla el algoritmo de ordenació3  azn
void mezclaDirecta(nomArch f,bool desc)
{
    int longSec;
    int numReg;
    nomArch f1 = "auxiliar1.txt";
    nomArch f2 = "auxiliar2.txt";

    numReg = cuentaReg(f); // determina número de registros
    longSec = 1;

    while (longSec < numReg)
    {
        distribuir(f, f1, f2, longSec, numReg);
        mezclar(f1, f2, f, longSec, numReg,desc);
    }
}
    // función que separa secuencias ordenadas de registros
void distribuir(nomArch nf, nomArch nf1, nomArch nf2, int lonSec, int numReg)
{
    int numSec, resto, i;

    numSec = numReg /(2*lonSec);
    resto = numReg %(2*lonSec);

    ifstream f(nf);
    ofstream f1(nf1);
    ofstream f2(nf2);

    if (f.bad()||f1.bad()||f2.bad())
        throw " Error en el proceso de separación ";
    for (i = 1; i <= numSec; i++)
    {
        subSecuencia(f, f1, lonSec);
        subSecuencia(f, f2, lonSec);
    }
    /*
    Se procesa el resto de registros del archivo
    */
    if (resto > lonSec)
        resto -= lonSec;
    else
    {
        lonSec = resto;
        resto = 0;
    }

    subSecuencia(f, f1, lonSec);
    subSecuencia(f, f2, resto);

    f1.close(); f2.close(); f.close();
}
    // lee de f una secuencia y la escribe en t
void subSecuencia(ifstream &f, ofstream &t, int longSec)
{
    for (int j = 1; j <= longSec; j++)
    {
        int reg;
        f >> reg; // lee (extrae) del archivo asociado a f
        t << reg <<" "; // escribe en archivo asociato a t
    }
 }
    // mezcla pares de secuencias ordenadas
void mezclar(nomArch nf1, nomArch nf2, nomArch nf, int& lonSec, int numReg,bool desc)
{
    int numSec, resto, i, j, k;
    int reg1, reg2;

    numSec = numReg /(2 * lonSec); // número de subsecuencias
    resto = numReg %(2 * lonSec);

    ofstream f(nf);
    ifstream f1(nf1);
    ifstream f2(nf2);

    f1 >> reg1;
    f2 >> reg2;

    for (int s = 1; s <= numSec + 1; s++)
    {
        int n1, n2;
        n1 = n2 = lonSec;
        if (s == numSec+1)
        { // proceso de los registros de la subsecuencia incompleta
            if (resto > lonSec)
                n2 = resto - lonSec;
            else
            {
                n1 = resto;
                n2 = 0;
            }
        }
        i = j = 1;
        while (i <= n1 && j <= n2)
        {
            int actual;
            // descendentemente < ascendentemente >
            if(!desc){
                if (reg1 < reg2)
                {
                    actual = reg1;
                    f1 >> reg1;
                    i++;
                }
                else
                {
                    actual = reg2;
                    f2 >> reg2;
                    j++;
                }
                f << actual <<" ";
            }else{
                if (reg1 > reg2)
                {
                    actual = reg1;
                    f1 >> reg1;
                    i++;
                }
                else
                {
                    actual = reg2;
                    f2 >> reg2;
                    j++;
                }
                f << actual <<" ";
            }

        }
        /*
        Los registros no procesados se escriben directamente
        */
        for (k = i; k <= n1; k++)
        {
            f << reg1 <<" ";
            f1 >> reg1;
        }

        for (k = j; k <= n2; k++)
        {
            f << reg2 <<" ";
            f2 >> reg2;
        }
    }
    lonSec *= 2;
    f.close(); f1.close();f2.close();
}

// función para determinar el número de registros
int cuentaReg(nomArch nf)
{
    int k = 0;
    int registro;
    ifstream f(nf);
    while (!f.eof())
    {
        f >> registro;
        k++;
    }
    f.close();
    return k;
}

/*Cuenta La Cantidad De Datos Originales*/
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

/*Escribe Numero Aleatorios*/
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

/*Divide Los Numeros del archivo original y los agrega en dos archivos AUXLIARES*/
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


/*Divide Los Numeros del archivo original y los agrega en dos archivos AUXLIARES*/
void dividirDesc(){

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
        if(num1>=num2){
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



/*muestra los datos de archivo original*/
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

/*Mustra Los Datos del archivo auxiliar1*/
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


/*Muestra Los Datos Del Archivo Auxiliar2*/
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

/*Obtiene La Cantidad De Elementos De Auxiliar1*/
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
/*Obtiene La Cantidad De Elementos De Auxiliar2*/
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
/*Mezcla Los Dos Archivos Que Se Encuentran*/
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

/*Mezcla Los Dos Archivos Que Se Encuentran*/
void mezlaDes(){
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
                if(datoA2>=datoA1){
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
    int opc;

    do{
        remove("auxiliar1.txt");
        remove("auxiliar2.txt");

        system("cls");
        cout<<"Menu Ordenamiento Con Archivos"<<endl<<endl;

        cout<<"1- Ascendente(Mezla Directa)"<<endl;
        cout<<"2- Descendente(Mezla Directa)"<<endl;
        cout<<"3- Ascendente(Mezla Natural)"<<endl;
        cout<<"4- Descendente(Mezcla Natural)"<<endl;
        cout<<"5- Salir"<<endl;
        cin>>opc;
        switch (opc) {
            case 1:
                mezclaDirecta(fichero,false);
                cout<<"Se Mezclaron correctamente:"<<endl;
            break;
            case 2:
                mezclaDirecta(fichero,true);
                cout<<"Se Mezclaron Correctamente"<<endl;
            break;
            case 3:
                writeNum();

                cout<<"Datos Original: "<<endl;
                mostrarOriginal();
                cout<<endl;

                dividir();

                do{
                    mezla();
                    dividir();
                }while(obtenerCantElemAux2());

                cout<<"Datos Ordenados Ascendente"<<endl;
                mostrarOriginal();
                cout<<endl;
            break;

            case 4:
                writeNum();

                cout<<"Datos Original: "<<endl;
                mostrarOriginal();
                cout<<endl;

                dividirDesc();

                do{
                    mezlaDes();
                    dividirDesc();
                }while(obtenerCantElemAux2());

                cout<<"Datos Ordenados Descendente"<<endl;
                mostrarOriginal();
                cout<<endl;
            break;

            case 5:
            break;

            default:
            cout<<"Opcion Incorrecta"<<endl;
        }
        cout<<endl;
        system("pause");
    }while(opc!=5);

}

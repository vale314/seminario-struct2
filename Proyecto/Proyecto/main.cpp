#include <iostream>
#include <fstream>
using namespace std;

typedef const char nomArch;
nomArch* fichero = "origen.txt";
nomArch* fileAux1 = "auxiliar1.txt";
nomArch* fileAux2 = "auxiliar.txt";


void distribuir(nomArch* nf, nomArch* nf1, nomArch* nf2, int lonSec, int
numReg);

void mezclaDirecta(nomArch *f);
void subSecuencia(ifstream &f, ofstream &t, int longSec);
void mezclar(nomArch *nf1, nomArch *nf2, nomArch *nf, int& lonSec, int numReg);
int cuentaReg(nomArch* nf);


 // función que controla el algoritmo de ordenación
void mezclaDirecta(nomArch *f)
{

    int longSec;
    int numReg;
    nomArch *f1= "auxiliar1.txt";
    nomArch *f2= "auxiliar2.txt";

    numReg = cuentaReg(f); // determina número de registros
    longSec = 1;

    cout<<numReg<<endl;
    while (longSec < numReg)
    {
       distribuir(f, f1, f2, longSec, numReg);
       mezclar(f1, f2, f, longSec, numReg);
    }
}

void distribuir(nomArch* nf, nomArch* nf1, nomArch* nf2, int lonSec, int numReg)
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
void mezclar(nomArch *nf1, nomArch *nf2, nomArch *nf, int& lonSec, int numReg)
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
int cuentaReg(nomArch* nf)
{
    int k = 0;
    int registro;

    ifstream f(nf);

    while (!f.eof())
    {
        f >> registro;
        if(f.eof())
            break;
        k++;
    }
    f.close();
    return k;
}

int main(){

    mezclaDirecta("origen.txt");
}

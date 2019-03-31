#include "empresa.h"

Empresa::Empresa()
{
    dia=0;
}

void Empresa::menu()
{
    int opc;
    do{
        system("cls");
        cout<<"Dia Actual: "<<diasNombre[dia]<<endl;
        cout<<menuAlta<<" Alta"<<endl
            <<menuMostrar<<" Mostrar Todos"<<endl
            <<menuMostrarDias<< " Mostar Por Dia"<<endl
            <<menuCambiarDia<<" Cambiar Dia"<<endl
            <<menuMostraDia<<" Mostrar Dia Actual"<<endl
            <<menuSalir<<" Salir"<<endl;
        cout<<"Ingrese el numero de la opcion"<<endl;
        cin>>opc;
        switch (opc) {
            case menuAlta:
               alta();
            break;
            case menuMostrar:
                mostrar();
            break;
            case menuMostrarDias:
                mostrarDias();
            break;
            case menuMostraDia:
                mostrarDiaActual();
            break;
            case menuCambiarDia:
                cambiarDia();
            break;
            case menuSalir:
            break;
        }
    }while(opc!=menuSalir);
}

void Empresa::alta()
{
   string nombre;
   bool dias[7];
   int nss;
   Empleado empAux;

   cin.ignore();
   cout<<"Ingrese el Nombre"<<endl;
   getline(cin,nombre);

   cout<<"Numero de seguro Social"<<endl;
   cin>>nss;

   system("cls");
   cout<<"1-Trabaja \t0-No"<<endl<<endl;
   for(int i=0; i<7;i++){
    cout<<"dia "<<" "<<diasNombre[i]<<endl;
    cin>>dias[i];
   }
    empAux.setNombre(nombre);
    empAux.setNss(nss);

    int total=0;
    for(int i=0; i<7;i++)
     if(dias[i])
         total++;

   empAux.setTotal(total);

   InsertarOrdenado(empAux);
   asignar(empAux,dias);
}


void Empresa::asignar(Empleado emp,bool dias[7])
{
    for(int i=0;i<7;i++){
        if(dias[i])
            diasCola[i].push(emp);
    }
}

void Empresa::mostrar()
{
    system("cls");
    for(size_t i=0;i<trabajadores.size();i++)
        cout<<trabajadores[i]<<endl;
    cout<<endl<<endl;
    system("pause");
}

void Empresa::mostrarDias()
{
    int opc;

    cout<<"Ingrese El Dia A Ver"<<endl;
    for(int i=0;i<7;i++)
        cout<<diasNombre[i]<<" "<<i<<" ";
    cout<<'\n';

    cin>>opc;

    if(opc>7||opc<0){
        cout<<"Incorrecto "<<endl;
        return;
    }

    mostrarDia(opc);
}

void Empresa::mostrarDia(int opc)
{
    Cola<Empleado> colaAux(diasCola[opc]);
    Empleado empAux;
    while(!colaAux.empty()){
        empAux=colaAux.front();
        cout<<empAux<<endl;
        colaAux.pop();
    }
    system("pause");
}

void Empresa::mostrarDiaActual()
{
    mostrarDia(dia);
}

void Empresa::cambiarDia()
{
    int opc;

    cout<<"Ingrese El Dia A Ver"<<endl;
    for(int i=0;i<7;i++)
        cout<<diasNombre[i]<<" "<<i<<" ";
    cout<<'\n';

    cin>>opc;

    if(opc>7||opc<0){
        cout<<"Incorrecto "<<endl;
        return;
    }

    dia=opc;
}

void Empresa::InsertarOrdenado(Empleado empAux)
{
    if(trabajadores.empty()){
        trabajadores.push_back(empAux);
        return;
    }
    for(size_t i=0;i<trabajadores.size();i++){
        if(empAux.getNss()<trabajadores[i].getNss()){
            trabajadores.insert(i,empAux);
            return;
        }
    }
    trabajadores.push_back(empAux);
}


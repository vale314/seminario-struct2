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
    guardar();
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

   bool band=false;
   do{
       if(!band)
        cout<<"Numero de seguro Social"<<endl;
       else
           cout<<"Repetido Numero Seguro"<<endl<<"Ingrese nuevo Seguro Social"<<endl;
        cin>>nss;
        band=true;
   }while(buscarId(nss));

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

bool Empresa::buscarId(int id)
{
    for(size_t i=0;i<trabajadores.size();i++){
        if(trabajadores[i].getNss()==id)
            return true;
    }
    return false;
}

void Empresa::guardar()
{
    Empleado empAux;
    empAux.setNombre("###");
    empAux.setNss(000);
    empAux.setTotal(0);

    fstream salidaT("trabajadores.txt",ios::out);
    if(!salidaT.good()){
        cout<<"Error Al Crear El Archivo"<<endl;
        return;
    }
    for(size_t i=0;i<trabajadores.size();i++){
        salidaT.write(reinterpret_cast<char *>(&trabajadores[i]),sizeof(Empleado));
    }
    salidaT.close();

    fstream salidaD("dias.txt",ios::out);
    if(!salidaD.good()){
        cout<<"Error Al Crear Al Archivo"<<endl;
        return;
    }
    for(int i=0;i<7;i++){
        while(!diasCola[i].empty()){
            salidaD.write(reinterpret_cast<const char*>(&diasCola[i].back()),sizeof (Empleado));
            diasCola[i].back();
            diasCola[i].popBack();
        }
        salidaD.write(reinterpret_cast<char*>(&empAux),sizeof (Empleado));
    }
    salidaD.close();
}


#include <iostream>
#include "usuarios.h"
#include "FileUsage.h"
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
Usuarios s[100];
int main()
{
    char answer;
    bool sesion=1;
    int opcion;
    int password;
    do{
    cout<<"Como desea ingresar: \n1. Administrador\n2.Usuario"<<endl;
    cin>>answer;
    }
    while (answer!='1' && answer !='0');
    if (answer=='1'){
       cout<<"Sesion de administrador, ingrese la contraseña sudo: "<<endl;
       cin>>password;
       if (password==ReadSudo()){
       while (sesion){
           do{
           cout<<"Ingrese una opcion:\n1.Registrar usuarios\n2.Ver lista de usuarios\n3.Salir de Sesion"<<endl;
           cin>>opcion;
           }
           while (opcion!=1 && opcion !=2 && opcion!=3);
           if (opcion==1){
               int n;
               cout<<"Ingrese numero de usuarios a registrar: "<<endl;
               cin>>n;
               for (int i=0;i<n;i++)
                   s[i].ReadUsuarios();
              }
           else if (opcion==2){
               for (int i=0;s[i].getCedula()!=0;i++)
                   s[i].MostrarRegistro();
           }
           else if (opcion==3){
               sesion=false;
               cout<<"Saliendo de sesion"<<endl;
           }
       }
    }
    else
           cout<<"Contraseña no correcta, inicie de nuevo."<<endl;
    }
    writeRegister();
   return 0;
}

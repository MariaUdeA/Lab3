#include <iostream>
#include "usuarios.h"
#include "FileUsage.h"
using std::cout;
using std::cin;
using std::endl;
Usuarios s[100];
int main()
{
    readRegister();
    int answer;
    bool sesion=1;
    int opcion;
    int password;
    int intentos=1;
    do{
    cout<<"Como desea ingresar: \n1. Administrador\n2.Usuario"<<endl;
    cin>>answer;
    }
    while (answer !=1 && answer !=2);
    if (answer==1){
       int c=countUsers();
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
               for (int i=0;i<n;i++){
                   s[c].ReadUsuarios();
                   c++;
               }
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
    else if (answer==2){
        int ced;
        int clav;
        int usuario;
        cout<<"Ingrese su cedula:"<<endl;
        do
        cin>>ced;
        while(!CheckCedRepetida(ced));
        usuario=Cedplace(ced);
        cout<<"Ingrese su clave:"<<endl;
        cin>>clav;
        while(clav!=s[usuario].getClave() && intentos<3){
            cin>>clav;
            intentos++;
        }
        if (intentos==3 && clav!=s[usuario].getClave()){
            cout<<"Entrada bloqueada"<<endl;
            return 0;}
        while (sesion){
            do{
            cout<<"Elija una opcion:\n1.Consultar Saldo\n2.Retirar dinero\n3.Salir de sesion"<<endl;
            cin>>opcion;
            }
            while (opcion!=1 && opcion !=2 && opcion!=3);
            if (opcion==1){
                s[usuario].CheckSaldo();
            }
            else if (opcion==2){
                s[usuario].GetMoney();
            }
            else if (opcion==3){
                sesion=false;
                cout<<"Saliendo de sesion"<<endl;
            }
        }
    }
    writeRegister();
    return 0;
}

#include "usuarios.h"
#include <iostream>

/*Usuarios::Usuarios()
{

}*/
void Usuarios::SetUsuarios(int ced,int clave,int saldo){
    Cedula=ced;
    Clave=clave;
    Saldo=saldo;
}
int Usuarios::getClave(){
    return Clave;
}
int Usuarios::getCedula(){
    return Cedula;
}
int Usuarios::getSaldo(){
    return Saldo;
}
void Usuarios::ReadUsuarios(){
    Cedula=1;
    Clave=1;
    Saldo=1;
    std::cout<<"Ingrese la cedula de 10 digitos: "<<std::endl; //que sea mayor a cero, no incluyente
    do{
        std::cin>>Cedula;}
    while(Cedula<=0);
    std::cout<<"Ingrese la clave de 4 digitos: "<<std::endl;
    do{
        std::cin>>Clave;}
    while(Clave<0);
    std::cout<<"Ingrese el saldo: "<<std::endl;
    do{
        std::cin>>Saldo;}
    while(Saldo<0);
}
void Usuarios::CheckSaldo(){
    std::cout<<"El saldo del usuario es: $"<<Saldo<<std::endl;
    Saldo=Saldo-1000;
}
void Usuarios::GetMoney(){
    int money;
    std::cout<<"Ingrese la cantidad a retirar: ";
    std::cin>>money;
    while (money>Saldo){
        std::cout<<"La cantidad que ingreso excede su saldo, ingrese la cantidad a retirar: ";
        std::cin>>money;
    }
    Saldo=Saldo-money-1000;
}
void Usuarios::MostrarRegistro(){
    std::cout<<"Cedula: "<<Cedula<<", Clave: "<<Clave<<", Saldo: $"<<Saldo<<std::endl;
}

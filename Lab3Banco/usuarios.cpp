#include <usuarios.h>
#include <iostream>

/*Usuarios::Usuarios()
{

}*/
void Usuarios::SetUsuarios(int ced,int clave,int saldo){
    Cedula=ced;
    Clave=clave;
    Saldo=saldo;
}
void Usuarios::ReadUsuarios(){
    std::cout<<"Ingrese la cedula: "<<std::endl;
    std::cin>>Cedula;
    std::cout<<"Ingrese la clave: "<<std::endl;
    std::cin>>Clave;
    std::cout<<"Ingrese el saldo: "<<std::endl;
    std::cin>>Saldo;
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

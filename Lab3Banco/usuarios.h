#ifndef USUARIOS_H
#define USUARIOS_H


class Usuarios
{
private:
    int Cedula;
    int Clave;
    int Saldo;
public:
    //Usuarios();
    void SetUsuarios(int ced,int clave,int saldo);
    void ReadUsuarios();
    void CheckSaldo();
    void GetMoney();
    void MostrarRegistro();
};

#endif // USUARIOS_H

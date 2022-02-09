#ifndef USUARIOS_H
#define USUARIOS_H


class Usuarios
{
private:
    unsigned int Cedula;
    unsigned int Clave;
    unsigned int Saldo;
public:
    //Usuarios();
    void SetUsuarios(int ced,int clave,int saldo);
    void ReadUsuarios();
    void CheckSaldo();
    void GetMoney();
    void MostrarRegistro();
    int getClave();
    int getCedula();
    int getSaldo();
};

#endif // USUARIOS_H

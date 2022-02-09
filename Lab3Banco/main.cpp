#include <iostream>
#include <usuarios.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Usuarios u[100];
    int num;
    cout<<"number usrs: ";
    cin>>num;
    for (int i=0;i<num;i++)
        u[i].ReadUsuarios();
    for (int i=0;i<num;i++)
        u[i].MostrarRegistro();
return 0;
}

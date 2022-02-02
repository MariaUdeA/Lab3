#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int methoduno(int n);
int methoddos(int n);

int main()
{
    int n; //semilla de codificacion
    char method; //metodo de codificacion 1 o 2
    char str=01000001;
    cout<<str<<endl;
    /*cout<<"Ingrese la semilla de codificación: ";
    cin>>n;
    cout<<"\nSeleccione un metodo: ";
    cin>>method;
    (method=='1')? methoduno(n):methoddos(n);
    return 0;*/
}

int methoduno(int n){
    ifstream fin;
    fin.open("archivo.dat");
    return 0;
}

int methoddos(int n){
    return 0;
}

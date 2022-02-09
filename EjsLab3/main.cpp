#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//int methoduno(int n);
//int methoddos(int n);
void charabool();
int sizearray(char* array);
int main()
{
    //charabool();
    return 0;
}
int sizearray(char *array){
    int size=0;
    for (int i=0;*(array+i)!='\0';i++){
        size++;
    }
    return size;
}

void charabool(){
    char* linea="AbCd";
    bool* codificado=NULL;
    codificado=new bool[sizearray(linea)*8];
    bool* placeholder;
    char aid;
    int c=0;
    for (int i=0;*(linea+i)!='\0';i++){
        aid=*(linea+i);
        for (int j=0;aid>0;j++){
               placeholder[j] = ( aid % 2 == 0 ? 0 : 1 );
               cout<<codificado[c];
               aid=aid/2;
               c++;
           }
    }
    for (int i=0;i<(sizearray(linea)*8);i++)
        cout<<codificado[i];
}
/*
char* boolachar(bool* codificado){
    char* descodificado;
    for (int i=0;i<sizeof(codificado)/8;i=i+8){
        for (j=i;j<i+8;j++){

        }
    }
}*/

/*
int methoduno(int n){
    bool line[n];
    bool* total;
    ifstream fin;
    fin.open("archivo.dat");
    fin.getline(total,256);
    return 0;
}

int methoddos(int n){
    return 0;
}*/

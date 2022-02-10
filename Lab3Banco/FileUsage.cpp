#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "FileUsage.h"
#include "usuarios.h"
bool b[8];
extern Usuarios s[100];
int ReadSudo(){ //listo
    char a[32];
    bool line[32];
    int c=0;
    int clave=0;
    std::ifstream fin;
    fin.open("ArchivoSudo.txt");
    fin.getline(a,33);
    for (char i:a){
        line[c]= bool(i-48);
        c++;
    }
    for (int i=0;i<32;i=i+8){
        for (int j=0;j<8;j++)
            b[j]=line[i+j];
        desencriptar();
        clave=clave+BoolaInt()*pow(10,(((32-i)/8)-1));
    }
    fin.close();
    return clave;
    /* descripcion
     leer el archivo--> una linea
     desencriptar linea
     pasar a int
     */
}
void readRegister(){
    std::ifstream fin;
    fin.open("registro.txt");
    /*
    for linea en leyendo
    8*10 de cedula
    cada 8, se desencripta, y se pasa a int
    8*4 de clave
    8*el resto de saldo

    */
    fin.close();
}
void writeRegister(){ //listo
    int placeholder;
    int digit;
    std::ofstream fout;
    fout.open("registro.txt");
    for (int i=0;s[i].getCedula()!=0;i++){
        placeholder=s[i].getCedula(); //Se separa por digitos que se pasan a binario y se encriptan
        digit=floor(log10(placeholder)+1);
        char* palabra=new char[digit];
        int c=0;
        for (int j=digit;j>0;j--){
           *(palabra+c)=(floor(placeholder/(pow(10,j-1))))+48;
            placeholder=placeholder-(palabra[c]-48)*pow(10,j-1);
            c++;
        }
        for (int j=0;j<digit;j++){
            IntaBool(palabra[j]);
            encriptar();
            for (int k=0;k<8;k++){
                fout<<b[k];
            }
        }
        delete[] palabra;
        placeholder=s[i].getClave();
        digit=floor(log10(placeholder)+1);
        palabra=new char[digit];
        c=0;
        for (int j=digit;j>0;j--){
           *(palabra+c)=(floor(placeholder/(pow(10,j-1))))+48;
            placeholder=placeholder-(palabra[c]-48)*pow(10,j-1);
            c++;
        }
        for (int j=0;j<digit;j++){
            IntaBool(palabra[j]);
            encriptar();
            for (int k=0;k<8;k++){
                fout<<b[k];
            }
        }
        delete[] palabra;
        placeholder=s[i].getSaldo();
        digit=floor(log10(placeholder)+1);
        palabra=new char[digit];
        c=0;
        for (int j=digit;j>0;j--){
           *(palabra+c)=(floor(placeholder/(pow(10,j-1))))+48;
            placeholder=placeholder-(palabra[c]-48)*pow(10,j-1);
            c++;
        }
        for (int j=0;j<digit;j++){
            IntaBool(palabra[j]);
            encriptar();
            for (int k=0;k<8;k++){
                fout<<b[k];
            }
        }
        delete[] palabra;
        fout<<'\n';
    }
    /* explicacion
     for (student i:s){
     getCedula
     poner variable
     transformar en array de bool
    write in registros.txt
    getClave
    write in registros.txt
    getSaldo
    write in registros.txt
    write \n
}
se usa fout<<str o algo
     */
    fout.close();
}
void encriptar(){
    bool placeholder;
    for (int i=0;i<8;i=i+3){
        if ((8-i)>=3){
        placeholder=b[i];
        b[i]=b[i+1];
        b[i+1]=b[i+2];
        b[i+2]=placeholder;}
    }
    /*for (int i : b)
        std::cout<<i;*/
}
void desencriptar(){
    bool placeholder;
    for (int i=0;i<8;i=i+3){
        if ((8-i)>=3){
        placeholder=b[i+2];
        b[i+2]=b[i+1];
        b[i+1]=b[i];
        b[i]=placeholder;}
    }

}
int BoolaInt(){
    char num=0;
    for (int i=0;i<8;i++){
        num=num+b[i]*pow(2,7-i);
    }
    return (num-48);
}
void IntaBool(int a){
    int c=7;
    for (int i=a;c>=0;i=i/2){
        b[c]=(i%2==0)? 0 : 1 ;
        c--;
    }
}
bool CedRepetida (int Cedu){
    int c=0;
    for (int i=0;s[i].getCedula()!=0;i++){
        if (s[i].getCedula()==Cedu){
            c++;
        }
    }
    if (c>=2)
        return true;
    else
        return false;
}
int Cedplace(int cedu){
    int i=0;
    while(s[i].getCedula()!=0 && cedu!=s[i].getCedula())
        i++;
    return i;
}

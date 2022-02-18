#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "FileUsage.h"
#include "usuarios.h"
#include <vector>
bool b[8]={0};
extern Usuarios s[100];
/*int ReadSudo(){ //listo
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
     descripcion
     leer el archivo--> una linea
     desencriptar linea
     pasar a int

}
void readRegister(){
    std::ifstream fin;
    fin.open("registro.txt");
    int c=0;
    //int reader=0;
    fin.seekg(0);
    bool aid=0;
    while (fin.good()){
        int cedprov=0;
        for (int i=0;i<10;i++){ //Cedula
                for(int j=0;j<8;j++){
                    aid=fin.get()-48;
                    if (!fin.good())
                        break;
                    b[j]=aid;

                }
                if (!fin.good())
                    break;
                desencriptar();
                cedprov=cedprov+BoolaInt()*pow(10,9-i);
        }
        if (!fin.good())
            break;
        int claveprov=0;
        for (int i=0;i<4;i++){ //Clave
                for(int j=0;j<8;j++){
                    b[j]=fin.get()-48;
                }
                desencriptar();
                claveprov=claveprov+BoolaInt()*pow(10,3-i);
        }
        int saldoprov=0;
        char aid;
        char* ssaldo=new char[100];
        for (int i=0;ssaldo[i]!='\n';i++){ //Saldo
                for(int j=0;j<8;j++){
                    aid=fin.get();
                    if (aid=='\n')
                        break;
                    else
                        b[j]=aid-48;
                }
                if (aid=='\n'){
                    ssaldo[i]=aid;
                    break;}
                desencriptar();
                ssaldo[i]=BoolaInt()+48;
        } 
        int counter=0;
        for (int i=0;ssaldo[i]!='\n';i++)
            counter++;
        for (int i =0;i<counter;i++){
            saldoprov=saldoprov+(ssaldo[i]-48)*pow(10,counter-i-1);
        }
        delete [] ssaldo;
        s[c].SetUsuarios(cedprov,claveprov,saldoprov);
        c++;
    }

    for linea en leyendo
    8*10 de cedula
    cada 8, se desencripta, y se pasa a int
    8*4 de clave
    8*el resto de saldo


    fin.close();
}
void writeRegister(){
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
        //if (placeholder==0)
          //  digit=1;
        //else
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
    explicacion
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

    fout.close();
}*/
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
bool CheckCedRepetida (int Cedu){
    int c=0;
    for (int i=0;s[i].getCedula()!=0;i++){
        if (s[i].getCedula()==Cedu){
            c++;
        }
    }
    if (c>=1)
        return true;
    else
        return false;
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
int countUsers(){
    int num=0;
    for (int i=0;s[i].getCedula()!=0;i++)
        num++;
    return num;
}
void readRegister(){
    std::ifstream fin;
    char* file=new char[4000];
    int c=0;
    int n=3; //Clave de codificación
    char placeholder[n];
    fin.open("registro.txt");
    fin.seekg(0);
    int usuarios=0;
    while (fin.good()){
        *(file+c)=fin.get();
        c++;
    }
    //Desencriptar
    for (int i=0;i<c-(c%n);i=i+n){
        for (int j=0;j<n;j++){
            *(placeholder+j)=*(file+j+i);
        }
        *(file+i+n-1)=*(placeholder);
        for (int j=i;j<n+i-1;j++){
            *(file+j)=*(placeholder+j-i+1);
        }
    }
    //Pasar a las variables
    int counter=0;
    c--;
    while(c>0){
    int cedprov=0;
    for (int i=0;i<10;i++){ //Cedula
                int num=0;
                for (int j=0;j<8;j++){
                    num=num+(*(file+counter)-48)*pow(2,7-j);
                    c--;
                    counter++;
                }
                cedprov=cedprov+(num-48)*pow(10,9-i);
            }

    int claveprov=0;
    for (int i=0;i<4;i++){ //Clave
        int num=0;
        for (int j=0;j<8;j++){
            num=num+(*(file+counter)-48)*pow(2,7-j);
            counter++;
            c--;
        }
        claveprov=claveprov+(num-48)*pow(10,3-i);
    }
    int saldoprov=0;
    int c2=0;
    char* ssaldo=new char[20];
    do{
        for (int j=0;j<8;j++){
            ssaldo[c2]=ssaldo[c2]+(*(file+counter)-48)*pow(2,7-j);
            counter++;
            c--;
        }
        c2++;
    }
    while(ssaldo[c2-1]!=1);
    for (int i=0;ssaldo[i]!=1;i++)
       saldoprov=saldoprov+(ssaldo[i]-48)*pow(10,c2-2-i);
    delete[] ssaldo;
    s[usuarios].SetUsuarios(cedprov,claveprov,saldoprov);
    usuarios++;
    }
    delete []file;
    fin.close();
}
void writeRegister(){
    int placeholder1;
    int n=3;
    bool placeholder2[n];
    int digit;
    bool* file=new bool[10000];
    int counter=0;
    std::ofstream fout;
    fout.open("registro.txt");
    for (int i=0;s[i].getCedula()!=0;i++){
        placeholder1=s[i].getCedula(); //Se separa por digitos que se pasan a binario y se encriptan
        digit=10;
        char* palabra=new char[digit];
        int c=0;
        for (int j=digit;j>0;j--){
           *(palabra+c)=(floor(placeholder1/(pow(10,j-1))))+48;
            placeholder1=placeholder1-(palabra[c]-48)*pow(10,j-1);
            c++;
        }
        for (int j=0;j<digit;j++){
            IntaBool(palabra[j]);
            for (int k=0;k<8;k++){
                *(file+counter)=b[k];
                counter++;
            }
        }
        delete[] palabra;
        placeholder1=s[i].getClave();
        digit=4;
        palabra=new char[digit];
        c=0;
        for (int j=digit;j>0;j--){
           *(palabra+c)=(floor(placeholder1/(pow(10,j-1))))+48;
            placeholder1=placeholder1-(palabra[c]-48)*pow(10,j-1);
            c++;
        }
        for (int j=0;j<digit;j++){
            IntaBool(palabra[j]);
            for (int k=0;k<8;k++){
                *(file+counter)=b[k];
                counter++;
            }
        }
        delete[] palabra;
        placeholder1=s[i].getSaldo();
        if (placeholder1==0)
          digit=1;
        else
            digit=floor(log10(placeholder1)+1);
        palabra=new char[digit];
        c=0;
        for (int j=digit;j>0;j--){
           *(palabra+c)=(floor(placeholder1/(pow(10,j-1))))+48;
            placeholder1=placeholder1-(palabra[c]-48)*pow(10,j-1);
            c++;
        }
        for (int j=0;j<digit;j++){
            IntaBool(palabra[j]);
            for (int k=0;k<8;k++){
                *(file+counter)=b[k];
                counter++;
            }
        }
        delete[] palabra;
        for (int i=0;i<8;i++){
            *(file+counter)=0;
            counter++;}
        *(file+counter-1)=1;

    }
    //Encriptar
    for (int i=0;i<counter-(counter%n);i=i+n){
        for (int j=0;j<n;j++){
            *(placeholder2+j)=*(file+j+i);
        }
        *(file+i)=*(placeholder2+n-1);
        for (int j=i+1;j<n+i;j++){
            *(file+j)=*(placeholder2+j-i-1);
        }
    }
    //Pasar al archivo
    for (int i=0;i<counter;i++)
        fout<<*(file+i);
    delete[]file;
    fout.close();
}
int ReadSudo(){
    char a[32];
    bool line[32];
    int c=0;
    int clave=0;
    int n=3;
    bool placeholder[n];
    std::ifstream fin;
    fin.open("ArchivoSudo.txt");
    fin.getline(a,33);
    for (char i:a){
        line[c]= bool(i-48);
        c++;
    }
    //Desencriptar
    for (int i=0;i<32-(32%n);i=i+n){
        for (int j=0;j<n;j++){
            *(placeholder+j)=*(line+j+i);
        }
        *(line+i+n-1)=*(placeholder);
        for (int j=i;j<n+i-1;j++){
            *(line+j)=*(placeholder+j-i+1);
        }
    }
    //Pasar a int
    for (int i=0;i<4;i++){
    int num=0;
    for (int j=0;j<8;j++){
        num=num+*(line+j+i*8)*pow(2,7-j);
    }
    clave=clave+(num-48)*pow(10,3-i);
    }
    return clave;
}

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Data
{
    int dia;
    int mes;
    int ano;
public:
//CONSTRUTOR
    Data() {}
    Data(Data dE, int i)
    {
        if(i == 1){
            dia=dE.getDia()+7;
            if(dia>30){
                mes = (dE.getMes()+1);
                dia = (dia-30);
                ano = dE.getAno();
            }
            else{
                mes=dE.getMes();
                if(mes>12){
                    ano = dE.getAno()+1;
                }
                else
                    ano = dE.getAno();
            }
        }
        if(i == 2){
            dia=dE.getDia()+15;
            if(dia>30){
                mes = (dE.getMes()+1);
                dia = (dia-30);
                ano = dE.getAno();
            }
            else{
                mes = dE.getMes();
                if(mes>12){
                    ano = (dE.getAno()+1);
                }
                else
                    ano = dE.getAno();
            }
        }
    }
    Data(int d, int m, int a)
    {
        dia=d;
        mes=m;
        ano=a;
    }
//DESTRUTOR
    ~Data() {}
//GETTERS E SETTERS
    void setDia(int d){dia=d;}
    const int getDia(){return dia;}
    void setMes(int m){mes=m;}
    const int getMes(){return mes;}
    void setAno(int a){ano=a;}
    const int getAno(){return ano;}
//FUNÇÕES
    virtual void mostraData(){
        cout << dia <<"/" <<mes <<"/" << ano << endl;
    }
};

#include <iostream>
#include <vector>
#include <string.h>
#include "data.cpp"

using namespace std;

class Navio
{
    string id;
    string nome;
    Data dataEntrada;
    Data dataSaida;
public:
//CONSTRUTOR
    Navio() {}
    Navio(string i, string n, Data dE, Data dS)
    {
        id=i;
        nome=n;
        dataEntrada=dE;
        dataSaida=dS;
    }
//DESTRUTOR
    ~Navio() {}
//GETTERSS E SETTERS
    const string getId(){return id;}
    string getNome(){return nome;}
    Data getDataEntrada(){return dataEntrada;}
    Data getDataSaida(){return dataSaida;}
//FUNÇÕES

};

class Cargueiro:public Navio
{
    string carga;
    int quantidade;
    std::vector<Cargueiro> cargueiros;

public:
//CONSTRUTOR
    Cargueiro(string i, string n, string c, int q, Data dE, Data dS) : Navio(i, n, dE, dS)
    {
        carga=c;
        quantidade=q;
    }
//DESTRUTOR
    ~Cargueiro(){}
//GETS E SETS
    string getCarga(){return carga;}
    int getQuantidade(){return quantidade;}
};

class Cruzeiro:public Navio
{
    string localSaida;
    string localIda;
    int passageiros;
    string nomeCapitao;
    std::vector<Cruzeiro> cruzeiros;
public:
//CONSTRUTOR
    Cruzeiro(string i, string n,  string lS, string lI, int p, string nC, Data dE, Data dS)
        : Navio(i,n,dE,dS)
    {
        localSaida=lS;
        localIda=lI;
        passageiros=p;
        nomeCapitao=nC;
    }
//DESTRUTOR
    ~Cruzeiro() {}
//GETTERS E SETTERS
    string getLocalSaida(){return localSaida;}
    string getLocalIda(){return localIda;}
    int getPassageiros(){return passageiros;}
    string getNomeCapitao(){return nomeCapitao;}
};

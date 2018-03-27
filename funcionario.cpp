#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Funcionario
{
protected:
    string nome_funcinario;
    string identificacao;
    float salario;
public:
    Funcionario() {}
    Funcionario(string nF, string ident, float s)
    {
        nome_funcinario=nF;
        identificacao=ident;
        salario = s;
    }
    ~Funcionario() {}
    const string getNomeFuncionario(){return nome_funcinario;}
    const string getIdentificacao(){return identificacao;}
    const float getSalario(){return salario;}
    virtual float modifica_salario(float s, float aS){
        s=s*aS;
        return s;
    }
};

class TecnicoPortuario : public Funcionario
{
    float adicional_salario;
    string funcao;
public:
    TecnicoPortuario() {}
    TecnicoPortuario(float aS, string f, string n, string i, int s) : Funcionario(n,i,modifica_salario(s,aS))
    {
        adicional_salario=aS;
        funcao=f;
    }
    ~TecnicoPortuario() {}
//GETTERS E SETTER
    float getAdicionalSalario(){return adicional_salario;}
    string getFuncao(){return funcao;}
//FUNÇÕES
};

class Manobrista : public Funcionario
{
    float adicional_salario;
    string funcao;
public:
//CONSTRUTOR
    Manobrista() {}
    Manobrista(float aS, string f, string n, string i, int s) : Funcionario(n, i, modifica_salario(s,aS))
    {
        adicional_salario=aS;
        funcao=f;
    }
//DESTRUTOR
    ~Manobrista() {}
//GETTERS E SETTER
    float getAdicionalSalario(){return adicional_salario;}
    string getFuncao(){return funcao;}
};

class Diretor: public Funcionario
{
    float adicional_salario;
    string funcao;
public:
//OONSTRUTOR
    Diretor() {}
    Diretor(float aS, string f, string n, string i, int s) : Funcionario(n, i, modifica_salario(s, aS))
    {
        adicional_salario=aS;
        funcao=f;
    }
//DESTRUTOR
    ~Diretor() {}
//GET E SET
    float getAdicionalSalario(){return adicional_salario;}
    string getFuncao(){return funcao;}
};

class Operador : public Funcionario
{
    float adicional_salario;
    string funcao;
public:
//CONSTRUTOR
    Operador(float aS, string f, string n, string i, int s) : Funcionario(n, i, modifica_salario(s, aS))
    {
        adicional_salario=aS;
        funcao=f;
    }
//DESTRUTOR
    ~Operador() {}
//GETTERS E SETTERS
    float getAdicionalSalario(){return adicional_salario;}
    string getFuncao(){return funcao;}
};

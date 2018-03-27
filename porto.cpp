#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "navio.cpp"
#include "funcionario.cpp"

using namespace std;

class Escritorio
{
protected:
    std::list<TecnicoPortuario> tecnicos;
    TecnicoPortuario t1, t2;
    std::list<Manobrista> manobristas;
    Manobrista m1, m2;
    std::list<Diretor> diretor;
    Diretor d1;
    std::list<Operador> operadores;
    Operador o1, o2, o3, o4, o5;
    float dinheiro;
public:
    Escritorio():t1(1.2, "Tecnico Portuario", "Cleyson", "156", 1600), t2(1.6, "Tecnico Portuario", "Cleverson", "192", 1600),
        m1(1.1, "Manobrista", "Jefferson", "126", 1200), m2(1.1, "Manobrista", "Kleberson", "158", 1200),
        d1(4.5, "Diretor", "Calleduardo", "100", 1200),
        o1(1, "Operador", "Jesse", "201", 1000), o2(1, "Operador", "Linconl", "202", 1000), o3(1, "Operador", "Matias", "203", 1000),
        o4(1, "Operador", "Oseias", "204", 1000), o5(1, "Operador", "Habacuque", "205",1000)
    {
        adiciona_tecnico(t1);
        adiciona_manobrista(m1);
        adiciona_manobrista(m2);
        adiciona_diretor(d1);
        adiciona_operador(o1);
        adiciona_operador(o2);
        adiciona_operador(o3);
        adiciona_operador(o4);
        adiciona_operador(o5);
    }
    ~Escritorio() {}
//GETS E SETS
    int getDinheiro(){return dinheiro;}
//FUNÇÕES
//FUNÇOES FUNCIONARIOS
    //FUNÇÕES TECNICOS
    void listaTecnicos()
    {
        cout << endl << "Listando Tecnicos do Porto";
        for(std::list<TecnicoPortuario>::iterator i=tecnicos.begin(); i!=tecnicos.end(); i++)
        {
            cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                 endl << "Funcao: " << (*i).getFuncao() << endl <<
                 "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
        }
    }

    void adiciona_tecnico(TecnicoPortuario novoTecnico){tecnicos.push_back(novoTecnico);}
    //FUNÇOES MANOBRISTA
    void adiciona_manobrista(Manobrista novoManobrista){manobristas.push_back(novoManobrista);}

    void listaManobristas()
    {
        cout << endl <<"Listando Manobristas do Porto" << endl;
        for(std::list<Manobrista>::iterator i=manobristas.begin(); i!=manobristas.end(); i++)
        {
            cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                 endl << "Funcao: " << (*i).getFuncao() << endl <<
                 "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
        }
    }

    //FUNÇOES DIRETOR
    void listaDiretor()
    {
        cout << endl << "Listando Diretor do Porto";
        for(std::list<Diretor>::iterator i=diretor.begin(); i!=diretor.end(); i++)
        {
            cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                 endl << "Funcao: " << (*i).getFuncao() << endl <<
                 "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
        }
    }

    void adiciona_diretor(Diretor novoDiretor){diretor.push_back(novoDiretor);}

    //FUNÇOES OPERADOR
    void listaOperador()
    {
        cout << endl << "Listando Operador do Porto";
        for(std::list<Operador>::iterator i=operadores.begin(); i!=operadores.end(); i++)
        {
            cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                 endl << "Funcao: " << (*i).getFuncao() << endl <<
                 "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
        }
    }

    void adiciona_operador(Operador novoOperador){operadores.push_back(novoOperador);}

//OUTROS FUNÇÕES
    void cadastraFuncionario()
    {
        string n, i;
        int f;

        cout <<"Digite a ID do Funcionario com 3 digitos: ";
        cin >> i;
        while(i.size()>3 || i.size()<3){
            cout << "Erro, digite novamente: ";
            cin >> i;
        }
        cout <<"Digite o Nome do Funcionario: ";
        cin >> n;
        cout << "Escolha a Funcao: " << endl <<"   1 para Operador \n   2 Para Manobrista \n   3 Para Tecnico Portuario \n   4 Para Diretor: ";
        cin >> f;

        if(f==1)
        {
            Operador novoOperador(1, n, "Operador", i, 1000);
            adiciona_operador(novoOperador);
        }
        if(f==2)
        {
            Manobrista novoManobrista(1.2, n, "Manobrista", i, 1200);
            adiciona_manobrista(novoManobrista);
        }
        if(f==3)
        {
            TecnicoPortuario novoTecnico(1.4, n, "Tecnico Operador", i, 1400);
            adiciona_tecnico(novoTecnico);
        }
        if(f==4)
        {
            Diretor novoDiretor(4.5, n, "Diretor", i, 1200);
            adiciona_diretor(novoDiretor);
        }
    }

    virtual void excluindo_operador(string id)
    {
        int flag;
        flag=0;
        for(std::list<Operador>::iterator i=operadores.begin(); i!=operadores.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                i = operadores.erase(i);
                flag=1;
            }
            if(flag ==0)
            {
                cout << "Operador nao encontrado"<< endl;
            }
            else
            {
                cout << "Operador removido com sucesso!";
            }
        }
    }

    virtual void excluindo_tecnico(string id)
    {
        int flag;
        flag=0;
        for(std::list<TecnicoPortuario>::iterator i=tecnicos.begin(); i!=tecnicos.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                i = tecnicos.erase(i);
                flag=1;
            }
            if(flag ==0)
            {
                cout << "Tecnico nao encontrado"<< endl;
            }
            else
            {
                cout << "Tecnico removido com sucesso!";
            }
        }
    }

    virtual void excluindo_diretor(string id)
    {
        int flag;
        flag=0;
        for(std::list<Diretor>::iterator i=diretor.begin(); i!=diretor.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                i=diretor.erase(i);
                flag=1;
            }
            if(flag ==0)
            {
                cout << "Diretor nao encontrado"<< endl;
            }
            else
            {
                cout << "Diretor removido com sucesso!";
            }
        }
    }

    virtual void excluindo_manobrista(string id)
    {
        int flag;
        flag=0;
        for(std::list<Manobrista>::iterator i=manobristas.begin(); i!=manobristas.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                i=manobristas.erase(i);
                flag=1;
            }
            if(flag ==0)
            {
                cout << "Manobrista nao encontrado"<< endl;
            }
            else
            {
                cout << "Manobrista removido com sucesso!";
            }
        }
    }

//PROCURA
    void procura_Tecnico(string id)
    {
        int flag;
        flag=0;
        for(std::list<TecnicoPortuario>::iterator i=tecnicos.begin(); i!=tecnicos.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                     endl << "Funcao: " << (*i).getFuncao() << endl <<
                     "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
                flag=1;
            }
        }
        if(flag !=1)
        {
            cout << "\nTecnico Nao Encontrado"<< endl;
        }
    }

    void procura_Diretor(string id)
    {
        int flag;
        flag=0;
        for(std::list<Diretor>::iterator i=diretor.begin(); i!=diretor.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                     endl << "Funcao: " << (*i).getFuncao() << endl <<
                     "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
                flag=1;
            }
        }
        if(flag !=1)
        {
            cout << "Diretor Nao Encontrado"<< endl;
        }
    }

    void procura_Manobrista(string id)
    {
        int flag;
        flag=0;
        for(std::list<Manobrista>::iterator i=manobristas.begin(); i!=manobristas.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                     endl << "Funcao: " << (*i).getFuncao() << endl <<
                     "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
                flag=1;
            }
        }
        if(flag !=1)
        {
            cout << "\nManobrista Nao Encontrado"<< endl;
        }
    }

    void procura_Operador(string id)
    {
        int flag;
        flag=0;
        for(std::list<Operador>::iterator i=operadores.begin(); i!=operadores.end(); i++)
        {
            if((*i).getIdentificacao() == id || (*i).getNomeFuncionario() == id)
            {
                cout << endl << "Nome: " << (*i).getNomeFuncionario() << " / Identificacao: " << (*i).getIdentificacao()<<
                     endl << "Funcao: " << (*i).getFuncao() << endl <<
                     "Salario: "<<(*i).modifica_salario((*i).getSalario(),(*i).getAdicionalSalario()) << endl;
                flag=1;
            }
        }
        if(flag !=1)
        {
            cout << "\nOperador Nao Encontrado"<< endl;
        }
    }
//FUNÇÕES SALARIO
    virtual float soma_salarios()
    {
        float total = 0;
        total = (total + (operadores.size()*1000));
        total = (total + (manobristas.size()*1200));
        total = (total + (tecnicos.size()*1600));
        total = (total + (diretor.size()*4500));
        return total;
    }
};

class Doca
{
protected:
    std::list<Cargueiro> cargueiros;
    Cargueiro c1,c2,c3;
    std::list<Cruzeiro> cruzeiros;
    Cruzeiro cr1, cr2, cr3;
    FILE *b;
public:
    Doca():c1("1974", "World Discover", "Soja", 9856, Data(12,1,2001), Data(Data(12,1,2001), 2)), c2("1952", "Sky Mediterraneo", "Laranja", 2503, Data(23,1,2001), Data(Data(23,1,2001), 2)),
        c3("1940", "SS AMerica", "Eletronicos", 12028, Data(1,2,2001), Data(Data(1,2,2001), 2)),
        cr1("2009", "MS Freedom of The Seas", "Guaratuba", "Matinhos", 4370, "Willian Kid", Data(7,1,2001), Data(Data(7,1,2001), 1)),
        cr2("2003", "Queen Mary II", "Santos", "Fernando de Noronha", 3241, "Edward Teach", Data (23,1,2001), Data(Data (23,1,2001), 1)),
        cr3("2007", "Norwegian Epic", "Curitiba", "São Paulo", 4100, "Bartholomew Roberts", Data(14,2,2001), Data(Data(14,2,2001),1))
    {
        adiciona_cargueiro(c1);
        adiciona_cargueiro(c2);
        adiciona_cargueiro(c3);
        adiciona_cruzeiro(cr1);
        adiciona_cruzeiro(cr2);
        adiciona_cruzeiro(cr3);
    }

    void adiciona_cargueiro(Cargueiro novoCargueiro){cargueiros.push_back(novoCargueiro);}

    void listaCargueiros()
    {
        cout <<"Listando Navios: " << endl;
        for(std::list<Cargueiro>::iterator i=cargueiros.begin(); i!=cargueiros.end(); i++)
        {
            cout <<endl << "Id do Cargueiro: " << (*i).getId() << endl << "Nome do Cargueiro: " << (*i).getNome()
                 <<endl << "Tipo de carga: " << (*i).getCarga() <<endl << "Quantidade de container: "<< (*i).getQuantidade()
                 << endl << "Data de chegada: ";
            (*i).getDataEntrada().mostraData();
            cout << "Data de Saida: ";
            (*i).getDataSaida().mostraData();
        }
    }

    void cadastraCargueiro()
    {
        string  n, c, i;
        int q,d,m, a;

        cout << "Insira ID do Navio de 4 digitos: ";
        cin >> i;
        while(i.size()>4 || i.size()<4){
            cout << "Erro, digite novamente: ";
            cin >> i;
        }
        cout <<"Insira o Nome do Navio: ";
        cin >> n;
        cout <<"Insira o Tipo de Carga do Navio: ";
        cin >> c;
        cout <<"Insira a Quantidade de Container: ";
        cin >> q;
        cout <<"Insira a Data de Chegada(d/m/a): ";
        cin >> d >> m >> a;

        Cargueiro novoCargueiro(i,n,c,q,Data(d,m,a),Data(Data(d,m,a), 2));
        adiciona_cargueiro(novoCargueiro);
    }

    void procuraCargueiro(string idCarg)
    {
        std::list<Cargueiro>::iterator it;
        int aqui;
        it=cargueiros.begin();
        aqui=0;
        while(it!=cargueiros.end())
        {
            if(idCarg==(*it).getId())
            {
                cout << endl << "ID: " <<(*it).getId() << "\n" << " / Nome " <<(*it).getNome()<<endl << "Data de entrada: ";
                (*it).getDataEntrada().mostraData();
                cout << endl <<"Data de saida: ";
                (*it).getDataSaida().mostraData();
                cout << endl << "carga: " << (*it).getCarga() << endl
                     << "quantidade: " << (*it).getQuantidade() << endl;
                aqui = 1;
            }
            it++;
        }
        if(aqui!=1)
        {
            cout << "Navio nao encontrado!";
        }
    }

//FUNÇOES CRUZEIRO
    void adiciona_cruzeiro(Cruzeiro novoCruzeiro){cruzeiros.push_back(novoCruzeiro);}

    void listaCruzeiros()
    {
        cout <<"Listando Cruzeiros" << endl << endl;
        for(std::list<Cruzeiro>::iterator i=cruzeiros.begin(); i!=cruzeiros.end(); i++)
        {
            cout << endl << "ID do Cruzeiro: " << (*i).getId() << endl << "Nome do Cruzeiro: " << (*i).getNome() << endl
                 << "Nome do Capitao: " << (*i).getNomeCapitao() <<endl
                 <<"Destino: De " << (*i).getLocalSaida() << " para " << (*i).getLocalIda() << endl
                 << "Total de Passageiros:" << (*i).getPassageiros() << endl << "Data Chegada: ";
            (*i).getDataEntrada().mostraData();
        }
    }

    void cadastraCruzeiro()
    {
        string n, nC, lS, lI, i;
        int p, d, m,a;

        cout<<"Insira A ID do Cruzeiro de 5 digitos: ";
        cin >> i;
        while(i.size()>4 || i.size()<4){
            cout << "Erro, digite novamente: ";
            cin >> i;
        }
        cout<<"Insira o Nome do Cruzeiro: ";
        cin >> n;
        cout<<"Insira o Nome do Capitao: ";
        cin >> nC;
        cout<<"Insira o Local de Saida: ";
        cin >> lS;
        cout<<"Insira o Destino: ";
        cin >> lI;
        cout <<"Insira o Numero de Passageiros: ";
        cin >> p;
        cout <<"Insira a Data de Chegada <d/m/a>: ";
        cin >> d >> m >> a;

        Cruzeiro novoCruzeiro(i, n, lS, lI, p, nC, Data(d,m,a), Data(Data(d,m,a), 1));
        adiciona_cruzeiro(novoCruzeiro);
    }
//DEMAIS FUNÇÕES
};


class Porto : public Escritorio, public Doca
{
    string nomePorto;
    float lucro;
    Escritorio E;
    Doca D;
//NAVIOS
//FUNCIONARIOS
public:
//CONSTRUTOR
    Porto():E(), D()
    {
        nomePorto="PROG2";
        lucro = 150000;
    }

//DESTRUTOR
    ~Porto() {}

//GETS E SETS
    void setNomePorto(string np){nomePorto=np;}
    string getNomePorto(){return nomePorto;}

//FUNÇOES PORTO
    void mostraNome(){cout<<"Nome do Porto: "<<nomePorto;}

//OUTRAS FUNÇÕES
    float soma_custo()
    {
        float total=0;
        total = (total + (cargueiros.size()*30000));
        total = (total + (cruzeiros.size()*7000));
        return total;
    }

    void mostra_custos_porto()
    {
        float total = lucro + (soma_custo()-soma_salarios());
        cout << "Relatorio de Contabilidade do Porto: \n\nDinheiro atual: " << lucro << ",00\n\nEntradas Futuras: " << soma_custo() << ",00\n\nSaidas Futuras: " <<
             soma_salarios() << ",00\n\nLiquido de: " << total << ",00\n\nRelatorio Realizado com Sucesso";
    }

    void registra_saida(string n, Data dS)
    {
        b=fopen("Saidas.txt", "a");
        fputs("\n\nNome do Navio: ",b);
        fputs(n.c_str(), b);
        fputs("\nData de Saida: ", b);
        fprintf(b, "%d/%d/%d", dS.getDia(), dS.getMes(), dS.getMes());
        fclose(b);
    }

    Data saidaNavio()
    {
        Data aux;
        std::list<Cargueiro>::iterator i=cargueiros.begin();
        std::list<Cruzeiro>::iterator a=cruzeiros.begin();
        if((*i).getDataEntrada().getMes()==(*a).getDataEntrada().getMes())
        {
            if((*i).getDataEntrada().getDia()>(*a).getDataEntrada().getDia())
            {
                aux=(*a).getDataSaida();
                cruzeiros.pop_front();
                lucro=(lucro+7000);
                registra_saida((*a).getNome(), aux);
                return aux;
            }
            else
            {
                aux=(*i).getDataSaida();
                cargueiros.pop_front();
                lucro=(lucro+30000);
                registra_saida((*i).getNome(), aux);
                return aux;
            }
        }
        else if((*i).getDataEntrada().getMes()>(*a).getDataEntrada().getMes())
        {
            aux=(*a).getDataSaida();
            cruzeiros.pop_front();
            lucro=(lucro+7000);
            registra_saida((*a).getNome(), aux);
            return aux;
        }
        else
        {
            aux=(*i).getDataSaida();
            cargueiros.pop_front();
            lucro=(lucro+30000);
            registra_saida((*i).getNome(), aux);
            return aux;
        }
    }

    void imprime_relatorio()
    {
        FILE *c;
        c=fopen("Relatorio.txt", "w");
        if(c!=NULL){
            fputs("RELATORIO COMPLETO PORTO", c);
            fputs("\n\nCargueiros\n",c);
            for(std::list<Cargueiro>::iterator i=cargueiros.begin();i!=cargueiros.end(); i++){
                fputs("\n\nID do Cargueiro: ", c);
                fputs((*i).getId().c_str(), c);
                fputs("\nNome do Cargueiro: ",c);
                fputs((*i).getNome().c_str(), c);
                fputs("\nCarga: " ,c);
                fputs((*i).getCarga().c_str(),c);
                fputs("\nQuantidade de Container: ",c);
                fprintf(c, "%d", (*i).getQuantidade());
                fputs("\nData de Chegada e Saida", c);
                fprintf(c, "Entrada: %d/%d/%d\n", (*i).getDataEntrada().getDia(),(*i).getDataEntrada().getMes(),(*i).getDataEntrada().getAno()  );
            }
            fputs("\n\nCruzeiros", c);
            for(std::list<Cruzeiro>::iterator i=cruzeiros.begin();i!=cruzeiros.end();i++){
                fputs("\n\nID do Cruzeiro: ",c);
                fputs((*i).getNome().c_str(), c);
                fputs("\nNome do Cruzeiro: ",c);
                fputs((*i).getNome().c_str(),c);
                fputs("\nNome do Capitão: ",c);
                fputs((*i).getNomeCapitao().c_str(),c);
                fputs("\nLocal de Saida\\Destino: ",c);
                fputs((*i).getLocalSaida().c_str(), c);
                fputs(" \\ ",c);
                fputs((*i).getLocalIda().c_str(),c);
                fputs("\nNumero de Passageiros: ",c);
                fprintf(c, "%d", (*i).getPassageiros());
                fputs("\nData de Chegada: ",c);
                fprintf(c, "Entrada: %d/%d/%d\n", (*i).getDataEntrada().getDia(),(*i).getDataEntrada().getMes(),(*i).getDataEntrada().getAno()  );
            }
            fputs("\n\nFUNCIONARIOS\n\nOPERADOR\n",c);
            for(std::list<Operador>::iterator i=operadores.begin();i!=operadores.end();i++){
                fputs("\n\nId do Operador: ",c);
                fputs((*i).getIdentificacao().c_str(),c);
                fputs("\nNome do Operador: ", c);
                fputs((*i).getNomeFuncionario().c_str(),c);
                fputs("\nSalario: R$",c);
                fprintf(c, "%.2f", (*i).getSalario());
            }
            fputs("\nTECNICO PORTUARIO\n",c);
            for(std::list<TecnicoPortuario>::iterator i=tecnicos.begin();i!=tecnicos.end();i++){
                fputs("\n\nId do Tecnico Portuario: ",c);
                fputs((*i).getIdentificacao().c_str(),c);
                fputs("\nNome do Tecnico: ", c);
                fputs((*i).getNomeFuncionario().c_str(),c);
                fputs("\nSalario: R$",c);
                fprintf(c, "%.2f", (*i).getSalario());
            }
            fputs("\nMANOBRISTA\n",c);
            for(std::list<Manobrista>::iterator i=manobristas.begin();i!=manobristas.end();i++){
                fputs("\n\nId do Manobrista: ",c);
                fputs((*i).getIdentificacao().c_str(),c);
                fputs("\nNome do Manobrista: ", c);
                fputs((*i).getNomeFuncionario().c_str(),c);
                fputs("\nSalario: R$",c);
                fprintf(c, "%.2f", (*i).getSalario());
            }
            fputs("\nDIRETOR\n",c);
            for(std::list<Diretor>::iterator i=diretor.begin();i!=diretor.end();i++){
                fputs("\n\nId do Diretor: ",c);
                fputs((*i).getIdentificacao().c_str(),c);
                fputs("\nNome do Diretor: ", c);
                fputs((*i).getNomeFuncionario().c_str(),c);
                fputs("\nSalario: R$",c);
                fprintf(c, "%.2f", (*i).getSalario());
            }
            fputs("\n\nFINANCEIRO\n\nSaldo Atual: ",c);
            fprintf(c, "%.2f", lucro);
            fputs("\nEntradas Futuras: ",c);
            fprintf(c, "%.2f", soma_custo());
            fputs("\nSaidas Futuras: ",c);
            fprintf(c, "%.2f", soma_salarios());
            fputs("\nLiquido: ",c);
            fprintf(c, "%.2f", (lucro + (soma_custo()-soma_salarios())));

        }
        fclose(c);
    };

};

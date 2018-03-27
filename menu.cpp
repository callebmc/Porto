#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include "porto.cpp"

using namespace std;

class Menu
{
    string nomeUsuario;
    Porto p;
    Data d;
public:
//CONSTRUTOR
    Menu():d(1,1,2001)
    {
        cout << "Programa Inicializado";
        cadastraUsuario();
        mostraMenu();
    }
//DESTRUTOR
    ~Menu() {}
//FUNÇÕES
    void cadastraUsuario()
    {
        cout << endl << endl << endl << endl << "Insira o nome de Usuario: ";
        cin >> nomeUsuario;
    }

    virtual void mostraMenu()
    {
        Porto();
        int opt;
        system("cls");
        cout << "                 Bem Vindo ao SisNavin 2017      ";
        d.mostraData();
        cout << "\n\n\nUsuario: "<< nomeUsuario << "\n\n\nEscolha a opcao desejada:\n1. Gerenciar Navios\n2. Gerenciar Funcionarios\n"
        <<"3. Gerenciar Porto\n4. Trocar Usuario\n5. Sair\n\nOpcao: ";
        cin >> opt;
        if(opt == 1)
        {
            mostraMenuNavio();
        }
        else if(opt == 2)
        {
            mostraMenuFunc();
        }
        else if(opt == 3){
            mostraMenuPorto();
        }
        else if(opt == 4 ){
            system("cls");
            cadastraUsuario();
            mostraMenu();
        }
        else if(opt == 5){
            exit(EXIT_SUCCESS);
        }
        else
            mostraMenu();
    }

    void mostraMenuNavio()
    {
        int opt, opt2;
        system("cls");
        cout << "                 Bem Vindo ao SisNavin 2017      ";
        d.mostraData();
        cout <<"\n\n\nEscolha uma opcao\n\n1. Cadastrar Navio\n2. Registar Saida\n3. Listar Cargueiro"
        << "\n4. Listar Cruzeiros\n5. Procurar Navio\n6. Voltar\n\nOpcao: ";
        cin >> opt;
        if(opt == 1)
        {
            system("cls");
            cout << "                 Bem Vindo ao SisNavin 2017\n\n\n\nEscolha uma opcao\n\n1. Cadastrar Cargueiro "<<
            "\n2. Cadastrar Cruzeiro\n\nOpcao: ";
            cin >> opt2;
            if(opt2 == 1)
            {
                p.cadastraCargueiro();
                cout << "\n\nCadastro Realizado com Sucesso! \n Aperte 1 para voltar ou 2 para sair ";
                cin >> opt2;
                if(opt2 == 1)
                {
                    mostraMenu();
                }
                if(opt2 == 2)
                {
                    exit(EXIT_SUCCESS);
                }
            }
            if(opt2 == 2)
            {
                p.cadastraCruzeiro();
            }
        }
        else if(opt == 2)
        {
            d=p.saidaNavio();
            cout << "\n\nSaida Realizada com Sucesso! \nAperte 1 para voltar ou 2 para sair ";
            cin >> opt2;
            if(opt2 == 1)
            {
                mostraMenu();
            }
            if(opt2 == 2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt == 3)
        {
            system("cls");
            p.listaCargueiros();
            cout << "\n\nCargueiros Listados Com Sucesso! \n Aperte 1 Para Voltar ou 2 Para Sair";
            cin >> opt2;
            if(opt2 == 1)
            {
                mostraMenu();
            }
            if(opt2 == 2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt == 4){
            system("cls");
            p.listaCruzeiros();
            cout << "\n\nCruzeiros Listados Com Sucesso! \n Aperte 1 Para Voltar ou 2 Para Sair";
            cin >> opt2;
            if(opt2 == 1)
            {
                mostraMenu();
            }
            if(opt2 == 2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt == 5)
        {
            string idShip;
            cout << "Digite a ID do navio: ";
            cin >> idShip;
            p.procuraCargueiro(idShip);
            cout <<"\nAperte 1 Para Voltar ou 2 Para Sair";
            cin >> opt2;
            if(opt2 == 1)
            {
                mostraMenu();
            }
            if(opt2 == 2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt == 6)
        {
            mostraMenu();
        }
        else
            mostraMenuNavio();
    }

    void mostraMenuFunc()
    {
        int opt3;
        system("cls");
        cout << "                 Bem Vindo ao SisNavin 2017      ";
        d.mostraData();
        cout << "\n\n\n\nEscolha uma opcao\n\n1. Cadastra Novo Funcionario\n2. Listar Funcionarios"
        << "\n3. Despedir Funcionario\n4. Procurar Funcionario\n5. Voltar\n\nOpcao: ";
        cin >> opt3;
        if(opt3==1)
        {
            system("cls");
            p.cadastraFuncionario();
            cout << "\nCadastro realizado com sucesso! \nAperte 1 para voltar ou 2 para sair: ";
            cin >> opt3;
            if(opt3==1)
            {
                mostraMenu();
            }
            if(opt3==2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt3==2)
        {
            system("cls");
            p.listaDiretor();
            p.listaTecnicos();
            p.listaManobristas();
            p.listaOperador();

            cout << "\n\nListagem feita com Sucesso!\nDigite 1 para voltar ou 2 para sair ";
            cin >> opt3;
            if(opt3==1)
            {
                mostraMenu();
            }
            if(opt3==2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt3==3)
        {
            string ident;
            system("cls");
            cout << "Escolha um cargo para a demissao: \n 1. Manobrista \n 2. Tecnico \n 3. Operador \n Opcao: ";
            cin >> opt3;
            if(opt3 == 1)
            {
                cout << "Digite a ID ou Nome do Manobrista: ";
                cin >> ident;
                p.excluindo_manobrista(ident);
            }
            if(opt3 == 2)
            {
                cout << "Digite a ID ou Nome do Tecnico: ";
                cin >> ident;
                p.excluindo_tecnico(ident);
            }
            if(opt3 == 3)
            {
                cout << "Digite a ID ou Nome do Operador: ";
                cin >> ident;
                p.excluindo_operador(ident);
            }
            cout << endl << endl <<"Demissao feita com Sucesso! \nDigite 1 para voltar ou 2 para sair ";
            cin >> opt3;
            if(opt3 == 1)
            {
                mostraMenu();
            }
            if(opt3==2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt3==4){
            system("cls");
            string id;
            cout << "Digite a ID ou o Nome do funcionario: ";
            cin >> id;
            p.procura_Diretor(id);
            p.procura_Manobrista(id);
            p.procura_Tecnico(id);
            p.procura_Operador(id);

            cout << endl << endl <<"Procura feita com Sucesso! \nDigite 1 para voltar ou 2 para sair ";
            cin >> opt3;
            if(opt3==1)
            {
                mostraMenu();
            }
            if(opt3==2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        else if(opt3 == 5){
            mostraMenu();
        }
        else
            mostraMenuFunc();
    }

    void mostraMenuPorto()
    {
        int opt4;
        system("cls");
        cout << "                 Bem Vindo ao SisNavin 2017      ";
        d.mostraData();
        cout << "\n\n\n\nEscolha uma opcao\n\n 1. Contabilidade\n 2. Relatorio\n3. Voltar\n\nOpcao: ";
        cin >> opt4;
        if(opt4==1){
            system("cls");
            p.mostra_custos_porto();
            cout << "\n\n\nDigite 1 para voltar ou 2 para sair ";
            cin >> opt4;
            if(opt4 == 1)
            {
                mostraMenu();
            }
            if(opt4 == 2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        if(opt4 == 2){
            system("cls");
            p.imprime_relatorio();
            cout << "\n\n\nDigite 1 para voltar ou 2 para sair ";
            cin >> opt4;
            if(opt4 == 1)
            {
                mostraMenu();
            }
            if(opt4 == 2)
            {
                exit(EXIT_SUCCESS);
            }
        }
        if(opt4 == 3){
            mostraMenu();
        }
        else
            mostraMenuPorto();
    }

};

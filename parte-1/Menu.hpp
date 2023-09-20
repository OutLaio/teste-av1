#if !defined(MENU_HPP)
#define MENU_HPP

#include<iostream>
#include<string>
#include<vector>

// Incluindo bibliotecas próprias com funcões criadas para o devido objetivo proposto
#include "Veiculo.hpp"
#include "Locacao.hpp"
#include "Data.hpp"
#include "Cliente.hpp"
#include "Utilitarios.hpp"

using namespace std;

// Esta biblioteca foi criada para conter funcões relacionadas a manipulacao de menu

/*  A funcao dispMenuCliente imprime na tela do usuario as opcões disponiveis relacionadas ao cliente
    e solicita que o usuario escolha uma, caso o usuario digite uma opcao nao disponivel e solicitado
    novamente ao usuario que escolha uma opcao disponivel, ao informar uma das opcões a funcao retorna
    a escolha do usuario.
*/
int dispMenuCliente(){
    int op = 0;
    Data data = getDataAtual();

    limpaTela();
    cout << "********* LocaFINA S/A *********" << endl;
    cout << "\t" << data.toString() << endl;
    cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
        << "#1. Incluir um novo cliente" << endl
        << "#2. Excluir um cliente" << endl
        << "#3. Alterar (apenas por CPF)" << endl 
        << "#4. Listar todos os clientes" << endl 
        << "#5. Localizar um cliente (por CPF)" << endl 
        << "#0. Sair" << endl << endl
        << "> # ";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 5){
        limpaTela();
        cout << "********* LocaFINA S/A *********" << endl;
        cout << "\t" << data.toString() << endl;
        cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
            << "#1. Incluir um novo cliente" << endl
            << "#2. Excluir um cliente" << endl
            << "#3. Alterar (apenas por CPF)" << endl 
            << "#4. Listar todos os clientes" << endl 
            << "#5. Localizar um cliente (por CPF)" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> # ";
        cin >> op;
        limpaBuffer();
    }

    return op;
}

/*  A funcao dispMenuVeiculo imprime na tela do usuario as opcões disponiveis relacionadas ao veiculo
    e solicita que o usuario escolha uma, caso o usuario digite uma opcao nao disponivel e solicitado
    novamente ao usuario que escolha uma opcao disponivel, ao informar uma das opcões a funcao retorna
    a escolha do usuario.
*/
int dispMenuVeiculo(){
    int op = 0;
    Data data = getDataAtual();

    limpaTela();
    cout << "********* LocaFINA S/A *********" << endl;
    cout << "\t" << data.toString() << endl;
    cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
        << "#1. Incluir um novo veiculo" << endl
        << "#2. Excluir um veiculo" << endl
        << "#3. Alterar (apenas por Placa)" << endl 
        << "#4. Listar todos os veiculos" << endl 
        << "#5. Localizar um veiculo (por Placa)" << endl 
        << "#0. Sair" << endl << endl
        << "> #";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 5){
        limpaTela();
        cout << "********* LocaFINA S/A *********" << endl;
        cout << "\t" << data.toString() << endl;
        cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
            << "#1. Incluir um novo veiculo" << endl
            << "#2. Excluir um veiculo" << endl
            << "#3. Alterar (apenas por Placa)" << endl 
            << "#4. Listar todos os veiculos" << endl 
            << "#5. Localizar um veiculo (por Placa)" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> #";
        cin >> op;
        limpaBuffer();
    }
    
    return op;
}

/*
    A funcao dispMenuLocacao imprime na tela do usuario as opcões disponiveis relacionadas a Locacao
    e solicita que o usuario escolha uma, caso o usuario digite uma opcao nao disponivel e solicitado
    novamente ao usuario que escolha uma opcao disponivel, ao informar uma das opcões a funcao retorna
    a escolha do usuario.
*/
int dispMenuLocacao(){
    int op = 0;
    do{
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        cout << endl << "Escolha uma opcao abaixo:" << endl << endl
            << "#1. Incluir Locacao" << endl
            << "#2. Deletar Locacao" << endl
            << "#3. Alterar Locacao" << endl 
            << "#4. Listar Locacoes" << endl
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> # ";
        cin >> op;
    }while(op < 0 || op > 4);

    return op;
}

/*
    A funcao dispMenuOcorrencia imprime na tela do usuario as opcões disponiveis relacionadas as
    Ocorrencias e solicita que o usuario escolha uma, caso o usuario digite uma opcao nao disponivel
    e solicitado novamente ao usuario que escolha uma opcao disponivel, ao informar uma das opcões a
    funcao retorna a escolha do usuario.
*/
int dispMenuOcorrencia(){
    int op = 0;
    do{
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        cout << endl << "Escolha uma opcao abaixo:" << endl << endl
            << "#1. Incluir Ocorrencia" << endl
            << "#2. Deletar Ocorrencia" << endl
            << "#3. Alterar Ocorrencia" << endl 
            << "#4. Listar Ocorrencias por Cliente" << endl
            << "#5. Listar Ocorrencias por Veiculos" << endl
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> # ";
        cin >> op;
    }while(op < 0 || op > 5);

    return op;
}

/*
    Funcao para o menu de clientes
*/
void menuCliente(vector<Cliente> *lista){
    int opcao; // variavel que ira receber a opcao de escolha do usuario
    do{
        opcao = dispMenuCliente(); // chama o menu de clientes da biblioteca Menu e armazena a escolha do usuario
        switch (opcao){ // se o usuario escolher uma opcao dentre as diponiveis abaixo, sera chamada a funcao correspondente da biblioteca Cliente
            case 0:
                break;
            case 1:
                setCliente(lista);
                break;
            case 2:
                deleteCliente(lista);
                break;
            case 3:
                alteraCliente(lista);
                break;
            case 4:
                listaClientes(*lista);
                break;
            case 5:
                buscaCliente(*lista);
                break;
            default:
                break;
        }
    } while (opcao != 0); // o programa ira encerrar caso o usuario escolha sair, selecionando 0
}

/*
    Funcao para o menu de veiculos
*/
void menuVeiculos(vector<Veiculo> *lista){
    int op; // variavel que ira receber a opcao de escolha do usuario

    do{
        op = dispMenuVeiculo(); // chama o menu de veiculos da biblioteca Menu e armazena a escolha do usuario
        switch (op){ // se o usuario escolher uma opcao dentre as diponiveis abaixo, sera chamada a funcao correspondente da biblioteca Veiculo
            case 0:
                break;
            case 1:
                setVeiculo(lista);
                break;
            case 2:
                deleteVeiculo(lista);
                break;
            case 3:
                alteraVeiculo(lista);
                break;
            case 4:
                listaVeiculos(*lista);
                break;
            case 5:
                buscaVeiculo(*lista);
                break;
            default:
                break;
        }
    } while (op != 0); // o programa ira encerrar caso o usuario escolha sair, selecionando 0
}

/*
    Funcao para o menu de locacao
*/
void menuLocacao(vector<Locacao> *lista){
    int op; // variavel que ira receber a opcao de escolha do usuario
    do{
        op = dispMenuLocacao(); // chama o menu de Locacao e armazena a escolha do usuario
        switch (op){ // se o usuario escolher uma opcao dentre as diponiveis abaixo, sera chamada a funcao correspondente da biblioteca Veiculo
            case 0:
                break;
            case 1:
                setLocacao(lista);
                break;
            case 2:
                deleteLocacao(lista);
                break;
            case 3:
                alteraLocacao(lista);
                break;
            case 4:
                listaLocacao(*lista);
                break;
            default:
                break;
        }
    } while (op != 0); // o programa ira encerrar caso o usuario escolha sair, selecionando 0
}

/*
    Funcao para o menu de ocorrencia
*/
void menuOcorrencia(vector<Locacao> *lista){
    int op; // variavel que ira receber a opcao de escolha do usuario
    do{
        op = dispMenuOcorrencia(); // chama o menu de Locacao e armazena a escolha do usuario
        switch (op){ // se o usuario escolher uma opcao dentre as diponiveis abaixo, sera chamada a funcao correspondente da biblioteca Veiculo
        case 0:
            break;
        case 1:
            setOcorrencia(lista);
            break;
        case 2:
            deleteOcorrencia(lista);
            break;
        case 3:
            alteraOcorrencia(lista);
            break;
        case 4:
            listaOcorrenciaCliente(*lista);
            break;
        case 5:
            listaOcorrenciaVeiculo(*lista);
            break;
        default:
            break;
        }
    } while (op != 0); // o programa ira encerrar caso o usuario escolha sair, selecionando 0
}

/*
    Funcao para o menu principal
*/
int menuPrincipal(void){
    int op = 0;
    do{
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        cout << endl << "Escolha uma opcao abaixo:" << endl << endl
            << "#1. Gestao de Clientes" << endl
            << "#2. Gestao de Veiculos" << endl
            << "#3. Gestao de Ocorrencias" << endl 
            << "#4. Gestao de Locacao" << endl
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> # ";
        cin >> op;
    }while(op < 0 || op > 4);

    return op;
}

#endif // MENU_HPP
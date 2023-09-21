#if !defined(LOCACAO_HPP)
#define LOCACAO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Data.hpp"
#include "Utilitarios.hpp"
#include "Ocorrencia.hpp"

using namespace std;

// Esta biblioteca foi criada para conter funções relacionadas à manipulação das Alocações

// Definiu-se a struct a Alocação contendo os atributos necessários a ela, além de algumas funções próprias da struct.
typedef struct T_locacao{
    char Realizada;
    Data Dt_HoraRetirada;
    Data Dt_HoraEntrega;
    Cliente cliente;
    Veiculo veiculo;
    Ocorrencia ocorrencia;
}Locacao; // optou-se pela utilização de um typedef para definir o nome da struct como Alocacao

int indexLocacao(vector<Locacao> lista){
    string cpf, placa;
    
    cout << "Informe o CPF do cliente (apenas numeros): ";
    getline(cin, cpf);
    while(cpf.size() > 11 || cpf.size() < 9){
        cout << "Digite um CPF valido (apenas numeros): ";
        getline(cin, cpf);
    }
    
    cout << "Informe a placa do veiculo: ";
    getline(cin, placa);
    
    for (size_t i = 0; i < lista.size(); i++){
        if(lista[i].cliente.CPF == cpf && lista[i].veiculo.Placa == placa)
            return i;
    }
    
    cout << "O cliente e o veiculo nao coincidem em uma locacao." << endl;
    pausa_tela();
    return -1;
}

void setOcorrencia(vector<Locacao> *lista){
    Ocorrencia nova;
    int idLoc;
    
    limpaTela();
    cout << "********* Cadastro de Ocorrencia *********" << endl << endl;
    
    idLoc = indexLocacao(*lista);
    if(idLoc < 0)
        return;
    if((*lista)[idLoc].ocorrencia.ativa == 's'){
        cout << "A locacao ja possui uma ocorrencia registrada!" << endl;
        pausa_tela();
        return;
    }
    cout << "Informe a data da ocorrencia:" <<  endl;
    setData(&nova.data_hora);
    while (!nova.data_hora.isData()){
        cout << "Informe uma data valida:" << endl;
        setData(&nova.data_hora);
    }
    
    cout << "Informe o numero da apolice: ";
    getline(cin, nova.apolice);
    
    cout << "Descreva a ocorrencia: ";
    getline(cin, nova.descricao);

    nova.ativa = 's';
    
    (*lista)[idLoc].ocorrencia = nova;

    limpaTela();
    
    cout << "********* Cadastro de Ocorrencia *********" << endl << endl;
    cout << "Ocorrencia cadastrada com sucesso!" << endl;
    pausa_tela();
    return;
}

void setOcorrenciaByVeiculo(vector<Locacao> *lista){
    string placa;
    Ocorrencia nova;
    int k;
    
    limpaTela();
    cout << "********* Cadastro de Ocorrencia *********" << endl << endl;
    cout << "Informe a placa do veiculo: ";
    getline(cin, placa);
    
    nova = addOcorrencia();

    for (size_t i = 0; i < lista->size(); i++){
        if((*lista)[i].veiculo.Placa.compare(placa) == 0){
            if((*lista)[i].ocorrencia.ativa == 'n'){
                k++;
                (*lista)[i].ocorrencia = nova;
            }
        }
    }
    if(k == 0){
        cout << "Nao ha locacoes registradas para o veiculo informado!" << endl;
        pausa_tela();
        return;
    }
    cout << "********* Cadastro de Ocorrencia *********" << endl << endl;
    cout << "Ocorrencia cadastrada com sucesso!" << endl;
    pausa_tela();
    return;
}

void deleteOcorrencia(vector<Locacao> *lista){
    char op;
    Ocorrencia nula;
    limpaTela();
    int idLoc = indexLocacao(*lista);
    if(idLoc < 0)
        return;
    if((*lista)[idLoc].ocorrencia.ativa == 'n'){
        cout << "A locacao nao possui uma ocorrencia ativa registrada!" << endl;
        pausa_tela();
        return;
    }
    (*lista)[idLoc].ocorrencia.dispDadosOcorrencia();
    cout << "Deseja remover esta ocorrencia? ([S]im / [N]ao)" << endl << "> ";
    cin >> op;
    limpaBuffer();
    if(toupper(op) == 'S'){
        (*lista)[idLoc].ocorrencia = nula;
        cout << "Ocorrencia removida com sucesso!";
        pausa_tela();
    }
    return;
}

void alteraOcorrencia(vector<Locacao> *lista){
    string texto;
    int op;
    
    limpaTela();
    int idLoc = indexLocacao(*lista);
    if(idLoc < 0){
        return;
    }
    if((*lista)[idLoc].ocorrencia.ativa == 'n'){
        cout << "A locacao nao possui uma ocorrencia ativa registrada!" << endl;
        pausa_tela();
        return;
    }

    (*lista)[idLoc].ocorrencia.dispDadosOcorrencia();

    do{
        op = dispAlteraOcorrencia();
        switch (op){
        case 1:
            cout << "Informe a nova data da ocorrencia:" << endl;
            setData(&(*lista)[idLoc].ocorrencia.data_hora);
            while(!(*lista)[idLoc].ocorrencia.data_hora.isData()){
                cout << "Informe uma data valida:" << endl;
                setData(&(*lista)[idLoc].ocorrencia.data_hora);
            }
            cout << "Informe o novo horario da ocorrencia:" << endl;
            setHora(&(*lista)[idLoc].ocorrencia.data_hora);
            while(!(*lista)[idLoc].ocorrencia.data_hora.isHora()){
                cout << "Informe um horario valida:" << endl;
                setHora(&(*lista)[idLoc].ocorrencia.data_hora);
            }
            break;
        case 2:
            cout << "Informe o novo numero da apolice:" << endl << "> ";
            getline(cin, texto);
            (*lista)[idLoc].ocorrencia.apolice = texto;
            break;
        case 3:
            cout << "Informe a nova descricao:" << endl << "> ";
            getline(cin, texto);
            (*lista)[idLoc].ocorrencia.descricao = texto;
            break;
        default:
            break;
        }
        if(op != 0){
            cout << "Alteracoes realizadas com sucesso!" << endl;
            cout << "Deseja outra alteração? ([1]Sim / [0]Nao)" << endl << "> ";
            cin >> op;
            limpaBuffer();
        }
    } while (op != 0);
}

void listaOcorrenciaCliente(vector<Locacao> lista){
    string cpf;
    int k = 0;

    limpaTela();
    cout << "Informe o CPF do cliente (apenas numeros): ";
    getline(cin, cpf);
    while(cpf.size() > 11 || cpf.size() < 9){
        cout << "Digite um CPF valido (apenas numeros): ";
        getline(cin, cpf);
    }

    for (size_t i = 0; i < lista.size(); i++){
        if(lista[i].cliente.CPF.compare(cpf) == 0){
            k++;
            lista[i].ocorrencia.dispListaOcorrencia(k);
        }
    }
    if(k == 0){
        cout << "Nao ha ocorrencias registradas para o CPF informado!" << endl;
        pausa_tela();
        return;
    }
    pausa_tela();
    return;
}

void listaOcorrenciaVeiculo(vector<Locacao> lista){
    string placa;
    int k = 0;
    
    limpaTela();
    cout << "Informe a placa do veiculo: ";
    getline(cin, placa);

    for (size_t i = 0; i < lista.size(); i++){
        if(lista[i].veiculo.Placa.compare(placa) == 0){
            if(lista[i].ocorrencia.ativa == 's'){
                k++;
                lista[i].ocorrencia.dispListaOcorrencia(k);
            }
        }
    }
    if(k == 0){
        cout << "Nao ha ocorrencias registradas para o veiculo informado!" << endl;
        pausa_tela();
        return;
    }
    pausa_tela();
    return;
}

#endif
#if !defined(OCORRENCIA_HPP)
#define OCORRENCIA_HPP

#include<iostream>
#include<string>
#include <vector>
#include "Data.hpp"
#include "Utilitarios.hpp"
#include "Cliente.hpp"
#include "Veiculo.hpp"

using namespace std;

typedef struct T_ocorrencia{
    char ativa = 'n';
    string descricao;
    Data data_hora;
    string apolice;
    
    void dispDadosOcorrencia(){
        limpaTela();
        cout << "********* Dados da Ocorrencia *********" << endl << endl;
        cout << "Data da ocorrencia: " << this->data_hora.toString() << endl
            << "Numero da apolice: " << this->apolice << endl
            << "Descricao: " << this->descricao << endl;
        getchar();
    }

    void dispListaOcorrencia(int id){
        cout << endl << "********* Dados da Ocorrencia #" << id
            << " *********" << endl << endl;
        cout << "Data da ocorrencia: " << this->data_hora.toString() << endl
            << "Numero da apolice: " << this->apolice << endl
            << "Descricao: " << this->descricao << endl;
    }
} Ocorrencia;

int dispAlteraOcorrencia(void){
    int op = 0;

    limpaTela();
    cout << endl << "O que deseja alterar?" << endl << endl
        << "#1. Data e hora da ocorrencia" << endl
        << "#2. Numero da apolice" << endl
        << "#3. Descricao da ocorrencia" << endl 
        << "#0. Sair" << endl << endl
        << "> #";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 3){
        limpaTela();
        cout << endl << "O que deseja alterar?" << endl << endl
            << "#1. Data e hora da ocorrencia" << endl
            << "#2. Numero da apolice" << endl
            << "#3. Descricao da ocorrencia" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> #";
        cin >> op;
        limpaBuffer();
    }
    
    return op;
}



#endif
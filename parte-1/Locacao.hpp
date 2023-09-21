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
    char Realizada = 'n';
    char Entrega = 'n';
    Data Dt_HoraRetirada;
    Data Dt_HoraEntrega;
    Cliente cliente;
    Veiculo veiculo;
    Ocorrencia ocorrencia;

    void dispDadosOcorrencia(){
        limpaTela();
        cout << "********* Dados da Locacao *********" << endl << endl
            << "Data da retirada: " << this->Dt_HoraRetirada.getHora()
            << " " << this->Dt_HoraRetirada.toString() << endl
            << "Situacao da retirada: " << this->getRetirada() << endl << endl
            << "Data da entrega: " << this->Dt_HoraEntrega.getHora()
            << " " << this->Dt_HoraEntrega.toString() << endl
            << "Situacao da entrega: " << this->getEntrega() << endl << endl
            << "=========     Veiculo      =========" << endl
            << "Placa do veiculo: " << this->veiculo.Placa << endl
            << "Numero do renavan: " << this->veiculo.Renavan << endl
            << "Loja de retirada: " << this->veiculo.Loja_Retirada << endl << endl
            << "=========     Cliente      =========" << endl
            << "Nome do cliente: " << this->cliente.Nome << endl
            << "CPF: " << this->cliente.getCPF() << endl
            << "CNH: " << this->cliente.CNH << endl;
        getchar();
    }

    void dispListaOcorrencia(int id){
        cout << endl << "******* Dados da Ocorrencia #" << id << " ********" << endl << endl
            << "Data da retirada: " << this->Dt_HoraRetirada.getHora()
            << " " << this->Dt_HoraRetirada.toString() << endl
            << "Situacao da retirada: " << this->getRetirada() << endl << endl
            << "Data da entrega: " << this->Dt_HoraEntrega.getHora()
            << " " << this->Dt_HoraEntrega.toString() << endl
            << "Situacao da entrega: " << this->getEntrega() << endl << endl
            << "=========     Veiculo      =========" << endl
            << "Placa do veiculo: " << this->veiculo.Placa << endl
            << "Numero do renavan: " << this->veiculo.Renavan << endl
            << "Loja de retirada: " << this->veiculo.Loja_Retirada << endl << endl
            << "=========     Cliente      =========" << endl
            << "Nome do cliente: " << this->cliente.Nome << endl
            << "CPF: " << this->cliente.getCPF() << endl
            << "CNH: " << this->cliente.CNH << endl;
    }

    string getRetirada(){
        return (this->Realizada == 's') ? "REALIZADA" : "NAO REALIZADA";
    }

    string getEntrega(){
        return (this->Entrega == 's') ? "REALIZADA" : "NAO REALIZADA";
    }

} Locacao; // optou-se pela utilização de um typedef para definir o nome da struct como Alocacao

Cliente addCliente(string cpf, vector<Cliente> lista){
    int id = indexCliente(cpf, lista);
    return lista[id];
}

Veiculo addVeiculo(string placa, vector<Veiculo> lista){
    int id = indexVeiculo(placa, lista);
    return lista[id];
}

/*
    F
*/
void setLocacao(vector<Locacao> *lista, vector<Cliente> clientes, vector<Veiculo> veiculos){
    string cpf, placa;
    Locacao novo;
    char op;
    
    limpaTela();
    cout << "********* Cadastro de Locacao *********" << endl << endl;
    cout << "Informe o CPF do cliente: ";
    getline(cin, cpf);
    while((cpf.size() > 11 || cpf.size() < 9) || !hasCPF(cpf, clientes)){
        cout << "CPF invalido ou nao cadastrado!" << endl;
        cout << "Deseja tentar novamente? ([S]im / [N]ao)" << endl << ">";
        cin >> op;
        limpaBuffer();
        if(toupper(op) != 'S')
            return;
        limpaTela();
        cout << "********* Cadastro de Locacao *********" << endl << endl;
        cout << "Informe o CPF do cliente: ";
        getline(cin, cpf);
    }

    limpaTela();
    cout << "********* Cadastro de Locacao *********" << endl << endl;
    cout << "Informe a placa do veiculo: ";
    getline(cin, placa);
    while(!hasPlaca(placa, veiculos)){
        cout << "Placa nao cadastrada no sistema!" << endl;
        cout << "Deseja tentar novamente? ([S]im / [N]ao)" << endl << ">";
        cin >> op;
        limpaBuffer();
        if(toupper(op) != 'S')
            return;
        limpaTela();
        cout << "********* Cadastro de Locacao *********" << endl << endl;
        cout << "Informe a placa do veiculo: ";
        getline(cin, placa);
    }

    novo.cliente = addCliente(cpf, clientes);
    novo.veiculo = addVeiculo(placa, veiculos);

    limpaTela();
    cout << "********* Cadastro de Locacao *********" << endl << endl;
    cout << "Informe a data da retirada:" << endl;
    setHora(&novo.Dt_HoraRetirada);
    while(!novo.Dt_HoraRetirada.isHora()){ // Caso o usuário informe uma hora inválida, será solicitado um novo horario
        cout << "Informe uma hora valida:" << endl;
        setHora(&novo.Dt_HoraRetirada);
    }
    setData(&novo.Dt_HoraRetirada);
    while(!novo.Dt_HoraRetirada.isData()){ // Caso o usuário informe uma data inválida, será solicitado uma nova data
        cout << "Informe uma data valida:" << endl;
        setData(&novo.Dt_HoraRetirada);
    }

    do{
        limpaTela();
        cout << "********* Cadastro de Locacao *********" << endl << endl;
        cout << "A retirada ja foi realizada? ([S]im / [N]ao)" << endl;
        cin >> op;
        limpaBuffer();
    } while (tolower(op) != 's' && tolower(op) != 'n');
    
    novo.Realizada = op;

    (*lista).push_back(novo);
    cout << "********* Cadastro de Locacao *********" << endl << endl;
    cout << "Locacao cadastrada com sucesso!" << endl;
    getchar();
}

// Deletar locacao
void deleteLocacao(vector<Locacao> *lista, vector<Cliente> clientes, vector<Veiculo> veiculos){
    string placa;
    string CPF_t;

    limpaTela();
    cout << "********* Deletar  Locacao *********" << endl << endl;
    cout << "Informe a placa do veiculo: ";
    getline(cin, placa);

    while(!hasPlaca(placa, veiculos)){
        char op;
        cout << "Placa nao cadastrada no sistema!" << endl;
        cout << "Deseja tentar novamente? ([S]im / [N]ao)" << endl << ">";
        cin >> op;
        limpaBuffer();
        if(toupper(op) != 'S')
            return;
        limpaTela();
        cout << "********* Deletar Locacao *********" << endl << endl;
        cout << "Informe a placa do veiculo: ";
        getline(cin, placa);
    }
    cout << endl << "Locacoes do veiculo com placa " << placa << endl;
    for(size_t i=0; i<(*lista).size(); i++){
        if(lista->at(i).veiculo.Placa==placa){
            cout << "Locacao " << i << endl;
            cout << endl << "CPF do clinte: "
                << lista->at(i).cliente.CPF << endl
                << "Renavan do veiculo: "
                << lista->at(i).veiculo.Renavan << endl << endl;
            }
    }
    cout << endl << "Informe o CPF do cliente: ";
    getline(cin, CPF_t);
    while((CPF_t.size() > 11 || CPF_t.size() < 9) || !hasCPF(CPF_t, clientes)){
        char op;
        cout << "CPF invalido ou nao cadastrado!" << endl;
        cout << "Deseja tentar novamente? ([S]im / [N]ao)" << endl << ">";
        cin >> op;
        limpaBuffer();
        if(toupper(op) != 'S')
            return;
        limpaTela();
        cout << "********* Cadastro de Locacao *********" << endl << endl;
        cout << "Informe o CPF do cliente: ";
        getline(cin, CPF_t);
    }
    
    for(size_t i=0; i<(*lista).size(); i++){
        if(lista->at(i).cliente.CPF==CPF_t){
            lista->erase(lista->begin()+i);
            cout << "Locacao deletada com sucesso!" << endl;
        }
    }
}

void alteraLocacao(vector<Locacao> *lista, vector<Cliente> clientes, vector<Veiculo> veiculos){
    string placa;
    string CPF_t;

    limpaTela();
    cout << "********* ALtera Locacao *********" << endl << endl;
    cout << "Informe a placa do veiculo: ";
    getline(cin, placa);

    while(!hasPlaca(placa, veiculos)){
        char op;
        cout << "Placa nao cadastrada no sistema!" << endl;
        cout << "Deseja tentar novamente? ([S]im / [N]ao)" << endl << ">";
        cin >> op;
        limpaBuffer();
        if(toupper(op) != 'S')
            return;
        limpaTela();
        cout << "********* Altera Locacao *********" << endl << endl;
        cout << "Informe a placa do veiculo: ";
        getline(cin, placa);
    }
    cout << endl << "Lista de todos os passageiros que tem reserva com esse veiculo de placa: " << placa << endl;
    for(size_t i=0; i<(*lista).size(); i++){
        if(lista->at(i).veiculo.Placa==placa){
            cout << "Cliente locacao: " << i << endl;
            cout << endl << "CPF do clinte: "
                << lista->at(i).cliente.CPF << endl
                << "Nome do cliente: "
                << lista->at(i).cliente.Nome << endl;
            }
    }
    cout << endl << "Informe o CPF do cliente: ";
    getline(cin, CPF_t);
    while((CPF_t.size() > 11 || CPF_t.size() < 9) || !hasCPF(CPF_t, clientes)){
        char op;
        cout << "CPF invalido ou nao cadastrado!" << endl;
        cout << "Deseja tentar novamente? ([S]im / [N]ao)" << endl << ">";
        cin >> op;
        limpaBuffer();
        if(toupper(op) != 'S')
            return;
        limpaTela();
        cout << "********* Cadastro de Locacao *********" << endl << endl;
        cout << "Informe o CPF do cliente: ";
        getline(cin, CPF_t);
    }

    for(size_t i=0; i<(*lista).size(); i++){
        if(lista->at(i).cliente.CPF==CPF_t){
            cout << "Digite uma nova data de entrega: " << endl;
            setData(&(*lista).at(i).Dt_HoraEntrega);
        }
    }
}

void listaLocacao(vector<Locacao> lista){
    limpaTela();
    cout << "Lista de locacoes realizadas: " << endl;
    if(lista.size() == 0){
        cout << "Nenhuma locação registrada!" << endl;
        pausa_tela();
        return;
    }
    for(size_t i=0; i<lista.size(); i++){
        if(lista.at(i).Realizada=='s'){
            cout << "Nome do cliente: " << lista.at(i).cliente.Nome << endl;
            cout << "Renavan do carro: " << lista.at(i).veiculo.Renavan << endl;
            cout << "Dt_Hora Retirada: " << lista.at(i).Dt_HoraRetirada.toString() << endl;
            cout << "Dt_Hora Entrega: " << lista.at(i).Dt_HoraEntrega.toString() << endl;
        }
    }
    cout << "Lista de locacoes ainda não realizadas: " << endl;
    for(size_t i=0; i<lista.size(); i++){
        if(lista.at(i).Realizada=='n'){
            cout << "Nome do cliente: " << lista.at(i).cliente.Nome << endl;
            cout << "Renavan do carro: " << lista.at(i).veiculo.Renavan << endl;
            cout << "Dt_Hora Retirada: " << lista.at(i).Dt_HoraRetirada.toString() << endl;
            cout << "Dt_Hora Entrega: " << lista.at(i).Dt_HoraEntrega.toString() << endl;
        }
    }
    pausa_tela();
}

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
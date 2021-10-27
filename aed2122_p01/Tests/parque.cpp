#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned lot, unsigned nMaxCli): lotacao(lot), numMaximoClientes(nMaxCli){
    vagas = lotacao;
}

unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    for (int i = 0; i < clientes.size(); i++){
        if (clientes.at(i).nome == nome){
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome){
    if (clientes.size() == numMaximoClientes){
        return false;
    }
    else{
        InfoCartao nCliente;
        nCliente.nome = nome;
        nCliente.presente = false;
        clientes.push_back(nCliente);
    }
    return true;
}

bool ParqueEstacionamento::entrar(const string & nome){
    if (posicaoCliente(nome) == -1){
        return false;
    }
    else if (clientes.at(posicaoCliente(nome)).presente){
        return false;
    }
    else if(vagas == 0){
        return false;
    }
    else{
        clientes.at(posicaoCliente(nome)).presente = true;
        vagas--;
    }
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome){
    if (posicaoCliente(nome) == -1){
        return false;
    }
    else if(clientes.at(posicaoCliente(nome)).presente){
        return false;
    }
    else{
        clientes.erase(clientes.begin() + posicaoCliente(nome));
    }
    return true;
}

bool ParqueEstacionamento::sair(const string & nome){
    if (posicaoCliente(nome) == -1){
        return false;
    }
    else if (!clientes.at(posicaoCliente(nome)).presente){
        return false;
    }
    else{
        clientes.at(posicaoCliente(nome)).presente = false;
        vagas++;
    }
    return true;
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}







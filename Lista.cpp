#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};


void IncluirFuncionario(vector<Funcionario>& lista) {
    Funcionario novoFuncionario;
    cout << "Digite o prontuario, por favor apenas numeros: ";
    cin >> novoFuncionario.prontuario;
    
    
    auto it = find_if(lista.begin(), lista.end(), [&](const Funcionario& f) {
        return f.prontuario == novoFuncionario.prontuario;
    });

    if (it != lista.end()) {
        cout << "Funcionario com prontuario " << novoFuncionario.prontuario << " ja existe." << endl;
        return;
    }

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, novoFuncionario.nome);
    cout << "Digite o salario: ";
    cin >> novoFuncionario.salario;

    lista.push_back(novoFuncionario);
    cout << "Funcionario adicionado com sucesso." << endl;
}


void ExcluirFuncionario(vector<Funcionario>& lista) {
    int prontuario;
    cout << "Digite o prontuario do funcionario a ser excluido: ";
    cin >> prontuario;

    auto it = find_if(lista.begin(), lista.end(), [&](const Funcionario& f) {
        return f.prontuario == prontuario;
    });

    if (it != lista.end()) {
        lista.erase(it);
        cout << "Funcionario excluido com sucesso." << endl;
    } else {
        cout << "Funcionario com prontuario " << prontuario << " nao encontrado." << endl;
    }
}

void PesquisarFuncionario(const vector<Funcionario>& lista) {
    int prontuario;
    cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    cin >> prontuario;

    auto it = find_if(lista.begin(), lista.end(), [&](const Funcionario& f) {
        return f.prontuario == prontuario;
    });

    if (it != lista.end()) {
        cout << "Funcionario encontrado:" << endl;
        cout << "Prontuario: " << it->prontuario << endl;
        cout << "Nome: " << it->nome << endl;
        cout << "Salario: " << it->salario << endl;
    } else {
        cout << "Funcionario com prontuario " << prontuario << " nao encontrado." << endl;
    }
}


void ListarFuncionarios(const vector<Funcionario>& lista) {
    cout << "Lista de Funcionarios:" << endl;
    for (const auto& funcionario : lista) {
        cout << "Prontuario: " << funcionario.prontuario << ", Nome: " << funcionario.nome << ", Salario: " << funcionario.salario << endl;
    }

    double totalSalarios = 0;
    for (const auto& funcionario : lista) {
        totalSalarios += funcionario.salario;
    }
    cout << "Total dos Salarios: " << totalSalarios << endl;
}

int main() {
    vector<Funcionario> listaFuncionarios;
    int opcao;

    do {
        cout << "\nMENU\n";
        cout << "0. Sair\n";
        cout << "1. Incluir\n";
        cout << "2. Excluir\n";
        cout << "3. Pesquisar\n";
        cout << "4. Listar\n";
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                IncluirFuncionario(listaFuncionarios);
                break;
            case 2:
                ExcluirFuncionario(listaFuncionarios);
                break;
            case 3:
                PesquisarFuncionario(listaFuncionarios);
                break;
            case 4:
                ListarFuncionarios(listaFuncionarios);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}

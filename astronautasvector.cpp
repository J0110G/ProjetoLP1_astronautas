#include <iostream>
#include <string>
#include <vector>
using namespace std;
//teste
class astronauta {
public:
    string cpf;
    string nome;
    int idade;
    int morto = 0;
    int indisponivel = 0;

    void criar_astronauta() {
        cout << "Digite o cpf:" << endl;
        cin >> cpf;
        cout << "o nome:" << endl;
        cin >> nome;
        cout << "a idade:" << endl;
        cin >> idade;
    }
};

class voo {
public:
    int codigo;
    int planejado = 0;
    int em_curso = 0;
    int finalizado = 0;
    int explodido = 0;
    vector<string> passageiros;

    void criar_voo(){
        string cpf;
        cout << "Digite o código do voo:" << endl;
        cin >> codigo;
        cout << "e quem estará nele (cpf):" << endl;
        cin >> cpf;
        adicionar_astronauta(cpf);
    };
    void adicionar_astronauta(string& cpf) {
        passageiros.push_back(cpf);

    }
    void listar_passageiros() {
        for (string& cpf : passageiros) {
            cout << cpf << " ";
        }
        cout << endl;
    }
    void lancar_voo(){
        int codigo;
        cout << "Digite o voo (código):" << endl;
        cin >> codigo;

    }
    void explodir(){
        
    }
};

int main() {
    int x;
    vector<astronauta> vetor_a; 
    vector<voo> vetor_v;

    do {
        cout << "O que deseja fazer:" << endl
             << "1-Cadastrar Astronauta" << endl
             << "2-Cadastrar Voo" << endl
             << "3-Adicionar Astronauta em Voo" << endl
             << "4-Remover Astronauta de um Voo" << endl
             << "5-Lançar um voo" << endl
             << "6-Explodir um Voo" << endl
             << "7-Finalizar um um voo" << endl
             << "8-Listar todos os voos" << endl
             << "9-Listar astronautas mortos" << endl
             << "0-Parar sistema" << endl;

        cin >> x;

        if (x == 1) {
            astronauta a;
            a.criar_astronauta();
            vetor_a.push_back(a);

        } else if (x == 2) {
            voo v;
            v.criar_voo();
            v.planejado++;
            vetor_v.push_back(v);

        } else if (x == 3){
            int codigo_voo;
            string cpf;
            cout << "Digite o código do voo:" << endl;
            cin >> codigo_voo;
            cout << "Digite o CPF do astronauta:" << endl;
            cin >> cpf;

            int voo_encontrado = 0;
            for (voo& v : vetor_v) {
                if (v.codigo == codigo_voo) {
                    voo_encontrado++;
                    int astronauta_encontrado = 0;
                    for (astronauta& a : vetor_a) {
                        if ((a.cpf == cpf) && (a.indisponivel == 0)) {
                            astronauta_encontrado++;
                            v.adicionar_astronauta(cpf);
                            cout << "Astronauta adicionado ao voo." << endl;
                            break;
                        } 
                    }
                    if (astronauta_encontrado != 1) {
                        cout << "Astronauta não encontrado ou indisponível." << endl;
                    }
                    break;
                }
            }
            if (voo_encontrado != 1) {
                cout << "Voo não encontrado." << endl;
            }
        } else if (x == 4){
            /* code */
        } else if (x == 5){
            /* code */
        } else if (x == 6){
            /* code */
        } else if (x == 7){
            /* code */
        } else if (x == 8){
            cout << "Voos cadastrados:" << endl;
            for (voo& v : vetor_v) {
                if(v.planejado == 1){
                    cout << "Planejado:";
                } else if (v.em_curso == 1){
                    cout << "Em curso:";
                } else if ((v.finalizado == 1) && (v.explodido == 0)){
                    cout << "Finalizado com sucesso:";
                } else if ((v.finalizado == 1) && (v.explodido == 1)){
                    cout << "Explodiu:";
                }
                
                cout << "Código: " << v.codigo << " Passageiros(CPF): ";
                v.listar_passageiros();
            }

        } else if (x == 9){
            cout << "Astronautas mortos:" << endl;
            for (astronauta& a : vetor_a) {
                if (a.morto == 1){
                    cout << "CPF: " << a.cpf << " Nome: " << a.nome << " Idade: " << a.idade << endl;
                
                }
            }
        }
        cout << endl;
    } while (x != 0);

    return 0;
}
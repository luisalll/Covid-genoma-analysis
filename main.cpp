#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

//Classe Hash Table;
class HashTable{
    private:
        //Classe Node;
        class Node{
            public:
                string bloco;
                int quantasvezes;
                Node* proximo;

                //Contrutor do Nó
                Node(string dado){
                    this->bloco = dado;
                    this->proximo = nullptr;
                    quantasvezes = 1;   //Se o bloco foi achado, ele ja aparece em quantidade 1;
                }
            };
            
            //Outros atributos;
            Node* topo;
            Node* fim;
            vector<string> blocos;  //Vetor usado para checar se o bloco ja foi inserido na Hash;

    //Construtor da Hash;
    public:
    HashTable(){
        topo = fim = nullptr;
    }
    //Destrutor da Hash (deletando um node até o topo for nulo);
    ~HashTable(){
        while (topo != nullptr) {
            Node* temp = topo;
            topo = topo->proximo;
            delete temp;
        }
    }
    //Função colocar dado;
    void colocar(string dado){
        //Se a Hash estiver vazia, cria o novo node e torna ele 'topo' e 'fim';
        if(topo == nullptr){
            Node *novo_no = new Node(dado);
            topo = fim = novo_no;
            blocos.push_back(dado);
        }else{
            //Se o bloco procurado ja existir no vetor blocos (impede de colocar um bloco que já apareceu em outro Node):
            if(find(blocos.begin(), blocos.end(), dado) != blocos.end()){
                //Ponteiro para percorrer a Hash;
                Node *atual = topo;
                //Percorre todos Nodes;
                while(atual != nullptr){
                    if(atual->bloco == dado){
                        atual->quantasvezes++;  //Incrementa a quantidade do Node que o 'bloco' for iguao ao dado;
                        return;
                    }
                    atual=atual->proximo;
                }
            //Caso o dado buscado não esteja ainda no0 vetor 'blocos';
            }else{
                //Cria novo Node com o dado e ele vira o novo 'fim1;
                Node *novo_no = new Node(dado);
                fim->proximo = novo_no;
                fim = novo_no;
                blocos.push_back(dado);
            }
        }   
    }
    //Função para impressão da Hash -> Exemplo::  AAAAAA (bloco): 3 (quantidade);
    void imprimir(){
        Node *atual = topo;
        while(atual != nullptr){
            cout<<atual->bloco<<" : "<<atual->quantasvezes<<endl;
            atual = atual->proximo;
        }
    }
};

//Função para dividir a entradas em blocos dm 6 caracteres cada;
vector<string> dividir_os_blocos(string entrada) {
    vector<string> blocos;
    for (size_t i = 0; i < entrada.length(); i += 6) {
        blocos.push_back(entrada.substr(i, 6));
    }
    return blocos;
}

//Execução do Programa;
int main(){
    HashTable *mapear_genoma = new HashTable();

    //Número de linhas do Genoma;
    int quantas_linhas;
    cin >> quantas_linhas;
    //Para cada linha de entrada do genoma (parado Covid-19 deve colocar 498 na entrada 'linhas');
    for(int a = 0; a < quantas_linhas; a++){
        string linha;
        cin>> linha;

        //Dividindo cada entrada nos blocos;
        vector<string> genoma = dividir_os_blocos(linha);

        //Para cada bloco no vetor 'genoma', é colocado na função 'colocar' da Hash;
        for(const string& bloco : genoma){
            mapear_genoma->colocar(bloco);
        }
    }

    //Impressão da Hash 'mapear_genoma' completo;
    mapear_genoma->imprimir();
    delete mapear_genoma;
}
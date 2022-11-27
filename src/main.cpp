#include "../Config/contract.hpp"

using namespace std;

int main(){
    Indice indice;
    string continua;
    string fraseABuscar;

    while(continua != "n"){
        cout << "Digite as palavras a serem buscadas nos documentos: ";
        getline(cin, fraseABuscar);
        set<string> recuperados = indice.recuperacao(fraseABuscar);
        if(recuperados.empty()){
            cout << endl << "Não existem documentos contendo todas as palavras inseridas" << endl;
        }else{
            cout << endl << "Documentos que contém as palavras: " << fraseABuscar << endl;
            for(string documento : recuperados){
                cout << documento << endl;
            }
        }
        cout << endl;
        cout << "Deseja buscar mais alguma frase? (s/n)" << endl;
        getline(cin, continua);
        cout << endl;
    }

    return 0;
}
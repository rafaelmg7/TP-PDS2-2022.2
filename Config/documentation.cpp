#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include "contract.hpp"

using namespace std;

int normalizaCaracter(int valorAsc){
    if((valorAsc >= 192 && valorAsc <= 197) || (valorAsc >= 224 && valorAsc <= 229)){
        valorAsc = 97;
    }else if((valorAsc >= 200 && valorAsc <= 203) || (valorAsc >= 232 && valorAsc <= 235)){
        valorAsc = 101;
    }else if((valorAsc >= 204 && valorAsc <= 207) || (valorAsc >= 236 && valorAsc <= 239)){
        valorAsc = 105;
    }else if((valorAsc >= 210 && valorAsc <= 214) || (valorAsc >= 242 && valorAsc <= 246)){
        valorAsc = 111;
    }else if((valorAsc >= 217 && valorAsc <= 220) || (valorAsc >= 249 && valorAsc <= 252)){
        valorAsc = 117;
    }
    // Se a letra for maiúscula, põe o código da minúscula
    else if (valorAsc >= 65 && valorAsc <= 90){
        valorAsc += 32;
    }
    // Se o carácter for algum especial indesejado, o remove.
    else if((valorAsc < 97 || valorAsc > 122)){
        valorAsc = 32;
    }
    return valorAsc;
}

string normalizaPalavra(string palavra){
    string novo;

    for(int i = 0; i < palavra.length(); i++){
        string atual = palavra.substr(i, 2);
        int codigoLetra = int((unsigned char)atual[0]);

        // Se a letra não estiver no padrão desejada (minúscula, sem acento ou caracter especial), a altera ou remove.
        if(codigoLetra < 97 || codigoLetra > 122){
            
            // Variável que conterá o código para o caracter a ser normalizado.
            int num = 0;

            // Se a letra tiver um acento, codigoLetra indicará isso (estando além dos valores ASCII tradicionais)
            // e atual[1] indicará qual é o acento.
            if(codigoLetra > 127){
                num = int((unsigned char)atual[1]) + 64;
                
                // Como a próxima dupla de caracteres terá como primeiro elemento um "indicador" de acento, incrementa o 'i'
                // para passar para a próxima
                i++;
            }else{
                num = codigoLetra;
            }

            codigoLetra = normalizaCaracter(num);

            // Se o caracter não for uma letra a-z, pula pra próxima iteração e não o insere na nova string
            if(codigoLetra == 32) continue;
        }

        novo.push_back(char(codigoLetra));
    }

    return novo;
}

Indice::Indice(){
    string path = "./documentos";
    ifstream file;

    for (const auto & entry : fs::directory_iterator(path)){
        file.open(entry.path());

        string palavra;
        while(file >> palavra){
            palavra = normalizaPalavra(palavra);
            
            if(elementos_.find(palavra) == elementos_.end()) elementos_.insert({palavra, {}});

            elementos_[palavra].insert(entry.path().filename());
        }

        file.close();
    }
}

void Indice::imprime(){
    for(map<string, set<string>>::iterator it = elementos_.begin(); it != elementos_.end(); ++it){
        cout << it->first << "   ";
        for(string doc : it->second){
            cout << doc << " | ";
        }
        cout << endl;
    }
}

set<string> Indice::recuperação(string frase){

    string temp = "";
    vector<string> v;
    // vector<string> docs;
    map<string, int> docs;
    for(auto ch : frase){
        if(ch == ' '){
            v.push_back(temp);
            temp = "";
        }else{
            temp += ch;
        }
    }

    for(string palavra : v){
        if(elementos_.find(palavra) != elementos_.end()){
            map[elementos_.find(palavra)->second] += 1;
        }
    }

    for 

    
}

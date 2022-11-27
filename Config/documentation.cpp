#include "./contract.hpp"

using namespace std;

int normalizaCaracter(int valorAsc){
    // Normaliza variações da letra a
    if((valorAsc >= 192 && valorAsc <= 197) || (valorAsc >= 224 && valorAsc <= 229)){
        valorAsc = 97;
    }
    // Normaliza variações da letra e
    else if((valorAsc >= 200 && valorAsc <= 203) || (valorAsc >= 232 && valorAsc <= 235)){
        valorAsc = 101;
    }
    // Normaliza variações da letra i
    else if((valorAsc >= 204 && valorAsc <= 207) || (valorAsc >= 236 && valorAsc <= 239)){
        valorAsc = 105;
    }
    // Normaliza variações da letra o
    else if((valorAsc >= 210 && valorAsc <= 214) || (valorAsc >= 242 && valorAsc <= 246)){
        valorAsc = 111;
    }
    // Normaliza variações da letra u
    else if((valorAsc >= 217 && valorAsc <= 220) || (valorAsc >= 249 && valorAsc <= 252)){
        valorAsc = 117;
    }
    // Normaliza 'ç'
    else if(valorAsc == 231){
        valorAsc = 99;
    }
    // Normaliza 'ñ'
    else if(valorAsc == 241){
        valorAsc = 110;
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
            // e atual[1] indicará qual é o acento. int((unsigned char)atual[1]) + 64 retorna o código para o caracter com o acento.
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
    for(auto elemento : elementos_){
        cout << elemento.first << "   ";
        for(string doc : elemento.second){
            cout << doc << " | ";
        }
        cout << endl;
    }
}

set<string> Indice::recuperacao(string frase){

    string aux;
    vector<string> palavrasFrase;
    map<string, int> docs;
    set<string> relevantes;
    int numPalavras = 0;

    // Passa por cada caracter da frase a ser buscada, de modo a buscar palavras e inserí-las no vetor "palavrasFrase"
    for(auto ch : frase){
        if(ch == ' '){
            palavrasFrase.push_back(normalizaPalavra(aux));
            aux = "";
            numPalavras++;
        }else{
            aux += ch;
        }
    }

    // Insere também a última palavra da frase no vetor
    palavrasFrase.push_back(normalizaPalavra(aux));
    numPalavras++;

    // Passa pelas palavras da frase para contar quantas delas aparecem em cada documento
    for(string palavra : palavrasFrase){
        if(elementos_.find(palavra) != elementos_.end()){

            // Guarda o nome dos documentos nos quais a palavra atual aparece e incrementa o número de palavras que aparecem em cada um
            set<string> docsComPalavra = elementos_.find(palavra)->second;
            for(string doc : docsComPalavra){
                docs[doc]++;
            }
        }

        // Se alguma das palavras a serem buscadas não existirem no índice, então não há documentos relevantes a serem retornados
        else{
            break;
        }
    }

    // Insere os documentos que contém todas as palavras no set de documentos relevantes
    for(auto doc : docs){
        if(doc.second == numPalavras){
            relevantes.insert(doc.first);
        }
    }

    return relevantes;
}

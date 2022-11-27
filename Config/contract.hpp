#ifndef __CONTRACT_H__
#define __CONTRACT_H__

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

/**
 * @brief Classe que representa um índice invertido, que mapeia cada
 * palavra às suas ocorrências nos documentos em ./documentos.
*/
class Indice {
    public:
        /**
         * @brief Passa por todas as palavras de todos os documentos, relacionando-as
         * com suas respectivas ocorrências e, assim, construindo o índice invertido.
        */
        Indice();

        /**
         * @brief Imprime cada uma das palavras presentes nos documentos, juntamente
         * aos nomes dos documentos nos quais elas aparecem.
         * Função unicamente para fins de teste; não é chamada durante a execução da
         * máquina de busca.
        */
        void imprime();

        /**
         * @brief Obtém os nomes dos documentos relevantes para uma determinada consulta.
         * Os documentos considerados relevantes são aqueles que contém todas as palavras da
         * consulta.
         * @param frase Conjunto de palavras a serem buscadas nos documentos.
         * @return Um conjunto contendo os nomes de todos os documentos relevantes para a consulta.
        */
        set<string> recuperacao(string frase);
    private:
        /**
         * @brief Contêiner que armazena a relação de palavras e os documentos nos quais
         * elas aparecem.
        */
        map<string, set<string>> elementos_;
};

/** ------------------------------------------- FUNÇÕES AUXILIARES DE NORMALIZAÇÃO --------------------------------------------------------------*/

/**
 * @brief Obtém um código ASCII de um caracter normalizado (minúsculo, sem acento e sem ser especial)
 * a partir do código do caracter indesejado.
 * @param valorAsc Código ASCII do caracter a ser normalizado.
 * @return O código ASCII para o caracter desejado.
*/
int normalizaCaracter(int valorAsc);

/**
 * @brief Passa por todos os caracteres da palavra e os normaliza, removendo todos os acentos
 * e caracteres especiais e convertendo todos os caracteres para letras minúsculas.
 * @param palavra Palavra a ser normalizada.
 * @return A palavra sem os caracteres indesejados, ou seja, padronizada.
*/
string normalizaPalavra(string palavra);

#endif // __CONTRACT_H__
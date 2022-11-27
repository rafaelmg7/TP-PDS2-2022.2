#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "contract.hpp"

TEST_CASE("int normalizaCaracter(int valorAsc)") {
    // Testes para letra a
    CHECK_EQ(normalizaCaracter(195), 97);
    CHECK_EQ(normalizaCaracter(226), 97);

    // Testes para letra e
    CHECK_EQ(normalizaCaracter(201), 101);
    CHECK_EQ(normalizaCaracter(234), 101);

    // Testes para letra i
    CHECK_EQ(normalizaCaracter(206), 105);
    CHECK_EQ(normalizaCaracter(238), 105);

    // Testes para letra o
    CHECK_EQ(normalizaCaracter(212), 111);
    CHECK_EQ(normalizaCaracter(244), 111);

    // Testes para letra u
    CHECK_EQ(normalizaCaracter(218), 117);
    CHECK_EQ(normalizaCaracter(250), 117);

    // Testes para letras maiúsculas
    CHECK_EQ(normalizaCaracter(70), 102);
    CHECK_EQ(normalizaCaracter(80), 112);
    CHECK_EQ(normalizaCaracter(90), 122);

    // Testes para outros caracteres
    CHECK_EQ(normalizaCaracter(95), 32);
    CHECK_EQ(normalizaCaracter(125), 32);
    CHECK_EQ(normalizaCaracter(255), 32);
}

TEST_CASE("string normalizaPalavra(string palavra)"){
    CHECK_EQ(normalizaPalavra("Guarda-Chuva"), "guardachuva");
    CHECK_EQ(normalizaPalavra("guarda-chuva"), "guardachuva");
    CHECK_EQ(normalizaPalavra(".g.u.a.r.d.a-c.h.u.v.a."), "guardachuva");
    CHECK_EQ(normalizaPalavra("guárdâ-chüvà."), "guardachuva");

    CHECK_EQ(normalizaPalavra("árvores"), "arvores");
    CHECK_EQ(normalizaPalavra("Pássarões"), "passaroes");
}

TEST_CASE("Testa Indice::recuperacao(string frase)"){
    Indice d;
    set<string> s;
    CHECK_EQ(d.recuperacao("palavra"), s);
    CHECK_EQ(d.recuperacao("jogo do Brasil"), s);

    s.insert("d5.txt");
    

    CHECK_EQ(d.recuperacao("Dominick V. Zurlo"), s);
    s.erase("d5.txt");
    s.insert("d1.txt");

    CHECK_EQ(d.recuperacao("newsletter"), s);
    CHECK_EQ(d.recuperacao("spirituality"), s);
    CHECK_EQ(d.recuperacao("SCREAMING"), s);
    CHECK_EQ(d.recuperacao("outrageously"), s);
    
    s.erase("d1.txt");
    s.insert("d22.txt");

    CHECK_EQ(d.recuperacao("worldwide"), s);
    CHECK_EQ(d.recuperacao("vacationers"), s);
    CHECK_EQ(d.recuperacao("FOLKS"), s);
    CHECK_EQ(d.recuperacao("aware"), s);
}
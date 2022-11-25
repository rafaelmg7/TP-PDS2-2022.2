#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Config/doctest.h"

#include "../Config/documentation.cpp"

TEST_CASE("Testa Indice::recuperacao(string frase)"){
    Indice d;
    set<string> s;
    CHECK_EQ(d.recuperacao("palavra"), s);
    CHECK_EQ(d.recuperacao("jogo do Brasil"), s);

    s.insert("d5.txt");

    CHECK_EQ(d.recuperacao("Dominick V. Zurlo"), s);
}
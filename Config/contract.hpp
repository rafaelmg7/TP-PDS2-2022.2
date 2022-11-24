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

class Indice {
    public:
        Indice();
        void imprime();
        set<string> recuperacao(string frase);
    private:
        map<string, set<string>> elementos_;
};

#endif // __CONTRACT_H__
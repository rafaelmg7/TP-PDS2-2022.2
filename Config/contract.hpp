#ifndef __CONTRACT_H__
#define __CONTRACT_H__

#include <list>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <filesystem>
using namespace std;

namespace fs = filesystem;

// using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;


class Indice {
    public:
        Indice();
        void imprime();
        
    private:
        map<string, set<string>> elementos_;
};

#endif // __CONTRACT_H__
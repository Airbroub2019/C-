#include <iostream>
#include <vector>

//compiler : g++ -Wall -Wpedantic -std=c++14    ..

std::vector<int> saisie (){
    std::vector<int> result;
    unsigned int nb;
    std::cout << "Combien de valeurs ? " ; std::cin >> nb;
    for (unsigned int i=0; i<nb; ++i) {
        std::cout << "Valeur " << i << " ";
        int e;
        std::cin >> e;
        result.push_back(e);
    }
    return result;
}

void saisie(std::vector<int> & s){
    unsigned int nb;
    std::cout << "Combien de valeurs ? " ; std::cin >> nb;
    for (unsigned int i=0; i<nb; ++i) {
        std::cout << "Valeur " << i << " ";
        int e;
        std::cin >> e;
        s.push_back(e);
    }
}

int max_indice (std::vector<int> const & v){
    int max = v[0];
    for (std::vector<int>::size_type i(1); i<v.size(); ++i)
        if (max < v[i]) max = v[i];
    return max;
}

int max_iterateur (std::vector<int> const & v){
    int max = v[0];
    for (auto i(v.begin()); i!=v.end(); ++i  ) // iterator pour modifier
                                               // const_iterator quand on modifie pas
                                               // no risque = utiliser auto
                                               // i(v.begin()+1) pour éviter le test du 1er element
         if (max < *i) max = *i;
    return max;
}

int max_interval (std::vector<int> const & v){
    int max(v[0]);
    for (auto &i : v)
          if (max < i) max = i;
    return max;
}

int main()
{
    std::vector<int>  s(saisie());

   // std::vector<int> s;
    saisie(s);
    return 0;
}

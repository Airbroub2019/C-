#include <iostream>
#include "graphe.hh"
using namespace std;

int main()
{
   sommet s("abc");
   s.ajouterarc(2,"");
   s.ajouterarc(3,"etiq");
   s.dot_etiquette(std::cout);
   s.dot_arcssortants((std::cout));
   return 0;
}

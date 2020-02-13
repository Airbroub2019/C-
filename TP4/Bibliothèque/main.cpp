#include <iostream>
#include "biblio.hh"

int main()
{
    documents * d = new periodique("Titre", "Auteur" , 100 , 5);
    std::cout << (*d) << std::endl;
    delete d;
    bibliotheque b;
    b.ajout(periodique("T", "A",100,5));
    for (std::size_t i=0 ; i<b.taille() ; ++i)
        std::cout << b.acces(i) << std::endl;
    // on peut quand meme causer un probleme en faisant : delete &b.acces(i);
    return 0;
}

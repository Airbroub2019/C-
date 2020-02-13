#include "sequence.hh"
#include <iostream>

/* pas besoin d'implémenter le constructeur par défault et le constructeur par recopie
sequence::sequence()
    :_contenu() {}

sequence::sequence(sequence const & s)
    :_contenu(s._contenu){}

sequence::~sequence(){
    delete [] _contenu;
}

*/
void sequence::ajouter(couleur c) {
   _contenu.push_back(c);

}

indicesequence sequence::taille() const {       //on aurrait pu le faire dans le .hh
    return _contenu.size();
}





void sequence::afficher(couleur c, std::ostream & os ) const {
    switch (c) {
             case couleur::rouge: os << "rouge" ; break;
             case couleur::bleu:  os << "bleu" ; break;
             case couleur::jaune: os << "jaune" ; break;
             case couleur::vert:  os << "vert" ; break;

    }
}

void sequence::afficher(couleur c) const {
    afficher (c, std::cout); //dupliquer un code est une mauvaise idée
}

couleur sequence::acces(indicesequence i) const {
    return _contenu.at(i);
}

void sequence::vider() {
    _contenu.clear();
}

void sequence::afficher(std::ostream & os) const {
    for (indicesequence i(0) ; i<taille() ; ++i) { // ou remplacer taille par _contenu.size()
        afficher(acces(i), os);
        os << " "; }
    os << "\n";
}

bool sequence::comparer(const sequence &s) const {
    return _contenu== s._contenu;                                            // regarder la dogme de vector
}

void sequence::copier(  sequence const &s) {
   _contenu = s._contenu;
}

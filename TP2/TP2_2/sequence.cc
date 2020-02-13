#include "sequence.hh"
#include <iostream>
sequence::sequence()
    :_contenu(nullptr), _taille(0) {}

void sequence::ajouter(couleur c) {
    couleur * nouveau(new couleur[_taille+1]);
    for (indicesequence i(0); i<_taille; ++i)
        nouveau[i] = _contenu[i];
    nouveau[_taille] = c;
    delete [] _contenu;
    _contenu = nouveau;
    ++ _taille;

}

indicesequence sequence::taille() const {       //on aurrait pu le faire dans le .hh
    return _taille;
}

sequence::sequence(sequence const & s)
    :_contenu ((s._taille ==0) ? nullptr : new couleur[s._taille]),     //opérateur ternaire car on peut pas utiliser un if dans un constructeur
      _taille(s._taille) {
    for (indicesequence i(0); i<_taille ; ++i)
        _contenu[i] = s._contenu[i];
}

sequence::~sequence(){
    delete [] _contenu;
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
    return _contenu[i];
}

void sequence::vider() {
    _taille = 0;
    delete [] _contenu;
    _contenu = nullptr;
}

void sequence::afficher(std::ostream & os) const {
    for (indicesequence i(0) ; i<_taille ; ++i) {
        afficher(acces(i), os);
        os << " "; }
    os << "\n";
}

bool sequence::comparer(const sequence &s) const {
    if (_taille!=s._taille)
        return false;
    else {
        for (indicesequence i=0 ; i<_taille ; ++i)
            if (acces(i)!= s.acces(i))
                    return false;
        return true;
    }
}

void sequence::copier(  sequence const &s) {
    if (_taille !=s._taille) {
        delete [] _contenu;
        if (s._taille == 0)
            _contenu = nullptr;
        else
            _contenu = new couleur[s._taille];
        _taille = s._taille;
    }
    for (indicesequence i(0); i<s._taille; ++i)
        _contenu[i] = s._contenu[i];
}

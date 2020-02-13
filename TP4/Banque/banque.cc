#include "banque.hh"

std::string personne::nom() const {
    return _nom;
}

std::string couple::nom() const {
    return _p1->nom() + " " + _p2->nom();
}

std::string societe::nom() const {
    return _nom;
}

proprietaire::type societe::typeprop() const {
    return type::societe;
}

proprietaire::type personne::typeprop() const {
    return type::personne;
}

proprietaire::type couple::typeprop() const {
    return type::couple;
}

std::string const & couple::adresse() const {
    return _p1->adresse();
}

std::string const & personne::adresse() const {
    return _adresse;
}
std::string const & societe::adresse() const {
    return _adresse;
}

std::ostream & operator<<(std::ostream & os, proprietaire const & p) {
    p.sortieflux(os);
    return os;
}

unsigned int compte::_compteur(0);

compte::compte(std::shared_ptr<proprietaire> prop, float montant)
    :_numero(_compteur++) , _prop(prop) , _montant(montant) {}

void compte::verser(float m) {
    _montant +=m;
}

void compte::retirer(float m) {
    _montant -=m;
}

void compte::virervers(compte &c, float f) {
    _montant -=f;
    c._montant+=f;
    if (_prop != c._prop)
        _montant -=1;

}

#include "biblio.hh"
#include "sstream"
bool videos::emprunter() const {
    return true;
}

bool periodique::emprunter() const {
    return false;
}

bool livres::emprunter() const {
    return emprunt;
}

float videos::prix() const {
    return 70;
}

float documents_ecrits::prix() const {
    return 0.5*(_nbpages);
}



std::string videos::typedoc() const {
    return "video";
}

std::string livres::typedoc() const {
    return "livre";
}

std::string periodique::typedoc() const {
    return "periodique";
}

void documents::sortieflux(std::ostream &os) const {
    os << typedoc() << " ";
    os << _titre << " " << _auteur;
    os << (emprunter() ? " EMP" : "NONEMP ");
}

std::ostream & operator<<(std::ostream & os, documents const & d) {
    d.sortieflux(os);
    return os;
}

void videos::sortieflux(std::ostream &os) const {
    documents::sortieflux(os);
    switch (_support) {
        case support::DVD: os << "DVD"; break;
        case support::BluRay: os << "Blu-Ray"; break;
        case support::BluRay3D: os << "Blu-Ray 3d"; break;

    }
}

void documents_ecrits::sortieflux(std::ostream &os) const {
     documents::sortieflux(os);
     os << " " << _nbpages << "p.";
}

void periodique::sortieflux(std::ostream &os) const {
    documents_ecrits::sortieflux(os);
    os << " num." << _numero;
}

bibliotheque::~bibliotheque() {  //Régle des 3 -> constructeur par recopie virtuel / operateur d'affectation
    for (auto i : _contenu)
        delete i;
}

documents * videos::clone() const {
    return new videos(*this);
}

documents * periodique::clone() const {
    return new periodique(*this);
}
documents * livres::clone() const {
    return new livres(*this);
}

void bibliotheque::ajout(const documents &d) {
    _contenu.push_back(d.clone());
}

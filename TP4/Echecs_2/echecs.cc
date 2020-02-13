#include "echecs.hh"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
std::ostream & operator<<(std::ostream & os, position const & p) {
    os << "(" << p.x() << "," << p.y() << ")";
    return os;
}

int pion::valeur() const{
    return 1;
}
int roi::valeur() const{
    return 20;
}

int dame::valeur() const {
    return 9;
}

int cavalier::valeur() const {
    return 3;
}

char pion::symbole() const {
    return 'P';
}

char roi::symbole() const {
    return 'R';
}

char cavalier::symbole() const {
    return 'C';
}
char dame::symbole() const {
    return 'D';
}

std::string piece::tostring() const {
    /*
    std::ostringstream out;
    out << symbole();
    if(couleur()==couleur::blanc) out << "B";
    else out << "N";
    out << _position.x();
    out << _position.y();
    return out.str();
    */
    return std::string (1,symbole()) + std::string((_couleur == couleur::noir) ? "N" : "B") + std::to_string(_position.x()) + std::to_string(_position.y());
}


std::vector<position> pion::deplacementspossibles() const {
    std::vector<position> resultat;
    auto p(pos());
    p.sety(p.y() + ((coul() == couleur::noir) ? 1 : -1 ));
    if (p.estvalide())
        resultat.push_back(p);
    return resultat;
}

std::vector<position> roi::deplacementspossibles() const {
    std::vector<position> resultat;
    position posactuelle(pos());
    for (coord x=-1 ; x<=1 ; ++x)
        for (coord y=-1 ; y<=1 ; ++y)
        {
            if ((x!=0) || (y!=0))
            {
                position p(posactuelle.x()+x,posactuelle.y() +y);
                if (p.estvalide())
                    resultat.push_back(p);
            }
        }

    return resultat;
}
std::vector<position> cavalier::deplacementspossibles() const {
    std::vector<position> resultat;
    position posactuelle(pos());
    for (coord a : { -2 , 2})
        for (coord b : { -1 , 1 }) {
            position p1(posactuelle.x() +a, posactuelle.y() +b);
            if (p1.estvalide())
                resultat.push_back(p1);
            position p2(posactuelle.x() +b, posactuelle.y() +a);
            if (p2.estvalide())
                resultat.push_back(p2);

        }


    return resultat;
}

bool piece::accepterposition(position const & p) const {
    auto dp = deplacementspossibles();
    return std::find(dp.begin(), dp.end(), p)!=dp.end();
}

bool piece::deplacer(position const & p) {
    if (accepterposition(p)) {
        _position = p;
        return true;
    }
    else
        return false;
}

void echiquier::ajout(std::unique_ptr<piece> p) {
    _pieces.push_back(std::move(p));
}

unsigned int echiquier::valeurdujoueur(couleur c) const {
    int resultat(0);
    for (auto const &p : _pieces) {
        if (p->coul() == c)
            resultat+= p->valeur();
    }
    return resultat;

}
bool echiquier::deplacer(const position &source, const position &destination) {
    if (source.estvalide() && destination.estvalide()) {
        for (auto const & i : _pieces) {
            if(i->pos()==source) {
                i->deplacer(destination);
            }
        }

    }
    return false;

}

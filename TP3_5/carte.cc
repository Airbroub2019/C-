#include "tailleposition.hh"
#include "element.hh"
#include "carte.hh"
#include <list>
#include <iostream>

void carte::ajouter(personnage const & p) {
    _personnages.push_back(p);
}

void carte::ajouter(obstacle const & o) {
    _obstacles.push_back(o);
}

void carte::ajouter(objetramassable const & obr) {
    _objetramassables.push_back(obr);
}


void carte::afficherpersonnages() const {
    for(auto const & i : _personnages)
        std::cout << i.accesposition().tostring() << " " << i.accestaille().tostring() << "\n";
}

void carte::afficher() const {
    for(auto const & i : _personnages)
        std::cout << i.accesposition().tostring() << " " << i.accestaille().tostring() << "\n";
    for(auto const & i : _objetramassables)
        std::cout << i.accesposition().tostring() << " " << i.accestaille().tostring() << "\n";
    for(auto const & i : _obstacles)
        std::cout << i.accesposition().tostring() << " " << i.accestaille().tostring() << "\n";
}

bool intersectionIntervalle(coordonnee x1,coordonnee x2, coordonnee x3,coordonnee x4) {
    return !( (x3>=x2 && x3>x1) || (x3<x1 && x4<x1 ) );
}
bool carte::intersection(element const & e1, element const & e2) const {
    return intersectionIntervalle(e1.accesposition().x(), e1.accesposition().x() + e1.accestaille().largeur(), e2.accesposition().x(),
                                  e2.accesposition().x()+e2.accestaille().largeur())
            && intersectionIntervalle(e1.accesposition().y(), e1.accesposition().y()+e1.accestaille().hauteur(), e2.accesposition().y(),
                                      e2.accesposition().y()+e2.accestaille().hauteur());
}
bool carte::deplacements(personnage &p, deplacement d) {

    if (d==deplacement::gauche)
    {
        personnage p2(position(p.accesposition().x()-1, p.accesposition().y()),p.accestaille(), p.nom());
        for (auto const & i : _personnages)

            if (i.nom()!=p.nom() && intersection(i,p2)) return false;
        for (auto const & i : _objetramassables)
            if (intersection(i,p2)) return false;
        for (auto const & i : _obstacles)
            if (intersection(i,p2)) return false;

        p = p2;
        return true;

    }

    if (d==deplacement::haut)
    {
        personnage p2(position(p.accesposition().x(), p.accesposition().y()+1),p.accestaille(), p.nom());
        for (auto const & i : _personnages)
            if (intersection(i,p2)) return false;
        for (auto const & i : _objetramassables)
            if (intersection(i,p2)) return false;
        for (auto const & i : _obstacles)
            if (intersection(i,p2)) return false;

        p = p2;
        return true;

    }

    if (d==deplacement::droite)
    {
        personnage p2(position(p.accesposition().x()+1, p.accesposition().y()),p.accestaille(), p.nom());
        for (auto const & i : _personnages)
            if (intersection(i,p2)) return false;
        for (auto const & i : _objetramassables)
            if (intersection(i,p2)) return false;
        for (auto const & i : _obstacles)
            if (intersection(i,p2)) return false;

        p = p2;
        return true;

    }

    if (d==deplacement::bas)
    {
        personnage p2(position(p.accesposition().x(), p.accesposition().y()-1),p.accestaille(), p.nom());
        for (auto const & i : _personnages)
            if (intersection(i,p2)) return false;
        for (auto const & i : _objetramassables)
            if (intersection(i,p2)) return false;
        for (auto const & i : _obstacles)
            if (intersection(i,p2)) return false;

        p = p2;
        return true;

    }
    return false;

}


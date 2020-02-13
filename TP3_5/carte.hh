#pragma once
#include "element.hh"
#include "tailleposition.hh"
#include <list>


enum class deplacement {
    droite,
    gauche,
    bas,
    haut
};

class carte {
private:
    taille _taille;
    std::list<personnage> _personnages;
    std::list<obstacle> _obstacles;
    std::list<objetramassable> _objetramassables;

public:
    carte(taille const & t):_taille(t){}
    void ajouter(personnage const & p);
    void ajouter(obstacle const & o);
    void ajouter(objetramassable const & o);
    void afficherpersonnages() const;
    void afficher() const;
    bool intersection(element const & e1, element const & e2) const;
    bool deplacements(personnage &p, deplacement d);

};

bool intersectionIntervalle(coordonnee x1,coordonnee x2, coordonnee y1,coordonnee y2);


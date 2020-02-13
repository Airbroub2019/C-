#pragma once

#include <iostream>
#include <list>
#include <string>
#include <ostream>

#include "element.hh"

using identifiant = unsigned int;


struct arcsortant {
    identifiant id;
    std::string etiquette;
};

class sommet {
private:
    static identifiant _compteur;
    identifiant _id;
    std::string _etiquette;
    std::list<arcsortant> _arcs ;

public:
    sommet(std::string const & etiquette);
    identifiant id() const { return _id ;}
    std::string const & etiquette() const { return _etiquette;}
    void ajouterarc(identifiant ext,std::string const & etiq);
    void supprimerarc(identifiant ext);
    void supprimertousarcs();
    void dot_etiquette(std::ostream & os ) const;
    void dot_arcssortants(std::ostream & os) const;


};

class graphe {

    graphe() = default;
    graphe(graphe const & g) = default;
public:
    identifiant ajoutersommet(std::string const & etiquette);
    bool ajouterarc(identifiant i1 , identifiant i2 , std::string const & etiquettearc);
    std::list<sommet>::iterator chercher(identifiant id);
    void supprimersommet(identifiant s);
    void dot_sortie(std::ostream & os) const;

private:
    std::list<sommet> _sommets;
};



class carte {
public:
    carte(taille const & t)
        :_taille(t) {

    }
    void ajouter(objetramassable const & o);
    void ajouter (personnage const & p);
    void ajouter(obstacle const & o);
    void afficherpersonnages() const;
    void afficher() const;

private:
    taille _taille;
    std::list<personnage> _per;
    std::list<obstacle> _obs;
    std::list<objetramassable> _obj;
};

bool interval_intersection (coordonnee x1, coordonnee x2, coordonne y1, coordonne y2) ;

#include "grille.hh"
#include <iostream>

grille::grille(coordonnee largeur, coordonnee longueur)
    :_longueur(longueur),_largeur(largeur)//,_grille()
    {

    std::vector<etatcellule> v1;

    for ( int j=0; j<_largeur; ++j)
        v1.push_back(etatcellule::mort);


    for ( int i=0; i<_longueur; ++i)
    {
        _grille.push_back(v1);
    }

}

void grille::vider() {
    for (auto & i : _grille)
        for (auto & j : i)
            j = etatcellule::mort;
}

bool grille::vivante(coordonnee x, coordonnee y){
    if (x >= _longueur || y >= _largeur || x < 0 || y < 0) return false;
    else return _grille[x][y] == etatcellule::vivant;
}


void grille::generer (coordonnee x, coordonnee y) {
    _grille[x][y] = etatcellule::vivant;
}

void grille::afficher() {
    for (auto i : _grille)
    {
        for (auto j : i )
        {
            if (j==etatcellule::vivant) std::cout << "*";
            else std::cout << " ";

        }
        std::cout << std::endl;
    }

}

void grille::ajouterstructure (structure s, coordonnee x, coordonnee y){
    if (s == structure::oscillateurligne) {
        for ( int i=x; i<x+3 ; ++i)
          _grille[i][y] = etatcellule::vivant;
    }

    else if (s == structure::floraison)
    {
          ajouterstructure(structure::oscillateurligne, x+1 , y);
          ajouterstructure(structure::oscillateurligne, x+1 , y+2);
        for ( int i=x; i<x+5 ; i = i+2)               //en decendant de 1 mettre à vivant 1 sur 2
          _grille[i][y+1] = etatcellule::vivant;


    }

    else if (s == structure::planeur)
    {
        ajouterstructure(structure::oscillateurligne, x, y);
        _grille[x+2][y+1] = etatcellule::vivant;
        _grille[x+1][y+2] = etatcellule::vivant;

    }

    else if (s == structure::oscilateurcroix)
    {
        _grille[x+1][y] = etatcellule::vivant;
        ajouterstructure(structure::oscillateurligne, x, y+1);
        _grille[x+1][y+2] = etatcellule::vivant;

    }

 }

int grille::vivantes (coordonnee x, coordonnee y){
    int compt=0;
    for (int i = x-1 ; i < x+2 ; ++i)
    {
       for (int j = y-1 ; j<y+2 ; ++j)
           if (vivante(i,j)) compt++;
    }

    if(vivante(x,y)) compt--;

    return compt;
}

void grille::evolution(grille &g){
    for (int i = 0; i < _longueur ; i++)
        for (int j = 0 ; j < _largeur ; ++j)
             if (!vivante(i,j) && vivantes(i,j)==3) _grille[i][j] = etatcellule::mort;
             else if (vivante(i,j) && (vivantes(i,j)==0 || vivantes(i,j)==1)) _grille[i][j] = etatcellule::mort;
             else if (vivante(i,j) && vivantes(i,j)>=4) _grille[i][j] = etatcellule::mort;
    }



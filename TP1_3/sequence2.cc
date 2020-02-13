
#include "sequence2.hh"
#include <iostream>
#include <array>
void sc_initialiservide(sequence & s) {
        s.contenu = nullptr;
        s.taille=0;
        s.taille_reserver = 0;
}
/*
void sc_ajouter_premier(sequence & s, couleur c)
{
    couleur * nouveau(new couleur[s.taille +1]);
    for (indicesequence i(0); i<s.taille;++i)
        nouveau[i]=s.contenu[i];
    nouveau[s.taille] = c;
    ++s.taille;
    delete [] s.contenu;
    s.contenu = nouveau;
}
*/
void sc_ajouter(sequence & s, couleur c)
{
    if (s.taille==s.taille_reserver) {
        s.taille_reserver+=5;
        couleur * nouveau(new couleur[s.taille_reserver]);
        for (indicesequence i(0); i<s.taille;++i)
            nouveau[i]=s.contenu[i];
        delete [] s.contenu;
        s.contenu = nouveau;
    }

     s.contenu[s.taille++] = c;




}

/*
void sc_ajouter_moi(sequence & s, couleur c)
{


    if (s.taille == 0)
    {
        s.contenu = new couleur[s.taille+1];
        s.contenu[0] = c;
        s.taille++;
    }
    else {

        couleur * tmp = s.contenu;
        s.contenu = new couleur[s.taille+1];

        for (unsigned int i = 0; i<s.taille ; i++)
        {
            s.contenu[i] = tmp[i];
        }
        delete[] tmp;
        s.contenu[s.taille] = c;
        s.taille++;

    }
}
*/

/*void sc_copier_premier(sequence & destination, sequence const & source)
{

    if (destination.taille!=source.taille)
    {
        delete [] destination.contenu;
        if(source.taille !=0)
            destination.contenu = new couleur[source.taille];
        else destination.contenu = nullptr;
        destination.taille = source.taille;

    }

    for (indicesequence i=0; i<source.taille ; ++i)
        destination.contenu[i] = source.contenu[i];

}
*/
void sc_copier(sequence & destination, sequence const & source)
{

    if (destination.taille_reserver!=source.taille_reserver)
    {
        delete [] destination.contenu;
        if(source.taille !=0)
            destination.contenu = new couleur[source.taille_reserver];
        else destination.contenu = nullptr;
        destination.taille_reserver = source.taille_reserver;

    }
    destination.taille = source.taille;

    for (indicesequence i=0; i<source.taille ; ++i)
        destination.contenu[i] = source.contenu[i];

}
couleur sc_acces (sequence const & s, indicesequence i){

    return s.contenu[i];
}

void sc_afficher (couleur c)
{
    switch (c) {
            case couleur::rouge: std::cout << "rouge" ; break ;
            case couleur::bleu: std::cout << "bleu" ; break ;
            case couleur::vert: std::cout << "vert" ; break ;
            case couleur::jaune: std::cout << "jaune" ; break ;

    }
}

void sc_vider (sequence & s)
{
      delete [] s.contenu;
      s.contenu = nullptr;
      s.taille = 0;
      s.taille_reserver = 0;

}


void sc_afficher (sequence const & s){
    for (indicesequence i=0; i<s.taille ; ++i) {
            sc_afficher(sc_acces(s,i));
            std::cout << " ";
     }
    std::cout << std::endl;

}

bool sc_comparer (sequence const &a, sequence const &b){
    if (a.taille!=b.taille)
        return false;
    else {
        for (indicesequence i=0; i<a.taille ; ++i)
            if (a.contenu[i]!=b.contenu[i]) return false;
        return true;
    }
}
void sc_detruire(sequence & s){
    delete [] s.contenu;
}

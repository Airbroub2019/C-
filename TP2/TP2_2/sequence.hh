#pragma once
#include <cstddef>
#include <iostream>

enum class couleur{
    rouge,
    bleu,
    jaune,
    vert

};

using indicesequence = std::size_t;


class sequence {

public:
    sequence(); //constructeur par défault
                // Eviter le probleme 1 & 2
    sequence (sequence const & s);
    void ajouter (couleur c);
    indicesequence taille() const;
    // mauvaise idée :  couleur * contenu () const;
    // car on peut faire delete d'une pointeur et libérer le tableau alloué dynamiquement   (Probleme 5)

    // pas de mutateurs
    // car depuis le main on pourra modifier contenu/taille               (probleme 4)

    ~sequence();
    void afficher(couleur c) const;
    void afficher (couleur c, std::ostream & os) const;

    couleur acces (indicesequence i) const;
    void vider();
    void afficher (std::ostream & os) const;

    bool comparer (sequence const & s) const;
    void copier (sequence const & s);


private:
    indicesequence _taille;
    couleur * _contenu;
};

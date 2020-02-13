#include <iostream>
#include "tailleposition.hh"
#include "element.hh"
#include "carte.hh"
int main()
{
    /*
    position p1(5,0);
    position p2(p1);

    std::cout << p2.x() << " " << p1.x() << std::endl;

    std::cout << p2.y() << " " << p1.y() << std::endl;

    std::cout << p2.comparaison(p1) << std::endl;

    p2.modifiery(32); p1.modifierx(25);

    std::cout << p2.x() << " " << p1.x() << std::endl;

    std::cout << p2.y() << " " << p1.y() << std::endl;

    std::cout << p2.comparaison(p1) << std::endl;


    element e(position(5,4),taille(2,3));
    std::cout << e.tostring() << std::endl;

    std::cout << e.contientposition(position(5,4)) << e.contientposition(position(4,4)) << e.contientposition(position(6,5)) << e.contientposition(position(7,6)) << std::endl;
    */
    carte c(taille(100,100));
    c.ajouter(personnage(position(10,10),taille(2,2),"toto"));
    c.ajouter(obstacle(position(50,50),taille(20,1)));
    return 0;


}

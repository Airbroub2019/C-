#include <iostream>
#include "tailleposition.hh"
int main(){
    position p1(5, 6);
    position p2(5,7);
    std::cout << p2.x() << " " << p2.y() << std::endl;
    std:: cout << p1.comparaison(p2);
    return 0;
}


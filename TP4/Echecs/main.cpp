#include <iostream>
#include "echecs.hh"
using namespace std;

int main()
{
    /*cavalier c(position(4,2), couleur::noir);
    std::cout << c.tostring() << std::endl;*/
    pion p(position(4,7), couleur::noir);
    std::cout << p.tostring() << std::endl;
    auto d(p.deplacementspossibles());
    for (auto const & i : d)
        std::cout << i << " ";
    std::cout << std::endl;

    roi r(position(0,0), couleur::noir);
    std::cout << r.tostring() << std::endl;
    auto c(r.deplacementspossibles());
    for (auto const & i : c)
        std::cout << i << " ";
    std::cout << "DP en 01 " << r.accepterposition(position(0,1)) << std::endl;
    std::cout << "DP en 02 " << r.accepterposition(position(0,2)) << std::endl;
    std::cout << "DP en 66 " << r.deplacer(position(6,6)) << std::endl;
    std::cout << r.tostring() << std::endl;
    std::cout << "DP en 11 " << r.deplacer(position(1,1)) << std::endl;
    std::cout << r.tostring() << std::endl;
    return 0;
}

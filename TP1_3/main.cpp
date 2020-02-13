#include <iostream>
#include "sequence2.hh"


using namespace std;

int main()  {
        sequence a, b;
        sc_initialiservide(a); // 3
        sc_initialiservide(b);
        sc_ajouter(a, couleur::rouge); // 4
        sc_ajouter(a, couleur::bleu);
        sc_ajouter(a, couleur::rouge);
        sc_ajouter(a, couleur::vert);
        sc_copier(b, a); // Copie a dans b // 5
       sc_afficher(sc_acces(a, 0)); std::cout << "\n"; // 6 et 7
         for (indicesequence i=0; i<a.taille; ++i)
            sc_afficher(sc_acces(a,i));
        sc_vider(a); // 8
        cout << "A: "; sc_afficher(a); // 9
        cout << "B: "; sc_afficher(b);
        cout << sc_comparer(a,b) << "\n"; // 10
        sc_copier(a,b);
        cout << sc_comparer(a,b) << "\n";
        sc_detruire(a);
        sc_detruire(b);
        return 0;
  }

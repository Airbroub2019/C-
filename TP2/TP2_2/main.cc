#include <iostream>
#include "sequence.hh"
int main()
{
 /* 1. ne pas oublier initialisation
    2. initialiser plusieurs fois                utiliser sc_initialiservide au lieu de scvider
    3. ne pas oublier destruction (1 seule fois)
    4. ne pas modifier contenu, taille           a.taille++
    5. ne pas liberer contenu                    delete [] a.contenu
 */



      sequence a;
      a.ajouter(couleur::rouge);
      a.ajouter(couleur::bleu);
      a.ajouter(couleur::rouge);
      a.ajouter(couleur::vert);

      sequence b(a); // voir question 3
      a.afficher(a.acces(0)); std::cout << "\n";
      for (indicesequence i=0; i<a.taille(); ++i)
          a.afficher(a.acces(i));
      std::cout << "\n";
      a.vider();
      std::cout << "A: "; a.afficher(std::cout); // voir question 4
      std::cout << "B: "; b.afficher(std::cout);
      std::cout << a.comparer(b) << "\n";
      // a=b, erreur     opérateur d'affectation
      a.copier(b); // voir question 5
      std::cout << a.comparer(b) << "\n";
      return 0;
}

#include <iostream>
#include "plateau.h"
#include "jeu2048.h"
using namespace std;

int main()
{
    bool fin;
    Plateau lePlateau;
    Jeu2048 leJeu;

    lePlateau.Afficher();
    do {
        fin = lePlateau.JouerCoup();
        fin=leJeu.RechercherFinDePartie();
    } while (fin==false);
    return 0;
}

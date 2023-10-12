#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <string.h>

#include "jeu2048.h"

using namespace std ;

class Plateau
{
public:
    Plateau();
    void Afficher();
    bool JouerCoup();
private:
    int nbCoups;
    int score;
    Jeu2048 leJeu;
};

#endif // PLATEAU_H

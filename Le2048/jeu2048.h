#ifndef JEU2048_H
#define JEU2048_H
#include <math.h>
#include <time.h>


class Jeu2048
{
public:
    enum ETATS_DU_JEU {
      EN_COURS,
        GAGNE,
        PERDU,
    };
    Jeu2048();
    void PlacerNouvelleTuile();
    bool Calculer(const char _direction);
    void Deplacer(const char _direction);
    int CalculerScore();
    void ObtenirGrille(int _grille[][4]);
    ETATS_DU_JEU RechercherFinDePartie();
private:
    int grille[4][4];
};

#endif // JEU2048_H

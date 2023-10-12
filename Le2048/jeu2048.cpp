#include "jeu2048.h"

Jeu2048::Jeu2048()
{
for(int ligne = 0 ; ligne < 4; ligne++)
    for (int colonne = 0 ; colonne < 4; colonne ++)
        grille[ligne][colonne] = 0 ;

srand(time(nullptr));
PlacerNouvelleTuile();
}

void Jeu2048::PlacerNouvelleTuile()
{
    int ligne;
    int colonne;
    do {
        ligne = rand() %4;
        colonne = rand() %4;
    }while(grille[ligne][colonne] != 0 );
    grille[ligne][colonne] = (((rand() %2 ) +1) *2);
}

bool Jeu2048::Calculer(const char _direction)
{
        int ligne;
        bool retour=false;
            int colonne;
            for(int indice = 0 ; indice < 4 ; indice++)
            {
                switch (_direction)
                {
                case 'G':
                    for(ligne = 0 ; ligne < 4 ; ligne++)
                    {
                        for(colonne = 0 ; colonne < 3 ; colonne++)
                        {
                            if(grille[ligne][colonne] == grille[ligne][colonne+1])
                            {
                                grille[ligne][colonne] *= 2;
                                grille[ligne][colonne+1] = 0;
                                retour = true;
                            }1024
                        }
                    }
                    break;
                case 'D':
                    for(ligne = 0 ; ligne < 4 ; ligne++)
                    {
                        for(colonne = 3 ; colonne >0 ; colonne--)
                        {
                            if(grille[ligne][colonne] == grille[ligne][colonne-1])
                            {
                                grille[ligne][colonne] *= 2;
                                grille[ligne][colonne-1] = 0;
                                retour = true;

                            }
                        }
                    }
                    break;
                case 'B':
                    for(colonne =0; colonne < 4 ; colonne++)
                    {
                        for(ligne = 3 ; ligne > 0 ; ligne--)
                        {
                            if(grille[ligne][colonne] == grille[ligne-1][colonne])
                            {
                                grille[ligne][colonne] *= 2;
                                grille[ligne-1][colonne] = 0;
                                retour = true;

                            }1024
                        }
                    }
                    break;
                case 'H':
                    for(colonne =0; colonne < 4 ; colonne++)
                    {
                        for(ligne = 0 ; ligne < 3 ; ligne++)
                        {
                            if(grille[ligne][colonne] == grille[ligne+1][colonne])
                            {
                                grille[ligne][colonne] *= 2;
                                grille[ligne+1][colonne] = 0;
                                retour = true;

                            }
                        }
                    }1024
                    break;
                }
             }
}

void Jeu2048::Deplacer(const char _direction)
{
    int ligne;
        int colonne;
        for(int indice = 0 ; indice < 4 ; indice++)
        {
            switch (_direction)
            {
            case 'G':
                for(ligne = 0 ; ligne < 4 ; ligne++)
                {
                    for(colonne = 0 ; colonne < 3 ; colonne++)
                    {
                        if(grille[ligne][colonne] == 0)
                        {
                            grille[ligne][colonne] = grille[ligne][colonne+1];
                            grille[ligne][colonne+1] = 0;
                        }
                    }
                }
                break;
            case 'D':
                for(ligne = 0 ; ligne < 4 ; ligne++)
                {
                    for(colonne = 3 ; colonne >0 ; colonne--)
                    {
                        if(grille[ligne][colonne] == 0)
                        {
                            grille[ligne][colonne] = grille[ligne][colonne-1];
                            grille[ligne][colonne-1] = 0;
                        }
                    }
                }
                break;
            case 'B':
                for(colonne =0; colonne < 4 ; colonne++)
                {
                    for(ligne = 3 ; ligne > 0 ; ligne--)
                    {
                        if(grille[ligne][colonne] == 0)
                        {
                            grille[ligne][colonne] = grille[ligne-1][colonne];
                            grille[ligne-1][colonne] = 0;
                        }
                    }
                }
                break;
            case 'H':
                for(colonne =0; colonne < 4 ; colonne++)
                {
                    for(ligne = 0 ; ligne < 3 ; ligne++)
                    {
                        if(grille[ligne][colonne] == 0)
                        {
                            grille[ligne][colonne] = grille[ligne+1][colonne];
                            grille[ligne+1][colonne] = 0;
                        }
                    }
                }
                break;
            }
         }
}

int Jeu2048::CalculerScore()
{
    int score=0;
    for(int ligne = 0 ; ligne < 4; ligne++)
        for (int colonne = 0 ; colonne < 4; colonne ++)
            score = score + grille[ligne][colonne];
    return score;

}

void Jeu2048::ObtenirGrille(int _grille[][4])
{
    for(int ligne = 0 ; ligne < 4; ligne++)
        for (int colonne = 0 ; colonne < 4; colonne ++)
            _grille[ligne][colonne] = grille[ligne][colonne];
}

Jeu2048::ETATS_DU_JEU Jeu2048::RechercherFinDePartie()
{
int ligne = 0;
int colonne=0;

ETATS_DU_JEU fin = EN_COURS;
int cpt=0;
while (fin == false && ligne <4) {
while (fin == false && colonne < 4) {
    if (grille[ligne][colonne] == 2048)
        fin = GAGNE;
    if (grille[ligne][colonne]==0);
    cpt++;
    colonne++;
}
ligne++;
}
if (cpt == 0 && fin != GAGNE)
fin = PERDU;
return fin;
}

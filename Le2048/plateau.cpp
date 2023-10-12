#include "plateau.h"


Plateau::Plateau():
    nbCoups(0),
    score(0)
{

}

void Plateau::Afficher()
{
    int laGrille[4][4];
    system("clear");
    leJeu.ObtenirGrille(laGrille);
    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;
    for(int ligne = 0 ; ligne < 4 ; ligne++)
    {
        cout << "   +";
        for (int indice = 0 ; indice <4 ; indice++)
            cout << setw(7) << setfill('-') << '+';

        cout << setfill(' ') << endl;
        cout << "   |" ;
        for (int colonne = 0 ; colonne < 4 ; colonne++){
            if(laGrille[ligne][colonne] !=0){
                cout << setw(5) << laGrille[ligne][colonne] << " |" ;
            }else {
                cout << setw(7) << '|';
            }
        }
        cout << endl;
    }
    cout << "   +";
    for (int indice = 0 ; indice <4 ; indice++)
        cout << setw(7) << setfill('-') << '+';
    cout << endl << endl;
    cout << "F pour sortir du jeu" << endl;
    cout << "Votre déplacement : H(^) , B(v) , G(<-), D(->) : " << endl << endl;


}

bool Plateau::JouerCoup()
{
    bool retour = false;
        char touche;
        cin  >> touche ;
        touche = toupper(touche);
        if(strchr("BHGD",touche) != nullptr)
        {
            nbCoups++;
            leJeu.Deplacer(touche);
            if (leJeu.Calculer(touche))
                leJeu.Deplacer(touche);
            leJeu.PlacerNouvelleTuile();
            score=leJeu.CalculerScore();
            Afficher();

        }
        if(touche == 'F')
            retour = true;

        return retour;
}

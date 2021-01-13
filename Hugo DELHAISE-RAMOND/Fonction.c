#include "fonction.h"

static int etat = 0;



void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20;
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;

	for (index = 0; index < Pas; ++index)
	{
		const double angle = 2.*M_PI*index/Pas;
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
	}

}

void gestionEvenement(EvenementGfx evenement){

	switch (evenement)
	{
		case Initialisation:

			demandeTemporisation(20);
			break;

		case Temporisation:
			rafraichisFenetre();
			break;

		case Affichage:

			effaceFenetre (255, 255, 255);

			tracegraphique(etat);


			break;

		case BoutonSouris:
			break;

		case Souris:
			break;

		case Inactivite:
			break;

		case Redimensionnement:
			break;
		case Clavier:
			break;
		case ClavierSpecial:
			break;
	}
}

void tracegraphique(int etat){
	int AbsX=350; //Abcisse palet coin gauche
	int AbsXX=450;//Abscisse palet coin droit
	int TailleBonus=0;// Ajout d'une certaine valeur de pixel au palet. ATTENTION cette valeur est divisée par deux car répartie de chaque côté du palet pour conserver les symétries (Exemple si TailleBonus=50 alors le palet gagne 100pixels.
	couleurCourante(220,220,220);
	rectangle(0,0,LargeurFenetre,HauteurFenetre);
	switch (etat){
	case 0:

		couleurCourante(0,102,255);
		if(etatBoutonSouris()==1){ //Position de départ au milieu de l'écran
			rectangle(AbsX,25,AbsXX,40);
		}
		else if(abscisseSouris()+100>=800){ //Si le palet atteint la bordure droite de l'écran il se bloque.
			rectangle(700,25,abscisseSouris()+100,40);
		}
		else if(abscisseSouris()<=0){
			rectangle(0,25,100,40);
		}
		else{
			if(abscisseSouris() >= AbsX && abscisseSouris() <= AbsXX && ordonneeSouris() >= 25 && ordonneeSouris() <= 40){

				rectangle(abscisseSouris(),25,abscisseSouris()+100,40);//Un clic est détecté, le palet suit la souris jusqu'à que le clic soit relaché. Si le clic est relaché le palet reste sur sa dernière position.

			}
		}
		break;
	}
}
int gereClicBoutons(int etat){
return 0;
}

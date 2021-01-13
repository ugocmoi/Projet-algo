#include "main.h"

bool verifTrans = false;

static int etat = 0;

static DonneesImageRGB *image = NULL;
static DonneesImageRGB *image1 = NULL;
static DonneesImageRGB *image2 = NULL;
static DonneesImageRGB *image3 = NULL;
static DonneesImageRGB *image4 = NULL;


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

void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false;


	switch (evenement)
	{
		case Initialisation:

			image = lisBMPRGB("menu.bmp");
			image1 = lisBMPRGB("menuniveaux.bmp");
			image2 = lisBMPRGB("facile.bmp");
			image3 = lisBMPRGB("moyen.bmp");
			image4 = lisBMPRGB("difficile.bmp");


			demandeTemporisation(20);
			break;

		case Temporisation:
			rafraichisFenetre();
			break;

		case Affichage:

			effaceFenetre (255, 255, 255);

			tracegraphique(&etat);


			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
				etat==gereClicBoutons(&etat);

			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}

			break;

		case Souris:
			break;

		case Inactivite:
			break;

		case Redimensionnement:
			break;
	}
}


void tracegraphique(int* petat){

	switch(*petat){
	case 0:
	if (image != NULL) // Si l'image a pu etre lue
				{
						// On affiche l'image
						ecrisImage(0, 0, image->largeurImage, image->hauteurImage, image->donneesRGB);
				}
	 break;

	case 1:
	if (image1 != NULL) // Si l'image a pu etre lue
				{
						// On affiche l'image
						ecrisImage(0, 0, image1->largeurImage, image1->hauteurImage, image1->donneesRGB);
				}
	 break;

	 case 2:
	if (image2 != NULL) // Si l'image a pu etre lue
				{
						// On affiche l'image
						ecrisImage(0, 0, image2->largeurImage, image2->hauteurImage, image2->donneesRGB);
				}
	 break;
		}
}


int gereClicBoutons(int* petat) {
if(*petat==0)// Menu Principale
{
if(abscisseSouris() >= 439 && abscisseSouris() <= 1477 && ordonneeSouris() >= 153 && ordonneeSouris() <= 330) { // Coordonées Bouton Quitter
exit(0);
}

if(abscisseSouris() >= 439 && abscisseSouris() <= 900 && ordonneeSouris() >= 431 && ordonneeSouris() <= 615) {  // Coordonées Bouton Jouer
 *petat=1;
}

if(abscisseSouris() >= 1020 && abscisseSouris() <= 1477 && ordonneeSouris() >= 431 && ordonneeSouris() <= 615) {  // Coordonées Bouton Scores

}

}

if(*petat==1)//Menu niveaux de difficultés ou aléatoires
{
if(abscisseSouris() >= 447 && abscisseSouris() <= 1475 && ordonneeSouris() >= 458 && ordonneeSouris() <= 631) { // Coordonées Bouton Niveaux Aléatoires

}

if(abscisseSouris() >= 447 && abscisseSouris() <= 1475 && ordonneeSouris() >= 205 && ordonneeSouris() <= 381) {  // Coordonées Bouton Niveaux De Difficulté
	*petat=2;
}

if(abscisseSouris() >= 95 && abscisseSouris() <= 275 && ordonneeSouris() >= 808 && ordonneeSouris() <= 962) {  // Coordonées Retour en arrière
 	*petat=0;
}

}

if(*petat==2)//Menu avec les différents niveaux de difficultés
{

if(abscisseSouris() >= 535 && abscisseSouris() <= 1385 && ordonneeSouris() >= 503 && ordonneeSouris() <= 648) { // Coordonées Bouton Niveau Facile

}

if(abscisseSouris() >= 535 && abscisseSouris() <= 1385 && ordonneeSouris() >= 308 && ordonneeSouris() <= 455) { // Coordonées Bouton Niveau Moyen

}

if(abscisseSouris() >= 535 && abscisseSouris() <= 1385 && ordonneeSouris() >= 113 && ordonneeSouris() <= 256) { // Coordonées Bouton Niveau Difficile

}


if(abscisseSouris() >= 95 && abscisseSouris() <= 275 && ordonneeSouris() >= 808 && ordonneeSouris() <= 962) {  // Coordonées Retour en arrière
 	*petat=1;
}

}

	}

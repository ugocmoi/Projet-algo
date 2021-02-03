#include "casse_brique.h"
#include <time.h>
static T_palet palet={ {0, 255, 0} , 100, 15, 250, 20};
static T_balle balle={ {255, 0, 0} , 300, 46, 10, 10, 1, 100, 20};
static T_brique brique={ {0, 0, 0}, 115, 30, 0, 0};
static DonneesImageRGB *image = NULL;
static DonneesImageRGB *image1 = NULL;
static DonneesImageRGB *image2 = NULL;
///static DonneesImageRGB *image3 = NULL;
//static DonneesImageRGB *image4 = NULL;

void affiche_menu(){
		sautDeLigne();
     	ecrisChaine("*************  TP GRAPHIQUE ******** \n");
     	ecrisChaine("taper h	pour afficher ce menu    :\n");
     	ecrisChaine("taper r	pour rafraichir la fenêtre graphique    :\n");
     	ecrisChaine("taper q    pour  SORTIR de l'APPLICATION  : \n");
		ecrisChaine("taper p    pour  dessiner un point rouge au centre de la fenêtre  : \n");
		ecrisChaine("taper a    pour  dessiner une balle au centre de la fenêtre  : \n");   
     	sautDeLigne();   
     
}
void dessineBalle(T_balle *balle){

	epaisseurDeTrait(balle->taille);
	couleurCourante(balle->color.red, balle->color.green, balle->color.blue);
	point(balle->pos_x, balle->pos_y);
	rafraichisFenetre();
}

void dessineBalleAnimee(T_balle *balle, T_palet *palet, T_brique *brique){
	
	if(rebondissement(balle, palet)==1 || niveau2_4(brique, balle)==1){
		balle->vy = -balle->vy;
	}
	if(rebondissement(balle, palet)==2){
		balle->vx = -balle->vx;
	}
	balle->pos_x += balle->vx;
	balle->pos_y += balle->vy;
	dessineBalle(balle);
}

int rebondissement(T_balle *balle, T_palet *palet){

	int rebondis=0;
	if(balle->pos_y + balle->taille/2 >= hauteurFenetre() // on vérifie si la balle arrive en haut de la fenetre
	|| (balle->pos_y <= palet->pos_y + palet->taille_y // on verifie si la balle arrive à la hauteur du palet
		&& balle->pos_y >= palet->pos_y
		&& balle->pos_x >= palet->pos_x // on vérifie si elle tombe entre les deux extremités du palet
		&& balle->pos_x <= palet->pos_x + palet->taille_x)){
		rebondis=1;
	}
	if(balle->pos_x /*+ balle->taille/2*/ >= largeurFenetre()  || balle->pos_x /*- balle->taille/2*/ < 0){
		rebondis=2;
	}
	return rebondis;
}

void tracePalet(T_palet *palet){
	couleurCourante(palet->color.red, palet->color.green, palet->color.blue);
	rectangle(palet->pos_x, palet->pos_y, palet->pos_x + palet->taille_x, palet->pos_y + palet->taille_y);
	rafraichisFenetre();
		
}

int gereClicBoutons(int etat) {
if(etat==2)//Menu avec les différents niveaux de difficultés
{

if(abscisseSouris() >= 535 && abscisseSouris() <= 1385 && ordonneeSouris() >= 503 && ordonneeSouris() <= 648) { // Coordonées Bouton Niveau Facile

}

if(abscisseSouris() >= 535 && abscisseSouris() <= 1385 && ordonneeSouris() >= 308 && ordonneeSouris() <= 455) { // Coordonées Bouton Niveau Moyen

}

if(abscisseSouris() >= 535 && abscisseSouris() <= 1385 && ordonneeSouris() >= 113 && ordonneeSouris() <= 256) { // Coordonées Bouton Niveau Difficile

}


if(abscisseSouris() >= 95 && abscisseSouris() <= 275 && ordonneeSouris() >= 808 && ordonneeSouris() <= 962) {  // Coordonées Retour en arrière
 	etat=1;
}

}

if(etat==1)//Menu niveaux de difficultés ou aléatoires
{
if(abscisseSouris() >= 447 && abscisseSouris() <= 1475 && ordonneeSouris() >= 458 && ordonneeSouris() <= 631) { // Coordonées Bouton Niveaux Aléatoires
	etat=3;
}

if(abscisseSouris() >= 447 && abscisseSouris() <= 1475 && ordonneeSouris() >= 205 && ordonneeSouris() <= 381) {  // Coordonées Bouton Niveaux De Difficulté
	etat=2;
}

if(abscisseSouris() >= 95 && abscisseSouris() <= 275 && ordonneeSouris() >= 808 && ordonneeSouris() <= 962) {  // Coordonées Retour en arrière
 	etat=0;
}

}

if(etat==0)// Menu Principale
{
if(abscisseSouris() >= 439 && abscisseSouris() <= 1477 && ordonneeSouris() >= 153 && ordonneeSouris() <= 330) { // Coordonées Bouton Quitter
exit(0);
}

if(abscisseSouris() >= 439 && abscisseSouris() <= 900 && ordonneeSouris() >= 431 && ordonneeSouris() <= 615) {  // Coordonées Bouton Jouer
 etat=1;
}

if(abscisseSouris() >= 1020 && abscisseSouris() <= 1477 && ordonneeSouris() >= 431 && ordonneeSouris() <= 615) {  // Coordonées Bouton Scores

}

}


return etat;
}

void affichage(int etat){

	switch(etat){
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
	 
	 case 3:{
	 	dessineBalleAnimee(&balle, &palet, &brique); //on dessine la balle à partir de la structure, la structure ce met à jour à chaque nouveau dessin.
		tracePalet(&palet);
		niveau2_4(&brique, &balle);
		break;
	 }
		}
}

void initImage(){
	image = lisBMPRGB("image_menu/menu.bmp");
	image1 = lisBMPRGB("image_menu/menuniveaux.bmp");
	image2 = lisBMPRGB("image_menu/facile.bmp");
	//image3 = lisBMPRGB("image_menu/moyen.bmp");
	//image4 = lisBMPRGB("image_menu/difficile.bmp");
}

void gestion_palet(float abs){
	abs = abscisseSouris();
	palet.pos_x = abs - (palet.taille_x/2);
}

void gestion_palet2(){
if(palet.pos_x + palet.taille_x >= largeurFenetre()){
	palet.pos_x = largeurFenetre() - palet.taille_x;
}
}

void gestion_palet3(){
if(palet.pos_x <= 0){
	palet.pos_x =0;
}
}

int RAND100(void) //generateur de nombre aleatoire entre 0 et 100  sans avoir toujours le meme nombre dans une courte periode de temps
{
	static int memoire;
	int nombre_aleatoire = 0;
	memoire += time(NULL);
	srand(memoire);					 // se base par rapport au temps de l'ordinateur
	nombre_aleatoire = rand() % 101; // génére un nombre allant de 0 à 100
	return nombre_aleatoire;
}




int gestion_rebondissement_brique(T_brique *brique, T_balle *balle){
	int rebondis;
	couleurCourante(brique->color.red, brique->color.green, brique->color.blue);
	rectangle(brique->pos_x, brique->pos_y, brique->pos_x + brique->taille_x, brique->pos_y + brique->taille_y);
	if((balle->pos_y <= brique->pos_y + brique->taille_y // on verifie si la balle arrive à la hauteur du palet
		&& balle->pos_y >= brique->pos_y
		&& balle->pos_x >= brique->pos_x // on vérifie si elle tombe entre les deux extremités du palet
		&& balle->pos_x <= brique->pos_x + brique->taille_x))
		{
			rebondis=1;
		}
return rebondis;
}

/*-----------------------------------------------NIVEAU 1 _ 4----------------------------------------------------------------------------*/

int niveau1_4(T_brique *brique, T_balle *balle){
	int rebondis=0;
	int i;
	const int j = 117;
	/* LVL 1
	28 Briques vertes - 8 Briques bleues - 4 briques violettes

						/--/	
					/--/	/--/
				/--//--/	/--//--/	
			/--//--/			/--//--/
			/--/					/--/		
		/--//--/					/--//--/
		/--/							/--/
	/--/									/--/
		/--/							/--/
		/--//--/					/--//--/
			/--/					/--/
			/--//--/			/--//--/
				/--//--/	/--//--/				 		
					/--/	/--/
						/--/

	*/
	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 800;
	brique->pos_y=hauteurFenetre()- 32;
	rebondis = gestion_rebondissement_brique(brique, balle);

	for(i = 64; i <= 96; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 683;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 96; i <= 156; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 169;
		brique->color.green= 249;
		brique->pos_x = 566;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 128; i <= 192; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 449;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 192; i <= 224; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 332;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 215;
	brique->pos_y=hauteurFenetre()- 256;
	rebondis = gestion_rebondissement_brique(brique, balle);

	/*-----------------------------------------------------------------------------------*/

	for(i = 64; i <= 96; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 683 + 2*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 96; i <= 156; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 683 + 3*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 128; i <= 192; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 683 + 4*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 192; i <= 224; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 683 + 5*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 683 + 6*j;
	brique->pos_y=hauteurFenetre()- 256;
	rebondis = gestion_rebondissement_brique(brique, balle);

	int last = 683 + 6*j;

	/*-----------------------------------------------------------------------------------*/

	/* 2 - 3 - 2 - 2*/
	
	for(i = 288; i <= 320; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = last - j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 320; i <= 388; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = last - 2*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 384; i <= 416; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = last - 3*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 416; i <= 452; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = last - 4*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = last - 5*j;
	brique->pos_y=hauteurFenetre()- 480;
	rebondis = gestion_rebondissement_brique(brique, balle);

	/*-----------------------------------------------------------------------------------*/

	int last2 = last - 5* j;

	for(i = 448; i >= 414; i-=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = last2 - j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 416; i >= 384; i-=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = last2 - 2*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 384; i >= 320; i-=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = last2 - 3*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 320; i >= 288; i-=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = last2 - 4*j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

return rebondis;
}

/*-----------------------------------------------NIVEAU 2 _ 4----------------------------------------------------------------------------*/

int niveau2_4(T_brique *brique, T_balle *balle)
{
	int rebondis=0;
	int i;
	int j = 117;
	/*
	*	27 briques vertes 12 briques bleues 13 briques violette
	*/

/*--------------------------IIIIIIIIIIIIIIIIII-------------------------------------------------------------------------*/
	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = j;
	brique->pos_y=hauteurFenetre()- 64;
	rebondis = gestion_rebondissement_brique(brique, balle);

	for(i = 128; i <= 320; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = j;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	/*-----------------------------------------------------------------SSSSSSS--------------------------------------------------------*/

	for(i = 96; i <= 192; i+=32)
	{
		brique->color.red= 169;
		brique->color.blue= 249;
		brique->color.green= 8;
		brique->pos_x = j * 4;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 192; i <= 320; i+=32)
	{
		brique->color.red= 169;
		brique->color.blue= 249;
		brique->color.green= 8;
		brique->pos_x = j * 5;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = j * 5;
	brique->pos_y=hauteurFenetre()- 64;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = j * 6;
	brique->pos_y=hauteurFenetre()- 96;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = j * 4;
	brique->pos_y=hauteurFenetre()- 352;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = j * 3;
	brique->pos_y=hauteurFenetre()- 320;
	rebondis = gestion_rebondissement_brique(brique, balle);

/*-----------------------------------------------------------------EEEEEEEEEEE--------------------------------------------------------*/

	for(i = 64; i <= 352; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = j * 8;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = j * 9;
	brique->pos_y=hauteurFenetre()- 64;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = j * 9;
	brique->pos_y=hauteurFenetre()- 352;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = j * 9;
	brique->pos_y=hauteurFenetre()- 224;
	rebondis = gestion_rebondissement_brique(brique, balle);

/*-----------------------------------------------------------------NNNNNNNNN--------------------------------------------------------*/

	for(i = 64; i <= 352; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = j * 11;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 64; i <= 352; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = j * 13;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = j * 12;
	brique->pos_y=hauteurFenetre()- 64;
	rebondis = gestion_rebondissement_brique(brique, balle);

	return rebondis;
}

/*-----------------------------------------------NIVEAU 3 _ 4----------------------------------------------------------------------------*/

int niveau3_4(T_brique *brique, T_balle *balle)
{
	int rebondis=0;
	int i;
/*-----------------------------LLLLL-------------------------------------------------------------------------------------*/

	for(i = 32; i < 320; i+=32)
	{
		brique->color.red= 169;
		brique->color.blue= 249;
		brique->color.green= 8;
		brique->pos_x = 117 * 4;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 117*5;
	brique->pos_y=hauteurFenetre()- 256;
	rebondis = gestion_rebondissement_brique(brique, balle);
	
	
	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 117*5;
	brique->pos_y=hauteurFenetre()- 288;
	rebondis = gestion_rebondissement_brique(brique, balle);

/*-----------------------------EEEE-------------------------------------------------------------------------------------*/

	
	for(i = 32; i < 320; i+=32)
	{
		brique->color.red= 169;
		brique->color.blue= 249;
		brique->color.green= 8;
		brique->pos_x = 117 * 7;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 117*8;
	brique->pos_y=hauteurFenetre()- 32;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 117*8;
	brique->pos_y=hauteurFenetre()- 288;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 169;
	brique->color.blue= 249;
	brique->color.green= 8;
	brique->pos_x = 117*8;
	brique->pos_y=hauteurFenetre()- 160;
	rebondis = gestion_rebondissement_brique(brique, balle);

	/*-----------------------------VVV-------------------------------------------------------------------------------------*/


	for(i = 352; i <= 640; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 0;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = 117;
	brique->pos_y=hauteurFenetre()- 352;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = 117;
	brique->pos_y=hauteurFenetre()- 640;
	rebondis = gestion_rebondissement_brique(brique, balle);

	/*------------------------------------OOOO------------------------------------------------------------------------------*/

	for(i = 352; i <= 640; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 117*3;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = 117*4;
	brique->pos_y=hauteurFenetre()- 352;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = 117*4;
	brique->pos_y=hauteurFenetre()- 640;
	rebondis = gestion_rebondissement_brique(brique, balle);

	for(i = 352; i <= 640; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 117*5;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

/*----------------------------------------VVVV---------------------------------------------------------------------------*/

	for(i = 352; i <= 608; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 117*7;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	for(i = 352; i <= 608; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 249;
		brique->color.green= 218;
		brique->pos_x = 117*9;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 249;
	brique->color.green= 218;
	brique->pos_x = 117*8;
	brique->pos_y=hauteurFenetre()- 640;
	rebondis = gestion_rebondissement_brique(brique, balle);

/*---------------------------------IIIIIII----------------------------------------------------------------------------------*/

	for(i = 418; i <= 652; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 117*11;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = 117*11;
	brique->pos_y=hauteurFenetre()- 352;
	rebondis = gestion_rebondissement_brique(brique, balle);


/*-----------------------------------------DDDDD--------------------------------------------------------------------------*/

	for(i = 352; i <= 640; i+=32)
	{
		brique->color.red= 8;
		brique->color.blue= 160;
		brique->color.green= 249;
		brique->pos_x = 117*13;
		brique->pos_y=hauteurFenetre()- i;
		rebondis = gestion_rebondissement_brique(brique, balle);
	}

	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = 117*14;
	brique->pos_y=hauteurFenetre()- 352;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = 117*13;
	brique->pos_y=hauteurFenetre()- 672;
	rebondis = gestion_rebondissement_brique(brique, balle);

	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = 117*14;
	brique->pos_y=hauteurFenetre()- i;
	rebondis = gestion_rebondissement_brique(brique, balle);

	for(i = 384; i <= 640; i+=32)
	{
	brique->color.red= 8;
	brique->color.blue= 160;
	brique->color.green= 249;
	brique->pos_x = 117*15;
	brique->pos_y=hauteurFenetre()- i;
	rebondis = gestion_rebondissement_brique(brique, balle);
	}
	return rebondis;
}


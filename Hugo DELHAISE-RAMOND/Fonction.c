#include "fonction.h"

static int etat = 0;
static int AbsX=350; //Abcisse palet coin gauche
static int AbsXX=450;//Abscisse palet coin droit

void tracegraphique(int etat){
	int TailleBonus=0;// Ajout d'une certaine valeur de pixel au palet. ATTENTION cette valeur est divisée par deux car répartie de chaque côté du palet pour conserver les symétries (Exemple si TailleBonus=50 alors le palet gagne 100pixels.
	couleurCourante(220,220,220);
	rectangle(0,0,LargeurFenetre,HauteurFenetre);
	switch (etat){
	case 0:

		couleurCourante(0,102,255);
		if(etatBoutonSouris()==1){ //Position de départ au milieu de l'écran
			rectangle(AbsX,25,AbsXX,40);
		}
		else if(abscisseSouris()+50>=800){ //Si le palet atteint la bordure droite de l'écran il se bloque.
			rectangle(700,25,abscisseSouris()+100,40);
		}
		else if(abscisseSouris()<=50){
			rectangle(0,25,100,40);
		}
		else{
			if(abscisseSouris() >= AbsX && abscisseSouris() <= AbsXX && ordonneeSouris() >= 25 && ordonneeSouris() <= 40){

				rectangle(abscisseSouris()-50,25,abscisseSouris()+50,40);//Un clic est détecté, le palet suit la souris jusqu'à que le clic soit relaché. Si le clic est relaché le palet reste sur sa dernière position.
				AbsX=abscisseSouris()-50;
				AbsXX=abscisseSouris()+50;
			}
			else{
				rectangle(AbsX,25,AbsXX,40);
			}
		}
		break;
	}
}

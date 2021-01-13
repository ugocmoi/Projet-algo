#include "fonction.h"

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();

	return 0;
}

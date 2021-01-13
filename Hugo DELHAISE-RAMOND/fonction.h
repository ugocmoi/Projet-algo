#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GfxLib.h"
#include "BmpLib.h"
#include "ESLib.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

void cercle(float centreX, float centreY, float rayon);
void gestionEvenement(EvenementGfx evenement);

void tracegraphique(int etat);

int gereClicBoutons(int etat);

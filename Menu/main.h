#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "GfxLib.h"
#include "BmpLib.h"
#include "ESLib.h"

#define LargeurFenetre 1920
#define HauteurFenetre 1080

void cercle(float centreX, float centreY, float rayon);
void gestionEvenement(EvenementGfx evenement);

void tracegraphique(int* petat);

int gereClicBoutons(int* petat);

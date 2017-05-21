#include <stdio.h>
#include <stdlib.h>


typedef struct _pecaBaralho{
int number; //corresponde ao número de cada carta
int naipe; //representa a naipe: 0 - Basto, 1- Espada, 2 - Ouro e 3 - Copa
struct _pecaBaralho *right;
struct _ pecaBaralho *left;
}TpPecaBaralho;
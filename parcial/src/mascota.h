/*
 * mascota.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define EMPTY 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int isEmpty;

}eMascotas;

int GenerarId();
void InicializarMascotas(eMascotas[],int);
int BuscarLibre(eMascotas[],int);
int BuscarId(eMascotas[],int,int);



#endif /* MASCOTA_H_ */

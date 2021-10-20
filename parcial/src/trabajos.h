/*
 * trabajos.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "fecha.h"

#define EMPTY 0
#define OCUPADO 1

typedef struct
{
	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajos;

int GenerarIdT();
void InicializarTrabajos(eTrabajos[],int);
int BuscarTrabajoLibre(eTrabajos[],int);

#endif /* TRABAJOS_H_ */

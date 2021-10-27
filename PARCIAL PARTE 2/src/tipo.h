/*
 * tipo.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef TIPO_H_
#define TIPO_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct
{
	int id;
	char descripcion[20];
}eTipo;


void HardcodeoTipo(eTipo[],int);
void MostrarTipos(eTipo[],int);

#endif /* TIPO_H_ */

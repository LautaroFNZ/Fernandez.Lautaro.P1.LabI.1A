/*
 * servicios.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct
{
	int id;
	char descripcion[25];
	float precio;

}eServicios;

void HardcodeoServicios(eServicios[],int);
void MostrarServicios(eServicios[],int);


#endif /* SERVICIOS_H_ */

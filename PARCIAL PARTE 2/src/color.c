/*
 * color.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "color.h"

void HardcodeoColor(eColor colores[],int tam)
{
	int id[]={5000,5001,5002,5003,5004};
	char descripcion[][20]={"Negro","Blanco","Rojo","Gris","Azul"};

	int i;

	for(i=0;i<tam;i++)
	{
		colores[i].id = id[i];
		strcpy(colores[i].nombreColor,descripcion[i]);

	}

}

void MostrarColores(eColor colores[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		printf("ID:%d|%s\n", colores[i].id,colores[i].nombreColor);
	}

}






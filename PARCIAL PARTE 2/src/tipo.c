/*
 * tipo.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "tipo.h"

void HardcodeoTipo(eTipo tipos[],int tam)
{
	int id[]={1000,1001,1002,1003,1004};
	char descripcion[][20]={"Ave","Perro","Roedor","Gato","Pez"};

	int i;

	for(i=0;i<tam;i++)
	{
		tipos[i].id=id[i];
		strcpy(tipos[i].descripcion,descripcion[i]);

	}

}

void MostrarTipos(eTipo tipos[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		printf("ID:%d|%s\n", tipos[i].id,tipos[i].descripcion);


	}



}



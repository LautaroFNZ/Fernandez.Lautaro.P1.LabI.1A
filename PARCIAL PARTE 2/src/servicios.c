/*
 * servicios.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "servicios.h"

void HardcodeoServicios(eServicios servicios[],int tam)
{
	int id[]={20000,20001,20002};
	char descripcion[][25]={"Corte","Desparasitado","Castrado"};
	float precio[]={450,800,600};

	int i;

	for(i=0;i<tam;i++)
	{
		servicios[i].id=id[i];
		strcpy(servicios[i].descripcion,descripcion[i]);
		servicios[i].precio=precio[i];


	}

}

void MostrarServicios(eServicios servicios[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		printf("ID:%d|%s|$%.2f\n", servicios[i].id,servicios[i].descripcion,servicios[i].precio);

	}

}

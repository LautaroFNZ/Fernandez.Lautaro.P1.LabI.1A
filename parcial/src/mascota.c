/*
 * mascota.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "mascota.h"

int IdIncremental=0;

int GenerarId()
{
	return IdIncremental+=1;

}

void InicializarMascotas(eMascotas mascotas[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		mascotas[i].isEmpty = EMPTY;
	}
}

int BuscarLibre(eMascotas mascotas[],int tam)
{
	int i;
	int index=-1;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty==EMPTY)
		{
			index=i;
			break;
		}

	}

	return index;
}

int BuscarId(eMascotas mascotas[],int tam,int index)
{
	int i;
	int retorno=-1;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO)
		{
			if(mascotas[i].id==index)
			{
				retorno=i;
			}


		}

	}

	return retorno;
}




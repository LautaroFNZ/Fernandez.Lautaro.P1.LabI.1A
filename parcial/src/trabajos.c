/*
 * trabajos.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "trabajos.h"

int idIncrementall=0;

int GenerarIdT()
{
	return idIncrementall+=1;
}

void InicializarTrabajos(eTrabajos trabajos[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		trabajos[i].isEmpty=EMPTY;

	}

}

int BuscarTrabajoLibre(eTrabajos trabajos[],int tam)
{
	int i;
	int retorno=-1;

	for(i=0;i<tam;i++)
	{

		if(trabajos[i].isEmpty==EMPTY)
		{
			retorno=i;
			break;
		}


	}

	return retorno;
}





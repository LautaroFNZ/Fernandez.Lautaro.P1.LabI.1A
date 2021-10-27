/*
 * trabajos.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "trabajos.h"

int idIncrementall=4;

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

void HardcodeoBonus(eTrabajos trabajos[],int tTrabajos)
{
	int id[]={1,2,3,4};
	int mascota[]={1,1,2,2};
	int servicio[]={20000,20001,20000,20002};
	int dia[]={2,6,2,6};
	int mes[]={11,11,11,11};
	int anio[]={2021,2021,2021,2021};

	int i;

	for(i=0;i<tTrabajos;i++)
	{
		trabajos[i].id=id[i];
		trabajos[i].idMascota=mascota[i];
		trabajos[i].idServicio=servicio[i];
		trabajos[i].fecha.dia=dia[i];
		trabajos[i].fecha.mes=mes[i];
		trabajos[i].fecha.anio=anio[i];

	}


}



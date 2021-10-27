/*
 * mascota.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "mascota.h"

int IdIncremental=2;

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

void HardcodeoBonusMascotas(eMascotas mascotas[],int tMascotas)
{
	int id[]={1,2};
	char nombre[][20]={"Milo","Rocco"};
	int idTipo[]={1001,1001};
	int idColor[]={5000,5001};
	int edad[]={5,1};
	char vacunado[]={'s','n'};
	int ise[]={OCUPADO,OCUPADO};

	int i;

	for(i=0;i<tMascotas;i++)
	{
		mascotas[i].id=id[i];
		strcpy(mascotas[i].nombre,nombre[i]);
		mascotas[i].idTipo=idTipo[i];
		mascotas[i].idColor=idColor[i];
		mascotas[i].edad=edad[i];
		mascotas[i].vacunado=vacunado[i];
		mascotas[i].isEmpty=ise[i];


	}

}

int isEmpty(eMascotas mascotas[],int tam)
{
	int retorno=0;
	int i;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO)
		{
			retorno=1;
			break;
		}

	}


	return retorno;
}




/*
 * funciones.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "funciones.h"

int menu()
{
	int opcion;

	printf("Bienvenidos al menu!\n");
	printf("1. Alta Mascota\n");
	printf("2. Modificar Mascota\n");
	printf("3. Baja Mascota\n");
	printf("4. Listar Mascotas\n");
	printf("5. Listar Tipos\n");
	printf("6. Listar Colores\n");
	printf("7. Listar Servicios\n");
	printf("8. Alta Trabajo\n");
	printf("9. Listar Trabajos\n");
	printf("10. Cancelar\n");
	opcion = GetInt("Ingrese una opcion:");




	return opcion;
}

eMascotas cargarMascotas(eTipo tipos[],int tTipos,eColor colores[],int tColores)
{
	eMascotas auxiliar;

	auxiliar.id=GenerarId();
	GetString("Ingrese el nombre:", auxiliar.nombre);
	MostrarTipos(tipos, tTipos);
	auxiliar.idTipo=GetIntParam("Ingrese el id correspondiente:", 1000, 1004);
	MostrarColores(colores, tColores);
	auxiliar.idColor=GetIntParam("Ingrese el id correspondiente:",5000,5004);
	auxiliar.edad=GetIntParam("Ingrese la edad:",1,99);
	auxiliar.vacunado=GetChar("Ingrese 's' o 'n' para saber si su mascota esta o no vacunada:");
	while(auxiliar.vacunado!='s' && auxiliar.vacunado!='n')
	{
		auxiliar.vacunado=GetChar("ERROR.Ingrese 's' o 'n' para saber si su mascota esta o no vacunada:");
	}

	auxiliar.isEmpty=OCUPADO;

	return auxiliar;
}

int InsertarMascota(eTipo tipos[],int tTipos,eColor colores[],int tColores,eMascotas mascotas[],int tMascotas)
{
	int index=BuscarLibre(mascotas, tMascotas);

	if(index==-1)
	{
		printf("No hay espacio disponible!\n");
	}else
	{

		mascotas[index]=cargarMascotas(tipos, tTipos, colores, tColores);
	}


	return 0;
}

void ListarMascotas(eTipo tipos[],int tTipos,eColor colores[],int tColores,eMascotas mascotas[],int tMascotas)
{
	int i;
	int c;
	int t;

	for(i=0;i<tMascotas;i++)
	{

		if(mascotas[i].isEmpty==OCUPADO)
		{

		printf("ID:%d|NOMBRE:%s|EDAD:%d", mascotas[i].id,mascotas[i].nombre,mascotas[i].edad);

		for(c=0;c<tColores;c++)
		{
			if(mascotas[i].idColor==colores[c].id)
			{
				printf("|COLOR:%s", colores[c].nombreColor);
			}


		}

		for(t=0;t<tTipos;t++)
		{
			if(mascotas[i].idTipo==tipos[t].id)
			{
				printf("|%s",tipos[t].descripcion);
			}


		}

		if(mascotas[i].vacunado=='s')
		{
			printf("|VACUNADO\n\n");
		}else if(mascotas[i].vacunado=='n')
		{
			printf("|NO VACUNADO\n\n");
		}

		}//Cierre if

	}




}

void ModificarMascotas(eTipo tipos[],int tTipos,eMascotas mascotas[],int tMascotas,eColor colores[],int tColores)
{
	ListarMascotas(tipos, tTipos, colores, tColores, mascotas, tMascotas);

	int index=GetInt("Ingrese la id correspondiente: ");
	int retorno=BuscarId(mascotas, tMascotas, index);
	int opcion;

	if(retorno!=-1)
	{
		printf("ID ENCONTRADA!\n");
		printf("1 .Editar Tipo\n");
		printf("2. Editar Vacunado\n");
		printf("3. Cancelar\n");
		opcion=GetIntParam("Ingrese la opcion correspondiente:", 1, 3);

		switch(opcion)
		{
			case 1:
				printf("Usted esta editando el tipo...\n\n");
				MostrarTipos(tipos, tTipos);
				mascotas[retorno].idTipo=GetIntParam("Ingrese el id correspondiente:", 1000, 1004);

				break;

			case 2:

				if(mascotas[retorno].vacunado=='s')
				{

					mascotas[retorno].vacunado='n';
					printf("Se ha cambiado el vacunado a NO!\n");
				}

				if(mascotas[retorno].vacunado=='n')
				{
					mascotas[retorno].vacunado='s';
					printf("Se ha cambiado el vacunado a SI!\n");
				}


				break;
			case 3:

				printf("Ha cancelado correctamente!\n");

				break;

			default:

				printf("ERROR EN LA OPCION INGRESADA\n");

				break;

		}




	}else printf("No se ha encontrado el id!");





}

void EliminarMascotas(eTipo tipos[],int tTipos,eMascotas mascotas[],int tMascotas,eColor colores[],int tColores)
{
	ListarMascotas(tipos, tTipos, colores, tColores, mascotas, tMascotas);

	int index=GetInt("Ingrese el id correspondiente: ");
	int retorno=BuscarId(mascotas, tMascotas, index);

	if(retorno!=-1)
	{
		mascotas[retorno].isEmpty=EMPTY;
		printf("Mascota eliminada con exito!\n");

	}else
	{
		printf("No se ha encontrado el id ingresado!\n");
	}

}

eTrabajos cargarTrabajo(eServicios servicios[],int tServicios,eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos,eColor colores[],int tColores)
{
	eTrabajos auxiliar;

	auxiliar.id = GenerarIdT();

	ListarMascotas(tipos, tTipos, colores, tColores, mascotas, tMascotas);
	auxiliar.idMascota = GetInt("Ingrese el id correspondiente:");
	int retorno=BuscarId(mascotas, tMascotas, auxiliar.id);
	while(retorno==-1)
	{
		printf("Su id no se ha encontrado!\n");
		auxiliar.idMascota = GetInt("Reingrese el id correspondiente:");
	}
	MostrarServicios(servicios, tServicios);
	auxiliar.idServicio=GetIntParam("Ingrese el id correspndiente:", 20000, 20002);
	auxiliar.fecha.dia=GetIntParam("Ingrese el dia:", 1, 31);
	auxiliar.fecha.mes=GetIntParam("Ingrese el mes:", 1, 12);
	auxiliar.fecha.anio=GetIntParam("Ingrese el año:",2021,2022);


	auxiliar.isEmpty=OCUPADO;

	return auxiliar;
}

int InsertarTrabajo(eServicios servicios[],int tServicios,eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos,eColor colores[],int tColores,eTrabajos trabajos[],int tTrabajos)
{
	int index = BuscarTrabajoLibre(trabajos, tTrabajos);

	if(index!=-1)
	{

		trabajos[index]=cargarTrabajo(servicios, tServicios, mascotas, tMascotas, tipos, tTipos, colores, tColores);

	}else printf("No hay espacio disponible!\n");

	return 0;
}

void ListarTrabajos(eServicios servicios[],int tServicios,eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos,eColor colores[],int tColores,eTrabajos trabajos[],int tTrabajos)
{
	int i;
	int m;
	int s;

	for(i=0;i<tTrabajos;i++)
	{
		if(trabajos[i].isEmpty==OCUPADO)
		{


		printf("ID:%d", trabajos[i].id);

		for(m=0;m<tMascotas;m++)
		{

			if(trabajos[i].idMascota==mascotas[m].id)
			{
				printf("|NOMBRE:%s|EDAD:%d", mascotas[m].nombre,mascotas[m].edad);

			}


		}

		for(s=0;s<tServicios;s++)
		{
			if(trabajos[i].idServicio==servicios[s].id)
			{
				printf("|%s|$%.2f", servicios[s].descripcion,servicios[s].precio);
			}


		}

		printf("|FECHA:%d/%d/%d\n",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);

		}//cierre if
	}



}




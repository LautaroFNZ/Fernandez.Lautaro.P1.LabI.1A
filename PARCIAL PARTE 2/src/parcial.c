/*
 ============================================================================
 Name        : parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"

#define TM 7
#define TS 3
#define TC 5
#define TT 5
#define TTT 5
#define TA 5

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	eServicios servicio[TS];
	eMascotas mascotas[TM];
	eTipo tipos[TT];
	eColor colores[TC];
	eTrabajos trabajos[TTT];
	eAux color[TA];

	int flag=0;
	int flag2=0;


	InicializarTrabajos(trabajos, TTT);
	InicializarMascotas(mascotas, TM);
	HardcodeoBonus(trabajos, TTT);
	HardcodeoBonusMascotas(mascotas,TM);
	HardcodeoServicios(servicio, TS);
	HardcodeoTipo(tipos,TT);
	HardcodeoColor(colores, TC);


	HardcodearAux(color,TA);

	do{
		opcion = menu();

		switch(opcion)
		{
			case 1:

				InsertarMascota(tipos, TT, colores, TC, mascotas, TM);
				flag=isEmpty(mascotas, TM);

				break;

			case 2:
				if(flag==1)
				{
				ModificarMascotas(tipos, TT, mascotas, TM, colores, TC);
				}else printf("Primero debes ingresar una mascota!\n");
				break;

			case 3:
				if(flag==1)
				{
				EliminarMascotas(tipos, TT, mascotas, TM, colores, TC);
				}else printf("Primero debes ingresar una mascota!\n");
				break;

			case 4:
				if(flag==1)
				{
				ListarMascotas(tipos, TT, colores, TC, mascotas, TM);
				}else printf("Primero debes ingresar una mascota!\n");
				break;

			case 5:

				MostrarTipos(tipos, TT);

				break;

			case 6:

				MostrarColores(colores, TC);

				break;

			case 7:

				MostrarServicios(servicio, TS);

				break;

			case 8:
				if(flag==1)
				{
				InsertarTrabajo(servicio, TS, mascotas, TM, tipos, TT, colores, TC, trabajos, TTT);
				flag=2;
				}else printf("Primero debes ingresar una mascota!\n");
				break;

			case 9:
				if(flag2==1)
				{
					ListarTrabajos(servicio, TS, mascotas, TM, tipos, TT, colores, TC, trabajos, TTT);
				}else printf("Primero debe ingresar un trabajo!\n");


				break;

			case 10:

				 if(flag==1)
				{
				seleccionarColor(mascotas, TM, colores, TC);
				}else printf("Primero debes ingresar una mascota!\n");

				break;

			case 11:
				 if(flag==1)
				{
				calcularYMostrarPromedio(mascotas, TM);
				}else printf("Primero debes ingresar una mascota!\n");


				break;

			case 12:
				 if(flag==1)
				{
				mostrarPorEdad(mascotas, TM);
				}else printf("Primero debes ingresar una mascota!\n");



				break;
			case 13:

				 if(flag==1)
				{
				mascotasPorTipo(mascotas, TM, tipos, TT);
				}else printf("Primero debes ingresar una mascota!\n");


				break;
			case 14:

				 if(flag==1)
				{
				elegirColorYTipo(tipos, TT, mascotas, TM, colores, TC);
				}else printf("Primero debes ingresar una mascota!\n");

				break;


			case 15:
				if(flag==1)
				{
				mostrarColoresMaximos(mascotas, TM, colores, TC, color, TA);
				}else printf("Primero debe ingresar una mascota!\n");
				break;
			case 0:

				printf("Ha cancelado con exito!\n");

				break;

			default:

				printf("ERROR! La opcion ingresada no existe!\n");

				break;

		}



	}while(opcion!=0);


/*

 	 if(flag==1)
	{

	}else printf("Primero debes ingresar una mascota!\n");




 */



	return EXIT_SUCCESS;
}

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

#define TM 5
#define TS 3
#define TC 5
#define TT 5
#define TTT 5

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	eServicios servicio[TS];
	eMascotas mascotas[TM];
	eTipo tipos[TT];
	eColor colores[TC];
	eTrabajos trabajos[TTT];

	HardcodeoServicios(servicio, TS);
	HardcodeoTipo(tipos,TT);
	HardcodeoColor(colores, TC);
	InicializarMascotas(mascotas, TM);
	InicializarTrabajos(trabajos, TTT);

	do{
		opcion = menu();

		switch(opcion)
		{
			case 1:

				InsertarMascota(tipos, TT, colores, TC, mascotas, TM);

				break;

			case 2:

				ModificarMascotas(tipos, TT, mascotas, TM, colores, TC);

				break;

			case 3:

				EliminarMascotas(tipos, TT, mascotas, TM, colores, TC);

				break;

			case 4:

				ListarMascotas(tipos, TT, colores, TC, mascotas, TM);

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

				InsertarTrabajo(servicio, TS, mascotas, TM, tipos, TT, colores, TC, trabajos, TTT);

				break;

			case 9:

				ListarTrabajos(servicio, TS, mascotas, TM, tipos, TT, colores, TC, trabajos, TTT);

				break;

			case 10:

				printf("Ha cancelado con exito!\n");

				break;

			default:

				printf("ERROR! La opcion ingresada no existe!\n");

				break;

		}



	}while(opcion!=10);






	return EXIT_SUCCESS;
}

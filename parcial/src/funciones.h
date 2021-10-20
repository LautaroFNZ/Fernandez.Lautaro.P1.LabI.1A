/*
 * funciones.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicios.h"
#include "trabajos.h"
#include "input.h"

int menu();
eMascotas cargarMascotas(eTipo[],int,eColor[],int);
int InsertarMascota(eTipo[],int,eColor[],int,eMascotas[],int);
void ListarMascotas(eTipo[],int,eColor[],int,eMascotas[],int);
void ModificarMascotas(eTipo[],int,eMascotas[],int,eColor[],int);
void EliminarMascotas(eTipo[],int,eMascotas[],int,eColor[],int);

eTrabajos cargarTrabajo(eServicios[],int,eMascotas[],int,eTipo[],int,eColor[],int);
int InsertarTrabajo(eServicios[],int,eMascotas[],int,eTipo[],int,eColor[],int,eTrabajos[],int);

void ListarTrabajos(eServicios[],int,eMascotas[],int,eTipo[],int,eColor[],int,eTrabajos[],int);


#endif /* FUNCIONES_H_ */

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

typedef struct
{
	int id;
	int contador;

}eAux;

int menu();
eMascotas cargarMascotas(eTipo[],int,eColor[],int);
int InsertarMascota(eTipo[],int,eColor[],int,eMascotas[],int);
void MostrarMascota(eMascotas);
void ListarMascotas(eTipo[],int,eColor[],int,eMascotas[],int);
void ModificarMascotas(eTipo[],int,eMascotas[],int,eColor[],int);
void EliminarMascotas(eTipo[],int,eMascotas[],int,eColor[],int);


eTrabajos cargarTrabajo(eServicios[],int,eMascotas[],int,eTipo[],int,eColor[],int);
int InsertarTrabajo(eServicios[],int,eMascotas[],int,eTipo[],int,eColor[],int,eTrabajos[],int);

void ListarTrabajos(eServicios[],int,eMascotas[],int,eTipo[],int,eColor[],int,eTrabajos[],int);

//

int seleccionarColor(eMascotas[],int,eColor[],int);
void mostrarcolorseleccionado(eMascotas[],int,eColor[],int,int);

int obtenerMascotasVacunadas(eMascotas[],int);
int obtenerTotalMascotas(eMascotas[],int);
void calcularYMostrarPromedio(eMascotas[],int);

void mascotasPorTipo(eMascotas[],int,eTipo[],int);

int obtenerMenorEdad(eMascotas[],int);
void mostrarPorEdad(eMascotas[],int);

void HardcodearAux(eAux[],int);
int contarColores(eMascotas[],int,eAux[],int);
void mostrarColoresMaximos(eMascotas[],int,eColor[],int,eAux aux[],int);

int iniciarContador(eMascotas[],int,int,int);
void elegirColorYTipo(eTipo[],int,eMascotas[],int,eColor[],int);



#endif /* FUNCIONES_H_ */

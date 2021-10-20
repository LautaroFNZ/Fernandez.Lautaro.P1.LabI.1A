/*
 * color.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct
{
	int id;
	char nombreColor[20];

}eColor;

void HardcodeoColor(eColor[],int);
void MostrarColores(eColor[],int);

#endif /* COLOR_H_ */

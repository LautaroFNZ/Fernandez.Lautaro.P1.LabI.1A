/*
 * input.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "input.h"


int GetInt(char *msj)
{
    int value;

    printf(msj);
    scanf("%d", &value);

    return value;
}

int GetIntParam(char *msj,int min, int max)
{
	int value;

	printf(msj);
	scanf("%d", &value);

	while(value<min || value>max)
	{
		printf("ERROR! Ingrese el numero correspondiente:");
		scanf("%d", &value);
	}


	return value;
}

float GetFloat(char *msj)
{
    float value;

    printf(msj);
    scanf("%f", &value);

    return value;
}

void GetString(char *msj, char value[])
{
    printf(msj);
    fflush(stdin);
    scanf("%[^\n]", value);
}

char GetChar(char *msj)
{
    char value;

    printf(msj);
    fflush(stdin);
    scanf("%c", &value);

    return value;
}

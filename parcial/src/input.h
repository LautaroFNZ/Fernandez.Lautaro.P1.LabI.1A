/*
 * input.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


int GetInt(char *msj);
int GetIntParam(char *msj,int min, int max);
float GetFloat(char *msj);
void GetString(char *msj, char value[]);
char GetChar(char *msj);


#endif /* INPUT_H_ */

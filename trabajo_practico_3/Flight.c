/*
 * eFlight.c
 *
 * Created on: 5 may. 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Esta bilioteca contiene las funciones de la estructura eFlights
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#include "Flight.h"

Flight* Flight_new()
{
	Flight* memoryPointer = NULL;
	memoryPointer = (Flight*) malloc(sizeof(Flight)*2);
	return memoryPointer;
}

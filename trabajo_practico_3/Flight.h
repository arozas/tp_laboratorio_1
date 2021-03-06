/*
 * eFlight.h
 *
 * Created on: 5 may. 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Esta bilioteca contiene los datos de la estructura eFlights
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#ifndef FLIGHT_H_
#define FLIGHT_H_
// *************************************** STRING LENGTH **************************************
#define FLYCODE_LENGTH 15
// ************************************** ISEMPTY STATUS **************************************
#define TRUE 1
#define FALSE 0
#define UNREGISTERED -1
// *************************************** FLIGHT STATUS **************************************
#define SCHEDULED 1
#define DELAYED 2
#define LANDED 3
#define IN_AIR 4
// *************************************** OTHER DEFINES  **************************************
#define RETRIES 3
#define MAX_PRICE 1000000
#define MIN_PRICE 2000

#include "menu.h"
#include "input.h"

typedef struct
{
	char codigoVuelo[FLYCODE_LENGTH];
	int estadoVuelo;

}Flight;

Flight* Flight_new();
Flight* Flight_newParametros(char* flycodeStr,char* estadoVueloStr);
void Flight_delete(Flight* this);

int Flight_setCodigoVuelo(Flight* this,char* codigoVuelo);
int Flight_getCodigoVuelo(Flight* this,char* codigoVuelo);

int Flight_setEstadoVuelo(Flight* this,int estadoVuelo);
int Flight_getEstadoVuelo(Flight* this,int* estadoVuelo);

int Flight_setData(Flight* this);


#endif /* FLIGHT_H_ */

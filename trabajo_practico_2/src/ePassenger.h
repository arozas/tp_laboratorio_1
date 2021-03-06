/*
 * ePassenger.h
 *
 * Created on: 04 Mayo de 2022
 * Author: Alejandro Alberto Martín Rozas - División H.
 * Biblioteca “ArrayPassenger”
 * Esta bilioteca contiene los datos de la estructura ePassenger
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#ifndef EPASSENGER_H_
#define EPASSENGER_H_
// *************************************** STRING LENGTH **************************************
#define NAME_LENGTH 51
#define FLYCODE_LENGTH 10
// ************************************** ISEMPTY STATUS **************************************
#define TRUE 1
#define FALSE 0
#define UNREGISTERED -1
// *************************************** FLIGHT STATUS **************************************
#define SCHEDULED 1
#define DELAYED 2
#define DEPARTED 3
#define IN_AIR 4
#define EXPECTED 5
#define	DIVERTED 6
#define RECOVERY 7
#define LANDED 8
#define ARRIVED 9
#define CANCELLED 10
#define PAST_FLIGHT 11
// ************************************** PASSENGER TYPES **************************************
#define ADULT 1
#define CHILDREN 2
#define INFANT 3
// *************************************** OTHER DEFINES  **************************************
#define RETRIES 3
#define MAX_PRICE 1000000
#define MIN_PRICE 2000


#include "menu.h"
#include "input.h"
#include "operations.h"

typedef struct
{
	int id;
	char name[NAME_LENGTH];
	char lastname[NAME_LENGTH];
	float price;
	int typePassenger;
	char flycode[FLYCODE_LENGTH];
	int isEmpty;

}ePassenger;
//int initPassengers(Passenger* list, int len)
int ePassenger_init(ePassenger ePassengerList[], int length);
void ePassenger_printOne(ePassenger toPrintStruc);
//int printPassenger(Passenger* list, int length)
int ePassenger_printAll(ePassenger toPrintStruc[], int length);
int ePassenger_searchEmptyIndex(ePassenger toSearchStruc[], int length);
int ePassenger_create(ePassenger *passengerList);
//int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
int ePassenger_add(ePassenger list[], int length, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]);
//int removePassenger(Passenger* list, int len, int id)
int ePassenger_remove(ePassenger toUnRegisterStruc[], int length, int id);
//int findPassengerById(Passenger* list, int len,int id)
int ePassenger_findPassengerById(ePassenger toSearchStruc[], int length, int id);
int ePassenger_searchUsedIndex(ePassenger toSearchStruc[], int length);
//int sortPassengers(Passenger* list, int len, int order)
int ePassenger_Sort(ePassenger passengerList[], int TAM, int order);
//int sortPassengersByCode(Passenger* list, int len, int order)
int ePassenger_totalPrice(ePassenger passengerList[], int passengerLength, float *priceTotal);
int ePassenger_totalPassager(ePassenger passengerList[], int passengerLength, float *totalPassagers);
int ePassenger_passengerOverAverage(ePassenger passengerList[], int passengerLength, float averagePrice, int *overPrice);

#endif /* EPASSENGER_H_ */

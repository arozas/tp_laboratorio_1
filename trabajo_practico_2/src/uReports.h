/*
 * uReports.h
 *
 * Created on: 4 may. 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Esta bilioteca contiene los datos de la relación entre eFlights y ePassengers.
 * Versión 1.0 del 13 de Mayo de 2022.*/

#ifndef UREPORTS_H_
#define UREPORTS_H

// **************************************   LIST DEFINES   *************************************
#define MAX_PASSENGER 2000
#define MAX_FLIGHT 100
// *******************************************   ID   ******************************************
#define STARTING_PASSENGER_ID 1000
#define STARTING_FLIGHT_ID 500
// **************************************   MENU DEFINES   *************************************
#define RETRIES 3
#define MENU_OPTIONS 6
#define SUBMENU_OPTIONS 4
#define SORT_MENU 2
// ************************************* SORT ORDER DEFINES  ************************************
#define ORDER_UP 1
#define ORDER_DOWN 0
// *************************************** OTHER DEFINES  **************************************
#define REGISTERED -1
#define FLIGHTSTATUS 4

#include "ePassenger.h"
#include "eFlight.h"

int uReports_registerArray(ePassenger toRegisterStruc[], int length, eFlight toRegisterFlight[], int flightLenght);
ePassenger uReports_ModifyOne(ePassenger passengerList, eFlight flighList[], int flightLength);
int uReports_ModifyArray(ePassenger toMofiedStruc[], int length, eFlight flighList[], int flightLength);
int uReports_remove(ePassenger passengerList[], int passengerLength, eFlight flighList[], int flightLength);
int uReports_sort(ePassenger passengerList[], int passengerLength, int order);
int uReports_Operations(ePassenger passengerList[], int passengerLength);
int uReport_printPassengerByFlghtStatus(ePassenger toPrintStruc[], int length, eFlight flightList[], int flightLenght, int flightStatus);
void uReports_ForcePassengers(ePassenger passengerList[], eFlight flightList[]);
void uReports_cantModifyMsg(void);
void uReports_cantRemoveMsg(void);
void uReports_cantReportMsg(void);
void uReports_ForceLoadMsg(void);
void uReports_endProgramMsg(void);


#endif /* UREPORTS_H_ */

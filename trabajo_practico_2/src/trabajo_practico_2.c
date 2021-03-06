/*
 ============================================================================
 Name        : trabajo_practico_2.c
 Author      : Alejandro Alberto Martín Rozas - División H.
 Version     : 1.0 del 10 de Mayo del 2022
 Objetive	 : Crear un sistema para administrar los pasajeros de cada vuelo
 	 	 	 : de un Aerolinea.
 Description : Trabajo Practico 2 - Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "uReports.h"

int main(void)
{
	ePassenger passengerList[MAX_PASSENGER];
	eFlight flightList[MAX_FLIGHT];
	ePassenger_init(passengerList, MAX_PASSENGER);
	eFlight_init(flightList, MAX_FLIGHT);

	int menu;
	int reportsMenu;
	int sortMenu;
	do
	{
		menu=menu_menu
				("TRABAJO PRACTICO 2",
						"\n1 - ALTAS."
						"\n2 - MODIFICAR."
						"\n3 - BAJA."
						"\n4 - INFORMAR."
						"\n5 - CARGA FORZADA"
						"\n6 - SALIR.",
						"ERROR INTENTE DE NUEVO.",
						RETRIES,
						MENU_OPTIONS);
		switch(menu)
		{
		case 1:
			uReports_registerArray(passengerList, MAX_PASSENGER, flightList, MAX_FLIGHT);
			break;
		case 2:
			if(ePassenger_searchUsedIndex(passengerList, MAX_PASSENGER) != REGISTERED)
			{
				uReports_ModifyArray(passengerList, MAX_PASSENGER, flightList, MAX_FLIGHT);
			}
			else
			{
				uReports_cantModifyMsg();
			}
			break;
		case 3:
			if(ePassenger_searchUsedIndex(passengerList, MAX_PASSENGER) != REGISTERED)
			{
				uReports_remove(passengerList, MAX_PASSENGER, flightList, MAX_FLIGHT);
			}
			else
			{
				uReports_cantRemoveMsg();
			}
			break;
		case 4:
			if(ePassenger_searchUsedIndex(passengerList, MAX_PASSENGER) != REGISTERED)
			{
				do
				{
					reportsMenu = menu_menu
							("INFORMAR:",
									"\n1 - LISTADO PASAJEROS (ORDEN ALFABETICO)."
									"\n2 - PRECIOS: TOTAL, PROMEDIOS Y PASAJEROS POR ARRIBA PROMEDIO."
									"\n3 - LISTADO DE PASAJEROS VUELOS ACTIVOS."
									"\n4 - SALIR.",
									"ERROR, REINGRESE OPCIÓN <1-4>:.",
									RETRIES,
									SUBMENU_OPTIONS);
					switch(reportsMenu)
					{
					case 1:
						sortMenu = menu_menu
						("LISTAR PASAJER0S",
								"\n1 - POR ORDEN ALFABETICO ASCENDENTE."
								"\n2 - POR ORDEN ALFABETICO DESCENDENTE.",
								"ERROR, REINGRESE OPCIÓN <1-2>:",
								RETRIES,
								SORT_MENU);
						switch(sortMenu)
						{
						case 1:
							uReports_sort(passengerList, MAX_PASSENGER, ORDER_UP);
							break;
						case 2:
							uReports_sort(passengerList, MAX_PASSENGER, ORDER_DOWN);
							break;
						}
						break;
						case 2:
							uReports_Operations(passengerList,MAX_PASSENGER);
							break;
						case 3:
							uReport_printPassengerByFlghtStatus(passengerList,MAX_PASSENGER, flightList, MAX_FLIGHT, FLIGHTSTATUS);
							break;
					}
				}
				while(reportsMenu < SUBMENU_OPTIONS);
			}
			else
			{
				{
					uReports_cantReportMsg();
				}
			}
			break;
		case 5:
			uReports_ForcePassengers(passengerList, flightList);
			uReports_ForceLoadMsg();
			break;
		case 6:
			puts("Extras");
			break;
		}
	}
	while( menu < MENU_OPTIONS);

	uReports_endProgramMsg();

	return EXIT_SUCCESS;
}

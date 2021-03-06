/*
 * eFlight.c
 *
 * Created on: 5 may. 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Esta bilioteca contiene las funciones de la estructura eFlights
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#include "eFlight.h"

/// @fn int eFlight_init(eFlight[], int)
/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all position of the array
///
/// @param eFlightList Pointer to array of Flights
/// @param length Array length
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int eFlight_init(eFlight eFlightList[], int length)
{
	int rtn = -1;
	int i;

	if (eFlightList != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				eFlightList[i].isEmpty = TRUE;
			}
		}
	}
	return rtn;
}
/// @fn int eFlight_searchEmptyIndex(eFlight[], int)
/// @brief Search for an empty index in the array.
///
/// @param toSearchStruc The array where to search for an empty index.
/// @param length Array length.
/// @return return the free index or -1 if there is an error.
int eFlight_searchEmptyIndex(eFlight toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;

	if (toSearchStruc != NULL) {
		if (length > 0) {
			//ESTA OK
			for (i = 0; i < length; i++) {
				if (toSearchStruc[i].isEmpty == TRUE)
				{
					flag = 1;
					rtn = i;
					break;
				}
			}

			if (flag == 0)
			{
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}
/// @fn int eFlight_searchUsedIndex(eFlight[], int)
/// @brief It searches the array for the first index with loaded data, in this way it is verified that the array has information.
///
/// @param toSearchStruc The array where to search for an used index.
/// @param length Array length.
/// @return return the used index or -1 if there is an error.
int eFlight_searchUsedIndex(eFlight toSearchStruc[], int length)
{
	int rtn = -1;
	int i;

	if (toSearchStruc != NULL && length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (toSearchStruc[i].isEmpty == FALSE)
			{
				rtn = i;
				break;
			}
		}

	}

	return rtn;
}
/// @fn void eFlight_printOne(eFlight)
/// @brief Prints the information of a flight.
///
/// @param toPrintStruc The array of flights where it takes the information to print on the console.
void eFlight_printOne(eFlight toPrintStruc)
{
	printf(	"\n------------------------------------------------------------------------------------------|");
    printf(
		    "\n%-6d%-15s",
			toPrintStruc.id,
			toPrintStruc.flycode);
	switch(toPrintStruc.statusFlight)
	{
	case SCHEDULED:
		printf("%-15s","EN HORARIO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case DELAYED:
		printf("%-15s","ATRASADO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case DEPARTED:
		printf("%-15s","VUELO SALIÓ A DESTINO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case IN_AIR:
		printf("%-15s","EN VUELO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case EXPECTED:
		printf("%-15s","VUELO ESPERADO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case DIVERTED:
		printf("%-15s","VUELO DESVIADO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case RECOVERY:
		printf("%-15s","VUELO EN RECUPERACIÓN");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case LANDED:
		printf("%-15s","VUELO ATERRIZADO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case ARRIVED:
		printf("%-15s","VUELO EN DESTINO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case CANCELLED:
		printf("%-15s","CANCELADO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	case PAST_FLIGHT:
		printf("%-15s","VUELO PASADO");
		printf("\n------------------------------------------------------------------------------------------|");
		break;
	}
}
/// @fn int eFlight_printAll(eFlight[], int)
/// @brief Prints all the information of all the flights loaded in the array.
///
/// @param The array of flights where it takes the information to print on the console.
/// @param length Array length.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int eFlight_printAll(eFlight toPrintStruc[], int length)
{
	int rtn = -1;
	int i;

	if (toPrintStruc != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				if (toPrintStruc[i].isEmpty == FALSE)
				{
					eFlight_printOne(toPrintStruc[i]);
				}
			}
		}
	}
	return rtn;
}
/// @fn eFlight eFlight_create()
/// @brief Take a list of flights and load data into the structure.
///
/// @param passengerList The array where it loads the data of the elements of the structure.
/// @return return 0 if its ok or -1 if there is an error.
int eFlight_create(eFlight *flightList)
{
	int rtn = -1;

	eFlight eFlightBuffer;
	int flightStatusMenu;

	if(input_getStringletters("INGRESE CÓDIGO DE VUELO:", RETRIES, "ERROR", eFlightBuffer.flycode, FLYCODE_LENGTH)==0)
	{
		flightStatusMenu=menu_menu("ELIJA EL ESTADO DEL VUELO",
				"\n1 - EN HORARIO."
				"\n2 - ATRASADO."
				"\n3 - VUELO SALIÓ A DESTINO."
				"\n4 - EN VUELO."
				"\n5 - VUELO ESPERADO."
				"\n6 - VUELO DESVIADO."
				"\n7 - VUELO EN RECUPERACIÓN."
				"\n8 - VUELO ATERRIZADO."
				"\n9 - VUELO EN DESTINO."
				"\n10 - CANCELADO."
				"\n11 - VUELO PASADO."
				,"ERROR INTENTE DE NUEVO"
				, RETRIES
				, 11);
		if(flightStatusMenu!=-1)
		{
		switch (flightStatusMenu)
		{
		case SCHEDULED:
			eFlightBuffer.statusFlight=SCHEDULED;
			break;
		case DELAYED:
			eFlightBuffer.statusFlight=DELAYED;
			break;
		case DEPARTED:
			eFlightBuffer.statusFlight=DEPARTED;
			break;
		case IN_AIR:
			eFlightBuffer.statusFlight=IN_AIR;
			break;
		case EXPECTED:
			eFlightBuffer.statusFlight=EXPECTED;
			break;
		case DIVERTED:
			eFlightBuffer.statusFlight=DIVERTED;
			break;
		case RECOVERY:
			eFlightBuffer.statusFlight=RECOVERY;
			break;
		case LANDED:
			eFlightBuffer.statusFlight=LANDED;
			break;
		case ARRIVED:
			eFlightBuffer.statusFlight=ARRIVED;
			break;
		case CANCELLED:
			eFlightBuffer.statusFlight=CANCELLED;
			break;
		case PAST_FLIGHT:
			eFlightBuffer.statusFlight=PAST_FLIGHT;
			break;
		}
		strncpy(flightList->flycode,eFlightBuffer.flycode,FLYCODE_LENGTH);
		flightList->statusFlight=eFlightBuffer.statusFlight;
		rtn=0;
		}
	}
	return rtn;
}
/// @fn int eFlight_searchIndexId(eFlight[], int)
/// @brief Search the array for a specific flight based on its Id.
///
/// @param toSearchStruc Array where the search will be performed.
/// @param length Array length.
/// @return return index of the flights if its ok  or -1 if there is an error.
int eFlight_searchIndexId(eFlight toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;
	int searchId;

	if (toSearchStruc != NULL) {
		if (length > 0) {

			eFlight_printAll(toSearchStruc, length);
			input_getInt("INGRESE ID: ", 1 , 0,1000, "ERROR, VUELVA A INGRESAR ID:", &searchId);

			for (i = 0; i < length; i++) {
				if (toSearchStruc[i].isEmpty == FALSE) {
					if (toSearchStruc[i].id == searchId) {
						flag = 1;
						rtn = i;
						break;
					}
				}
			}

			if (flag == 0) {
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}
/// @fn int eFlight_searchIndexFlycodeStatus(eFlight[], int, char[], int)
/// @brief
///
/// @param toSearchStruc Array where the search will be performed.
/// @param length Array length.
/// @param flycode The flight code to compare.
/// @param status The state we are looking for is in int format.
/// @return return index of the flights if its ok  or -1 if there is an error.
int eFlight_searchIndexFlycodeStatus(eFlight toSearchStruc[], int length, char flycode[], int status)
{
	int rtn = -1;
	int flag = 0;
	int i;

	if (toSearchStruc != NULL)
	{
		if (length > 0)
		{
			for (i = 0; i < length; i++)
			{
				if (toSearchStruc[i].isEmpty == FALSE)
				{
					if(toSearchStruc[i].statusFlight==status)
					{
						if (strcmp(toSearchStruc[i].flycode,flycode)==0)
						{
							flag = 1;
							rtn = i;
							break;
						}
					}
				}
			}

			if (flag == 0)
			{
				rtn = -2;
			}
		} else {
			rtn = -3;
		}
	} else {
		rtn = -4;
	}

	return rtn;
}


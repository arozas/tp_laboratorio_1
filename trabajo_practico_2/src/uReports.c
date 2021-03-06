/*
 * uReports.c
 *
 * Created on: 4 may. 2022
 * Author: Alejandro Alberto Martín Rozas - División H.
 * Esta bilioteca contiene las funciones de la relación entre eFlights y ePassengers.
 * Versión 1.0 del 13 de Mayo de 2022.*/

#include "uReports.h"

//********************************************************************  STATICS FUNCTIONS  ********************************************************************

static int uReports_passengerIDgetUniqueID(void);
static int uReports_flightIDgetUniqueID(void);
static int passengerIdAutoincremental = STARTING_PASSENGER_ID;
static int flightIdAutoincremental = STARTING_FLIGHT_ID;
static void uReports_noPassengerIDMsg(void);
static void uReports_noFlightIDMsg(void);
static void uReports_flightListFullMsg(void);
static void uReports_flightCreatedMsg(void);
static void uReports_flightErrorMsg(void);
static void uReports_noFlightsMsg(void);
static void uReports_passengerRegSuccessMsg(void);
static void uReports_passengerRegCanceledMsg(void);
static void uReports_passengerRegErrorMsg(void);
static void uReports_passengerFullMsg(void);
static void uReports_modSuccesMsg(void);
static void uReports_modCanbceledMsg(void);
static void uReports_passengerPrintHead(void);
static void uReports_flightsPrintHead(void);

//**********************************************************************  GENERATE IDs   **********************************************************************

/// @fn int uReports_passengerIDgetUniqueID()
/// @brief Generates a unique ID for passengers. It is autoincremental.
///
/// @return Return the generated ID.
static int uReports_passengerIDgetUniqueID()
{
	return passengerIdAutoincremental++;
}
/// @fn int uReports_flightIDgetUniqueID()
/// @brief Generates a unique ID for flights. It is autoincremental.
///
/// @return Return the generated ID.
static int uReports_flightIDgetUniqueID()
{
	return flightIdAutoincremental++;
}

//**********************************************************************  STATIC MSG   **********************************************************************

/// @fn void uReports_noPassengerIDMsg()
/// @brief prints a message informing that no passenger with that ID was found.
///
static void uReports_noPassengerIDMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n   NO EXISTE PASAJERO CON ESE ID");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_noFlightIDMsg()
/// @brief prints a message informing that no flight with that ID was found
///
static void uReports_noFlightIDMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n   NO EXISTE VUELO CON ESE ID");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_flightListFullMsg()
/// @brief prints message informing that the list of flights is full.
///
static void uReports_flightListFullMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n     LISTA DE VUELOS LLENA");
	printf("\n     ELIJA UN VUELO EXITENTE");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_flightCreatedMsg()
/// @brief prints message informing that the flight was successfully created.
///
static void uReports_flightCreatedMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n         ¡VUELO CREADO!");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_flightErrorMsg()
/// @brief prints message informing that there was an error loading flight data.
///
static void uReports_flightErrorMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n    ¡ERROR DE CARGA DE VUELO!");
	printf("\n       ¡VUELVA A CARGARLO!");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_noFlightsMsg()
/// @brief prints a message informing that there are no flights loaded in the system, one must be loaded.
///
static void uReports_noFlightsMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n    ¡NO HAY VUELOS CARGADOS!");
	printf("\n        DEBE CARGAR UNO");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_passengerRegSuccessMsg()
/// @brief prints a message informing that the loading of passenger data was successful.
///
static void uReports_passengerRegSuccessMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n         ¡CARGA EXITOSA!");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_passengerRegCanceledMsg()
/// @brief prints a message informing that the loading of passenger data was canceled.
///
static void uReports_passengerRegCanceledMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n         CARGA CANCELADA");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_passengerRegErrorMsg()
/// @brief prints a message informing that the loading of passenger data produced an error, the data loading was cancelled.
///
static void uReports_passengerRegErrorMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n    ERROR EN LA CARGA DE DATOS");
	printf("\n           DEL PASAJERO");
	printf("\n        ¡CARGA CANCELADA!");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_passengerFullMsg()
/// @brief prints a message informing that the passenger list is full, no more can be loaded.
///
static void uReports_passengerFullMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n    LISTA DE PASAJEROS LLENA");
	printf("\n     GENERE LA BAJA DE UNO");
	printf("\n|:::::::::::::::::::::::::::::::::|");
}
/// @fn void uReports_modSuccesMsg()
/// @brief prints a message informing that the data modification was successful.
///
static void uReports_modSuccesMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n     ¡MODIFICACIÓN EXITOSA!");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_modCanbceledMsg()
/// @brief prints a message informing that the data modification was cancelled.
///
static void uReports_modCanbceledMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n     MODIFICACIÓN CANCELADA");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_passengerPrintHead()
/// @brief  Prints the passenger header on the console.
///
static void uReports_passengerPrintHead()
{
	printf(
			"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
			"\n                                         PASAJEROS"
			"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
	printf("\n%-6s%-15s%-15s%-15s%-20s%-20s","ID","NOMBRE","APELLIDO","PRECIO","TIPO DE PASAJERO","CODIGO DE VUELO");
}
/// @fn void uReports_flightsPrintHead()
/// @brief Prints the flights header on the console.
///
static void uReports_flightsPrintHead()
{
	printf(
			"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
			"\n                                          VUELOS"
			"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
	printf("\n%-6s%-15s%-15s","ID","CODIGO","ESTADO");
}
//**********************************************************************  REGISTER PASSANGERS   **********************************************************************

/// @fn int uReports_registerArray(ePassenger[], int, eFlight[], int)
/// @brief function that registers a passenger and allows to assign or create a flight for it.
///
/// @param toRegisterStruc  	Passengers array where the loaded data of the passenger will be saved.
/// @param length  				Passenger array length.
/// @param toRegisterFlight 	Array of flights, from which the flight assigned to the passenger will be chosen or loaded.
/// @param flightLenght 		Flight array length..
/// @return						Return (-1) if Error [Invalid length or NULL pointer] - the index of the passenger if Ok.
int uReports_registerArray(ePassenger toRegisterStruc[], int length, eFlight toRegisterFlight[], int flightLenght)
{
	int rtn = -1;
	int emptyPassengerIndex;
	int emptyFlightIndex;
	int menu;
	int usedFlightIndex;
	usedFlightIndex=0;
	int subMenu;

	int inputValidationPassenger;
	int inputValidationFlight;

	ePassenger passengerBuffer;
	eFlight flightBuffer;

	emptyPassengerIndex = ePassenger_searchEmptyIndex(toRegisterStruc, length);


	if (toRegisterStruc != NULL && toRegisterFlight != NULL)
	{
		if (length > 0 && flightLenght >0)
		{
			if (emptyPassengerIndex >= 0)
			{
				inputValidationPassenger=ePassenger_create(&passengerBuffer);

				if (inputValidationPassenger==0)
				{
					emptyFlightIndex = eFlight_searchEmptyIndex(toRegisterFlight, flightLenght);

					do
					{
						if(emptyFlightIndex >= 0)
						{
							menu=menu_menu
									("VUELOS",
											"\n1 - CARGAR VUELO NUEVO."
											"\n2 - ELEGIR VUELO EXISTENTE.",
											"ERROR, INGRESE UNA OPCIÓN <1-2>:",
											RETRIES,
											2);
						}
						else
						{
							uReports_flightListFullMsg();
							menu=2;
						}
						switch(menu)
						{
						case 1:
							inputValidationFlight=eFlight_create(&flightBuffer);
							if(inputValidationFlight==0)
							{
								flightBuffer.id=uReports_flightIDgetUniqueID();
								flightBuffer.isEmpty=FALSE;
								uReports_flightCreatedMsg();
								menu=3;
							}
							else
							{
								uReports_flightErrorMsg();
								menu=1;
							}
							break;
						case 2:
							usedFlightIndex=eFlight_searchUsedIndex(toRegisterFlight, flightLenght);
							if(usedFlightIndex!=-1)
							{
								subMenu=menu_menu
										("CARGAR VUELO EXISTENTE",
												"\n1 - INGRESAR ID DE VUELO."
												"\n2 - VOLVER AL MENU.",
												"ERROR, INGRESE UNA OPCIÓN <1-2>:",
												RETRIES,
												2);
								switch(subMenu)
								{
								case 1:
									uReports_flightsPrintHead();
									emptyFlightIndex=eFlight_searchIndexId(toRegisterFlight, flightLenght);
									if(emptyFlightIndex < 0)
									{
										uReports_noFlightIDMsg();
										emptyFlightIndex=0;
										usedFlightIndex=-1;
									}
									else
									{
										flightBuffer=toRegisterFlight[emptyFlightIndex];
									}
									break;
								}
							}
							else
							{
								uReports_noFlightsMsg();
							}
							break;
						}
					}while(menu<3 && usedFlightIndex==-1);

					passengerBuffer.id = uReports_passengerIDgetUniqueID();
					passengerBuffer.isEmpty = FALSE;
					strncpy(passengerBuffer.flycode,flightBuffer.flycode,FLYCODE_LENGTH);
					ePassenger_printOne(passengerBuffer);

					if(menu_confirm("¿DESEA REALIZAR LA CARGA?"
							"\nINGRESE RESPUESTA <S/N> :"
							, "ERROR, REINGRESE <S/N>:")==1)
					{
						ePassenger_add(toRegisterStruc, length,
								passengerBuffer.id,
								passengerBuffer.name,
								passengerBuffer.lastname,
								passengerBuffer.price,
								passengerBuffer.typePassenger,
								flightBuffer.flycode);
						toRegisterFlight[emptyFlightIndex] = flightBuffer;
						uReports_passengerRegSuccessMsg();
						rtn = emptyPassengerIndex;
					}
					else
					{
						uReports_passengerRegCanceledMsg();
					}
				}
				else
				{
					uReports_passengerRegErrorMsg();
				}
			}
			else
			{
				uReports_passengerFullMsg();
			}
		}
	}
	else
	{

	}
	return rtn;
}
//**********************************************************************  MODIFY PASSANGERS   **********************************************************************
/// @fn ePassenger uReports_ModifyOne(ePassenger, eFlight[], int)
/// @brief This function modifies a passenger.
///
/// @param passengerList The list where the passenger to modify is.
/// @param flighList     The list where the flights associated to the passanger is.
/// @param flightLength  The length of the flight array.
/// @return The passenger returns with all the modifications made.
ePassenger uReports_ModifyOne(ePassenger passengerList, eFlight flighList[], int flightLength)
{
	int menu;
	int subMenu;
	int passengerTypeMenu;
	int emptyFlightIndex;
	emptyFlightIndex = -1;

	int usedFlightIndex;
	int inputValidationFlight;

	eFlight flightBuffer;


	do{
		menu = menu_menu("SELECCIONE QUE MODIFICAR",
				"\n\n1 - NOMBRE."
				"\n2 - APELLIDO."
				"\n3 - PRECIO."
				"\n4 - TIPO DE PASAJERO."
				"\n5 - MODIFICAR EL CÓDIGO DE VUELO"
				"\n6 - DEJAR DE MODIFICAR",
				"ERROR, INGRESE UNA OPCIÓN <1-6>:", 2, 6);

		switch (menu)
		{
		case 1:
			input_getStringletters("MODIFIQUE NOMBRE:",RETRIES, "ERROR", passengerList.name, NAME_LENGTH);
			break;
		case 2:
			input_getStringletters("MODIFIQUE APELLIDO:",RETRIES, "ERROR", passengerList.lastname, NAME_LENGTH);
			break;
		case 3:
			input_getFloat("MODIFIQUE PRECIO:", RETRIES, 0, MAX_PRICE, "ERROR", &passengerList.price);
			break;
		case 4:
			passengerTypeMenu=menu_menu("ELIJA EL TIPO DE PASAJERO",
					"\n1 - ADULTO."
					"\n2 - NIÑO."
					"\n3 - INFANTE."
					,"ERROR, INGRESE OPCION <1-3>:"
					, RETRIES
					, 3);
			switch (passengerTypeMenu)
			{
			case ADULT:
				passengerList.typePassenger=ADULT;
				break;
			case CHILDREN:
				passengerList.typePassenger=CHILDREN;
				break;
			case INFANT:
				passengerList.typePassenger=INFANT;
				break;
			}
			break;
			case 5:
				emptyFlightIndex = eFlight_searchEmptyIndex(flighList, flightLength);
				do
				{
					if(emptyFlightIndex >= 0)
					{
						menu=menu_menu
								("VUELOS",
										"\n1 - CARGAR VUELO NUEVO."
										"\n2 - ELEGIR VUELO EXISTENTE.",
										"ERROR, INGRESE UNA OPCIÓN <1-2>:",
										RETRIES,
										2);
					}
					else
					{
						uReports_flightListFullMsg();
						menu=2;
					}
					switch(menu)
					{
					case 1:
						inputValidationFlight=eFlight_create(&flightBuffer);
						if(inputValidationFlight==0)
						{
							flightBuffer.id=uReports_flightIDgetUniqueID();
							flightBuffer.isEmpty=FALSE;
							uReports_flightCreatedMsg();
							menu=3;
						}
						else
						{
							uReports_flightErrorMsg();
							menu=1;
						}
						break;
					case 2:
						uReports_flightsPrintHead();
						usedFlightIndex=eFlight_searchUsedIndex(flighList, flightLength);
						if(usedFlightIndex!=-1)
						{
							subMenu=menu_menu
									("CARGAR VUELO EXISTENTE",
											"\n1 - INGRESAR ID DE VUELO."
											"\n2 - VOLVER AL MENU.",
											"ERROR, INGRESE UNA OPCIÓN <1-2>:",
											RETRIES,
											2);
							switch(subMenu)
							{
							case 1:
								emptyFlightIndex=eFlight_searchIndexId(flighList, flightLength);
								if(emptyFlightIndex < 0)
								{
									uReports_noFlightIDMsg();
									emptyFlightIndex=0;
									usedFlightIndex=-1;
								}
								else
								{
									flightBuffer=flighList[emptyFlightIndex];
								}
								break;
							}
						}
						break;
					}
				}while(menu<3 && usedFlightIndex==-1);
				break;
		}
	}while(menu<6);
	if(emptyFlightIndex!=-1)
	{
		strncpy(passengerList.flycode,flightBuffer.flycode,FLYCODE_LENGTH);
	}
	ePassenger_printOne(passengerList);
	return passengerList;
}
/// @fn int uReports_ModifyArray(ePassenger[], int, eFlight[], int)
/// @brief Function that allows choosing the passenger to modify.
///
/// @param toMofiedStruc Array where the passengers to modify are located.
/// @param length The length of the passengers array.
/// @param flighList The list where the flights associated to the passanger is.
/// @param flightLength The length of the flight array.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - return 0 if Ok.
int uReports_ModifyArray(ePassenger toMofiedStruc[], int length, eFlight flighList[], int flightLength)
{
	int rtn = -1;
	int idBuffer;
	int toModStrucIndex;
	ePassenger eGenBuffer;

	if (toMofiedStruc != NULL)
	{
		if (length > 0)
		{
			ePassenger_printAll(toMofiedStruc, length);
			input_getInt("INGRESE ID:", RETRIES, 0, 3000, "ERROR, REINGRESE ID:", &idBuffer);
			toModStrucIndex = ePassenger_findPassengerById(toMofiedStruc,length, idBuffer);
			if (toModStrucIndex < 0)
			{
				uReports_noPassengerIDMsg();
				rtn = -2;
			}
			else
			{
				eGenBuffer = toMofiedStruc[toModStrucIndex];
				eGenBuffer = uReports_ModifyOne(eGenBuffer, flighList, flightLength);
				if(menu_confirm("¿DESEA REALIZAR LA MODIFICACIÓN?"
						"\nINGRESE RESPUESTA <S/N> :"
						, "ERROR, REINGRESE <S/N>:")==1)
				{
					toMofiedStruc[toModStrucIndex] = eGenBuffer;
					uReports_modSuccesMsg();
					rtn=0;
				}
				else
				{
					uReports_modCanbceledMsg();
					rtn=-5;
				}

			}

		}
	}

	return rtn;
}
//**********************************************************************  REMOVE PASSANGERS   **********************************************************************
/// @fn int uReports_remove(ePassenger[], int, eFlight[], int)
/// @brief Function to remove a passenger, changes the state of isEmpty to True.
///
/// @param passengerList Array of the passenger list where the passenger to remove is found.
/// @param passengerLength Passenger array size.
/// @param flighList Arrays of flights where the flight associated with the passenger to be removed is found.
/// @param flightLength Flights array size.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - return 0 if Ok.
int uReports_remove(ePassenger passengerList[], int passengerLength, eFlight flighList[], int flightLength)
{
	int rtn = -1;
	int searchBuffer;
	int idBuffer;
	if(passengerList != NULL && flighList != NULL
			&& passengerLength >0 && flightLength >0)
	{
		ePassenger_printAll(passengerList, passengerLength);
		input_getInt("INGRESE ID:", RETRIES, 0, 3000, "ERROR, REINGRESE ID:", &idBuffer);
		searchBuffer=ePassenger_findPassengerById(passengerList, passengerLength, idBuffer);
		if (searchBuffer < 0)
		{
			uReports_noPassengerIDMsg();
			rtn = -2;
		}
		else
		{
			ePassenger_remove(passengerList, passengerLength, searchBuffer);
			rtn=0;
		}
	}

	return rtn;
}
//**********************************************************************  SORT	 PASSANGERS   **********************************************************************
/// @fn int uReports_sort(ePassenger[], int, int)
/// @brief Function that orders the passengers, it does it inside a buffer without modifying the original array.
///		   Indicate UP or DOWN order.
/// @param passengerList Array with the list of passengers to order.
/// @param passengerLength Passenger array size.
/// @param order Order in which to order.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - return 0 if Ok.
int uReports_sort(ePassenger passengerList[], int passengerLength, int order)
{
	int rtn = -1;
	int i;
	ePassenger bufferList[passengerLength];
	if(passengerList != NULL && passengerLength >0)
	{
		for ( i = 0; i < passengerLength; ++i)
		{
			bufferList[i] = passengerList[i];
		}
		ePassenger_Sort(bufferList, passengerLength, 1);
		uReports_passengerPrintHead();
		ePassenger_printAll(bufferList, passengerLength);
		rtn=0;
	}

	return rtn;
}
/// @fn int uReports_Operations(ePassenger[], int)
/// @brief Function that generates the requested reports. Total price, average price and passengers above the average price.
///
/// @param passenger List List of passengers from which the data for the reports is taken.
/// @param passengerLength Passenger array size
/// @return Return (-1) if Error [Invalid length or NULL pointer] - return 0 if Ok.
//**********************************************************************  OPERATION	 PASSANGERS   **********************************************************************
int uReports_Operations(ePassenger passengerList[], int passengerLength)
{
	int rtn =-1;
	float totalPrice=0;
	int higherprice=0;
	float totalPassenger=0;
	float averagePrice;
	if (passengerList != NULL && passengerLength >0)
	{

		ePassenger_totalPrice(passengerList, passengerLength, &totalPrice);
		ePassenger_totalPassager(passengerList, passengerLength, &totalPassenger);
		operations_Split(totalPrice, totalPassenger, &averagePrice);
		ePassenger_passengerOverAverage(passengerList, passengerLength, averagePrice, &higherprice);

		printf(
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|"
				"\n                                        INFORMES:"
				"\n|:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|");
		printf(	"\n------------------------------------------------------------------------------------------|");
		printf("\n TOTAL RECAUDADO: $%.2f",totalPrice);
		printf(	"\n------------------------------------------------------------------------------------------|");
		printf("\n PRECIO PROMEDIO POR PASAJERO: $%.2f", averagePrice);
		printf(	"\n------------------------------------------------------------------------------------------|");
		printf("\n PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO: %d", higherprice);
		printf(	"\n------------------------------------------------------------------------------------------|\n");
		rtn=0;
	}

	return rtn;
}
//**********************************************************************  PRINT ACTIVE PASSANGERS   **********************************************************************
/// @fn int uReport_printOnAir(ePassenger[], int, eFlight[], int)
/// @brief Prints the passengers with the declared flight status on the console, by default ON_AIR (ACTIVE)
///
/// @param toPrintStruc Array with the list of passengers.
/// @param length Passenger array size.
/// @param flightList Arrays of flights.
/// @param flightLenght  Flights array size.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - return 0 if Ok.
int uReport_printPassengerByFlghtStatus(ePassenger toPrintStruc[], int length, eFlight flightList[], int flightLenght, int flightStatus)
{
	int rtn = -1;
	int i;
	int j;
	int x;

	if (toPrintStruc != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				for (j = 0; j < flightLenght; j++)
				{
					if (toPrintStruc[i].isEmpty == FALSE && flightList[j].isEmpty == FALSE)
					{
						if (flightList[j].statusFlight==flightStatus)
						{
							x=eFlight_searchIndexFlycodeStatus(flightList, length, toPrintStruc[i].flycode, flightStatus);

							if(strcmp(toPrintStruc[i].flycode,flightList[x].flycode)==0)
							{
								ePassenger_printOne(toPrintStruc[i]);
								rtn=0;
							}
						}
					}
				}
			}
		}
	}
	return rtn;
}
//**********************************************************************  FORCE LOAD DATA   **********************************************************************
/// @fn void uReports_ForcePassengers(ePassenger[], eFlight[])
/// @brief Function that forces the loading of data in the arrays to be able to do tests.
///
/// @param passengerList Array with the list of passengers.
/// @param flightList Arrays of flights.
void uReports_ForcePassengers(ePassenger passengerList[], eFlight flightList[])
{
	ePassenger passengerBuffer[10];
	eFlight flightBuffer[5];

	passengerBuffer[0].id=1010;
	strcpy(passengerBuffer[0].name,"MARIANO");
	strcpy(passengerBuffer[0].lastname,"ROZAS");
	passengerBuffer[0].price=9700.33;
	passengerBuffer[0].typePassenger=3;
	strcpy(passengerBuffer[0].flycode,"CRGFRZCUA");
	passengerBuffer[0].isEmpty=FALSE;

	passengerBuffer[1].id=1011;
	strcpy(passengerBuffer[1].name,"MATHIAS");
	strcpy(passengerBuffer[1].lastname,"BUSTAMANTE");
	passengerBuffer[1].price=90000;
	passengerBuffer[1].typePassenger=2;
	strcpy(passengerBuffer[1].flycode,"CRGFRZUNO");
	passengerBuffer[1].isEmpty=FALSE;

	passengerBuffer[2].id=1012;
	strcpy(passengerBuffer[2].name,"MARINA");
	strcpy(passengerBuffer[2].lastname,"CARDOZO");
	passengerBuffer[2].price=123000.33;
	passengerBuffer[2].typePassenger=1;
	strcpy(passengerBuffer[2].flycode,"CRGFRZUNO");
	passengerBuffer[2].isEmpty=FALSE;

	passengerBuffer[3].id=1013;
	strcpy(passengerBuffer[3].name,"MARTIN");
	strcpy(passengerBuffer[3].lastname,"HARRY");
	passengerBuffer[3].price=85000;
	passengerBuffer[3].typePassenger=3;
	strcpy(passengerBuffer[3].flycode,"CRGFRZUNO");
	passengerBuffer[3].isEmpty=FALSE;

	passengerBuffer[4].id=1014;
	strcpy(passengerBuffer[4].name,"MAURICIO");
	strcpy(passengerBuffer[4].lastname,"DAVILA");
	passengerBuffer[4].price=70000;
	passengerBuffer[4].typePassenger=1;
	strcpy(passengerBuffer[4].flycode,"CRGFRZDOS");
	passengerBuffer[4].isEmpty=FALSE;

	passengerBuffer[5].id=1015;
	strcpy(passengerBuffer[5].name,"OCTAVIO");
	strcpy(passengerBuffer[5].lastname,"VILLEGAS");
	passengerBuffer[5].price=240000;
	passengerBuffer[5].typePassenger=2;
	strcpy(passengerBuffer[5].flycode,"CRGFRZDOS");
	passengerBuffer[5].isEmpty=FALSE;

	passengerBuffer[6].id=1016;
	strcpy(passengerBuffer[6].name,"GERMAN");
	strcpy(passengerBuffer[6].lastname,"SCARAFILO");
	passengerBuffer[6].price=33500.50;
	passengerBuffer[6].typePassenger=3;
	strcpy(passengerBuffer[6].flycode,"CRGFRZDOS");
	passengerBuffer[6].isEmpty=FALSE;

	passengerBuffer[7].id=1017;
	strcpy(passengerBuffer[7].name,"SANTIAGO");
	strcpy(passengerBuffer[7].lastname,"FERNANDEZ");
	passengerBuffer[7].price=10000;
	passengerBuffer[7].typePassenger=2;
	strcpy(passengerBuffer[7].flycode,"CRGFRZTRES");
	passengerBuffer[7].isEmpty=FALSE;

	passengerBuffer[8].id=1018;
	strcpy(passengerBuffer[8].name,"GASTON");
	strcpy(passengerBuffer[8].lastname,"RAMIREZ");
	passengerBuffer[8].price=9700.33;
	passengerBuffer[8].typePassenger=2;
	strcpy(passengerBuffer[8].flycode,"CRGFRZTRES");
	passengerBuffer[8].isEmpty=FALSE;

	passengerBuffer[9].id=1019;
	strcpy(passengerBuffer[9].name,"ALEJANDRO");
	strcpy(passengerBuffer[9].lastname,"ROJAS");
	passengerBuffer[9].price= 15200.25;
	passengerBuffer[9].typePassenger=1;
	strcpy(passengerBuffer[9].flycode,"CRGFRZTRES");
	passengerBuffer[9].isEmpty=FALSE;

	flightBuffer[0].id=504;
	strcpy(flightBuffer[0].flycode,"CRGFRZCUA");
	flightBuffer[0].statusFlight=2;
	flightBuffer[0].isEmpty=FALSE;

	flightBuffer[1].id=505;
	strcpy(flightBuffer[1].flycode,"CRGFRZUNO");
	flightBuffer[1].statusFlight=4;
	flightBuffer[1].isEmpty=FALSE;

	flightBuffer[2].id=506;
	strcpy(flightBuffer[2].flycode,"CRGFRZDOS");
	flightBuffer[2].statusFlight=1;
	flightBuffer[2].isEmpty=FALSE;

	flightBuffer[3].id=507;
	strcpy(flightBuffer[3].flycode,"CRGFRZTRES");
	flightBuffer[3].statusFlight=9;
	flightBuffer[3].isEmpty=FALSE;

	passengerList[10]=passengerBuffer[0];
	passengerList[11]=passengerBuffer[1];
	passengerList[12]=passengerBuffer[2];
	passengerList[13]=passengerBuffer[3];
	passengerList[14]=passengerBuffer[4];
	passengerList[15]=passengerBuffer[5];
	passengerList[16]=passengerBuffer[6];
	passengerList[17]=passengerBuffer[7];
	passengerList[18]=passengerBuffer[8];
	passengerList[19]=passengerBuffer[9];
	flightList[04]=flightBuffer[0];
	flightList[05]=flightBuffer[1];
	flightList[06]=flightBuffer[2];
	flightList[07]=flightBuffer[3];
}
//**********************************************************************  MESSAGES MAIN  **********************************************************************
/// @fn void uReports_cantModifyMsg()
/// @brief informs the user that they cannot make changes without first having created a passenger.
void uReports_cantModifyMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n     PARA MOFICAR PASAJEROS");
	printf("\n    DEBE CARGAR AL MENOS UNO");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_cantRemoveMsg()
/// @brief informs the user that they cannot remove a passenger without first having created a one.
void uReports_cantRemoveMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n     PARA DAR DE BAJA PASAJEROS");
	printf("\n  DEBE HABER CARGADO AL MENOS UNO");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_cantReportMsg()
/// @brief informs the user that they cannot make reports without first having created a passenger.
void uReports_cantReportMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n      PARA GENERAR INFORMES");
	printf("\n  DEBE HABER CARGADO AL MENOS");
	printf("\n          UN PASAJERO");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_ForceLoadMsg()
/// @brief informs the user that the force load was successful.
void uReports_ForceLoadMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|"
			"\n     ¡CARGA FORZADA EXITOSA!"
			"\n   YA PUEDE OPERAR LAS OPCIONES"
			"\n|:::::::::::::::::::::::::::::::::|\n");
}
/// @fn void uReports_endProgramMsg()
/// @brief informs the user that the program has ended.
void uReports_endProgramMsg()
{
	printf("\n|:::::::::::::::::::::::::::::::::|");
	printf("\n       FINALIZÓ EL PROGRAMA");
	printf("\n|:::::::::::::::::::::::::::::::::|\n");
}

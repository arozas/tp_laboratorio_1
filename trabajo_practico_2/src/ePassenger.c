/*
 * ePassenger.c
 *
 * Created on: 04 Mayo de 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Biblioteca “ArrayPassenger”
 * Esta bilioteca contiene las funciones de la estructura ePassenger
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#include "ePassenger.h"

/// @fn int ePassenger_init(ePassenger[], int)
///@brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all position of the array
///
///@param list Passenger* Pointer to array of passenger
///@param len int Array length
///@return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int ePassenger_init(ePassenger ePassengerList[], int length)
{
	int rtn = -1;
	int i;

	if (ePassengerList != NULL)
	{
		if (length > 0)
		{
			rtn=0;
			for (i = 0; i < length; i++)
			{
				ePassengerList[i].isEmpty = TRUE;
			}
		}
	}
	return rtn;
}
/// @fn void ePassenger_printOne(ePassenger)
/// @brief Prints the information of a passenger in a column on the console.
///
/// @param toPrintStruc The array of passengers where it takes the information to print on the console.
void ePassenger_printOne(ePassenger toPrintStruc)
{


	printf(	"\n------------------------------------------------------------------------------------------|");
	printf(
			"\n%-6d%-15s%-15s$%-15.2f",
			toPrintStruc.id,
			toPrintStruc.name,
			toPrintStruc.lastname,
			toPrintStruc.price);
	switch(toPrintStruc.typePassenger)
	{
	case ADULT:
		printf("%-20s", "ADULT");
		break;
	case CHILDREN:
		printf("%-20s", "CHILDREN");
		break;
	case INFANT:
		printf("%-20s", "INFANT");
		break;
	}
	printf("%-20s",toPrintStruc.flycode);
}
/// @fn int ePassenger_printAll(ePassenger[], int)
/// @brief Prints all the information of all the passengers loaded in the array.
///
/// @param The array of passengers where it takes the information to print on the console.
/// @param length Array length.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int ePassenger_printAll(ePassenger toPrintStruc[], int length)
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
					ePassenger_printOne(toPrintStruc[i]);
				}
			}
		}
	}
	return rtn;
}
/// @fn int ePassenger_searchEmptyIndex(ePassenger[], int)
/// @brief Search for an empty index in the array.
///
/// @param toSearchStruc The array where to search for an empty index.
/// @param length Array length.
/// @return return the free index or -1 if there is an error.
int ePassenger_searchEmptyIndex(ePassenger toSearchStruc[], int length)
{
	int rtn = -1;
	int flag = 0;
	int i;

	if (toSearchStruc != NULL) {
		if (length > 0)
		{
			for (i = 0; i < length; i++)
			{
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
/// @fn int ePassenger_searchUsedIndex(ePassenger[], int)
/// @brief It searches the array for the first index with loaded data, in this way it is verified that the array has information.
///
/// @param toSearchStruc The array where to search for an used index.
/// @param length Array length.
/// @return return the used index or -1 if there is an error.
int ePassenger_searchUsedIndex(ePassenger toSearchStruc[], int length)
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
/// @fn int ePassenger_create(ePassenger*)
/// @brief Take a list of passengers and load data into the structure.
///
/// @param passengerList The array where it loads the data of the elements of the structure.
/// @return return 0 if its ok or -1 if there is an error.
int ePassenger_create(ePassenger *passengerList)
{
	int rtn=-1;
	ePassenger ePassengerBuffer;
	int passengerTypeMenu;
	if(		input_getStringletters("INGRESE EL NOMBRE DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN NOMBRE VALIDO:", ePassengerBuffer.name, NAME_LENGTH)== 0
			&& input_getStringletters("INGRESE EL APELLIDO DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN APELLIDO VALIDO:", ePassengerBuffer.lastname, NAME_LENGTH) == 0
			&& input_getFloat("INGRESE EL PRECIO DEL VUELO:", RETRIES, MIN_PRICE, MAX_PRICE, "ERROR, INGRESE UN PRECIO VALIDO:", &ePassengerBuffer.price) == 0)
	{
		passengerTypeMenu=menu_menu("ELIJA EL TIPO DE PASAJERO",
				"\n1 - ADULTO."
				"\n2 - NIÑO."
				"\n3 - INFANTE."
				,"ERROR INTENTE DE NUEVO"
				, RETRIES
				, 3);
		if(passengerTypeMenu!=-1)
		{
			switch (passengerTypeMenu)
			{
			case 1:
				ePassengerBuffer.typePassenger=ADULT;
				break;
			case 2:
				ePassengerBuffer.typePassenger=CHILDREN;
				break;
			case 3:
				ePassengerBuffer.typePassenger=INFANT;
				break;
			}
			strncpy(passengerList->name,ePassengerBuffer.name,NAME_LENGTH);
			strncpy(passengerList->lastname,ePassengerBuffer.lastname,NAME_LENGTH);
			passengerList->price=ePassengerBuffer.price;
			passengerList->typePassenger=ePassengerBuffer.typePassenger;

			rtn=0;
		}
		else
		{
			rtn=-3;
		}
	}
	else
	{
		rtn=-2;
	}


	return rtn;
}
/** \brief 	add in a existing list of passengers the values received as parameters
			in the first empty position
 * \param 	list passenger* passenger list where it loads the data entered by the parameters.
 * \param 	len int Array length.
 * \param 	id int Id parameter to load in the passanger.
 * \param 	name[] char name parameter to load in the passanger.
 * \param 	lastName[] char Lastname parameter to load in the passanger.
 * \param 	price float Price parameter to load in the passanger.
 * \param 	typePassenger int Type parameter to load in the passanger.There are 3 types, Adult, Children, Infant.
 * \param 	flycode[] char Flycode parameter to load in the passanger. Foreign key (FK) that relates to the flights structure.
 * \return 	int Return (-1) if Error [Invalid length or NULL pointer or without
			free space] - (0) if Ok
 **/
int ePassenger_add(ePassenger list[], int length, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
	int rtn = -1;
	int emptyIndex;
	ePassenger ePassengerBuffer[length];

	if(list!=NULL
			&& length>0)
	{
		emptyIndex = ePassenger_searchEmptyIndex(list, length);

		if((emptyIndex >= 0))
		{
			ePassengerBuffer[emptyIndex].id=id;
			strncpy(ePassengerBuffer[emptyIndex].name,name,NAME_LENGTH);
			strncpy(ePassengerBuffer[emptyIndex].lastname,lastName,NAME_LENGTH);
			ePassengerBuffer[emptyIndex].price=price;
			ePassengerBuffer[emptyIndex].typePassenger=typePassenger;
			strncpy(ePassengerBuffer[emptyIndex].flycode, flyCode,FLYCODE_LENGTH);
			list[emptyIndex]=ePassengerBuffer[emptyIndex];
			rtn=0;
		}

	}
	return rtn;
}
/// @fn int ePassenger_remove(ePassenger[], int, int)
/// @brief Function that removes a passenger by changing the state of the isEmpty attribute of the structure.
///
/// @param passengerList The array of passengers where the data of the passenger to be removed is found.
/// @param passengerLength Array length.
/// @param id The ID of the passenger to remove.
/// @return return 0 if its ok or -1 if there is an error.
int ePassenger_remove(ePassenger passengerList[], int passengerLength, int id)
{
	int rtn = -1;
	if(passengerList != NULL && passengerLength >0)
	{
		ePassenger_printOne(passengerList[id]);
		if(menu_confirm("¿DESEA REALIZAR LA BAJA?"
				"\nINGRESE RESPUESTA <S/N> :"
				, "ERROR, REINGRESE RESPUESTA <S/N>:")==1)
		{
			passengerList[id].isEmpty = TRUE;
			rtn=0;
		}
	}
	return rtn;
}
/// @fn int ePassenger_findPassengerById(ePassenger[], int, int)
/// @brief Function that searches for a specific passenger within the array by means of its ID.
///
/// @param toSearchStruc The array where to search for the passenger ID.
/// @param length Array length.
/// @param id The ID of the passenger to search.
/// @return return 0 if its ok, and finds the passenger or -1 if there is an error.
int ePassenger_findPassengerById(ePassenger toSearchStruc[], int length, int id)
{
	int rtn = -1;
	int flag = 0;
	int i;
	int searchId;

	if (toSearchStruc != NULL)
	{
		if (length > 0)
		{
			searchId=id;

			for (i = 0; i < length; i++)
			{
				if (toSearchStruc[i].isEmpty == FALSE)
				{
					if (toSearchStruc[i].id == searchId)
					{
						flag = 1;
						rtn = i;
						break;
					}
				}
			}

			if (flag == 0)
			{
				rtn = -2;
			}
		} else
		{
			rtn = -3;
		}
	} else
	{
		rtn = -4;
	}

	return rtn;
}
/// @fn int ePassenger_Sort(ePassenger[], int, int)
/// @brief 	Sort the elements in the array of passengers, the argument order
/// 		indicate UP or DOWN order.
/// @param 	passengerList The array to sort.
/// @param 	TAM Array length.
/// @param 	order The order in which we want it to be sorted.
/// @return	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int ePassenger_Sort(ePassenger passengerList[], int TAM, int order)
{
	int rtn = -1;
	int i;
	int j;
	ePassenger aux;

	if (passengerList != NULL && TAM > 0) {
		switch (order)
		{
		case 0:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j = i + 1; j < TAM; j++)
				{
					if (passengerList[i].isEmpty == FALSE
							&& passengerList[j].isEmpty == FALSE)
					{
						if(strncmp(passengerList[i].lastname,passengerList[j].lastname,TAM)==0)
						{
							if (passengerList[i].typePassenger>passengerList[j].typePassenger)
							{
								aux = passengerList[i];
								passengerList[i] = passengerList[j];
								passengerList[j] = aux;
							}
						}
						else
						{
							if (strncmp(passengerList[i].lastname,passengerList[j].lastname,TAM)<0)
							{
								aux = passengerList[i];
								passengerList[i] = passengerList[j];
								passengerList[j] = aux;
							}
						}
					}
				}
			}
			rtn = 0;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j = i + 1; j < TAM; j++)
				{
					if (passengerList[i].isEmpty == FALSE
							&& passengerList[j].isEmpty == FALSE)
					{
						if(strncmp(passengerList[i].lastname,passengerList[j].lastname,TAM)==0)
						{
							if (passengerList[i].typePassenger<passengerList[j].typePassenger)
							{
								aux = passengerList[i];
								passengerList[i] = passengerList[j];
								passengerList[j] = aux;
							}
						}
						else
						{
							if (strncmp(passengerList[i].lastname,passengerList[j].lastname,TAM)>0)
							{
								aux = passengerList[i];
								passengerList[i] = passengerList[j];
								passengerList[j] = aux;
							}
						}
					}
				}
			}
			rtn = 0;
			break;
		default:
			rtn = -1;
			break;
		}
	}
	return rtn;
}
/// @fn int ePassenger_totalPrice(ePassenger[], int, float*)
/// @brief Function that accumulates the prices of active passengers to obtain the total collected.
///
/// @param passengerList The array where passengers will be searched to accumulate price.
/// @param passengerLength The size of the passenger array.
/// @param priceTotal The total price, where the value of the function will be returned.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int ePassenger_totalPrice(ePassenger passengerList[], int passengerLength, float *priceTotal)
{
	int rtn =-1;
	int i;
	float totalPrice=0;
	if(passengerList != NULL
			&& passengerLength >0
			&& priceTotal != NULL)
	{
		for (i = 0; i < passengerLength-1; i++)
		{
			if (passengerList[i].isEmpty == FALSE)
			{
				totalPrice=totalPrice+passengerList[i].price;
				rtn=0;
			}
		}
		*priceTotal=totalPrice;
	}
	return rtn;
}
/// @fn int ePassenger_totalPassager(ePassenger[], int, float*)
/// @brief Function that counts the passengers loaded in the passenger array.
///
/// @param passengerList Passenger array where it counts loaded passengers.
/// @param passengerLength The size of the passenger array.
/// @param totalPassagers Memory pointer where the total number of passengers is stored.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int ePassenger_totalPassager(ePassenger passengerList[], int passengerLength, float *totalPassagers)
{
	int rtn =-1;
	int i;
	float passengers=0;

	if(passengerList != NULL
			&& passengerLength >0)
	{
		for (i = 0; i < passengerLength-1; i++)
		{
			if (passengerList[i].isEmpty == FALSE)
			{
				passengers++;
				rtn=0;
			}
			*totalPassagers = passengers;
		}
	}

	return rtn;
}
/// @fn int ePassenger_passengerOverAverage(ePassenger[], int, float, int*)
/// @brief Function that counts the total number of passengers above the average price.
///
/// @param passengerList  Array of passengers where the price comparison is made.
/// @param passengerLength The size of the passenger array.
/// @param averagePrice The average price to compare.
/// @param overPrice The total passenger above the average price. It is a memory pointer, there it stores the data.
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int ePassenger_passengerOverAverage(ePassenger passengerList[], int passengerLength, float averagePrice, int *overPrice)
{
	int rtn =-1;
	int i;
	int passengerOverPrice = 0;

	if(passengerList != NULL
			&& passengerLength >0)
	{
		for (i = 0; i < passengerLength; i++)
		{
			if (passengerList[i].isEmpty == FALSE)
			{
				if (averagePrice>passengerList[i].price)
				{
					passengerOverPrice++;
				}
			}
		}
		*overPrice=passengerOverPrice;
		rtn = 0;
	}
	return rtn;
}

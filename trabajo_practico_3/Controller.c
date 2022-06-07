#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "menu.h"
#include "input.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile;
	char confirm;
	//strcpy(path,"data.csv");
	pFile = fopen(path,"r");

	if(path != NULL && pArrayListPassenger != NULL)
	{

		if(pFile == NULL )
		{
			printf("\nNo se pudo abrir el archivo");
		}
		else
		{
			if(ll_isEmpty(pArrayListPassenger) == 1)
			{

				if(parser_PassengerFromText(pFile,pArrayListPassenger) == 0)
				{
					printf("\nSe ha podido parsear el archivo txt");
					rtn = 0;
				}
				else
				{
					printf("\nNo se ha podido parsear el archivo txt");
				}
			}
			else
			{
				confirm=menu_confirm("\nALERTA: Si carga el archivo data.csv, tendrá ID repetidos de los empleados cargados en el programa.\n"
						"Se le recomienda que previamente guarde los empleados cargados en el programa en un archivo.\n"
						" ¿Desea hacerlo de todos modos?\n"
						"s/n", "\nError, ingrese sólo s/n");
				if(confirm == 's')
				{
					if(parser_PassengerFromText(pFile,pArrayListPassenger) == 0)
					{
						printf("\nSe ha podido parsear el archivo txt");
						rtn = 0;
					}
					else
					{

						printf("\nNo se ha podido parsear el archivo txt");
					}
				}
				else					//Usuario elije destino donde guardará los empleados cargados en el programa
				{
					if(input_getFileName(path,2,20) == 0)
					{
						if(controller_saveAsText(path,pArrayListPassenger) == 0)
						{
							ll_clear(pArrayListPassenger);							//Limpio la linkedist y uso recursivamente la funcion
							if(controller_loadFromText(path,pArrayListPassenger) == 0)
							{
								printf("\nSE ejecuto con exito");
								rtn = 0;
							}
							else
							{
								printf("\nFallo la recursividad");
							}
						}
						else
						{
							printf("\nSe ha abortado la carga del archivo, volverá al menú principal");
						}
					}
					else
					{
						printf("\nFallo el input_getFileName");
					}
				}
			}

		}
	}

	fclose(pFile);
	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	{
		int ret = -1;
		int lastID;
		Passenger* PassengerBuffer = NULL;
		if(pArrayListPassenger != NULL)
		{
			lastID = controller_searchLastId(pArrayListPassenger);
			PassengerBuffer = Passenger_new();
			if(PassengerBuffer != NULL)
			{
				if(lastID != -1)
				{
					if(Passenger_setData(PassengerBuffer) == 0)
					{
						lastID++;
						Passenger_setId(PassengerBuffer,lastID);
						ll_add(pArrayListPassenger,PassengerBuffer);
						printf("\nSe ha cargado con exito el nuevo pasajero");
						controller_PrintPassenger(PassengerBuffer);
						ret = 0;
					}
				}
			}
		}
		if(ret == -1)
		{
			printf("\nSe ha abortado el alta de pasajero");
			free(PassengerBuffer);
			PassengerBuffer = NULL;
		}
		return ret;
	}
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	return 1;
}
int controller_searchLastId(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int listSize;
	int i;
	int bufferId;
	int maxId;
	char confirm;
	Passenger* PassengerBuffer;
	int flagMaxId = 0;
	if(pArrayListPassenger != NULL)
	{
		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			listSize=ll_len(pArrayListPassenger);
			for (i = 0; i < listSize; i++)
			{
				PassengerBuffer = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(PassengerBuffer,&bufferId);
				if(flagMaxId == 0 || bufferId > maxId)
				{
					maxId = bufferId;
					flagMaxId = 1;
					rtn = maxId;
				}
			}//FIN FOR
		}
		else
		{
			printf("\nNO HAY PASAJEROS CARGADADOS EN LA BASE DE DATOS");
			confirm = menu_confirm("¿DESEA RESETEAR EL ID?", "ERROR, INGRESE <S/N>");
			if(confirm == 'S')
			{
				rtn = 0;

			}
			else
			{
				printf("\nCARGA CANCELADA");
			}
		}
	}
	return rtn;
}

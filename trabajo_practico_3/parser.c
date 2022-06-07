#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int ret = -1;
		char buffer[6][128];
		int readedChars;
		Passenger* pAux;
		if(pFile != NULL && pArrayListPassenger !=NULL)
		{
						//	ID,NOMBRE, HORAS TRABAJADAS, SUELDO
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

				//printf("%s     %s    %s   %s    %s     %s    %s   %s\n\n",buffer[0],buffer[0],buffer[1],buffer[2],buffer[3],buffer[4], buffer[5],buffer[6]);

				while(!feof(pFile))
				{
					//printf("\nParser: Entro al whil1e");
					readedChars = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
					//printf("\nCharleidos = %d",readedChars);
					if(readedChars < 6)
					{
						printf("\nParser: Error de char leidos, break while");
						ret = -1;
						break;
					}
					else
					{
						pAux = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
						if(pAux == NULL)
						{
							printf("\nParser: nuevoEmpleado es == NULL");
							break;
						}
						else
						{
							ll_add(pArrayListPassenger,(Passenger*)pAux);
							ret = 0;
						}
						printf("\nParser:Se Agrego un elemento al final de la lista");
					}
				}//FIN WHILE
		}
	    return ret;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
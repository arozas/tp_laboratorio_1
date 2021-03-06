/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author:
 */
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* memoryPointer = NULL;
	memoryPointer = (Passenger*) malloc(sizeof(Passenger)*2); //ESTA MULTIPLICACIÓN ES LO QUE ME ARREGLA EL ERROR, SIN ESA MULTIPLICACIÓN ME SALE EL ERROR: malloc(): corrupted top size

	return memoryPointer;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char*apellidoStr,char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr)
{
	Passenger* newPassenger = Passenger_new();
	if(idStr != NULL
			&& nombreStr != NULL
			&& tipoPasajeroStr != NULL
			&& apellidoStr != NULL
			&& codigoVueloStr != NULL
			&& tipoPasajeroStr != NULL
			&& precioStr != NULL
			&& newPassenger  != NULL)
	{
		if(	(Passenger_setId(newPassenger,atoi(idStr)) != 0) ||
				(Passenger_setNombre(newPassenger,nombreStr) != 0) ||
				(Passenger_setApellido(newPassenger,apellidoStr) != 0) ||
				(Passenger_setPrecio(newPassenger,atof(precioStr)) != 0) ||
				(Passenger_setTipoPasajero(newPassenger,tipoPasajeroStr) != 0) ||
				(Passenger_setCodigoVuelo(newPassenger,codigoVueloStr) != 0))
		{
			Passenger_delete(newPassenger);
			newPassenger = NULL;
			//printf("\nEmployee: direccion de memoria NULL");
		}
	}
	return newPassenger;
}
void Passenger_delete(Passenger* this)
{
	free(this);
}
//====================================================== SETTER && GETTERS ==============================================================================
// ESTO ESTA INCOMPLETO, HAY QUE HACER TODAS LAS VALIDACIONES, NO LLEGUE HACERLAS. SE CUALES SON Y COMO HACERLAS, PERO NO LLEGUE POR TEMAS PERSONALES
int Passenger_setId(Passenger* this,int id)
{
	int rtn = -1;
	if(this != NULL && id > 0)
	{
		this->id =id;
		//printf("\nid pasajero : %d",this->id);
		rtn = 0;
	}
	return rtn;
}
int Passenger_getId(Passenger* this,int* id)
{
	int rtn = -1;
	if(this != NULL &&  id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}
	return rtn;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rtn = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		rtn = 0;
	}
	return rtn;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rtn = -1;
	if(this != NULL &&  nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		rtn = 0;
	}
	return rtn;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int rtn = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido,apellido);
		rtn = 0;
	}
	return rtn;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rtn = -1;
	if(this != NULL &&  apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		rtn = 0;
	}
	return rtn;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn = -1;
	if(this != NULL && precio > -1)
	{
		this->precio = precio;
		rtn = 0;
	}
	return rtn;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rtn = -1;
	if(this != NULL &&  precio != NULL)
	{
		*precio = this->precio;
		rtn = 0;
	}
	return rtn;
}
int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int rtn = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		rtn = 0;
	}
	return rtn;
}
int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int rtn = -1;
	if(this != NULL &&  tipoPasajero != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		rtn = 0;
	}
	return rtn;
}
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int rtn = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		rtn = 0;
	}
	return rtn;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn = -1;
	if(this != NULL &&  codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		rtn = 0;
	}
	return rtn;
}
int Passenger_setData(Passenger* this)
{
	int rtn=-1;
	Passenger PassengerBuffer;
	int passengerTypeMenu;
	if(this!=NULL)
	{
		printf("\n\t\t\tCARGA DE PASAJERO\t\t\t");
		if(		input_getStringletters("INGRESE EL NOMBRE DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN NOMBRE VALIDO:", PassengerBuffer.nombre, NAME_LENGTH)== 0
				&& input_getStringletters("INGRESE EL APELLIDO DEL PASAJERO:", RETRIES, "ERROR, INGRESE UN APELLIDO VALIDO:", PassengerBuffer.apellido, NAME_LENGTH) == 0
				&& input_getFloat("INGRESE EL PRECIO DEL VUELO:", RETRIES, MIN_PRICE, MAX_PRICE, "ERROR, INGRESE UN PRECIO VALIDO:", &PassengerBuffer.precio) == 0)
		{
			passengerTypeMenu=menu_menu("ELIJA EL TIPO DE PASAJERO",
					"\n1 - ECONOMY CLASS."
					"\n2 - FIRST CLASS."
					"\n3 - EXECUTIVE CLASS."
					,"ERROR INTENTE DE NUEVO"
					, RETRIES
					, 3);
			if(passengerTypeMenu!=-1)
			{
				switch (passengerTypeMenu)
				{
				case ECONOMY_CLASS:
					strcpy(PassengerBuffer.tipoPasajero,"ECONOMY CLASS");
					break;
				case FIRST_CLASS:
					strcpy(PassengerBuffer.tipoPasajero,"FIRST CLASS");
					break;
				case EXECUTIVE_CLASS:
					strcpy(PassengerBuffer.tipoPasajero,"EXECUTIVE CLASS");
					break;
				}
				if(Passenger_setNombre(this, PassengerBuffer.nombre)!=0 ||
						Passenger_setApellido(this, PassengerBuffer.apellido)!= 0 ||
						Passenger_setPrecio(this, PassengerBuffer.precio)!=0 ||
						Passenger_setTipoPasajero(this, PassengerBuffer.tipoPasajero)!= 0)
				{
					free(this);
					this = NULL;
				}
				else
				{
					rtn=0;
				}
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
	}
	return rtn;
}
int Passenger_sortById(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Passenger* passengerBufferOne;
	Passenger* passengerBufferTwo;
	int bufferIdOne;
	int bufferIdTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		passengerBufferOne=(Passenger*)pElementOne;
		passengerBufferTwo=(Passenger*)pElementTwo;
		if(!Passenger_getId(passengerBufferOne,&bufferIdOne)
				&& !Passenger_getId(passengerBufferTwo,&bufferIdTwo))
		{
			if(bufferIdOne > bufferIdTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferIdOne <bufferIdTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
int Passenger_sortByName(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Passenger* passengerBufferOne;
	Passenger* passengerBufferTwo;
	char bufferNameOne[NAME_LENGTH];
	char bufferNameTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		passengerBufferOne = (Passenger*) pElementOne;
		passengerBufferTwo = (Passenger*) pElementTwo;
		if(!Passenger_getNombre(passengerBufferOne, bufferNameOne) &&
				!Passenger_getNombre(passengerBufferTwo, bufferNameTwo))
		{
			if(strncmp(bufferNameOne,bufferNameTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferNameOne,bufferNameTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
int Passenger_sortByLastName(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Passenger* passengerBufferOne;
	Passenger* passengerBufferTwo;
	char bufferSurnameOne[NAME_LENGTH];
	char bufferSurnameTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		passengerBufferOne = (Passenger*) pElementOne;
		passengerBufferTwo = (Passenger*) pElementTwo;
		if(!Passenger_getNombre(passengerBufferOne, bufferSurnameOne) &&
				!Passenger_getNombre(passengerBufferTwo, bufferSurnameTwo))
		{
			if(strncmp(bufferSurnameOne,bufferSurnameTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferSurnameOne,bufferSurnameTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
int Passenger_sortByPrice(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Passenger* passengerBufferOne;
	Passenger* passengerBufferTwo;
	float bufferPrecioOne;
	float bufferPrecioTwo;
	if(pElementOne != NULL && pElementTwo != NULL)
	{
		passengerBufferOne=(Passenger*)pElementOne;
		passengerBufferTwo=(Passenger*)pElementTwo;
		if(!Passenger_getPrecio(passengerBufferOne,&bufferPrecioOne)
				&& !Passenger_getPrecio(passengerBufferTwo,&bufferPrecioTwo))
		{
			if(bufferPrecioOne > bufferPrecioTwo)
			{
				rtn = 1;
			}
			else
			{
				if(bufferPrecioOne <bufferPrecioTwo)
				{
					rtn = -1;
				}
			}
		}

	}
	return rtn;
}
int Passenger_sortByPassengerType(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Passenger* passengerBufferOne;
	Passenger* passengerBufferTwo;
	char bufferTypeOne[NAME_LENGTH];
	char bufferTypeTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		passengerBufferOne = (Passenger*) pElementOne;
		passengerBufferTwo = (Passenger*) pElementTwo;
		if(!Passenger_getTipoPasajero(passengerBufferOne, bufferTypeOne) &&
				!Passenger_getTipoPasajero(passengerBufferTwo, bufferTypeTwo))
		{
			if(strncmp(bufferTypeOne,bufferTypeTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferTypeOne,bufferTypeTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}
int Passenger_sortByFlycode(void* pElementOne,void* pElementTwo)
{
	int rtn = 0;
	Passenger* passengerBufferOne;
	Passenger* passengerBufferTwo;
	char bufferFlycodeOne[NAME_LENGTH];
	char bufferFlycodeTwo[NAME_LENGTH];
	if(pElementOne!=NULL && pElementTwo!=NULL)
	{
		passengerBufferOne = (Passenger*) pElementOne;
		passengerBufferTwo = (Passenger*) pElementTwo;
		if(!Passenger_getCodigoVuelo(passengerBufferOne, bufferFlycodeOne) &&
				!Passenger_getCodigoVuelo(passengerBufferTwo, bufferFlycodeTwo))
		{
			if(strncmp(bufferFlycodeOne,bufferFlycodeTwo,NAME_LENGTH)>0)
			{
				rtn = 1;
			}
			else
			{
				if(strncmp(bufferFlycodeOne,bufferFlycodeTwo,NAME_LENGTH)<0)
				{
					rtn = -1;
				}
			}
		}
	}
	return rtn;
}

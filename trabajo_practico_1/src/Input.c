/*
 * Input.c
 *
 *  Created on: 1 abr. 2022
 *      Author: Alejandro Alberto Martín Rozas
 *      Biblioteca de funciones de entrada.
 *      Versión 0.4 del 14 de abril de 2022
 */
#include "Input.h"
/// @fn int input_getInt(char[], int, int, int, char[], int*)
/// @brief 					Esta función solicita al usuario el ingreso de un entero validando el ingreso,
/// 						si no se encuentra entre los parametros vuelve a pedir el ingreso.
/// @param mensaje 			Es el mensaje que se le muestra al usuario para solicitar el numero.
/// @param reintentos 		Es la cantidad de reintentos que tendrá el usuario en el caso de que el dato ingresado no cumpla con los parametros.
/// @param minimo			Es el valor mínimo que puede ingresar el usuario.
/// @param maximo			Es el valor máximo que puede ingresar el usuario.
/// @param mensajeError		Es el mensaje de error que muestra la función si no pasó la validación el ingreso por el usuario.
/// @param pNumeroingresado	Es el puntero donde se guarda el valor ingresado por el usuario.
/// @return					El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int input_getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroingresado)
{
	int rtn = 0;
	int auxiliarInt; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroingresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%d", &auxiliarInt);
		do
		{
			if (retornoScanf !=1 || auxiliarInt > maximo || auxiliarInt < minimo)
			{
				printf("\n%s", mensajeError);
				retornoScanf = scanf("%d", &auxiliarInt);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroingresado = auxiliarInt;
				rtn = 1;
			}
		}
		while(reintentos>0);
	}
	return rtn;
}
/// @fn int input_getFloat(char[], int, int, int, char[], float*)
/// @brief 					Esta función solicita al usuario el ingreso de un decimal validando el ingreso,
/// 						si no se encuentra entre los parametros vuelve a pedir el ingreso.
/// @param mensaje 			Es el mensaje que se le muestra al usuario para solicitar el numero.
/// @param reintentos 		Es la cantidad de reintentos que tendrá el usuario en el caso de que el dato ingresado no cumpla con los parametros.
/// @param minimo			Es el valor mínimo que puede ingresar el usuario.
/// @param maximo			Es el valor máximo que puede ingresar el usuario.
/// @param mensajeError		Es el mensaje de error que muestra la función si no pasó la validación el ingreso por el usuario.
/// @param pNumeroingresado	Es el puntero donde se guarda el valor ingresado por el usuario.
/// @return					El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int input_getFloat(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroingresado)
{
	int rtn = 0;
	float auxiliarFloat; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroingresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);
		do
		{
			if (retornoScanf !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				printf("\n%s", mensajeError);
				retornoScanf = scanf("%f", &auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroingresado = auxiliarFloat;
				rtn = 1;
			}
		}
		while(reintentos>0);
	}
	return rtn;
}
/// @fn int input_getChar(char[], int, char, char, char[], char*)
/// @brief						Esta función solicita al usuario el ingreso de un carácter validando el ingreso,
///								si no se encuentra entre los parametros vuelve a pedir el ingreso.
/// @param mensaje				Es el mensaje que se le muestra al usuario para solicitar el carácter.
/// @param reintentos			Es la cantidad de reintentos que tendrá el usuario en el caso de que el dato ingresado no cumpla con los parametros.
/// @param minimo				Es el valor mínimo (ASCII) que puede ingresar el usuario.
/// @param maximo				Es el valor aáximo (ASCII) que puede ingresar el usuario.
/// @param mensajeError			Es el mensaje de error que muestra la función si no pasó la validación el ingreso por el usuario.
/// @param pCaracteringresado	Es el puntero donde se guarda el valor ingresado por el usuario.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int input_getChar(char mensaje[], int reintentos, char minimo, char maximo, char mensajeError[], char *pCaracteringresado)
{
	int rtn = 0;
	char auxiliarChar; //buffer
	int retornoScanf;
	//Revisar que todos los datos esten bien.
	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pCaracteringresado != NULL && reintentos >= 0)
	{
		printf("\n%s", mensaje);
		retornoScanf = scanf("%c", &auxiliarChar);
		do
		{
			if (retornoScanf !=1 || auxiliarChar > maximo || auxiliarChar < minimo)
			{
				printf("\n%s", mensajeError);
				__fpurge(stdin);
				retornoScanf = scanf("%c", &auxiliarChar);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pCaracteringresado = auxiliarChar;
				rtn = 1;
			}
		}
		while(reintentos>0);
	}
	return rtn;
}
/// @fn int input_menuTwoOp(char[], char[], char[])
/// @brief 				Esta función crea un menú numérico de dos opciones, solicita al usuario que ingrese
/// 					la opción del menú, e informa la opción seleccionada, en el caso que no tenga más
/// 					intentos informa al usuario.
/// @param nombreMenu	Es un string donde ingresamos el nombre del menú.
/// @param opcion1		Es un string donde ingresamos el nombre de la primer opción.
/// @param opcion2		Es un string donde ingresamos el nombre de la segunda opción.
/// @return				El retorno de la función es la opción ingreada, retorna la opción para poder incluila en un switch.
int input_menuTwoOp(char nombreMenu[], char opcion1[], char opcion2[])
{
	int opcionIngresada;

	printf("\n\t\t\t%s\n",nombreMenu);
	printf("1. %s\n",opcion1);
	printf("2. %s\n",opcion2);
	if(input_getInt("INTRODUZCA OPCIÓN <1-2>:", 3, 1, 2, "ERROR INTRODUZCA OPCIÓN <1-2>", &opcionIngresada) == 1)
	{
		printf("\nOPCIÓN INGRESADA:%d\n",opcionIngresada);
	}
	else
	{
		printf("\nFALLO TODOS LOS INTENTOS\n");
	}

	return opcionIngresada;
}
/// @fn int input_menuThreeOp(char[], char[], char[], char[])
/// @brief 				Esta función crea un menú numérico de tres opciones, solicita al usuario que ingrese
/// 					la opción del menú, e informa la opción seleccionada, en el caso que no tenga más
/// 					intentos informa al usuario.
/// @param nombreMenu	Es un string donde ingresamos el nombre del menú.
/// @param opcion1		Es un string donde ingresamos el nombre de la primer opción.
/// @param opcion2		Es un string donde ingresamos el nombre de la segunda opción.
/// @param opcion3		Es un string donde ingresamos el nombre de la tercera opción.
/// @return				El retorno de la función es la opción ingreada, retorna la opción para poder incluila en un switch.
int input_menuThreeOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[])
{
	int opcionIngresada;

	printf("\n\t\t\t%s\n",nombreMenu);
	printf("1. %s\n",opcion1);
	printf("2. %s\n",opcion2);
	printf("3. %s\n",opcion3);
	if(input_getInt("INTRODUZCA OPCIÓN <1-3>:", 3, 1, 3, "ERROR INTRODUZCA OPCIÓN <1-3>", &opcionIngresada) == 1)
	{
		printf("\nOPCIÓN INGRESADA:%d\n",opcionIngresada);
	}
	else
	{
		printf("\nFALLO TODOS LOS INTENTOS\n");
	}

	return opcionIngresada;
}
/// @fn int input_menuFourOp(char[], char[], char[], char[], char[])
/// @brief 				Esta función crea un menú numérico de cuatro opciones, solicita al usuario que ingrese
/// 					la opción del menú, e informa la opción seleccionada, en el caso que no tenga más
/// 					intentos informa al usuario.
/// @param nombreMenu	Es un string donde ingresamos el nombre del menú.
/// @param opcion1		Es un string donde ingresamos el nombre de la primer opción.
/// @param opcion2		Es un string donde ingresamos el nombre de la segunda opción.
/// @param opcion3		Es un string donde ingresamos el nombre de la tercera opción.
/// @param opcion4		Es un string donde ingresamos el nombre de la cuarta opción.
/// @return				El retorno de la función es la opción ingreada, retorna la opción para poder incluila en un switch.
int input_menuFourOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[], char opcion4[])
{
	int opcionIngresada;

	printf("\n\t\t\t%s\n",nombreMenu);
	printf("1. %s\n",opcion1);
	printf("2. %s\n",opcion2);
	printf("3. %s\n",opcion3);
	printf("4. %s\n",opcion4);
	if(input_getInt("INTRODUZCA OPCIÓN <1-4>:", 3, 1, 4, "ERROR INTRODUZCA OPCIÓN <1-4>", &opcionIngresada) == 1)
	{
		printf("\nOPCIÓN INGRESADA:%d\n",opcionIngresada);
	}
	else
	{
		printf("\nFALLO TODOS LOS INTENTOS\n");
	}

	return opcionIngresada;
}
/// @fn int input_menuFiveOp(char[], char[], char[], char[], char[], char[])
/// @brief 				Esta función crea un menú numérico de cinco opciones, solicita al usuario que ingrese
/// 					la opción del menú, e informa la opción seleccionada, en el caso que no tenga más
/// 					intentos informa al usuario.
/// @param nombreMenu	Es un string donde ingresamos el nombre del menú.
/// @param opcion1		Es un string donde ingresamos el nombre de la primer opción.
/// @param opcion2		Es un string donde ingresamos el nombre de la segunda opción.
/// @param opcion3		Es un string donde ingresamos el nombre de la tercera opción.
/// @param opcion4		Es un string donde ingresamos el nombre de la cuarta opción.
/// @param opcion5		Es un string donde ingresamos el nombre de la quinta opción.
/// @return				El retorno de la función es la opción ingreada, retorna la opción para poder incluila en un switch.
int input_menuFiveOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[])
{
	int opcionIngresada;

	printf("\n\t\t\t%s\n",nombreMenu);
	printf("1. %s\n",opcion1);
	printf("2. %s\n",opcion2);
	printf("3. %s\n",opcion3);
	printf("4. %s\n",opcion4);
	printf("5. %s\n",opcion5);
	if(input_getInt("INTRODUZCA OPCIÓN <1-5>:", 3, 1, 5, "ERROR INTRODUZCA OPCIÓN <1-5>", &opcionIngresada) == 1)
	{
		printf("\nOPCIÓN INGRESADA:%d\n",opcionIngresada);
	}
	else
	{
		printf("\nFALLO TODOS LOS INTENTOS\n");
	}

	return opcionIngresada;
}
/// @fn int input_menuSixOp(char[], char[], char[], char[], char[], char[], char[])
/// @brief 				Esta función crea un menú numérico de seis opciones, solicita al usuario que ingrese
/// 					la opción del menú, e informa la opción seleccionada, en el caso que no tenga más
/// 					intentos informa al usuario.
/// @param nombreMenu	Es un string donde ingresamos el nombre del menú.
/// @param opcion1		Es un string donde ingresamos el nombre de la primer opción.
/// @param opcion2		Es un string donde ingresamos el nombre de la segunda opción.
/// @param opcion3		Es un string donde ingresamos el nombre de la tercera opción.
/// @param opcion4		Es un string donde ingresamos el nombre de la cuarta opción.
/// @param opcion5		Es un string donde ingresamos el nombre de la quinta opción.
/// @param opcion5		Es un string donde ingresamos el nombre de la sexta opción.
/// @return				El retorno de la función es la opción ingreada, retorna la opción para poder incluila en un switch.
int input_menuSixOp(char nombreMenu[], char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[], char opcion6[])
{
	int opcionIngresada;

	printf("\n\t\t\t%s\n",nombreMenu);
	printf("1. %s\n",opcion1);
	printf("2. %s\n",opcion2);
	printf("3. %s\n",opcion3);
	printf("4. %s\n",opcion4);
	printf("5. %s\n",opcion5);
	printf("6. %s\n",opcion6);
	if(input_getInt("INTRODUZCA OPCIÓN <1-6>:", 3, 1, 6, "ERROR INTRODUZCA OPCIÓN <1-6>", &opcionIngresada) == 1)
	{
		printf("\nOPCIÓN INGRESADA:%d\n",opcionIngresada);
	}
	else
	{
		printf("\nFALLO TODOS LOS INTENTOS\n");
	}

	return opcionIngresada;
}
/// @fn void input_endProgram(void)
/// @brief 	Esta función solo finaliza el programa e imprime un mensaje informando al usuario
/// 		que el programa finalizó
void input_endProgram(void)
{
	printf("\n\t\t\tFINALIZÓ EL PROGRAMA");
	exit(-1);
}


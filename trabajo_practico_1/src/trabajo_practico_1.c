/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : 1.0 del 14 de abril del 2022
 Objetive	 : Que el usuario cargue datos y el programa realice los calculos
 	 	 	   solicitados.
 Description : Trabajo Practico 1 - Laboratorio 1
 ============================================================================
 */

#include "Input.h"
#include "Operations.h"
#include "utntp1.h"

// uso todos estos defines para que el código me quede limpio de números.

#define TRUE 1
#define KM_MAX 15000
#define KM_MIN 300
#define INTENTOS 1
#define PRECIO_MAX 500000
#define PRECIO_MIN 5000
#define DESCUENTO -10
#define INTERES 25
#define BITCOIN 7797094.5 //valor BTC nominal BLUE al 14/04/2022
#define	CARGAFORZADA_KM 7090
#define	CARGAFORZADA_AER 162965
#define	CARGAFORZADA_LAT 159339

int main(void)
{
	float entKm;
	float entPriceAerolineas;
	float entPriceLatam;
	float debitPriceAerolineas;
	float debitPriceLatam;
	float creditPriceAerolineas;
	float creditPriceLatam;
	float btcPriceAerolineas;
	float btcPriceLatam;
	float pricePerKmAerolineas;
	float pricePerKmLatam;
	float priceDiference;

	entKm = 0;
	entPriceAerolineas = 0;
	entPriceLatam = 0;
	do
	{
		switch(input_menuSixOp("TRABAJO PRACTICO 1", "Ingresar Kilómetros", "Ingresar Precio de Vuelo", "Calcular todos los costos", "Informar Resultados", "Carga forzada de datos", "Salir"))
		{
		case 1:
			do
			{
				input_getFloat("Ingrese los KM:", INTENTOS, KM_MIN, KM_MAX, "Error, reingrese los km:", &entKm);
			}while(input_menuTwoOp("¿Desea volver a cargar los km?", "SI", "NO")==TRUE);
			break;
		case 2:
			do
			{
				switch(input_menuTwoOp("PRECIO DE LOS VUELOS", "Precio vuelo Aerolineas", "Precio vuelo LATAM"))
				{
				case 1:
					input_getFloat("Ingrese el precio del vuelo de Aerolineas:", INTENTOS, PRECIO_MIN, PRECIO_MAX, "Error, reingrese el precio:", &entPriceAerolineas);
					break;
				default:
					input_getFloat("Ingrese el precio del vuelo de LATAM:", INTENTOS, PRECIO_MIN, PRECIO_MAX, "Error, reingrese el precio:", &entPriceLatam);
					break;
				}
			}while(input_menuTwoOp("¿Desea volver a cargar los precios?", "SI", "NO")==TRUE);
			break;
		case 3:
			/*La función calcularResultado:
			 * Hice la función de forma modular, que pueda en todo caso de necesitarse, agregar otra aerolinea
			 * por eso en este caso la misma se repite, podria haber resuelto con una sola función, pero la
			 * idea es que quede lo más "general" y "reutilizable" posible, y esta es la mejor forma que se me ocurrió.
			 * */
			utntp1_calculateResults(entKm, entPriceAerolineas, DESCUENTO, INTERES, BITCOIN, &debitPriceAerolineas, &creditPriceAerolineas, &btcPriceAerolineas, &pricePerKmAerolineas);
			utntp1_calculateResults(entKm, entPriceLatam, DESCUENTO, INTERES, BITCOIN, &debitPriceLatam, &creditPriceLatam, &btcPriceLatam, &pricePerKmLatam);
			/*La función calcularDiferencia:
			 * Esta función es concecuencia de la lógica pensada con la función anterior, si se "agregaran"
			 * más aerolineas se podria hardcodear distintas diferencias de costos. La misma tiene una validación
			 * y mensaje que informa si no se pueden hacer calculos.
			 * */
			utntp1_calculateDiference(entPriceAerolineas, entPriceLatam, &priceDiference);
			break;
		case 4:
			/*La función printResult:
			 * Siguiendo la linea general del código, si se agregaran nuevas aerolineas se podria reutilizar
			 * esta función ya los nombres mostrados son strings que modifican la impresión en la consola.
			 * */
			utntp1_printResult(entKm, entPriceAerolineas, entPriceLatam,"Aerolineas","LATAM", debitPriceAerolineas, debitPriceLatam, creditPriceAerolineas, creditPriceLatam, btcPriceAerolineas, btcPriceLatam, pricePerKmAerolineas, pricePerKmLatam, priceDiference);
			break;
		case 5:
			/*La carga forzada:
			 * La función es simple, condensé las variables del main y calculos en la función para limitar los parametros a cargar.
			 */
			utntp1_forceCharge(CARGAFORZADA_KM, CARGAFORZADA_AER, CARGAFORZADA_LAT, DESCUENTO, INTERES, BITCOIN);
			break;
		default :
			/*La función finalizarPrograma:
			 *busque una función que salga del programa exit(-1), pero queria que me imprima un mensaje
			 *en este caso "FINALIZÓ EL PROGRAMA", asi que lo agregué y evité usar un printf y repetir
			 *el return del main. Pense en cambiar el main a void y cerrarlo tambien con esta función,
			 *pero no quise arriesgar a que este mal, lo probé y funcionó, pero nose si por otro lado estoy
			 *generando un problema que desconozco.
			 * */
			input_endProgram();
			break;
		}/*La función menuTwoOp, SixOp, Etc:
		 * La idea de esta función es tener un menú programable y reutilizable.
		 * cada función explicita la cantidad de opciones, las mismas se cargan
		 * como string y luego pide un numero, ese es el return de la función,
		 * y me permite usarla como parametro del switch.
		 */
	}while(input_menuTwoOp("¿Desea continuar al menu principal?", "SI", "NO")==TRUE);

	return EXIT_SUCCESS;
}


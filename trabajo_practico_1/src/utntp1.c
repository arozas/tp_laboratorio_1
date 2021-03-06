/*
 * utntp1.c
 *
 *  Created on: 13 abr. 2022
 *  Author: Alejandro Alberto Martín Rozas
 *  Biblioteca de funciones especificas del TP 1 de Laboratorio.
 *  Versión 1.0 del 14 de abril de 2022.
 */
#include "utntp1.h"

/// @fn int utntp1_calculateResults(float, float, int, int, float, float*, float*, float*, float*)
/// @brief 						Función que hace todos los calculos sobre precios de UNA empresa,
/// 							esta función es exclusiva para el tp de laboratorio.
/// @param kilometros			Es el valor en kilometros, es para hacer los calculos de precio por kilometros.
/// @param precioEmpresa		Valor ingresado del vuelo de la empresa seleccionada.
/// @param descuentoDebito		El descuento que se realizará sobre el valor ingresado al pagar con débito.
/// @param aumentoCredito		El aumento que se realizará sobre el valor ingresado al pagar con crédito.
/// @param valorBTC				El valor del bitcoin al momento de la operación.
/// @param pPrecioConDebito		Puntero donde se guarda el valor con descuento por pagar con débito.
/// @param pPrecioCredito		Puntero donde se guarda el valor con interes (aumento) por pagar con crédito.
/// @param pPrecioBTC			Puntero donde se guarda el valor del pasaje en BTC.
/// @param pPrecioXkm			Puntero donde se guarda el valor de los precios por km.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int utntp1_calculateResults(float kilometros, float precioEmpresa, int descuentoDebito, int aumentoCredito, float valorBTC, float* pPrecioConDebito, float* pPrecioCredito, float* pPrecioBTC, float* pPrecioXkm)
{
	float debitoAux;
	float creditoAux;
	float btcAux;
	float precioKmAux;
	int rtn =0;
	if(kilometros>0 && precioEmpresa>0 && descuentoDebito >=-100 && aumentoCredito >=0 && valorBTC >= 0)
	{
		if(operations_CalcPriceVarations(precioEmpresa, descuentoDebito, "No se puede hacer la operación", &debitoAux)==1)
		{
			if(operations_CalcPriceVarations(precioEmpresa, aumentoCredito, "No se puede hacer la operación", &creditoAux)==1)
			{
				if(operations_ExchangeRate(precioEmpresa, valorBTC, &btcAux)==1)
				{
					if(operations_Split(precioEmpresa, kilometros, &precioKmAux)==1)
					{
						*pPrecioConDebito=debitoAux;
						*pPrecioCredito=creditoAux;
						*pPrecioBTC=btcAux;
						*pPrecioXkm=precioKmAux;
						rtn=1;
					}
				}
			}
		}
	}
	return rtn;
}
/// @fn int utntp1_printResult(float, float, float, char[], char[], float, float, float, float, float, float, float, float, float)
/// @brief 						Esta función imprime todos los resultados calculados con utntp1_calculateResults,
/// 							por como está planteado el ejercicio imprime en pantalla el los resultados calculados
/// 							para dos empresas.
/// @param kilometros			La valor de los kilometros, en este caso la variable que contiene el dato.
/// @param precioEmpresa		La variable donde se guarda el valor del precio ingresado de la primer empresa.
/// @param precioEmpresaDos		El precio ingresado por la segunda empresa.En este caso la variable que contiene el dato.
/// @param nombreEmpresaUno		Es un string, donde ingresamos el nombre la primer empresa.
/// @param nombreEmpresaDos		Es un string, donde ingresamos el nombre la segunda empresa.
/// @param precioDebito			El valor con descuento de la primer empresa. En este caso la variable que contiene el dato.
/// @param precioDebitoDos		El valor con descuento de la segunda empresa. En este caso la variable que contiene el dato.
/// @param precioCredito		El valor con aumento de la primer empresa. En este caso la variable que contiene el dato.
/// @param precioCreditoDos		El valor con aumento de la segunda empresa. En este caso la variable que contiene el dato.
/// @param precioBTC			El valor en BTC del precio ingresado de la primer empresa. En este caso la variable que contiene el dato.
/// @param precioBTCDos			El valor en BTC del precio ingredado de la segunda empresa. En este caso la variable que contiene el dato.
/// @param precioKm				El precio por km del valor ingresado de la primer empresa.En este caso la variable que contiene el dato.
/// @param precioKmDos			El precio por km del valor ingresado de la segunfa empresa. En este caso la variable que contiene el dato.
/// @param diferenciaPrecio		La diferencia en entre ambos precios. En este caso la variable que contiene el dato.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
/// 							En el caso que que no pueda validar, por falta de datos ingresados, imprime un mensaje
int utntp1_printResult(float kilometros, float precioEmpresa,float precioEmpresaDos, char nombreEmpresaUno[], char nombreEmpresaDos[], float precioDebito,float precioDebitoDos, float precioCredito,float precioCreditoDos, float precioBTC, float precioBTCDos, float precioKm, float precioKmDos, float diferenciaPrecio)
{

	int rtn;
	if(kilometros>0 && precioEmpresa>0 && precioEmpresaDos>0 && precioDebito>0 && precioDebitoDos>0 && precioCredito >0 && precioCreditoDos>0 && precioBTC>0 && precioBTCDos>0 && precioKm>0 && precioKmDos>0)
	{
		printf("\nKMs Ingresados: %.0f km.",kilometros);

		printf("\n\nPrecio %s: $ %.2f",nombreEmpresaUno ,precioEmpresa);
		printf("\na) Precio con tarjeta de débito: $ %.2f", precioDebito);
		printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioCredito);
		printf("\nc) Precio con bitcoin: %.6f BTC", precioBTC);
		printf("\nd) Precio por km: $ %.2f", precioKm);

		printf("\n\nPrecio %s: $ %.2f",nombreEmpresaDos ,precioEmpresaDos);
		printf("\na) Precio con tarjeta de débito: $ %.2f", precioDebitoDos);
		printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioCreditoDos);
		printf("\nc) Precio con bitcoin: %.6f BTC", precioBTCDos);
		printf("\nd) Precio por km: $ %.2f", precioKmDos);
		printf("\n\nLa diferencia de precio es: $ %.2f \n", diferenciaPrecio);
		rtn = 1;
	}
	else
	{
		printf("\n\t\t\tDEBE INGRESAR DATOS Y CALCULARLOS");
		printf("\n\t\t\tPARA PODER MOSTRAR LOS RESULTADOS\n");
		rtn= 0;
	}
	return rtn;
}
/// @fn int utntp1_calculateDiference(float, float, float*)
/// @brief 				Esta función calcula la diferencias de precio, y devuelve siempre un
/// 					valor positivo como resultado.
/// @param precioUno	Primer precio para hacer la diferencia.
/// @param precioDos	Segundo precio para hacer la diferencia.
/// @param pDiferencia	Puntero donde guarda el valor de la operación.
/// @return				El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
/// 					En el caso de error, devolvera un mensaje impreso en pantalla.
int utntp1_calculateDiference(float precioUno, float precioDos, float* pDiferencia)
{
	float difAux;
	int rtn;
	if(precioUno>0 && precioDos>0 && pDiferencia!=NULL)
	{
		if(precioUno>precioDos)
		{
			if(operations_Subtract(precioUno, precioDos, &difAux)==1)
			{
				*pDiferencia=difAux;
			}
		}
		else
		{
			if(operations_Subtract(precioDos, precioUno, &difAux)==1)
			{
				*pDiferencia=difAux;
			}
		}
		printf("\n\t\t\tCALCULADOS TODOS LOS COSTOS\n");
		rtn = 1;
	}
	else
	{
		printf("\n\t\tDEBE INGRESAR TODOS LOS DATOS A CALCULAR PRIMERO\n");
		rtn = 0;
	}
	return rtn;
}
/// @fn int utntp1_forceCharge(float, float, float, int, int, float)
/// @brief 						Esta función condensa todas las operacionese del programa, calcula los resultados
/// 							y los imprime en pantalla. Para eso hay que cargarle los datos con que queremos que
/// 							realice las operaciones.
/// @param kilometrosForzados	El valor de los kilometros que declaramos para que haga las operaciones.
/// @param precioUnoForzado		El valor del primer precio ingresado que declaramos para que haga las operaciones.
/// @param precioDosForzado		El valor del segundo precio ingresado que declaramos para que haga las operaciones.
/// @param descuento			El valor que declaramos para que realice los descuentos correspondientes.
/// @param interes				El valor que declaramos para que realice los aumentos correspondientes.
/// @param btc					El valor del BTC para que realice la converción de los precios.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int utntp1_forceCharge(float kilometrosForzados, float precioUnoForzado, float precioDosForzado, int descuento, int interes, float btc)
{
	int rtn =0;
	if(kilometrosForzados>0 && precioUnoForzado>0 && precioDosForzado>0 && descuento > -100 && interes >=0 && btc >=0)
	{
		float entKm=kilometrosForzados;
		float entPriceAerolineas=precioUnoForzado;
		float entPriceLatam=precioDosForzado;
		float debitPriceAerolineas;
		float debitPriceLatam;
		float creditPriceAerolineas;
		float creditPriceLatam;
		float btcPriceAerolineas;
		float btcPriceLatam;
		float pricePerKmAerolineas;
		float pricePerKmLatam;
		float priceDiference;
		utntp1_calculateResults(entKm, entPriceAerolineas, descuento, interes, btc, &debitPriceAerolineas, &creditPriceAerolineas, &btcPriceAerolineas, &pricePerKmAerolineas);
		utntp1_calculateResults(entKm, entPriceLatam, descuento, interes, btc, &debitPriceLatam, &creditPriceLatam, &btcPriceLatam, &pricePerKmLatam);
		utntp1_calculateDiference(entPriceAerolineas, entPriceLatam, &priceDiference);
		utntp1_printResult(entKm, entPriceAerolineas, entPriceLatam, "Aerolineas","LATAM", debitPriceAerolineas, debitPriceLatam, creditPriceAerolineas, creditPriceLatam, btcPriceAerolineas, btcPriceLatam, pricePerKmAerolineas, pricePerKmLatam, priceDiference);
		rtn=1;
	}
	return rtn;
}

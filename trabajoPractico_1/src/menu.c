/*
 * menu.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Dell
 */

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"

void mostrarMenu()
{
	printf("\t***MENU***\n");
	printf("Para comenzar elija una opcion:\n");
	printf("1.Ingresar kilometros\n\n");
	printf("2.Ingresar precio de vuelos(Aerolineas y Latam)\n");
	printf("-Precio vuelo Aerolineas:\n-Precio vuelo Latam:\n\n");
	printf("3.Calcular todos los costos\n");
	printf("\ta) Tarjeta de debito (descuento 10%%)\n");
	printf("\tb) Tarjeta de credito (interes 25%%)\n");
	printf("\tc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("\td) Mostrar precio por kilometro (precio unitario)\n");
	printf("\te) Mostrar diferencia de precio ingresada: (Latam - Aerolineas)\n");
	printf("4.Informar resultados\n");
	printf("“Latam:\na) Precio con tarjeta de débito: r\nb) Precio con tarjeta de crédito: r\nc) Precio pagando con bitcoin : r\nd) Precio unitario: r\n\n"
			"Aerolíneas:\na) Precio con tarjeta de débito: r\nb) Precio con tarjeta de crédito: r\nc) Precio pagando con bitcoin : r\nd) Precio unitario: r\n"
			"La diferencia de precio es : r \n\n");
	printf("5.Carga forzada de datos\n");
	printf("6.Salir\n\n");
}

int mostrarResultados(char* titulo, float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario)
{
	int todoOk=0;

	if( titulo!=NULL && precioDebito>0 && precioCredito>0 && precioBitcoin>0 && precioUnitario>0)
	{
		printf("\n%s\n", titulo);
		printf("a) Precio con tarjeta de debito: $ %.2f\n", precioDebito);
		printf("b) Precio con tarjeta de credito: $ %.2f\n", precioCredito);
		printf("c) Precio pagando con bitcoin: %.8f BTC\n", precioBitcoin);
		printf("d) Precio unitario: $ %.2f\n", precioUnitario);
		todoOk=1;
	}

	return todoOk;
}


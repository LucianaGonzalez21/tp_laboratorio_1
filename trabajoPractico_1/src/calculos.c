/*
 * calculos.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Dell
 */


#include <stdlib.h>
#include <stdio.h>
#include "calculos.h"

int calcularPrecioDebito(float precio, int descuento, float* pTotal)
{
	int todoOk=0;

	if(precio>0 && descuento>0 && pTotal!=NULL)
	{
		*pTotal = precio - ((precio * descuento)/100);
		todoOk=1;
	}

	return todoOk;
}

int calcularPrecioCredito(float precio, int interes, float* pTotal)
{
	int todoOk=0;

	if(precio>0 && interes>0 && pTotal != NULL)
	{
		*pTotal = precio + ((precio * interes)/100);
		todoOk=1;
	}

	return todoOk;
}

int calcularPrecioBitcoin(float precioPesos, float precioBitcoin, float* pTotal)
{
	int todoOk=0;

	if(precioPesos>0 && precioBitcoin>0 && pTotal != NULL)
	{
		*pTotal= precioPesos/precioBitcoin;
		todoOk=1;
	}

	return todoOk;
}

int calcularPrecioUnitario(float precio, float kilometros, float* pTotal)
{
	int todoOk=0;

	if(precio>0 && kilometros>0 && pTotal != NULL)
	{
		*pTotal = precio/kilometros;
		todoOk=1;
	}

	return todoOk;
}

int calcularDiferenciaPrecios(float precioUno, float precioDos, float* pTotal)
{
	int todoOk = 0;

	if (precioUno > 0 && precioDos > 0 && pTotal != NULL)
	{
		*pTotal = precioDos - precioUno;
		todoOk = 1;
	}

	return todoOk;
}


int calcularCostos(float precio, float kilometros, float* precioDebito, float* precioCredito, float* precioConBitcoin, float* precioUnitario, int interes, int descuento, float bitcoin)
{
	int todoOk=0;
	if(calcularPrecioDebito(precio, descuento, precioDebito) &&
		calcularPrecioCredito(precio, interes, precioCredito) &&
		calcularPrecioBitcoin(precio, bitcoin, precioConBitcoin) &&
		calcularPrecioUnitario(precio, kilometros,precioUnitario))
	{
		todoOk=1;
	}
	return todoOk;
}



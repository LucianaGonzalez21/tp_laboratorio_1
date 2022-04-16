/*
 ============================================================================
 Name        : trabajoPractico_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"
#include "menu.h"

#define BITCOIN 4606954.55
#define INTERES 25
#define DESCUENTO 10

int main(void) {
	setbuf(stdout, NULL);

	int rta;
	int todoOk;
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecios;
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;
	int flag1=0;
	int flag2=0;
	int flag3=0;

	do {

		mostrarMenu();
		todoOk = utn_getNumero(&rta, "Ingrese la opcion deseada:\n", "Error, opcion no valida\n", 1, 6, 3);

		if (!todoOk) {
			switch (rta) {
			case 1:
				if(!(utn_getFloat(&kilometros, "Ingrese la cantidad de kilometros: ", "Numero invalido\n", 0, 1000000, 3)))
				{
					printf("*Kilometros ingresados correctamente.*\n");
					printf("kilometros %.2f\n\n", kilometros);
					flag1 = 1;
				}
				else
				{
					printf("Error al cargar los kilometros\n\n");
				}
				break;
			case 2:
				if( !(utn_getFloat(&precioAerolineas, "Ingrese el precio de Aerolineas: ", "Numero invalido\n", 0, 1000000,3)) &&
					!(utn_getFloat(&precioLatam, "Ingrese el precio de Latam: ", "Numero invalido\n", 0, 1000000, 3)))
				{
					printf("*Precios ingresados correctamente.*\n");
					printf("Precio aerolineas: $%.2f\n", precioAerolineas);
					printf("Precio latam: $%.2f\n\n", precioLatam);
					flag2 = 1;
				}
				else
				{
					printf("\nError al cargar precios.\n\n");
				}
				break;
			case 3:
				if(	flag1 &&
					flag2 &&
					calcularCostos(precioAerolineas, kilometros, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &precioUnitarioAerolineas, INTERES, DESCUENTO, BITCOIN) &&
					calcularCostos(precioLatam, kilometros, &debitoLatam, &creditoLatam, &bitcoinLatam, &precioUnitarioLatam, INTERES, DESCUENTO, BITCOIN) &&
					calcularDiferenciaPrecios(precioAerolineas, precioLatam, &diferenciaPrecios))
				{
					printf("*Costos calculados correctamente.*\n");
					flag3 = 1;
				}
				else
				{
					printf("\nPrimero debe ingresar los kilometros y los precios.\n");
				}
				break;
			case 4:
				if(	flag3 &&
					mostrarResultados("Aerolineas:", debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas) &&
					mostrarResultados("Latam:", debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioLatam))
				{
					printf("La diferencia de precios es: %.2f\n\n", diferenciaPrecios);
					flag1 = 0;
					flag2 = 0;
				}
				else
				{
					printf("\nPrimero debe calcular los costos.\n");
				}
				break;
			case 5:
				if(flag1 || flag2 )
				{
					printf("\nPara la carga forzada, no se deben ingresar datos previamente.\n");
				}
				else
				{
					printf("KMs Ingresados: 7090 km\n");
						if( calcularCostos(162965, 7090, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &precioUnitarioAerolineas, INTERES, DESCUENTO, BITCOIN) &&
							calcularCostos(159339, 7090, &debitoLatam, &creditoLatam, &bitcoinLatam, &precioUnitarioLatam, INTERES, DESCUENTO, BITCOIN) &&
							mostrarResultados("Precio Aerolineas: $162965", debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas) &&
							mostrarResultados("Precio Latam: $159339", debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioLatam) &&
							calcularDiferenciaPrecios(162965, 159339, &diferenciaPrecios))
						{
							printf("\nLa diferencia de precios es: %.2f\n\n", diferenciaPrecios);
						}
				}
				break;
			case 6:
				printf("Usted ha salido\n");
				break;
			}
		} else {
			printf("Programa finalizado\n");
			break;
		}
	} while (rta != 6);

	return EXIT_SUCCESS;
}


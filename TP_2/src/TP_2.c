/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "passenger.h"
#include "statusFlight.h"
#include "typePassenger.h"

#define LEN_PASSENGERS 2000
#define LEN_STATUS 4
#define LEN_TYPE 3


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	Passenger passengersList[LEN_PASSENGERS];
	eStatusFlight status[LEN_STATUS] = {
			{7000, "Scheduled"},
			{7001, "Active"},
			{7002, "Landed"},
			{7003, "Cancelled"}
	};
	eTypePassenger types[LEN_TYPE] = {
			{2000, "Infant"},
			{2001, "Child"},
			{2002, "Adult"}
	};
	int index=100;
	int flag=0;
	int flagH=0;

	initPassengers(passengersList, LEN_PASSENGERS);
	do {
		if (!menuPrincipal(&opcion)) {

			switch (opcion) {
			case 1:
				if(cargarPasajero(passengersList, LEN_PASSENGERS, &index, status, LEN_STATUS, types, LEN_TYPE))
				{
					printPassenger(passengersList, LEN_PASSENGERS, types, LEN_TYPE, status, LEN_STATUS);
					printf("\nPasajero cargado correctamente!\n\n");
					flag=1;
				}
				else
				{
					printf("Error al intentar cargar pasajero.\n\n");
				}
				break;
			case 2:
				if(flag || flagH)
				{
					modificarPasajero(passengersList, LEN_PASSENGERS, types, LEN_TYPE, status, LEN_STATUS);
				}
				else
				{
					printf("Error. Primero debe cargar al menos un pasajero.\n\n");
				}
				break;
			case 3:
				if((flag || flagH))
				{
					if(darBajaPasajero(passengersList, LEN_PASSENGERS, types, LEN_TYPE, status, LEN_STATUS))
					{
						printf("Pasajero dado de baja con exito.\n\n");
					}
					else
					{
						printf("Error al eliminar.\n\n");
					}
				}
				else if(!flag)
				{
					printf("Error. Primero debe cargar al menos un pasajero.\n\n");
				}
				break;
			case 4:
				if(flag || flagH)
				{
					mostrarInformes(passengersList, LEN_PASSENGERS, types, LEN_TYPE, status, LEN_STATUS);
				}
				else
				{
					printf("Error. Primero debe ingresar al menos un pasajero.\n\n");
				}
				break;
			case 5:
				if(!flagH && hardcodearPasajeros(passengersList, LEN_PASSENGERS, 10, &index))
				{
					if(!printPassenger(passengersList, LEN_PASSENGERS, types, LEN_TYPE, status, LEN_STATUS))
					{
						flagH=1;
					}
				}
				else if(flagH)
				{
					printf("Ya se realizo la carga forzada.\n\n");
				}
				break;
			case 6:
				printf("Usted ha salido\n");
				break;
			}
		}
		else
		{
			printf("ERROR. Cantidad de reintentos agotada. \nPrograma finalizado\n");
			break;
		}
	} while (opcion != 6);

	return EXIT_SUCCESS;
}

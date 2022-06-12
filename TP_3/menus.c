/*
 * menus.c
 *
 *  Created on: Jun 10, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menuPrincipal(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero\n"
				"4. Modificar datos de pasajero\n"
				"5. Baja de pasajero\n"
				"6. Listar pasajeros\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 10, 3);
	}
	return rta;
}

int menuTipoPasajero(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("Type Passenger:\n"
				"1.First class\n"
				"2.Business class\n"
				"3.Economy class\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 3, 3);
	}
	return rta;
}

int menuEstadoVuelo(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("Status Flight:\n"
				"1.Scheduled\n"
				"2.Active\n"
				"3.Landed\n"
				"4.Cancelled\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 4, 3);
	}
	return rta;
}

int menuModificarPasajero(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("1. Nombre\n"
				"2.Apellido\n"
				"3.Precio\n"
				"4.Codigo de vuelo\n"
				"5.Tipo de vuelo"
				"6.Estado de vuelo\n"
				"7.Cancelar\n");

		rta = utn_getNumero(opcion, "Ingrese la opcion a modificar: ","Error. Opcion no valida\n", 1, 7, 3);
	}
	return rta;
}

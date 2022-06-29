/*
 * menus.c
 *
 *  Created on: Jun 10, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menus.h"

int menuPrincipal(int* opcion) {

	int rta;

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

	return rta;
}

int menuTipoPasajero() {

	int opcion=0;

	printf("Type Passenger:\n"
			"1.First class\n"
			"2.Business class\n"
			"3.Economy class\n");


	utn_getNumero(&opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 3, 3);
	return opcion;
}

int menuEstadoVuelo() {

	int opcion;

    printf("Status Flight:\n"
				"1.Scheduled\n"
				"2.Active\n"
				"3.Landed\n"
				"4.Cancelled\n");
    utn_getNumero(&opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 4, 3);

	return opcion;
}

int menuModificaciones()
{
	int opcion=0;

	printf("Menu modificar:\n"
			"1.Nombre\n"
			"2.Apellido\n"
			"3.Precio\n"
			"4.Codigo de vuelo\n"
			"5-Tipo de pasajero\n"
			"6-Estado de vuelo\n"
			"7-Cancelar\n");

	utn_getNumero(&opcion, "ingrese opcion: ", "error\n", 1,7, 3);

	return opcion;
}

int menuPrincipalOrdenamiento()
{
	int opcion=0;

	printf(	"Menu ordenar:\n"
			"1.Por id\n"
			"2-Por nombre\n"
			"3-Por apellido\n"
			"4-Por precio\n"
			"5-Por codigo de vuelo\n"
			"6-Por tipo de pasajero\n"
			"7-Por estado de vuelo\n"
			"8-Cancelar\n");

	utn_getNumero(&opcion, "ingrese opcion: ", "error\n", 1,8, 3);

	return opcion;
}
int menuCriterioOrdenamiento(int* tipo)
{
	int todoOk=1;
	int elegirOpcion=0;

	if(tipo!=NULL)
	{
		printf("1.Ascendente\n2.Descendente\n3.Cancelar\n");
		utn_getNumero(&elegirOpcion, "ingrese un opcion: ", "error\n", 1, 3,3);
		*tipo=elegirOpcion;
		todoOk=0;
	}

	return todoOk;
}

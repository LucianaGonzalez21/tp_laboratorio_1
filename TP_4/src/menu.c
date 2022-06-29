/*
 * menu.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int menuPrincipal()
{
	int opcion=0;

	printf(
			"1-Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
			"2-Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)\n"
			"3-Alta de pasajero\n"
			"4-Modificar datos\n"
			"5-Baja del pasajero\n"
			"6-Listar pasajeros\n"
			"7-Ordenar pasajeros\n"
			"8-Reiniciar lista (borra todos los elementos de la lista)\n"
			"9-Informes\n"
			"10-Guardar los datos de pasajeros en el data.csv (modo texto)\n"
			"11-Guardar los datos de pasajeros en el data.bin (modo binario)\n"
			"12-Salir\n");

	utn_getNumero(&opcion, "ingrese una opcion: ", "error, no valido\n", 1, 12, 3);

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
int menuInformes()
{

	int opcion=0;

	printf(	"Menu informes:\n"
			"1.Sublista seleccionado por usuario\n"
			"2-Eliminar pasajero con precio menor\n"
			"3-Alta en posicion elegida\n"
			"4-Cancelar\n");

	utn_getNumero(&opcion, "ingrese opcion: ", "error\n", 1,4, 3);

	return opcion;
}

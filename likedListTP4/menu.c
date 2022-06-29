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
			"1-CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO data.csv (modo texto)\n"
			"2-CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO data.bin (modo binario)|\n"
			"3-ALTA DE PASAJERO\n"
			"4-MODIFICAR DATOS DEL PASAJERO\n"
			"5-BAJA DEL PASAJERO\n"
			"6-LISTAR PASAJEROS\n"
			"7-ORDENAR PASAJEROS\n"
			"8-REINICIAR LISTA (borra todos los elementos de la lista)\n"
			"9-INFORMES TRAVEL UTN ARG (Aplico los linkedlist que faltan)\n"
			"10-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO data.csv (modo texto)\n"
			"11-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO data.bin (modo binario)\n"
			"12-SALIR\n");

	utn_getNumero(&opcion, "ingrese una opcion: ", "error, no valido\n", 1, 12, 3);

	return opcion;
}
int menuModificaciones()
{
	int opcion=0;

	printf("1-MODIFICAR NOMBRE\n"
			"2-MODIFICAR APELLIDO\n"
			"3-MODIFICAR PRECIO\n"
			"4-MODIFICAR CODIGO DE VUELO\n"
			"5-MODIFICAR TIPO DE PASAJERO\n"
			"6-MODIFICAR ESTADO DE VUELO\n"
			"7-SALIR\n");

	utn_getNumero(&opcion, "ingrese opcion: ", "error\n", 1,7, 3);

	return opcion;
}
int menuPrincipalOrdenamiento()
{
	int opcion=0;

	printf(	"1-ORDENAMIENTO POR ID\n"
			"2-ORDENAMIENTO POR NOMBRE\n"
			"3-ORDENAMIENTO POR APELLIDO\n"
			"4-ORDENAMIENTO POR PRECIO\n"
			"5-ORDENAMIENTO POR CODIGO DE VUELO\n"
			"6-ORDENAMIENTO POR TIPO DE PASAJERO\n"
			"7-ORDENAMIENTO POR ESTADO DE VUELO\n"
			"8-SALIR\n");

	utn_getNumero(&opcion, "ingrese opcion: ", "error\n", 1,8, 3);

	return opcion;
}
int menuCriterioOrdenamiento(int* tipo)
{
	int todoOk=1;
	int elegirOpcion=0;

	if(tipo!=NULL)
	{
		printf("1.ASCENDENTE\n2.DESCENDENTE\n3.SALIR\n");
		utn_getNumero(&elegirOpcion, "ingrese un opcion: ", "error\n", 1, 3,3);
		*tipo=elegirOpcion;
		todoOk=0;
	}

	return todoOk;
}
int menuInformes()
{

	int opcion=0;

	printf(	"1-INFORME SUD LISTADO SELECCIONADO POR EL USUARIO\n"
			"2-INFORME ELIMINA UN PASAJERO CON MENOR PRECIO\n"
			"3-INFORME ALTA EN POSICION ELEGIDA\n"
			"4-SALIR\n");

	utn_getNumero(&opcion, "ingrese opcion: ", "error\n", 1,4, 3);

	return opcion;
}

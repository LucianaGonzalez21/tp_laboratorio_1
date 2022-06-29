/*
 ============================================================================
 Name        : TP_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "passenger.h"
#include "utn.h"
#include "parser.h"
#include "menu.h"


int main(void) {
	setbuf(stdout, NULL);
	char salir;
	int flagLoadText=0;
	int flagLoadBinary=0;
	int flagAdd=0;
	int flagSave=0;

	LinkedList* listaPasajeros = ll_newLinkedList();

	if(listaPasajeros==NULL)
	{
		printf("No se consiguio memoria\n");
		exit(1);
	}

	do{


		switch(menuPrincipal())
		{
			case 1:
				if(flagLoadText==1)
				{
					printf("\nYa se cargo la lista del archivo de modo texto\n\n");
				}
				else if(flagLoadBinary==1)
				{
					printf("\nError. Ya se cargo la lista del archivo de modo binario\n\n");
				}
				else
				{
					controller_loadFromText("pasajeros.csv", listaPasajeros);
					flagLoadText=1;
					flagAdd=1;
				}
				break;
			case 2:
				if(flagLoadBinary)
				{
					printf("\nYa se cargo la lista del archivo de modo binario...\n\n");
				}
				else if(flagLoadText)
				{
					printf("\nError. Ya se cargo la lista del archivo de modo texto...\n\n");
				}
				else
				{
					controller_loadFromBinary("dataBinaria.bin", listaPasajeros);
					flagLoadBinary=1;
					flagAdd=1;
				}
				break;
			case 3:
				if(controller_addPassenger(listaPasajeros)==1)
				{
					flagAdd=1;
				}
				break;
			case 4:
				if(flagAdd)
				{
					controller_editPassenger(listaPasajeros);
				}
				else
				{
					printf("\nPrimero debe cargar pasajeros\n");
				}
				break;
			case 5:
				if(flagAdd)
				{
					controller_removePassenger(listaPasajeros);
				}
				else
				{
					printf("\nPrimero debe cargar pasajeros\n");
				}
				break;
			case 6:
				if(flagAdd)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("\nPrimero debe cargar pasajeros\n");
				}
				break;
			case 7:
				if(flagAdd)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("\nPrimero debe cargar pasajeros\n");
				}
				break;
			case 8:
				if(flagAdd)
				{
					ll_clear(listaPasajeros);
					printf("\nSe han borrado los elementos de la lista\n");
					flagAdd=0;
				}
				else
				{
					printf("\nPrimero debe cargar pasajeros\n");
				}
				break;
			case 9:
				if(flagAdd==1)
				{
					controller_informarListas(listaPasajeros);
				}
				else
				{
					printf("\nPrimero debe cargar pasajeros\n");
				}
				break;
			case 10:
				if(!flagLoadText)
				{
					printf("\nError. Ya se cargo el archivo en modo binario\n\n");
				}
				else
				{
					controller_saveAsText("data.csv", listaPasajeros);
					flagSave=1;
				}
				break;
			case 11:
				if(!flagLoadBinary)
				{
					printf("\nError. Ya se guardo el archivo en modo texxto\n\n");
				}
				else
				{
					controller_saveAsBinary("dataBinaria.bin", listaPasajeros);
					flagSave=1;
				}
				break;
			case 12:
				if(!flagSave)
				{
					printf("\nError. Debe guardar antes de salir\n\n");
				}
				else
				{
					ingresoChar(&salir, "Ingrese  s para salir del menu principal (s/n): ");
					ll_deleteLinkedList(listaPasajeros);
				}
				break;
			default:
				break;
		}
	}while(salir!='s');
	return EXIT_SUCCESS;
}

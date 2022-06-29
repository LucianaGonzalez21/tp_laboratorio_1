#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menus.h"
//#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    int opcion;
    int flag=0;
    int flagSave = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();


    do {
    		if (!menuPrincipal(&opcion)) {

    			switch (opcion) {
    			case 1:
    				if(!flagSave)
    				{
						if(controller_loadFromText("data2.csv" ,listaPasajeros))
						{
							printf("Datos cargados correctamente.\n\n");
							flagSave=1;
						}
						else
						{
							printf("Error al cargar datos desde archivo.\n\n");
						}
    				}
    				else if(flagSave)
    				{
    					printf("El archivo ya fue cargado.\n\n");
    				}
    				else
    				{
    					printf("El archivo ya fue cargado en modo binario.\n\n");
    				}
    				break;
    			case 2:
    				if(!flagSave)
    				{
						if(controller_loadFromBinary("data2.csv", listaPasajeros))
						{
							printf("Datos cargados correctamente.\n\n");
							flagSave = 2;
						}
						else
						{
							printf("Error al cargar datos desde el archivo.\n\n");
						}
    				}
    				else if(flagSave)
    				{
    					printf("El archivo ya fue cargado en modo texto.\n\n");
    				}
    				else
    				{
    					printf("El archivo ya fue cargado.\n\n");
    				}
    				break;
    			case 3:
    				if(!controller_addPassenger(listaPasajeros))
    				{
    					printf("Error al dar de alta.\n\n");
    				}
    				else
    				{
    					printf("Alta realizada con exito.\n\n");
    					flag=1;
    				}
    				break;
    			case 4:
    				if(flagSave || flagSave==2 || flag)
    				{
						if(!controller_editPassenger(listaPasajeros))
						{
							printf("Error al modificar datos.\n\n");
						}
						else
						{
							printf("Modificacion realizada con exito.\n\n");
						}
    				}
    				else
    				{
    					printf("Primero debe cargar pasajeros desde el archivo o dando de alta.\n\n");
    				}
    				break;
    			case 5:
    				if(flag || flagSave || flagSave==2)
    				{
						if(!controller_removePassenger(listaPasajeros))
						{
							printf("Error al eliminar pasajero.\n\n");
						}
						else
						{
							printf("Pasajero eliminado.\n\n");
						}
    				}
    				else
    				{
    					printf("Primero debe cargar pasajeros desde el archivo o dando de alta.\n\n");
    				}
    				break;
    			case 6:
    				if(flag || flagSave || flagSave==2)
    				{
						if(!controller_ListPassenger(listaPasajeros))
						{
							printf("Error al listar pasajeros.\n\n");
						}
    				}
    				else
    				{
    					printf("Primero debe cargar pasajeros desde el archivo o dando de alta\n\n");
    				}
    				break;
    			case 7:
    				if(flagSave || flagSave==2 || flag)
    				{
    					if(!controller_sortPassenger(listaPasajeros))
    					{
    						printf("Error al listar pasajeros.\n\n");
    					}
    				}
    				else
    				{
    					printf("Primero debe cargar pasajeros desde el archivo o dando de alta.\n\n");
    				}
    				break;
    			case 8:

    				if(flagSave || flag)
    				{
						controller_saveAsText("data.txt", listaPasajeros);
						flagSave=3;
						printf("Archivo guardado en modo texto correctamente.\n");
    				}
    				else
    				{
    					printf("Primero debe cargar los datos desde el archivo como texto.\n\n");
    				}
    				break;
    			case 9:

    				if(flagSave == 2)
    				{
						controller_saveAsBinary("data.bin", listaPasajeros);
						flagSave=3;
						printf("Archivo guardado en modo binario correctamente.\n");
    				}
    				else
    				{
    					printf("Primero debe cargar los datos desde el archivo como binario.\n\n");
    				}
    				break;
    			case 10:
    				if(flagSave==3)
    				{
    					Passenger_deleteAll(listaPasajeros);
    					ll_deleteLinkedList(listaPasajeros);
						printf("Programa finalizado.\n\n");
    				}
    				else
    				{
    					printf("No puede salir sin antes guardar los cambios.\n\n");
    				}
    				break;
    			}
    		}
    		else
    		{
    			printf("ERROR. Cantidad de reintentos agotada. \nPrograma finalizado\n");
    			break;
    		}
    	} while (opcion != 10);
    return 0;
}


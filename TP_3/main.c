#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menus.h"

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

    LinkedList* listaPasajeros = ll_newLinkedList();


    do {
    		if (!menuPrincipal(&opcion)) {

    			switch (opcion) {
    			case 1:
    				printf("opcion 1\n");
    				controller_loadFromText("data.csv" ,listaPasajeros);
    				break;
    			case 2:
    				controller_loadFromBinary("data.csv", listaPasajeros);
    				break;
    			case 3:
    				printf("alta pasajero\n");
    				controller_addPassenger(listaPasajeros);
    				break;
    			case 4:
    				printf("modificar datos\n");
    				//controller_editPassenger(listaPasajeros);
    				break;
    			case 5:
    				printf("eliminar pasajero\n");
    				//controller_removePassenger(listaPasajeros);
    				break;
    			case 6:
    				//printf("listar\n");
    				controller_ListPassenger(listaPasajeros);
    				break;
    			case 7:
    				printf("ordenar\n");
    				//controller_sortPassenger(listaPasajeros);
    				break;
    			case 8:
    				printf("guardar como texto\n");
    				//controller_saveAsText("data.txt", listaPasajeros);
    				break;
    			case 9:
    				printf("guardar como binario\n");
    				//controller_saveAsBinary("data.bin", listaPasajeros);
    				break;
    			case 10:
    				printf("Programa finalizado.\n\n");
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


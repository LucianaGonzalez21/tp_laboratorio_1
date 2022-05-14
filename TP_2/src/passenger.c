/*
 * passenger.c
 *
 *  Created on: May 8, 2022
 *      Author: Dell
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "passenger.h"
#include "statusFlight.h"
#include "utn.h"

int menuPrincipal(int *opcion) {

	int rta;

	if (opcion != NULL) {

		printf("    ***Aerolineas***\n");
		printf("	  *MENU*\n");
		printf("1.ALTA de pasajero.\n");
		printf(
				"2.MODIFICAR datos(Nombre, Apellido, Precio, Tipo de Pasajero o Codigo de vuelo)\n");
		printf("3.BAJA de pasajero.\n");
		printf("4.INFORMES\n");
		printf("5.CARGA FORZADA de datos\n");
		printf("6.SALIR\n\n");

		rta = utn_getNumero(opcion, "Ingrese una opcion: ","Error. Opcion no valida\n", 1, 6, 3);
	}

	return rta;

}


int menuModificarPasajero(int* opcionModificar)
{
	int rta;

	if(opcionModificar!=NULL)
	{
		printf("Opciones a modificar:\n");
		printf("1.Nombre\n");
		printf("2.Apellido\n");
		printf("3.Precio del vuelo\n");
		printf("4.Tipo de Pasajero\n");
		printf("5.Codigo de vuelo\n");
		printf("6.Cancelar\n\n");

		rta = utn_getNumero(opcionModificar, "Ingrese el numero de la opcion que desea modificar: ", "Error, opcion no valida.\n", 1, 6, 3);
	}

	return rta;
}


int initPassengers(Passenger *list, int len) {
	int todoOk = -1;

	if (list != NULL && len > 0) {
		todoOk = 0;

		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return todoOk;
}


int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int todoOk=-1;
	int i;

	if(list!=NULL && len>0 && id>=100 && name!=NULL && lastName!=NULL && price>0 && flycode!=NULL)
	{
		if(buscarPosicionLibre(list, len, &i) && i>=0)
		{
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].flyCode, flycode);
			list[i].statusFlight = statusFlight;
			list[i].isEmpty = 0;
			todoOk=0;
		}
	}
	return todoOk;
}


int buscarPosicionLibre(Passenger* list, int len, int* pPosicion)
{
	int todoOk=0;

	if(list != NULL && len>0 && pPosicion!=NULL)
	{
		todoOk=1;
		*pPosicion = -1;

		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty)
			{
				*pPosicion = i;
				break;
			}
		}
	}
	return todoOk;
}


int cargarPasajero(Passenger* list, int lenP, int* pIndex, eStatusFlight* status, int lenS, eTypePassenger* types, int lenT)
{
	int todoOk=0;
	Passenger newPassenger;
	char name[100];
	char lastName[100];
	char flyCode[100];

	if(list!=NULL && lenP>0 && pIndex!=NULL)
	{
		if(!GetString(name, 100, "Ingrese nombre: ", "Error, nombre invalido.\n", 3) &&
			!GetString(lastName, 100, "Ingrese apellido: ", "Error, apellido invalido.\n", 3) &&
			!utn_getFloat(&newPassenger.price, "Ingrese el precio del vuelo: ", "Error, precio no valido.\n", 0, 1000000, 3) &&
			!utn_getStringAlfaNumerico(flyCode, 100, "Ingrese el codigo de vuelo: ", "Error, codigo no valido.\n", 3) &&
			listarTiposPasajero(types, lenT) &&
			!utn_getNumero(&newPassenger.typePassenger, "Ingrese el id del tipo de pasajero: ", "Error, opcion no valida.\n", 2000, 2002, 3) &&
			listarEstadosDeVuelo(status, lenS) &&
			!utn_getNumero(&newPassenger.statusFlight, "Ingrese el id del estado de vuelo:", "Error, opcion no valida.\n", 7000, 7003, 3))
		{

			strncpy(newPassenger.name, name, 51);
			strncpy(newPassenger.lastName, lastName, 51);
			strncpy(newPassenger.flyCode, flyCode, 10);
			newPassenger.id = *pIndex;
			*pIndex = *pIndex + 1;
			addPassenger(list, lenP, newPassenger.id, newPassenger.name, newPassenger.lastName, newPassenger.price, newPassenger.typePassenger, newPassenger.flyCode, newPassenger.statusFlight);
			todoOk=1;
		}
	}

	return todoOk;
}


int findPassengerById(Passenger* list, int len,int id)
{
	int index=-1;

	if(list!=NULL && len>0 && id>=100)
	{
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				index=i;
				break;
			}
		}

	}
	return index;
}


int removePassenger(Passenger* list, int len, int id)
{
	int todoOk=-1;
	int index;

	if(list!=NULL && len>0 && id>=100)
	{
		index = findPassengerById(list, len, id);
		if(index!=-1)
		{
			list[index].isEmpty = 1;
			todoOk=0;
		}
	}
	return todoOk;
}


int darBajaPasajero(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS)
{
	int todoOk=-1;
	int id;
	int flag=0;

	if(list!=NULL && lenP>0 && types!=NULL && lenT>0 && status!=NULL && lenS>0)
	{
		todoOk=0;
		for(int i=0; i<lenP;i++)
		{
			if(!list[i].isEmpty)
			{
				flag=1;
				break;
			}
		}

		if(flag)
		{
			printPassenger(list, lenP, types, lenT, status, lenS);

			if(!utn_getNumero(&id, "Ingrese el id del pasajero al que desea dar de baja: ", "Error, id no valido.\n", 100, 10000,3)
					&& !removePassenger(list, lenP, id))
			{
				todoOk=1;
			}
		}
		else
		{
			printf("No hay pasajeros para eliminar.\n\n");
		}
	}

	return todoOk;
}


int sortPassengers(Passenger* list, int lenP, eTypePassenger* types, int lenT, int order)		//ordena por apellido y tipo de pasajero
{
	int todoOk=-1;
	Passenger auxiliar;
	char descripcionTipo1[100];
	char descripcionTipo2[100];

	if(list!=NULL && lenP>0 && types!=NULL && lenT>0 && (!order || order ))
	{
		todoOk=0;
		for(int i=0; i<lenP-1; i++)
		{
			for(int j=i+1; j<lenP; j++)
			{
				cargarDescripcionTipoPasajero(types, lenT, list[i].typePassenger, descripcionTipo1);
				cargarDescripcionTipoPasajero(types, lenT, list[j].typePassenger, descripcionTipo2);

				if((order && stricmp(list[i].lastName,list[j].lastName)>0) ||
					(order && stricmp(list[i].lastName, list[j].lastName)==0 && stricmp(descripcionTipo1, descripcionTipo2)>0))
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
				else if((!order && stricmp(list[i].lastName,list[j].lastName)<0) ||
						(!order && stricmp(list[i].lastName, list[j].lastName)==0 && stricmp(descripcionTipo1, descripcionTipo2)<0))
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
	}

	return todoOk;
}


int mostrarPasajero(Passenger aPassenger, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS)
{
	int todoOk=0;
	char descripcionTipo[20];
	char descripcionEstado[20];

	if(types!=NULL && lenT>0 && status!=NULL && lenS>0)
	{
		if(!aPassenger.isEmpty)
		{
			cargarDescripcionEstadoDeVuelo(status, lenS, aPassenger.statusFlight, descripcionEstado);
			cargarDescripcionTipoPasajero(types, lenT, aPassenger.typePassenger, descripcionTipo);

			printf("%4d     %-15s  %-15s $ %5.2f     %6s     %10s        %10s\n",
					aPassenger.id,
					aPassenger.name,
					aPassenger.lastName,
					aPassenger.price,
					aPassenger.flyCode,
					descripcionTipo,
					descripcionEstado);
			todoOk=1;
		}
	}
	return todoOk;
}


int printPassenger(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS)
{
	int todoOk=-1;
	int flag=0;

	if(list!=NULL && lenP>0 && types!=NULL && lenT>0 && status!=NULL && lenS>0)
	{
		todoOk=0;

		printf("      ***Passenger List***\n");
		printf("Id        Name          Last Name        Price       Code Flight    Type Passenger   Status Flight\n");
		printf("--------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<lenP; i++)
		{
			if(!list[i].isEmpty)
			{
				mostrarPasajero(list[i], types, lenT, status, lenS);
				flag=1;
			}
		}

		if(!flag)
		{
			printf("No hay pasajeros cargados.\n");
		}

		printf("\n\n");
	}

	return todoOk;
}

int modificarPasajero(Passenger *list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS)
{
	int todoOk=0;
	int id;
	int opcionModificar;
	int indice;
	char name[100];
	char lastName[100];
	float price;
	int typePassenger;
	char flyCode[100];

		if (list != NULL && lenP>0 && types!=NULL && lenT>0)
		{
			printPassenger(list, lenP, types, lenT, status, lenS);

			if (!utn_getNumero(&id, "Ingrese el id del pasajero a modificar\n",	"Error\n", 100, 10000, 3))
			{
				indice = findPassengerById(list, lenP, id);
			}
			else
			{
				printf("Reintentos agotados.\n\n");
				return todoOk;
			}

			if (indice>=0 && !menuModificarPasajero(&opcionModificar))
			{
				todoOk=1;

				switch (opcionModificar) {
				case 1:
					if(!GetString(name, 100, "Ingrese nuevo nombre: ", "Error, nombre no valido.\n", 3))
					{
						strncpy(list[indice].name, name, 51);
						printf("Id        Name          Last Name     Price    Code Flight    Type Passenger   Status Flight\n");
						printf("------------------------------------------------------------------------------------------\n");
						mostrarPasajero(list[indice], types, lenT, status, lenS);
						printf("Nombre modificado con exito.\n\n");
					}
					else
					{
						printf("Cantidad de reintentos agotada.\n\n");
					}
					break;
				case 2:
					if(!GetString(lastName, 100, "Ingrese nuevo apellido: ", "Error, apellido no valido.\n", 3))
					{
						strncpy(list[indice].lastName, lastName, 51);
						printf("Id        Name          Last Name     Price    Code Flight    Type Passenger   Status Flight\n");
						printf("------------------------------------------------------------------------------------------\n");
						mostrarPasajero(list[indice], types, lenT, status, lenS);
						printf("Apellido modificado con exito.\n\n");
					}
					else
					{
						printf("Cantidad de reintentos agotada.\n\n");
					}
					break;
				case 3:
					if(!utn_getFloat(&price, "Ingrese nuevo precio: ", "Error, precio no valido.\n", 0, 100000, 3))
					{
						list[indice].price = price;
						printf("Id        Name          Last Name     Price    Code Flight    Type Passenger   Status Flight\n");
						printf("------------------------------------------------------------------------------------------\n");
						mostrarPasajero(list[indice], types, lenT, status, lenS);
						printf("Precio modificado con exito.\n\n");
					}
					else
					{
						printf("Cantidad de reintentos agotada.\n\n");
					}
					break;
				case 4:
					if(listarTiposPasajero(types, lenT) &&
						!utn_getNumero(&typePassenger, "Ingrese nuevo id: ", "Error, opcion no valida.\n", 2000, 2002, 3))
					{
						list[indice].typePassenger = typePassenger;
						printf("Id        Name          Last Name     Price    Code Flight    Type Passenger   Status Flight\n");
						printf("------------------------------------------------------------------------------------------\n");
						mostrarPasajero(list[indice], types, lenT, status, lenS);
						printf("Tipo de pasajero modificado con exito.\n\n");
					}
					else
					{
						printf("Cantidad de reintetos agotada.\n\n");
					}
					break;
				case 5:
					if(!utn_getStringAlfaNumerico(flyCode, 100, "Ingrese nuevo codigo de vuelo: ", "Error, codigo no valido.\n", 3))
					{
						strncpy(list[indice].flyCode, flyCode, 10);
						printf("Id        Name          Last Name     Price    Code Flight    Type Passenger   Status Flight\n");
						printf("------------------------------------------------------------------------------------------\n");
						mostrarPasajero(list[indice], types, lenT, status, lenS);
						printf("Codigo de vuelo modificado con exito.\n\n");
					}
					else
					{
						printf("Cantidad de reintentos agotada.\n\n");
					}
					break;
				default:
					break;
				}
			} else if (indice<0)
			{
				printf("Id no encontrado\n");
			} else
			{
				printf("Cantidad de reintentos agotada\n");
			}
	}

	return todoOk;
}

int menuInformes(int* opcion)
{
	int rta;

	printf("Informes:\n");
	printf("1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");

	rta = utn_getNumero(opcion, "Ingrese una opcion: ", "Error, opcion no valida.\n", 1,3,3);

	return rta;
}

int calcularTotalYPromedioDePrecios(Passenger* list, int len, float* pPrecioTotal, float* pPromedio)
{
	int todoOk=0;
	float promedio=0;
	float acumuladorPrecio=0;
	int contador=0;

	if(list!=NULL && len>0 && pPrecioTotal!=NULL && pPromedio!=NULL)
	{
		todoOk=1;
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty)
			{
				acumuladorPrecio += list[i].price;
				contador++;
			}
		}

		if(contador>0)
		{
			promedio = acumuladorPrecio / contador;
		}

		*pPrecioTotal = acumuladorPrecio;
		*pPromedio = promedio;
	}

	return todoOk;
}

int contarPasajerosSuperanPrecioPromedio(Passenger* list, int len, float precioPromedio, int* pCantidad)
{
	int todoOk=0;
	int cantidad=0;

	if(list!=NULL && len>0 && pCantidad!=NULL)
	{
		todoOk=1;
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].price > precioPromedio)
			{
				cantidad++;
			}
		}

		*pCantidad= cantidad;
	}

	return todoOk;
}

int informarPrecioTotalYPromedioYPasajeros(Passenger* list, int len)
{
	int todoOk=0;
	float precioTotal;
	float promedio;
	int cantidadPasajeros;

	if(calcularTotalYPromedioDePrecios(list, len, &precioTotal, &promedio)
	&& contarPasajerosSuperanPrecioPromedio(list, len, promedio, &cantidadPasajeros))

	{
		printf("Informe:\n");
		printf("Total de precios: $%.2f\n Promedio de precios: $%.2f\n Cantidad de pasajeros que superan el promedio: %d\n\n", precioTotal, promedio, cantidadPasajeros);
		todoOk=1;
	}

	return todoOk;
}

int listarPasajerosConVueloActivo(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status,int lenS, int criterio)
{
	int todoOk=0;
	int flag=0;

	if(list!=NULL && lenP>0 && status!=NULL && lenS>0 && (criterio || !criterio))
	{
		todoOk=1;

		printf("Id        Name          Last Name        Price       Code Flight    Type Passenger   Status Flight\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		if(!sortPassengersByCode(list, lenP, criterio))
		{
			for(int i=0; i<lenP; i++)
			{
				if(!list[i].isEmpty && list[i].statusFlight == 7001)
				{
					mostrarPasajero(list[i], types, lenT, status, lenS);
					flag=1;
				}
			}
		}

		if(!flag)
		{
			printf("No hay pasajeros con vuelo activo.\n\n");
		}
	}

	return todoOk;
}


int sortPassengersByCode(Passenger* list, int len, int order)
{
	int todoOk=-1;
	Passenger auxiliar;

	if(list!=NULL && len>0  && (order || !order))
	{
		todoOk=0;
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if(!list[i].isEmpty &&
					((order && stricmp(list[i].flyCode,list[j].flyCode)>0) ||
					(!order && stricmp(list[i].flyCode,list[j].flyCode)<0)))
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
	}

	return todoOk;
}

int listarPasajerosPorApellidoYTipo(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS, int criterio)
{
	int todoOk=0;

	if(list!=NULL && lenP>0 && types!=NULL && lenT>0 && (criterio || !criterio))
	{
		todoOk=1;
		if(!sortPassengers(list, lenP, types, lenT, criterio))
		{
			printPassenger(list, lenP, types, lenT, status, lenS);
		}
	}

	return todoOk;
}

int mostrarInformes(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS)
{
	int todoOk=0;
	int opcion;
	int criterio;

	if(list!=NULL && lenP>0 && types!=NULL && lenT>0 && status!=NULL && lenS>0)
	{
		todoOk=1;
		if(!menuInformes(&opcion))
		{
			switch(opcion){
			case 1:
				if(!utn_getNumero(&criterio, "1. Orden Z-A\n2. Orden A-Z\nIngrese opcion: ", "Error, opcion no valida\n",1, 2, 1))
				{
					criterio = criterio-1;
					if(!listarPasajerosPorApellidoYTipo(list, lenP, types, lenT, status, lenS, criterio))
					{
						printf("Error al listar pasajeros.\n");
					}
				}

				break;
			case 2:
				if(!informarPrecioTotalYPromedioYPasajeros(list, lenP))
				{
					printf("Error al informar precio y promedio.\n");
				}
				break;
			case 3:
				if(!utn_getNumero(&criterio, "1.Orden Z-A\n2.Orden A-Z\nIngrese opcion: ", "Error, opcion no valida\n", 1,2,1))
				{
					criterio = criterio-1;
					if(!listarPasajerosConVueloActivo(list, lenP, types, lenT, status, lenS, criterio))
					{
						printf("Error al listar pasajeros.\n");
					}
				}
				break;
			}
		}
		else
		{
			printf("Reintentos agotados.\n\n");
		}
	}

	return todoOk;
}



int hardcodearPasajeros(Passenger* list , int len, int cant, int* pIndex)
{

    int todoOk = 0;
    Passenger pasajeros[] =
    {
		{0, "Juan", "Gomez", 5000, "ABC100", 2000, 7000, 0},
		{0, "Lucia", "Pereira", 4500, "ABD200", 2001, 7002, 0},
		{0, "Patricia", "Moreira", 3600, "DFG350", 2002, 7003, 0},
		{0, "Lorena", "Gonzalez", 5200, "KLI452", 2000, 7001, 0},
		{0, "Julian", "Gonzalez", 2100, "OPF890", 2002, 7002, 0},
		{0, "Carlos", "Gimenez", 7500, "JCB423", 2000, 7000, 0},
		{0, "Lorena", "Barrios", 4500, "ABD200", 2001, 7003, 0},
		{0, "Julio", "Fernandez", 6500, "DFG350", 2002, 7003, 0},
		{0, "Alberto", "Rodriguez", 9500, "KLI452", 2001, 7000, 0},
		{0, "Martina", "Dominguez", 4850, "OPF890", 2002, 7001, 0}
    };

    if(list != NULL && len > 0 && pIndex != NULL && cant > 0 && cant <= len)
    {

        for(int i=0; i < cant; i++)
        {
        	if(list[i].isEmpty)
        	{
				list[i] = pasajeros[i];
				list[i].id = *pIndex;
				*pIndex = *pIndex +1;
        	}

        }
        todoOk = 1;
    }
    return todoOk;

}



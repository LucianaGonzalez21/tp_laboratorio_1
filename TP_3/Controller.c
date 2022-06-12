#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"
#include "menus.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int todoOk=0;

    FILE* f = fopen(path, "r");

    if(path!=NULL && pArrayListPassenger!=NULL)
    {
    	parser_PassengerFromText(f, pArrayListPassenger);
    	todoOk=1;
    }
    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		FILE* pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			parser_PassengerFromBinary(pFile , pArrayListPassenger);
			retorno=1;
		}
	}

	return retorno;

}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	if(pArrayListPassenger!=NULL)
	{
		todoOk=1;
		int lenList = ll_len(pArrayListPassenger);

		printf("  Id           Nombre             Apellido            Precio         Codigo de vuelo      Tipo de pasajero         Estado de vuelo\n"
				"--------------------------------------------------------------------------------------------------------------------------\n");


		for (int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			printPassenger(pPassenger);
		}

		printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
	}

	return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk=0;
    Passenger* pasajero;

    if(pArrayListPassenger!=NULL)
    {
    	todoOk=1;
		pasajero = crear_Pasajero();

		if(pasajero!=NULL)
		{
			ll_add(pArrayListPassenger, pasajero);
			printf("Pasajero agregado con exito.\n");

			printf("  Id           Nombre             Apellido            Precio         Codigo de vuelo      Tipo de pasajero         Estado de vuelo\n"
					"--------------------------------------------------------------------------------------------------------------------------\n");
			printPassenger(pasajero);
			printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
		}
    }

    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk=0;
    Passenger* pasajero;
    int opcion;
    int idIngresado;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigo[20];
    int tipo;
    int estado;

    if(pArrayListPassenger!=NULL)
    {
    	printf("***Modificacion de pasajeros***\n");

    	if(controller_ListPassenger(pArrayListPassenger) &&
    	!utn_getNumero(&idIngresado, "Ingrese el Id del pasajero a modificar: ", "Error, no valido.\n", 1, 10000,3))
    	{
			pasajero = (Passenger*)ll_get(pArrayListPassenger, idIngresado);

			if(pasajero==NULL)
			{
				printf("No se pudo encontrar el Id %d en la base de datos del sistema\n\n", idIngresado);
				return 0;
			}
			else
			{
					if(!menuModificarPasajero(&opcion))
					{
						switch(opcion){
						case 1:
							if(!utn_getString(nombre, 50, "Ingrese el nuevo nombre: ", "Error, nombre no valido.\n",3))
							{
								Passenger_setNombre(pasajero, nombre);
								printf("Nombre modificado con exito!!!\n\n");
								printPassenger(pasajero);
							}
							break;
						case 2:
							if(!utn_getString(apellido, 50, "Ingrese el nuevo apellido: ", "Error, apellido no valido.\n",3))
							{
								Passenger_setApellido(pasajero, apellido);
								printf("Apellido modificado con exito!!!\n\n");
								printPassenger(pasajero);
							}
							break;
						case 3:
							if(!utn_getFloat(&precio,"Ingrese el nuevo precio: ", "Error, precio no valido.\n", 1, 10000, 3))
							{
								Passenger_setPrecio(pasajero, precio);
								printf("Precio modificado con exito!!!\n\n");
								printPassenger(pasajero);
							}
							break;
						case 4:
							if(!utn_getString(codigo, 20, "Ingrese el nuevo codigo: ", "Error, codigo no valido.\n",3))
							{
								Passenger_setCodigoVuelo(pasajero, codigo);
								printf("Codigo modificado con exito!!!\n\n");
								printPassenger(pasajero);
							}
							break;
						case 5:
							if(!utn_getNumero(&tipo, "Ingrese el nuevo tipo de pasajero: ", "Error, tipo no valido.\n", 1, 3, 3))
							{
								Passenger_setTipoPasajero(pasajero, tipo);
								printf("Tipo de pasajero modificado con exito!!!\n\n");
								printPassenger(pasajero);
							}
							break;
						case 6:
							if(!utn_getNumero(&estado, "Ingrese el nuevo estado de vuelo: ", "Error, estado de vuelo no valido.\n", 1, 4, 3))
							{
								Passenger_setStatus(pasajero, estado);
								printf("Estado de vuelo modificado con exito!!!\n\n");
								printPassenger(pasajero);
							}
							break;
						case 7:
							break;
						}
					}
			}
    	}

    }
    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	Passenger* pasajero;
	int idIngresado;
	char letra;

	if(pArrayListPassenger!=NULL)
	{
		todoOk=1;
		printf("***Eliminacion de pasajeros***\n");

		if(controller_ListPassenger(pArrayListPassenger) &&
		!utn_getNumero(&idIngresado, "Ingrese el Id del pasajero a eliminar: ", "Error, no valido.\n", 1, 10000,3))
		{
			pasajero = (Passenger*)ll_get(pArrayListPassenger, idIngresado);

			if(pasajero==NULL)
			{
				printf("Id %d no encontrado\n\n", idIngresado);
				return 0;
			}
			else
			{
				if(printPassenger(pasajero) &&
				!utn_getCaracter(&letra, "Confirma que desea eliminar al pasajero? s/n", "Error.\n", 'a', 'z', 1))
				{
					if(letra == 's')
					{
						ll_remove(pArrayListPassenger, idIngresado);
						printf("Pasajero eliminado correctamente.\n\n");
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
	return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int todoOk=0;
    FILE* pFile;
    int tam;
    Passenger* pasajero;
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigo[20];
    int tipo;
    int estado;

    if(path!=NULL && pArrayListPassenger!=NULL)
    {
    	todoOk=1;

    	pFile = fopen(path, "w");

    	if(pFile!=NULL)
    	{
    		fprintf(pFile, "id, nombre, apellido, precio, codigo, tipo, estado\n");

			tam = ll_len(pArrayListPassenger);

			for(int i=0; i<tam; i++)
			{
				pasajero = ll_get(pArrayListPassenger, i);

				if( pasajero!=NULL &&
				Passenger_getId(pasajero, &id) &&
				Passenger_getNombre(pasajero, nombre) &&
				Passenger_getApellido(pasajero, apellido) &&
				Passenger_getPrecio(pasajero, &precio) &&
				Passenger_getCodigoVuelo(pasajero, codigo) &&
				Passenger_getTipoPasajero(pasajero, &tipo) &&
				Passenger_getStatus(pasajero, &estado))
				{
					fprintf(pFile, "%d,%s,%s,%f,%s,%d,%d\n", id, nombre, apellido, precio, codigo, tipo, estado);
				}
				else
				{
					return 0;
				}
			}
    	}


    	fclose(pFile);

    }

	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int todoOk=0;
    int tam;
    FILE* pFile;
    Passenger* pasajero;

    if(path!=NULL && pArrayListPassenger!=NULL)
    {
    	todoOk=1;
    	pFile = fopen("path", "wb");

    	if(pFile!=NULL)
    	{
			tam = ll_len(pArrayListPassenger);
			for(int i=0; i<tam; i++)
			{
				pasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				fwrite(pasajero, sizeof(Passenger), 1, pFile);
			}
    	}
    	fclose(pFile);
    }

    return todoOk;
}


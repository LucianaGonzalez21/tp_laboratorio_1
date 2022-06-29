#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"
#include "menus.h"
#include "controller.h"


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
	int todoOk=0;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		FILE* pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			if(parser_PassengerFromBinary(pFile , pArrayListPassenger))
			{
				todoOk=1;
				printf("parser ok\n");
			}
			else
			{
				printf("fallo parser\n");
			}
		}
		else
		{
			printf("archivo igual a null\n");
		}
	}

	return todoOk;

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
	int tam;
	Passenger* pPasajero = NULL;

	if(pArrayListPassenger!=NULL)
	{
		todoOk=1;
		tam = ll_len(pArrayListPassenger);

		if(tam>0)
		{
			printf("  Id           Nombre             Apellido            Precio         Codigo de vuelo      Tipo de pasajero         Estado de vuelo\n"
					"--------------------------------------------------------------------------------------------------------------------------\n");


			for (int i=0; i < tam; ++i)
			{
				pPasajero = ll_get(pArrayListPassenger, i);
				printPassenger(pPasajero);
			}

			printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
		}
		else
		{
			printf("No hay empleados para mostrar.\n");
			todoOk=-1;
		}
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
	int todoOk=-1;
	int idPassengerActual;
	char confirmacion;
	Passenger* pasajeroNuevoAlta=NULL;


	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{

		pasajeroNuevoAlta=Passenger_altaPasajero();

		idPassengerActual=controller_getUltimoId();

		Passenger_setId(pasajeroNuevoAlta, idPassengerActual);

		if(pasajeroNuevoAlta!=NULL)
		{

			printPassenger(pasajeroNuevoAlta);

			utn_getCaracter(&confirmacion, "\n confirma el alta del pasajero? s/n : ", "Error\n", 'a', 'z', 2);

			if(confirmacion=='s')
			{

				ll_add(pArrayListPassenger, pasajeroNuevoAlta);
				Passenger_actualizarUltimoId(idPassengerActual);
				printf("Pasajero dado de alta con exito\n");
				todoOk=1;
			}
			else
			{
				Passenger_delete(pasajeroNuevoAlta);
				printf("Alta cancelada\n");
			}
		}

	}


    return todoOk;
}

int controller_buscarIdPasajero(LinkedList* pArrayListPassenger, int idPasajero)
{
	int indiceEncontrado=-1;
	int idEncontrado;
	int tam;
	Passenger* pasajero;

	if(pArrayListPassenger!=NULL && idPasajero>=0)
	{
		tam=ll_len(pArrayListPassenger);

		for(int i=0;i<tam;i++)
		{
			pasajero=ll_get(pArrayListPassenger, i);

			if(pasajero!=NULL)
			{
				Passenger_getId(pasajero, &idEncontrado);

				if(idEncontrado==idPasajero)
				{
					indiceEncontrado=i;
				}
			}
		}
	}

	return indiceEncontrado;
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
	int todoOK=-1;
	int idIngresado;
	int indiceEncontradoModificar;
	char afirmacion;
	int opcion;
	char nombre[50];
	char apellido[50];
	float auxPrecio;
	char precio[100];
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	char tipoPasajero[100];
	int auxEstadoVuelo;
	char estadoVuelo[100];
	Passenger* empleadoModificar=NULL;


	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{

		controller_ListPassenger(pArrayListPassenger);

		if(utn_getNumero(&idIngresado, "Ingrese el id que desea modificar: ", "Error\n", 1, 10000,3)==-1)
		{
			printf("error\n");
			return -1;
		}

		indiceEncontradoModificar=controller_buscarIdPasajero( pArrayListPassenger, idIngresado);

		empleadoModificar=ll_get(pArrayListPassenger, indiceEncontradoModificar);

		if(empleadoModificar!=NULL && indiceEncontradoModificar>=0 && indiceEncontradoModificar<ll_len(pArrayListPassenger))
		{

			printPassenger(empleadoModificar);

			utn_getCaracter(&afirmacion, "\n confirma modificacion? s/n: ", "error\n", 'a', 'z', 2);

			if(afirmacion=='s')
			{

					opcion=menuModificaciones();

					switch(opcion)
					{
						case 1:
							if(!utn_getString(nombre, 50,"Ingrese el nombre del pasajero: ","Error\n", 3))
							{
								Passenger_setNombre(empleadoModificar, nombre);
							}
							break;
						case 2:
							if(!utn_getString(apellido, 50,"Ingrese el apellido del pasajero: ","Error\n", 3))
							{
								Passenger_setApellido(empleadoModificar, apellido);
							}
							break;
						case 3:
							if(!utn_getFloat(&auxPrecio, "Ingrese el precio del vuelo (10000-50000): ", "Error\n", 10000, 50000, 3))
							{
								Passenger_setPrecio(empleadoModificar, auxPrecio);
								itoa(auxPrecio, precio, 10);
							}
							break;
						case 4:
							if(!utn_getStringAlfaNumerico(auxCodigoVuelo,10, "Ingrese el codigo del vuelo (max 10 caracteres): ", "Error\n", 3))
							{
								Passenger_setCodigoVuelo(empleadoModificar, auxCodigoVuelo);
							}
							break;
						case 5:
							printf("1.Primera clase\n");
							printf("2.Clase ejecutiva\n");
							printf("3.Clase economica\n");
							if(!utn_getNumero(&auxTipoPasajero, "Ingrese el tipo de pasajero: ", "Error\n", 1, 3, 3))
							{
								Passenger_setTipoPasajero(empleadoModificar, auxTipoPasajero);
								itoa(auxTipoPasajero, tipoPasajero, 10);
							}
							break;
						case 6:
							printf("1 - Aterrizado\n");
							printf("2 - En Horario\n");
							printf("3 - En Vuelo\n");
							printf("4 - Demorado\n");
							if(!utn_getNumero(&auxEstadoVuelo, "Ingrese el estado de vuelo: ", "Error\n", 1, 4, 3))
							{
								Passenger_setStatus(empleadoModificar, auxEstadoVuelo);
								itoa(auxEstadoVuelo, estadoVuelo, 10);
							}
							break;
						case 7:
							break;
						default:
							printf("Error\n");
							break;
					}
					printPassenger(empleadoModificar);

					printf("\nEl Id del pasejero %d fue modificado...\n\n", idIngresado);
				todoOK=1;
			}
			else
			{
				printf("\nModificacion cancelada");
			}
		}
		else
		{
			printf("\nNo se encontro el id ingresado\n");
		}

	}
	return todoOK;
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
	int todoOK=-1;
	int idIngresado;
	int indiceEncontradoEliminar;
	char afirmacion;
	Passenger* empleadoEliminar=NULL;

	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{

		controller_ListPassenger(pArrayListPassenger);

		utn_getNumero(&idIngresado, "Ingrese el id que desea modificar: ", "Error\n ", 1, 1000,3);

		indiceEncontradoEliminar=controller_buscarIdPasajero( pArrayListPassenger, idIngresado);

		empleadoEliminar=ll_get(pArrayListPassenger, indiceEncontradoEliminar);

		if(empleadoEliminar!=NULL && indiceEncontradoEliminar>=0 && indiceEncontradoEliminar<ll_len(pArrayListPassenger))
		{

			printPassenger(empleadoEliminar);

			utn_getCaracter(&afirmacion, "\nconfirma eliminacion? s/n: ","error\n", 'a', 'z', 2);
			fflush(stdin);

			if(afirmacion=='s')
			{
				ll_remove(pArrayListPassenger, indiceEncontradoEliminar);
				Passenger_delete(empleadoEliminar);
				printf("\nel pasajero fue eliminado con exito\n\n");
			}
			else
			{
				printf("Eliminacion cancelada\n");
			}
			todoOK=1;
		}
		else
		{
			printf("\nNo se el id ingresado\n");
		}

	}
	return todoOK;
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
	int todoOk=-1;
	int opcion;
	int tipo;
    LinkedList* listaAuxliar;

	if(pArrayListPassenger!=NULL)
	{
	    int(*pFuncionOrdenar)(void*,void*);
	    listaAuxliar=ll_clone(pArrayListPassenger);

        if(ll_isEmpty(listaAuxliar)>=0 && ll_containsAll(pArrayListPassenger, listaAuxliar))
        {
                opcion=menuPrincipalOrdenamiento();

                switch(opcion)
                {
                    case 1:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorId;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorId;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 2:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorNombre;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorNombre;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 3:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorApellido;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorApellido;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 4:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorPrecio;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorPrecio;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 5:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorCodigoDeVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorCodigoDeVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 6:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorTipoPasajero;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorTipoPasajero;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 7:
                        menuCriterioOrdenamiento(&tipo);
                        switch(tipo)
                        {
                            case 1:
                                pFuncionOrdenar=Passenger_ordenarPorEstadoVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 1);
                                break;
                            case 2:
                                pFuncionOrdenar=Passenger_ordenarPorEstadoVuelo;
                                ll_sort(listaAuxliar, pFuncionOrdenar, 0);
                                break;
                        }
                        break;
                    case 8:
                        break;
                    default:
                        printf("Error\n");
                        break;
                }

            controller_ListPassenger(listaAuxliar);
            ll_deleteLinkedList(listaAuxliar);
            todoOk=0;
        }
		else
        {
           printf("\nNo se han ingresado ningun elemento a la lista pasajeros\n");
		}
	}

    return todoOk;
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
					//falta validar el retonro de fprintf
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
    	pFile = fopen(path, "wb");

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

int controller_getUltimoId()
{
	int ultimoId=1;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", ultimoIdStr);

		ultimoId=atoi(ultimoIdStr);
	}
	else
	{
	    pFile=fopen("ultimoId.txt", "w");
	    fprintf(pFile, "%d\n", ultimoId);
	}
	fclose(pFile);

	return ultimoId;
}

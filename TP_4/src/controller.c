/*
 * controller.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "passenger.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"
#include "menu.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile=fopen(path, "r");

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		parser_PassengerFromText(pFile, pArrayListPassenger);
		retorno=1;
	}
	return retorno;
}


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

			Passenger_mostrarUnPasajero(pasajeroNuevoAlta);

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

			Passenger_mostrarUnPasajero(empleadoModificar);

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
								Passenger_setEstadoVuelo(empleadoModificar, auxEstadoVuelo);
								itoa(auxEstadoVuelo, estadoVuelo, 10);
							}
							break;
						case 7:
							break;
						default:
							printf("Error\n");
							break;
					}

				Passenger_mostrarUnPasajero(empleadoModificar);

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

			Passenger_mostrarUnPasajero(empleadoEliminar);

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


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;

	if(pArrayListPassenger!=NULL)
	{
		int lenList = ll_len(pArrayListPassenger);



		printf(" Id      Nombre         Apellido        Precio         Codigo vuelo        Tipo pasajero           Estado de vuelo\n");


		for (int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero(pPassenger);
		}

		todoOk=1;
	}
	return todoOk;
}


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


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[10];
	int tipoPasajero;
	int estadoVuelo;

	Passenger* pasajero=NULL;
	FILE* pFile;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile=fopen(path, "w");

		pasajero=Passenger_new();

		if(pasajero!=NULL)
		{
			fprintf(pFile, "id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo\n");
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				pasajero=(Passenger*) ll_get(pArrayListPassenger, i);
				if(pasajero!=NULL)
				{
					if(Passenger_getId(pasajero, &id) &&
						Passenger_getNombre(pasajero, nombre) &&
						Passenger_getApellido(pasajero, apellido) &&
						Passenger_getPrecio(pasajero, &precio) &&
						Passenger_getCodigoVuelo(pasajero, codigoDeVuelo) &&
						Passenger_getTipoPasajero(pasajero, &tipoPasajero) &&
						Passenger_getEstadoVuelo(pasajero, &estadoVuelo))
					{
						fprintf(pFile,"%d,%s,%s,%.2f,%s,%d,%d\n", id, nombre, apellido, precio, codigoDeVuelo, tipoPasajero, estadoVuelo);
						todoOk=1;
					}
				}
				else
				{
					todoOk=0;
					break;
				}
			}
		}
		fclose(pFile);

		if(todoOk)
		{
			printf("Se ha guardado correctamente el listado!\n");
		}
	}

	return todoOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{

	int todoOK=0;
	int tamArray;

	tamArray= ll_len(pArrayListPassenger);

	FILE* pFile;
	pFile = fopen(path, "wb");

	if(pFile!=NULL&& path!=NULL)
	{
		for (int i=0;i<tamArray;i++)
		{
			Passenger* auxPassenger= ll_get(pArrayListPassenger,i);
			fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
		}

		todoOK=1;
	}
	fclose(pFile);
	return todoOK;
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
int controller_ListPassengerInforme(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;

	if(pArrayListPassenger!=NULL)
	{
		int lenList = ll_len(pArrayListPassenger);

		for (int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero(pPassenger);
		}

        todoOk=0;
	}
	return todoOk;
}
int controller_InformeSubListadoPorRangoSelecionado(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int indiceIdSwapPrimero;
    int idSwapIngresadoPrimero;
    int indiceIdSwapSegundo;
    int idSwapIngresadoSegundo;
    LinkedList* listaPasajerosAux=NULL;

    if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
    {
        controller_ListPassenger(pArrayListPassenger);

        utn_getNumero(&idSwapIngresadoPrimero, "Ingrese el id que desea cambiar de ubicacion a la 1era: ", "Error\n", 1, 10000, 3);
        indiceIdSwapPrimero=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoPrimero);

        while(indiceIdSwapPrimero==-1)
        {
            utn_getNumero(&idSwapIngresadoPrimero, "Ingrese el id que desea cambiar de ubicacion a la 1era: ", "Error\n", 1, 10000, 3);
            indiceIdSwapPrimero=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoPrimero);
        }

        utn_getNumero(&idSwapIngresadoSegundo, "Ingrese el id que desea cambiar a la ultima ubicacion: ", "Error\n", 1, 1000,3);
        indiceIdSwapSegundo=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoSegundo);

        while(indiceIdSwapSegundo==-1)
        {
            utn_getNumero(&idSwapIngresadoSegundo, "Ingrese el id que desea cambiar a la ultima ubicacion: ", "Error\n", 1, 10000,3);
            indiceIdSwapSegundo=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoSegundo);
        }

        listaPasajerosAux=ll_subList(pArrayListPassenger, indiceIdSwapPrimero, indiceIdSwapSegundo+1);

        if(listaPasajerosAux!=NULL)
        {
            controller_ListPassengerInforme(listaPasajerosAux);
            todoOk=0;
            ll_deleteLinkedList(listaPasajerosAux);
        }
        else
        {
            printf("No hay pasajeros en la lista\n");
        }
    }
    else
	{
		printf("\nNo han ingresado elementos a la lista\n");
	}

    return todoOk;
}
int controller_InformeEliminarPasajeroMenorPrecio(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int tam;
    Passenger* auxPasajero=NULL;
    int flagMenorPrecio=0;
    float menorPrecio;
    int indicePasajeroMenorPrecio;

    if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
    {
        if(ll_len(pArrayListPassenger)>0)
        {
            tam=ll_len(pArrayListPassenger);

            for(int i=0;i<tam;i++)
            {
                auxPasajero=ll_get(pArrayListPassenger, i);

                if(auxPasajero!=NULL)
                {
                    if(!flagMenorPrecio || auxPasajero->precio<menorPrecio)
                    {
                        menorPrecio=auxPasajero->precio;
                        flagMenorPrecio=1;
                    }
                }
            }

            for(int i=0;i<tam;i++)
            {
                auxPasajero=ll_get(pArrayListPassenger, i);

                if(auxPasajero!=NULL)
                {
                    if(menorPrecio==auxPasajero->precio)
                    {
                        indicePasajeroMenorPrecio=ll_indexOf(pArrayListPassenger, auxPasajero);
                        break;
                    }
                }
            }

            auxPasajero=ll_pop(pArrayListPassenger, indicePasajeroMenorPrecio);

            if(auxPasajero!=NULL)
            {
                printf("Pasajero eliminado.\n El precio menor es: $%.2f\n", menorPrecio);


                Passenger_mostrarUnPasajero(auxPasajero);

                Passenger_delete(auxPasajero);
                todoOk=0;
            }
        }
        else
        {
            printf("No hay pasajeros\n");
        }
    }

    return todoOk;
}
int controller_InformeAltaEnPosicionSelecionada(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
	int idPassengerActual;
	char afirmacion;
	Passenger* pasajeroNuevoAlta=NULL;
    int idSelecionadoPorElUsuario;
    int indiceEncontradoSlecionado;

	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{

		pasajeroNuevoAlta=Passenger_altaPasajero();

		idPassengerActual=controller_getUltimoId();

		Passenger_setId(pasajeroNuevoAlta, idPassengerActual);

		if(pasajeroNuevoAlta!=NULL)
		{

			Passenger_mostrarUnPasajero(pasajeroNuevoAlta);


			utn_getCaracter(&afirmacion, "confirma la operacion? (s/n): ", "error\n", 'a', 'z', 3);

			if(afirmacion=='s')
			{
			    if(ll_contains(pArrayListPassenger, pasajeroNuevoAlta)==0)
                {
                    controller_ListPassenger(pArrayListPassenger);

                    utn_getNumero(&idSelecionadoPorElUsuario, "Ingrese el pasajero en su posicion: ", "Error", 1, ll_len(pArrayListPassenger),3);

                    indiceEncontradoSlecionado=controller_buscarIdPasajero(pArrayListPassenger, idSelecionadoPorElUsuario);

                    if(!ll_push(pArrayListPassenger, indiceEncontradoSlecionado+1, pasajeroNuevoAlta))
                    {
                        printf("Alta realizada con exito\n");
                        todoOk=1;
                    }

                    todoOk=1;
                }
                else
                {
                    printf("\nError\n");
                }
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

int controller_informarListas(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int opcion;

    if(pArrayListPassenger!=NULL)
    {
            opcion=menuInformes();

            switch(opcion)
            {
                case 1:
                    controller_InformeSubListadoPorRangoSelecionado(pArrayListPassenger);
                    break;
                case 2:
                    controller_InformeEliminarPasajeroMenorPrecio(pArrayListPassenger);
                    break;
                case 3:
                    controller_InformeAltaEnPosicionSelecionada(pArrayListPassenger);
                    break;
                case 4:
                    break;
                default:
                    break;
            }

        todoOk=0;
    }

    return todoOk;
}

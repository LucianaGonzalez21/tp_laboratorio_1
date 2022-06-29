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

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

			Passenger_mostrarUnPasajero(pasajeroNuevoAlta);

			utn_getCaracter(&confirmacion, "\n confirma el ingreso de datos? s/n : ", "Error\n", 'a', 'z', 2);

			if(confirmacion=='s')
			{

				ll_add(pArrayListPassenger, pasajeroNuevoAlta);
				Passenger_actualizarUltimoId(idPassengerActual);
				printf("Pasajero dado de alta con exito...\n");
				todoOk=1;
			}
			else
			{
				Passenger_delete(pasajeroNuevoAlta);
				printf("Se cancelo el alta del pasajero...\n");
			}
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
	int todoOK=-1;
	int idIngresado;
	int indiceEncontradoModificar;
	char afirmacion;
	int opcion;
	char nombre[50];
	char apellido[50];
	float auxPrecio;
	char precio[1000];
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	char tipoPasajero[1000];
	int auxEstadoVuelo;
	char estadoVuelo[1000];
	Passenger* empleadoModificar=NULL;


	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger)>=0)
	{

		controller_ListPassenger(pArrayListPassenger);

		utn_getNumeor(&idIngresado, "Ingrese el id que desea modificar: ", "Error\n", 1, 10000,3);

		indiceEncontradoModificar=controller_buscarIdPasajero( pArrayListPassenger, idIngresado);

		empleadoModificar=ll_get(pArrayListPassenger, indiceEncontradoModificar);

		if(empleadoModificar!=NULL && indiceEncontradoModificar>=0 && indiceEncontradoModificar<ll_len(pArrayListPassenger))
		{

			Passenger_mostrarUnPasajero(empleadoModificar);

			utn_getCaracter(&afirmacion, "\n confirma modificacion? s/n: ", "error\n", 'a', 'z', 2);

			if(afirmacion=='s')
			{
				do
				{
					opcion=menuModificaciones();

					switch(opcion)
					{
						case 1:
							utn_getString(nombre, 50,"Ingrese el nombre del pasajero: ","Error\n", 3);
							Passenger_setNombre(empleadoModificar, nombre);
							break;
						case 2:
							utn_getString(apellido, 50,"Ingrese el apellido del pasajero: ","Error\n", 3);
							Passenger_setApellido(empleadoModificar, apellido);
							break;
						case 3:
							utn_getFloat(&auxPrecio, "Ingrese el precio del vuelo (10000-50000): ", "Error\n", 10000, 50000, 3);
							Passenger_setPrecio(empleadoModificar, auxPrecio);
							itoa(auxPrecio, precio, 10);
							break;
						case 4:
							utn_getStringAlfaNumerico(auxCodigoVuelo,10, "Ingrese el codigo del vuelo (max 10 caracteres): ", "Error\n", 3);
							Passenger_setCodigoVuelo(empleadoModificar, auxCodigoVuelo);
							break;
						case 5:

							printf("1.Primera clase\n");
							printf("2.Clase ejecutiva\n");
							printf("3.Clase economica\n");
							utn_getNumero(&auxTipoPasajero, "Ingrese el tipo de pasajero: ", "Error\n", 1, 3, 3);
							Passenger_setTipoPasajero(empleadoModificar, auxTipoPasajero);
							itoa(auxTipoPasajero, tipoPasajero, 10);
							break;
						case 6:
							printf("1 - Aterrizado\n");
							printf("2 - En Horario\n");
							printf("3 - En Vuelo\n");
							printf("4 - Demorado\n");
							utn_getNumero(&auxEstadoVuelo, "Ingrese el estado de vuelo: ", "Error\n", 1, 4);
							Passenger_setEstadoVuelo(empleadoModificar, auxEstadoVuelo);
							itoa(auxEstadoVuelo, estadoVuelo, 10);
							break;
						case 7:
							printf("\nSaliendo del menu de modificaciones\n\n");
							break;
						default:
							printf("Error. Ingrese una opcion: \n");
							break;
					}

				}while(opcion!=7);
				if(opcion<1 || opcion>6)
				{

					Passenger_mostrarUnPasajero(empleadoModificar);

					printf("\nEl Id del pasejero %d fue modificado...\n\n", idIngresado);
				}
				todoOK=1;
			}
			else
			{
				printf("\nSe cancelo la modificacion del pasajero con el id %d\n", idIngresado);
			}
		}
		else
		{
			printf("\nNo se encontro ningun pasajero con el id %d\n", idIngresado);
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

			Passenger_mostrarUnPasajero(empleadoEliminar);

			utn_getCaracter(&afirmacion, "\nconfirma eliminacion: s/n: ", 'a', 'z', 2);

			if(afirmacion=='s')
			{
				ll_remove(pArrayListPassenger, indiceEncontradoEliminar);
				Passenger_delete(empleadoEliminar);
				printf("\nEl Id del pasejero %d fue eliminado...\n\n", idIngresado);
			}
			else
			{
				printf("\nSe cancelo la eliminacion del pasajero con el id %d\n", idIngresado);
			}
			todoOK=1;
		}
		else
		{
			printf("\nNo se encontro ningun pasajero con el id %d\n", idIngresado);
		}

	}
	return todoOK;
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
	int todoOk=-1;

	if(pArrayListPassenger!=NULL)
	{
		int lenList = ll_len(pArrayListPassenger);



		printf(" Id      Nombre      Apellido     Precio      Codigo vuelo     Tipo pasajero      Estado de vuelo\n");


		for (int i=0; i < lenList; ++i)
		{
			Passenger* pPassenger = ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero(pPassenger);
		}

		todoOk=1;
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
	int todoOk=-1;
	char salir;
	int opcion;
	int tipo;
    LinkedList* listaAuxliar;

	if(pArrayListPassenger!=NULL)
	{
	    int(*pFuncionOrdenar)(void*,void*);
	    listaAuxliar=ll_clone(pArrayListPassenger);

        if(ll_isEmpty(listaAuxliar)>=0 && ll_containsAll(pArrayListPassenger, listaAuxliar))
        {
//           do
//            {
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
//                        utn_getCaracter(&salir, "Ingrese  S para salir del menu de ordenamiento (s/n): ");
                        break;
                    default:
                        printf("Error\n");
                        break;
                }
//
//            }while(salir!='s');
            if(opcion<1 || opcion>7)
            {
                controller_ListPassenger(listaAuxliar);
            }
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
					Passenger_getId(pasajero, &id);
					Passenger_getNombre(pasajero, nombre);
					Passenger_getApellido(pasajero, apellido);
					Passenger_getPrecio(pasajero, &precio);
					Passenger_getCodigoVuelo(pasajero, codigoDeVuelo);
					Passenger_getTipoPasajero(pasajero, &tipoPasajero);
					Passenger_getEstadoVuelo(pasajero, &estadoVuelo);

					fprintf(pFile,"%d,%s,%s,%.2f,%s,%d,%d\n", id, nombre, apellido, precio, codigoDeVuelo, tipoPasajero, estadoVuelo);
					todoOk=1;
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

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
int controller_InformeSudListadoPorRangoSelecionado(LinkedList* pArrayListPassenger)
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

        utn_getNumero(&idSwapIngresadoPrimero, "Ingrese el id que desea cambiar de ubicacion a la 1era: ", "Error. Ingrese el id que desea cambiar de ubicacion a la 1era: ", 1, 10000, 3);
        indiceIdSwapPrimero=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoPrimero);

        while(indiceIdSwapPrimero==-1)
        {
            utn_getNumero(&idSwapIngresadoPrimero, "Ingrese el id que desea cambiar de ubicacion a la 1era: ", "Error. Ingrese el id que desea cambiar de ubicacion a la 1era: ", 1, 10000, 3);
            indiceIdSwapPrimero=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoPrimero);
        }

        utn_getNumero(&idSwapIngresadoSegundo, "Ingrese el id que desea cambiar a la ultima ubicacion: ", "Error. Ingrese el id que desea cambiar a la ultima ubicacion: ", 1, 1000,3);
        indiceIdSwapSegundo=controller_buscarIdPasajero(pArrayListPassenger, idSwapIngresadoSegundo);

        while(indiceIdSwapSegundo==-1)
        {
            utn_getNumero(&idSwapIngresadoSegundo, "Ingrese el id que desea cambiar a la ultima ubicacion: ", "Error. Ingrese el id que desea cambiar a la ultima ubicacion: ", 1, 10000,3);
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
            printf("Error no se pudo hacer la sub lista...\n");
        }
    }
    else
	{
		printf("\nNo han ingresado elementos a la lista...\n");
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
                printf("El pasajero fue eliminado correctamente y el menor precio fue $%.2f\n", menorPrecio);


                Passenger_mostrarUnPasajero(auxPasajero);

                Passenger_delete(auxPasajero);
                todoOk=0;
            }
        }
        else
        {
            printf("\nNo se han ingresado pasajeros...\n");
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


			utn_getCaracter(&afirmacion, "\n confirma? (s/n): ", 'a', 'z', 3);

			if(afirmacion=='s')
			{
			    if(ll_contains(pArrayListPassenger, pasajeroNuevoAlta)==0)
                {
                    controller_ListPassenger(pArrayListPassenger);

                    utn_getNumero(&idSelecionadoPorElUsuario, "Ingrese el pasajero en su posicion: ", "Error. Ingrese el pasajero en su posicion: ", 1, ll_len(pArrayListPassenger),3);

                    indiceEncontradoSlecionado=controller_buscarIdPasajero(pArrayListPassenger, idSelecionadoPorElUsuario);

                    if(!ll_push(pArrayListPassenger, indiceEncontradoSlecionado+1, pasajeroNuevoAlta))
                    {
                        printf("Se dio de alta correctamente el pasajero en el lugar selecionado por el usuario...\n");
                        todoOk=1;
                    }

                    todoOk=1;
                }
                else
                {
                    printf("\nSe ha producido un error con el pasajero ingresado...\n");
                }
			}
			else
			{
				Passenger_delete(pasajeroNuevoAlta);
				printf("Se cancelo el dada de alta del pasajero...\n");
			}
		}

	}

    return todoOk;
}

int controller_Informes(LinkedList* pArrayListPassenger)
{
    int todoOk=-1;
    int opcion;
    char afirmacion;

    if(pArrayListPassenger!=NULL)
    {
        do
        {
            opcion=menuInformes();

            switch(opcion)
            {
                case 1:
                    controller_InformeSudListadoPorRangoSelecionado(pArrayListPassenger);
                    break;
                case 2:
                    controller_InformeEliminarPasajeroMenorPrecio(pArrayListPassenger);
                    break;
                case 3:
                    controller_InformeAltaEnPosicionSelecionada(pArrayListPassenger);
                    break;
                case 4:
                    ingresoChar(&afirmacion,"\nDesea salir del menu de informes (s/n): ");
                    break;
                default:
                    break;
            }

        }while(afirmacion!='s');

        todoOk=0;
    }

    return todoOk;
}

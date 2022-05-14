/*
 * statusFlight.c
 *
 *  Created on: May 10, 2022
 *      Author: Dell
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "statusFlight.h"
#include "utn.h"


int listarEstadosDeVuelo(eStatusFlight* estados, int tam)
{
	int todoOk=0;

	if(estados!=NULL && tam>0)
	{
		printf("    ****Lista de Estados de Vuelo***\n");
		printf("------------------------------------\n");
		printf("Id                 Descripcion\n");
		for(int i=0; i<tam; i++)
		{
			printf("%4d      %20s\n", estados[i].id, estados[i].descripcion);
		}
		todoOk=1;
		printf("\n\n");
	}

	return todoOk;
}


int buscarEstadoDeVuelo(eStatusFlight* estados, int tam, int id, int* pIndice)
{
	int todoOk=0;

	if(estados!=NULL && tam>0 && pIndice!=NULL)	//validar id
	{
		*pIndice=-1;

		for(int i=0; i<tam; i++)
		{
			if(estados[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}


int validarEstadoDeVuelo(eStatusFlight* estados, int tam, int id)
{
	int esValido=0;
	int indice;

	buscarEstadoDeVuelo(estados, tam, id, &indice);//ya valido parametros en esa funcion
	if(indice!=-1)	// si es >=0 significa que encontro un id valiido y me devuelve el  indice
	{
		esValido=1;
	}

	return esValido;
}


int cargarDescripcionEstadoDeVuelo(eStatusFlight* estados, int tam, int id, char* descripcion)
{
	int todoOk=0;
	int indice;

	if(estados!=NULL && tam>0 && descripcion!=NULL && validarEstadoDeVuelo(estados, tam, id))	//id??
	{
		if(buscarEstadoDeVuelo(estados, tam, id, &indice) && indice!=-1)
		{
			strcpy(descripcion, estados[indice].descripcion);
		}
		todoOk=1;
	}
	return todoOk;
}


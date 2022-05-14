/*
 * typePassenger.c
 *
 *  Created on: May 10, 2022
 *      Author: Dell
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typePassenger.h"
#include "utn.h"

int listarTiposPasajero(eTypePassenger* tipos, int tam)
{
	int todoOk=0;

	if(tipos!=NULL && tam>0)
	{
		printf("      ****Lista de Tipos de Pasajero***\n");
		printf("------------------------------------------\n");
		printf("Id                  Descripcion\n");
		for(int i=0; i<tam; i++)
		{
			printf("%4d      %20s\n", tipos[i].id, tipos[i].descripcion);
		}
		todoOk=1;
		printf("\n\n");
	}

	return todoOk;
}

int buscarTipoPasajero(eTypePassenger* tipos, int tam, int id, int* pIndice)
{
	int todoOk=0;

	if(tipos!=NULL && tam>0 && pIndice!=NULL)
	{
		*pIndice=-1;

		for(int i=0; i<tam; i++)
		{
			if(tipos[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int validarTipoPasajero(eTypePassenger* tipos, int tam, int id)
{
	int esValido=0;
	int indice;

	buscarTipoPasajero(tipos, tam, id, &indice);
	if(indice!=-1)
	{
		esValido=1;
	}

	return esValido;
}

int cargarDescripcionTipoPasajero(eTypePassenger* tipos, int tam, int id, char* descripcion)
{
	int todoOk=0;
	int indice;

	if(tipos!=NULL && tam>0 && descripcion!=NULL && validarTipoPasajero(tipos, tam, id))
	{
		if(buscarTipoPasajero(tipos, tam, id, &indice) && indice!=-1)
		{
			strcpy(descripcion, tipos[indice].descripcion);
		}
		todoOk=1;
	}
	return todoOk;
}

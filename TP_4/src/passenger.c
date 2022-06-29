/*
 * passenger.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "passenger.h"

Passenger* Passenger_new()
{
    Passenger* nuevoPassenger=NULL;
    nuevoPassenger=(Passenger*)malloc(sizeof(Passenger));

	if(nuevoPassenger!=NULL)
	{
		Passenger_setId(nuevoPassenger, 0);
		Passenger_setNombre(nuevoPassenger, "sin asignar");
		Passenger_setApellido(nuevoPassenger, "sin asignar");
		Passenger_setPrecio(nuevoPassenger, 0);
		Passenger_setCodigoVuelo(nuevoPassenger, "error");
		Passenger_setTipoPasajero(nuevoPassenger, 2);
		Passenger_setEstadoVuelo(nuevoPassenger, 2);
	}
	return nuevoPassenger;
}
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,  char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
    Passenger* nuevoPassenger=NULL;
    nuevoPassenger = Passenger_new();

	if(nuevoPassenger!=NULL)
	{
		if(!(Passenger_setId(nuevoPassenger, atoi(idStr))
		&& Passenger_setNombre(nuevoPassenger, nombreStr)
		&& Passenger_setApellido(nuevoPassenger, apellidoStr)
		&& Passenger_setPrecio(nuevoPassenger, atoi(precioStr))
		&& Passenger_setCodigoVuelo(nuevoPassenger, codigoVueloStr)
		&& Passenger_setTipoPasajero(nuevoPassenger, atoi(tipoPasajeroStr))
		&& Passenger_setEstadoVuelo(nuevoPassenger, atoi(estadoVueloStr))))
		{
			Passenger_delete(nuevoPassenger);
		}
	}

	return nuevoPassenger;
}
void Passenger_delete(Passenger* this)
{
    if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}
//setters
int Passenger_setId(Passenger* this, int id)
{
	int todoOk=0;
	if(this!=NULL && id>=0)
	{
		this->id=id;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_setNombre(Passenger* this, char* nombre)
{
	int todoOk=0;
	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre)<50 && strlen(nombre)>1)
		{
			strcpy(this->nombre, nombre);
			todoOk=1;
		}
	}
	return todoOk;
}
int Passenger_setApellido(Passenger* this, char* apellido)
{
	int todoOk=0;
	if(this != NULL && apellido != NULL)
	{
		if(strlen(apellido)<50 && strlen(apellido)>1)
		{
			strcpy(this->apellido, apellido);
			todoOk=1;
		}
	}
	return todoOk;
}
int Passenger_setPrecio(Passenger* this, float precio)
{
	int todoOK=0;
	if(this!=NULL)
	{
		if((precio>=10000 && precio <=50000) || precio==0)
		{
			this->precio=precio;
			todoOK=1;
		}
	}
	return todoOK;
}
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int todoOK=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		if(strlen(codigoVuelo)<10 && strlen(codigoVuelo)>5)
		{
			strcpy(this->codigoVuelo, codigoVuelo);
			todoOK=1;
		}
	}
	return todoOK;
}
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(tipoPasajero<=3 && tipoPasajero>=1)
		{
			this->tipoPasajero=tipoPasajero;
			todoOk=1;
		}
	}
	return todoOk;
}
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int todoOk=0;
	if(this!=NULL)
	{
		if(estadoVuelo<=4 && estadoVuelo>=1)
		{
			this->estadoVuelo=estadoVuelo;
			todoOk=1;
		}

	}
	return todoOk;
}
//getters
int Passenger_getId(Passenger* this, int* id)
{
	int todoOk=0;

	if(this!=NULL)
	{
		*id=this->id;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getNombre(Passenger* this, char* nombre)
{
    int todoOk=0;

	if(this != NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int todoOk=0;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int todoOk=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int todoOk=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int todoOk=0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero=this->tipoPasajero;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getdescripcionTipoPasajero(int tipoPasajero , char* descripcionTipo)
{
	int todoOk=0;

	if(tipoPasajero<=3 &&  tipoPasajero>=1 && descripcionTipo!=NULL)
	{
		if(tipoPasajero==1)
		{
			strcpy(descripcionTipo, "Primera clase");
		}
		else if(tipoPasajero==2)
		{
			strcpy(descripcionTipo, "Clase ejecutiva");
		}
		else
		{
			strcpy(descripcionTipo, "Clase economica");
		}
		todoOk=1;
	}

	return todoOk;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int todoOk=0;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		*estadoVuelo=this->estadoVuelo;
		todoOk=1;
	}
	return todoOk;
}
int Passenger_getdescripcionEstadoVuelo(int estadoVuelo , char* descripcionEstadoVuelo)
{
	int todoOk=0;

		if(estadoVuelo<=4 &&  estadoVuelo>=1 && descripcionEstadoVuelo!=NULL)
		{
			if(estadoVuelo==1)
			{
				strcpy(descripcionEstadoVuelo, "Aterrizado");
			}
			else if(estadoVuelo==2)
			{
				strcpy(descripcionEstadoVuelo, "En Horario");
			}
			else if(estadoVuelo==3)
			{
				strcpy(descripcionEstadoVuelo, "En Vuelo");
			}
			else
			{
				strcpy(descripcionEstadoVuelo, "Demorado");
			}
			todoOk=1;
		}

		return todoOk;
}
Passenger* Passenger_altaPasajero()
{
	Passenger* pasajero=NULL;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char precio[20];
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	char tipoPasajero[20];
	int auxEstadoVuelo;
	char estadoVuelo[20];

	pasajero=Passenger_new();

	if(pasajero!=NULL)
	{
		if(!utn_getString(auxNombre,50,"Ingrese el nombre del pasajero: ","Error\n", 3) &&
		!utn_getString(auxApellido,50,"Ingrese el apellido del pasajero: ","Error\n", 3) &&
		!utn_getFloat(&auxPrecio, "Ingrese el precio del vuelo (10000-50000): ", "Error\n ", 10000, 50000, 3) &&
		!utn_getStringAlfaNumerico(auxCodigoVuelo,10, "Ingrese el codigo del vuelo: ", "Error", 3))
		{
			printf("1.Primera clase\n");
			printf("2.Clase ejecutiva\n");
			printf("3.Clase economica\n");
			if(!utn_getNumero(&auxTipoPasajero, "Ingrese el tipo de pasajero: ", "Error\n", 1, 3, 3))
			{
				printf("1 - Aterrizado\n");
				printf("2 - En Horario\n");
				printf("3 - En Vuelo\n");
				printf("4 - Demorado\n");
				if(!utn_getNumero(&auxEstadoVuelo, "Ingrese el estado de vuelo: ", "Error\n", 1, 4,3))
				{
					Passenger_setNombre(pasajero, auxNombre);
					Passenger_setApellido(pasajero, auxApellido);
					Passenger_setPrecio(pasajero, auxPrecio);
					Passenger_setCodigoVuelo(pasajero, auxCodigoVuelo);
					Passenger_setTipoPasajero(pasajero, auxTipoPasajero);
					Passenger_setEstadoVuelo(pasajero, auxEstadoVuelo);

					itoa(auxPrecio, precio, 10);
					itoa(auxTipoPasajero, tipoPasajero, 10);
					itoa(auxEstadoVuelo, estadoVuelo, 10);
				}
			}
		}
	}
	return pasajero;
}
void Passenger_mostrarUnPasajero(Passenger* pasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[10];
	int tipoPasajero;
	char descrTipoPasajero[30];
	int estadoVuelo;
	char descrEstadoVuelo[30];

	if(Passenger_getId(pasajero, &id) &&
		Passenger_getNombre(pasajero, nombre) &&
		Passenger_getApellido(pasajero, apellido) &&
		Passenger_getPrecio(pasajero, &precio) &&
		Passenger_getCodigoVuelo(pasajero, codigoDeVuelo) &&
		Passenger_getTipoPasajero(pasajero, &tipoPasajero) &&
		Passenger_getdescripcionTipoPasajero(tipoPasajero, descrTipoPasajero) &&
		Passenger_getEstadoVuelo(pasajero, &estadoVuelo)&&
		Passenger_getdescripcionEstadoVuelo(estadoVuelo, descrEstadoVuelo))
	{
		printf(" %5d   %20s  %20s  $%.2f     %10s        %15s         %15s\n", id, nombre, apellido, precio, codigoDeVuelo, descrTipoPasajero, descrEstadoVuelo);
	}

}
int Passenger_ordenarPorId(void* a, void* b)
{
	int retorno;
	int idA;
	int idB;
	Passenger* auxA = (Passenger*)a;
	Passenger* auxB = (Passenger*)b;

	if(auxA!=NULL && auxB!=NULL)
	{
		Passenger_getId(auxA, &idA);
		Passenger_getId(auxB, &idB);

		if(idA>idB)
		{
			retorno=1;
		}
		else if(idA<idB)
		{
			retorno=-1;
		}

		auxA=NULL;
		auxB=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorNombre(void* a, void* b)
{
    int retorno;
    char nombreA[10];
    char nombreB[100];
    Passenger* auxA = (Passenger*)a;
    Passenger* auxB = (Passenger*)b;

    if(auxA!=NULL && auxB!=NULL)
    {
    	Passenger_getNombre(auxA,nombreA);
    	Passenger_getNombre(auxB,nombreB);

    	if(strcmp(nombreA,nombreB)<0)
    	{
    		retorno=-1;
    	}
    	else if(strcmp(nombreA,nombreB)>0)
    	{
    		retorno=1;
    	}
    	auxA=NULL;
    	auxB=NULL;
    }

    return retorno;
}
int Passenger_ordenarPorApellido(void* a, void* b)
{
    int retorno;
    char apellidoA[128];
    char apellidoB[128];
    Passenger* auxA = (Passenger*)a;
    Passenger* auxB = (Passenger*)b;

    if(auxA!=NULL && auxB!=NULL)
    {
    	Passenger_getApellido(auxA,apellidoA);
    	Passenger_getApellido(auxB,apellidoB);

    	if(strcmpi(apellidoA,apellidoB)<0)
    	{
    		retorno=-1;
    	}
    	else if(strcmpi(apellidoA,apellidoB)>0)
    	{
    		retorno=1;
    	}
    	auxA=NULL;
    	auxB=NULL;
    }

    return retorno;
}
int Passenger_ordenarPorPrecio(void* a, void* b)
{
	int retorno;
	float precioA;
	float precioB;
	Passenger* auxA = (Passenger*)a;
	Passenger* auxB = (Passenger*)b;

	if(auxA!=NULL && auxB!=NULL)
	{
		Passenger_getPrecio(auxA, &precioA);
		Passenger_getPrecio(auxB, &precioB);

		if(precioA>precioB)
		{
			retorno=1;
		}
		else if(precioA<precioB)
		{
			retorno=-1;
		}
		auxA=NULL;
		auxB=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorCodigoDeVuelo(void* a, void* b)
{
	int retorno;
	char codigoA[128];
	char codigoB[128];
	Passenger* auxA = (Passenger*)a;
	Passenger* auxB = (Passenger*)b;

	if(auxA!=NULL && auxB!=NULL)
	{
		Passenger_getCodigoVuelo(auxA,codigoA);
		Passenger_getCodigoVuelo(auxB,codigoB);

		if(strcmp(codigoA,codigoB)<0)
		{
			retorno=-1;
		}
		else if(strcmp(codigoA,codigoB)>0)
		{
			retorno=1;
		}
		auxA=NULL;
		auxB=NULL;
	}
	return retorno;
}
int Passenger_ordenarPorTipoPasajero(void* a, void* b)
{
	int retorno;
	int tipoA;
	int tipoB;
	char auxTipoA[100];
	char auxTipoB[100];
	Passenger* auxA = (Passenger*)a;
	Passenger* auxB = (Passenger*)b;

	if(auxA!=NULL && auxB!=NULL)
	{

		Passenger_getTipoPasajero(auxA, &tipoA);
		Passenger_getdescripcionTipoPasajero(tipoA, auxTipoA);
		Passenger_getTipoPasajero(auxB, &tipoB);
		Passenger_getdescripcionTipoPasajero(tipoB, auxTipoB);

		if(strcmp(auxTipoA,auxTipoB)<0)
		{
			retorno=-1;
		}
		else if(strcmp(auxTipoA,auxTipoB)>0)
		{
			retorno=1;
		}

		auxA=NULL;
		auxB=NULL;
	}

	return retorno;
}
int Passenger_ordenarPorEstadoVuelo(void* a, void* b)
{
	int retorno;
	int estadoA;
	int estadoB;
	char auxEstadoA[128];
	char auxEstadoB[128];
	Passenger* auxA = (Passenger*)a;
	Passenger* auxB = (Passenger*)b;

	if(auxA!=NULL && auxB!=NULL)
	{

		Passenger_getEstadoVuelo(auxA, &estadoA);
		Passenger_getdescripcionEstadoVuelo(estadoA, auxEstadoA);
		Passenger_getEstadoVuelo(auxB, &estadoB);
		Passenger_getdescripcionEstadoVuelo(estadoB, auxEstadoB);

		if(strcmp(auxEstadoA,auxEstadoB)<0)
		{
			retorno=-1;
		}
		else if(strcmp(auxEstadoA,auxEstadoB)>0)
		{
			retorno=1;
		}

		auxA=NULL;
		auxB=NULL;
	}

	return retorno;
}
int Passenger_actualizarUltimoId(int idAnterior)
{
	int todoOk=0;

	FILE* pFile=fopen("ultimoId.txt", "w");

	if(pFile!=NULL)
	{
		fprintf(pFile, "%d\n", idAnterior+1);
		todoOk = 1;
	}
	fclose(pFile);

	return todoOk;
}

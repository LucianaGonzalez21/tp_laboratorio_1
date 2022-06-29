/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "utn.h"
#include "menus.h"
//#include "LinkedList.h"


/*------------CONSTRUCTORES Y DESTRUCTORES-----------------*/
Passenger* Passenger_new()
{
	Passenger* newPassenger = NULL;
	newPassenger = (Passenger*)malloc(sizeof(Passenger));

	if(newPassenger!=NULL)
	{
		Passenger_setId(newPassenger, 1);
		Passenger_setNombre(newPassenger, " ");
		Passenger_setApellido(newPassenger, " ");
		Passenger_setPrecio(newPassenger, 0);
		Passenger_setCodigoVuelo(newPassenger, " ");
		Passenger_setTipoPasajero(newPassenger, 1);
		Passenger_setStatus(newPassenger, 1);
	}
	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* newPassenger = Passenger_new();

	if(newPassenger!=NULL)
	{
		if(!(Passenger_setId(newPassenger, atoi(idStr)) &&
			Passenger_setNombre(newPassenger, nombreStr) &&
			Passenger_setApellido(newPassenger, apellidoStr) &&
			Passenger_setCodigoVuelo(newPassenger, codigoVueloStr) &&
			Passenger_setTipoPasajero(newPassenger, atoi(tipoPasajeroStr)) &&
			Passenger_setStatus(newPassenger, atoi(estadoVueloStr)) &&
			Passenger_setPrecio(newPassenger, atof(precioStr))))
		{
			free(newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

void Passenger_delete(Passenger* passenger)
{
	if(passenger!=NULL)
	{
		free(passenger);
	}
}

int Passenger_deleteAll(LinkedList* pArrayListPassenger)
{
	int todoOk;
	Passenger* pPasajero;
	int tam;

	if(pArrayListPassenger!=NULL)
	{
		tam = ll_len(pArrayListPassenger);
		for(int i=0; i<tam; i++)
		{
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_delete(pPasajero);
		}
		todoOk=1;
	}
	return todoOk;
}

/*-------------SETTERS Y GETTERS-------------*/
int Passenger_setId(Passenger* this,int id)
{
	int todoOk=0;

	if(this!=NULL && id>0)
	{
		todoOk=1;
		this->id = id;
	}
	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk=0;

	if(this!=NULL && id>0)
	{
		todoOk=1;
		*id = this->id;
	}
	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk=0;

	if(this!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<50)
	{
		todoOk=1;
		strcpy(this->nombre, nombre);
	}

	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk=0;

	if(this!=NULL && nombre!=NULL)
	{
		todoOk=1;
		strcpy(nombre, this->nombre);
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk=0;

	if(this!=NULL && apellido!=NULL && strlen(apellido)>1 && strlen(apellido)<50)
	{
		todoOk=1;
		strcpy(this->apellido, apellido);
	}
	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk=0;

	if(this!=NULL && apellido!=NULL)
	{
		todoOk=1;
		strcpy(apellido, this->apellido);
	}

	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk=0;

	if(this!=NULL && codigoVuelo!=NULL && strlen(codigoVuelo)<11)	//mayor a?
	{
		todoOk=1;
		strcpy(this->codigoVuelo, codigoVuelo);
	}

	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk=0;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		todoOk=1;
		strcpy(codigoVuelo, this->codigoVuelo);
	}

	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOk=0;

	if(this!=NULL && tipoPasajero>0 && tipoPasajero<4)
	{
		todoOk=1;
		this->tipoPasajero = tipoPasajero;
	}

	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOk=0;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		todoOk=1;
		*tipoPasajero = this->tipoPasajero;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk=0;

	if(this!=NULL && precio>0)
	{
		todoOk=1;
		this->precio = precio;
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk=0;

	if(this!=NULL && precio!=NULL)
	{
		todoOk=1;
		*precio = this->precio;
	}
	return todoOk;
}

int Passenger_setStatus(Passenger* this, int estado)
{
	int todoOk=0;

	if(this!=NULL && estado>0 && estado<5)
	{
		todoOk=1;
		this->estadoVuelo = estado;
	}

	return todoOk;
}

int Passenger_getStatus(Passenger* this, int* estado)
{
	int todoOk=0;

	if(this!=NULL && estado!=NULL)
	{
		todoOk=1;
		*estado = this->estadoVuelo;
	}

	return todoOk;
}

int Passenger_getStatusStr(int estado, char* cadena)
{
	int todoOk=0;

	if(estado>0 && estado<5 && cadena!=NULL)
	{
		todoOk=1;
		switch(estado)
		{
		case 1:
			strcpy(cadena, "Scheduled");
			break;
		case 2:
			strcpy(cadena, "Active");
			break;
		case 3:
			strcpy(cadena, "Landed");
			break;
		case 4:
			strcpy(cadena, "Cancelled");
			break;
		}
	}
	return todoOk;
}

int Passenger_getTypeStr(int tipo, char* cadena)
{
	int todoOk=0;

	if(tipo>0 && tipo<4 && cadena!=NULL)
	{
		todoOk=1;
		switch(tipo)
		{
		case 1:
			strcpy(cadena, "First class");
			break;
		case 2:
			strcpy(cadena, "Bussiness class");
			break;
		case 3:
			strcpy(cadena, "Economy class");
			break;
		}
	}
	return todoOk;
}


int validarEstadoVuelo(char* estado)
{
	int todoOk=0;

	if(estado!=NULL)
	{
		if(!strcmp(estado, "1")
			|| !strcmp(estado, "2")
			|| !strcmp(estado, "3")
			|| !strcmp(estado, "4"))
		{
			todoOk=1;
		}
	}

	return todoOk;
}

int validarTipoPasajero(char* tipo)
{
	int todoOk=0;

	if(tipo!=NULL)
	{
		if(!strcmp(tipo, "1")
			|| !strcmp(tipo, "2")
			|| !strcmp(tipo, "3"))
		{
			todoOk=1;
		}
	}

	return todoOk;
}


/*----------CREAR---------*/
Passenger* crear_Pasajero(char* id)
{
	Passenger* pPasajero;
	char nombre[50];
	char apellido[50];
	char precio[20];
	char codigo[10];
	char tipo[20];
	char estado[20];

	//pPasajero = Passenger_new();

//	if(pPasajero!=NULL)
//	{

		if(!utn_getString(nombre, 50, "Ingrese nombre del pasajero: ", "Error, nombre no valido.\n", 3)
			&& !utn_getString(apellido, 50, "Ingrese el apellido del pasajero: ", "Error, apellido no valido.\n", 3)
			&& !utn_getStringFloat(precio, 20, "Ingrese el precio: ", "Error, precio no valido.\n", 3)
			&& !utn_getStringAlfaNumerico(codigo, 20, "Ingrese el codigo de vuelo: ", "Error, codigo no valido.\n", 3)
			&& !utn_getStringInt(tipo, 20, "Ingrese el numero del tipo de pasajero: ", "Error, no valido.\n", 3)
			&& !utn_getStringInt(estado, 20, "Ingrese el estado de vuelo: ", "Error, no valido.\n", 3))
		{
//			if(strcmp(tipo, "1") != 0 && strcmp(tipo, "2") != 0 && strcmp(tipo, "3") != 0)
//			{
//				printf("Tipo de pasajero no valido.\n");
//			}
//			else if(strcmp(estado, "1") != 0 && strcmp(estado, "2") != 0 && strcmp(estado, "3") != 0 && strcmp(estado, "4") != 0)
//			{
//				printf("Estado de vuelo no valido.\n");
//			}
//			else
//			{
//				pPasajero =  Passenger_newParametros(id, nombre, apellido, precio, codigo, tipo, estado);
//				if(pPasajero!=NULL)
//				{
//					printf("pasajero creado ok\n");
//				}
//			}
			if(validarEstadoVuelo(estado) && validarTipoPasajero(tipo))
			{
				pPasajero =  Passenger_newParametros(id, nombre, apellido, precio, codigo, tipo, estado);
				if(pPasajero!=NULL)
				{
					printf("pasajero creado ok\n");
				}
			}
			else if(!validarEstadoVuelo(estado))
			{
				printf("Estado de vuelo no valido.\n");
			}
			else if(!validarTipoPasajero(tipo))
			{
				printf("Tipo de pasajero no valido.\n");
			}
//		}
	}
	return pPasajero;
}

/*----------------PRINT-------------*/

int printPassenger(Passenger* p)
{
	int todoOk=0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipo;
	char codigo[20];
	int estado;
	char descripcionTipo[20];
	char descripcionEstado[20];

	if(p!=NULL)
	{
		if(Passenger_getId(p, &id) &&
			Passenger_getNombre(p, nombre) &&
			Passenger_getApellido(p, apellido) &&
			Passenger_getPrecio(p, &precio) &&
			Passenger_getCodigoVuelo(p, codigo) &&
			Passenger_getStatus(p, &estado) &&
			Passenger_getStatusStr(estado, descripcionEstado) &&
			Passenger_getTipoPasajero(p, &tipo) &&
			Passenger_getTypeStr(tipo, descripcionTipo))
		{
			printf(" %5d   %15s  %15s      $%8.2f        %10s        %20s         %20s\n", id, nombre, apellido, precio, codigo, descripcionTipo, descripcionEstado);
			todoOk=1;
		}
	}

	return todoOk;
}


/*-------------SORT--------------*/
int sort_id(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	int id1;
	int id2;

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getId(pAux1, &id1);
		Passenger_getId(pAux2, &id2);

		if(id1 > id2)
		{
			retorno = 1;
		}
		else if(id1 < id2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int sort_nombre(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	char nombre1[50];
	char nombre2[50];

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getNombre(pAux1, nombre1);
		Passenger_getNombre(pAux2, nombre2);

		if(strcmp(nombre1, nombre2) > 0)
		{
			retorno = 1;
		}
		else if(strcmp(nombre1, nombre2) < 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int sort_apellido(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	char apellido1[50];
	char apellido2[50];

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getApellido(pAux1, apellido1);
		Passenger_getApellido(pAux2, apellido2);

		if(strcmp(apellido1, apellido2) > 0)
		{
			retorno = 1;
		}
		else if(strcmp(apellido1, apellido2) < 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int sort_precio(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	float precio1;
	float precio2;

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getPrecio(pAux1, &precio1);
		Passenger_getPrecio(pAux2, &precio2);

		if(precio1 > precio2)
		{
			retorno = 1;
		}
		else if(precio1 < precio2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int sort_codigoVuelo(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	char codigo1[50];
	char codigo2[50];

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getCodigoVuelo(pAux1, codigo1);
		Passenger_getCodigoVuelo(pAux2, codigo2);

		if(strcmp(codigo1, codigo2) > 0)
		{
			retorno = 1;
		}
		else if(strcmp(codigo1, codigo2) < 0)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int sort_tipoVuelo(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	int tipo1;
	int tipo2;

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getTipoPasajero(pAux1, &tipo1);
		Passenger_getTipoPasajero(pAux2, &tipo2);

		if(tipo1 > tipo2)
		{
			retorno = 1;
		}
		else if(tipo1 < tipo2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int sort_estadoVuelo(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* pAux1;
	Passenger* pAux2;
	int estado1;
	int estado2;

	if(p1!=NULL && p2!=NULL)
	{
		pAux1 = (Passenger*)p1;
		pAux2 = (Passenger*)p2;

		Passenger_getStatus(pAux1, &estado1);
		Passenger_getStatus(pAux2, &estado2);

		if(estado1 > estado2)
		{
			retorno = 1;
		}
		else if(estado1 < estado2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

/*-------------ID------------*/
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
					Passenger_setStatus(pasajero, auxEstadoVuelo);

					itoa(auxPrecio, precio, 10);
					itoa(auxTipoPasajero, tipoPasajero, 10);
					itoa(auxEstadoVuelo, estadoVuelo, 10);
				}
			}
		}
	}
	return pasajero;
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

		Passenger_getStatus(auxA, &estadoA);
		Passenger_getdescripcionEstadoVuelo(estadoA, auxEstadoA);
		Passenger_getStatus(auxB, &estadoB);
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

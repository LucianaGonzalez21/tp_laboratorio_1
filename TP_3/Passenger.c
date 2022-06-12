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
#include "math.h"

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
			Passenger_setPrecio(newPassenger, atof(precioStr))))
		{
			free(newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

void Passenger_delete(Passenger* passenger)	//no tiene parametros??
{
	if(passenger!=NULL)
	{
		free(passenger);	//valido que sea distinto de null?
	}
}

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

Passenger* crear_Pasajero()
{
	Passenger* pasajero = NULL;
	char nombre[50];
	char apellido[50];
	float precio;
	char precioStr[100];
	char codigo[10];
	int tipo;
	char tipoStr[100];
	int estado;
	char estadoStr[100];

	pasajero = Passenger_new();

	if(pasajero!=NULL)
	{
		if(!utn_getString(nombre, 50, "Ingrese el nombre: ", "Error, nombre no valido.\n", 3) &&
		!utn_getString(apellido, 50, "Ingrese el apellido: ", "Error, apellido no valido.\n", 3) &&
		!utn_getFloat(&precio, "Ingrese el precio: ", "Error, precio no valido.\n", 1, 100000, 3) &&
		!utn_getStringAlfaNumerico(codigo, 20, "Ingrese el codigo de vuelo: ", "Error, codigo no valido.\n", 3) &&
		!menuTipoPasajero(&tipo) &&
		!menuEstadoVuelo(&estado))
		{
			if(Passenger_setNombre(pasajero, nombre) &&
			Passenger_setApellido(pasajero, apellido) &&
			Passenger_setPrecio(pasajero, precio) &&
			Passenger_setCodigoVuelo(pasajero, codigo) &&
			Passenger_setNombre(pasajero, nombre) &&
			Passenger_setStatus(pasajero, estado) &&
			Passenger_setTipoPasajero(pasajero, tipo))
			{
				printf("Datos cargados correctamente.\n");
				itoa(precio, precioStr, 10);
				itoa(tipo, tipoStr, 10);
				itoa(estado, estadoStr, 10);
			}

		}
	}
	return pasajero;
}

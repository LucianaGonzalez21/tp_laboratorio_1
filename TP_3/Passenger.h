/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
void Passenger_delete(Passenger*);
int Passenger_deleteAll(LinkedList* pArrayListPassenger);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatus(Passenger* this, int estado);
int Passenger_getStatus(Passenger* this, int* estado);

int Passenger_getStatusStr(int estado, char* cadena);
int Passenger_getTypeStr(int tipo, char* cadena);

int printPassenger(Passenger* p);

Passenger* crear_Pasajero();

/*****ID****/
int Passenger_actualizarUltimoId(int idAnterior);

/*****SORT****/
int sort_id(void* p1, void* p2);
int sort_nombre(void* p1, void* p2);
int sort_apellido(void* p1, void* p2);
int sort_precio(void* p1, void* p2);
int sort_codigoVuelo(void* p1, void* p2);
int sort_tipoVuelo(void* p1, void* p2);
int sort_estadoVuelo(void* p1, void* p2);


int Passenger_ordenarPorId(void* a, void* b);
int Passenger_ordenarPorNombre(void* a, void* b);
int Passenger_ordenarPorApellido(void* a, void* b);
int Passenger_ordenarPorPrecio(void* a, void* b);
int Passenger_ordenarPorCodigoDeVuelo(void* a, void* b);
int Passenger_ordenarPorTipoPasajero(void* a, void* b);
int Passenger_ordenarPorEstadoVuelo(void* a, void* b);


int Passenger_getdescripcionEstadoVuelo(int estadoVuelo , char* descripcionEstadoVuelo);
int Passenger_getdescripcionTipoPasajero(int tipoPasajero , char* descripcionTipo);
Passenger* Passenger_altaPasajero();
#endif /* PASSENGER_H_ */

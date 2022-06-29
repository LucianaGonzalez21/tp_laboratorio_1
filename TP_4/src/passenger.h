/*
 * passenger.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */

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

#endif /* PASSENGER_H_ */

/**

 * @brief crea un nuevo pasajero
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
Passenger* Passenger_new();

/**
 * @brief crea un nuevo pasajero y le asigna a sus campos los valores pasados por parametro
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precioStrn
 * @param codigoVueloStr
 * @param tipoPasajeroStr
 * @param estadoVueloStr
 * @return retorna NULL si hubo error de parametros o el puntero al nuevo pasajero
 */
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr,  char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

/**
 * @brief elimina a un pasajero
 *
 * @param this
 */
void Passenger_delete(Passenger* this);

/**
 * @brief asigna el valor de id pasado por parametro al campo id del puntero a pasajero
 *
 * @param this
 * @param id
 *
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setId(Passenger* this, int id);

/**
 * @brief obtiene el id del puntero a pasajero y lo guarda en el puntero a id
 *
 * @param this
 * @param id
 *
 * @return retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getId(Passenger* this, int* id);

/**

 * @brief asigna el valor de nombre pasado por parametro al campo nombre del puntero a pasajero
 *
 * @param this:
 * @param nombre
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setNombre(Passenger* this, char* nombre);

/**

 * @brief obtiene el nombre del puntero a pasajero y lo guarda en el puntero a nombre
 *
 * @param this
 * @param nombre
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getNombre(Passenger* this, char* nombre);

/**

 * @brief  asigna el valor de apellido pasado por parametro al campo apellido del puntero a pasajero
 *
 * @param this
 * @param apellido
 * @return retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setApellido(Passenger* this, char* apellido);

/**

 * @brief obtiene el apellido del puntero a pasajero y lo guarda en el puntero a apellido
 *
 * @param this
 * @param apellido
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getApellido(Passenger* this, char* apellido);

/**

 * @brief asigna el valor de precio pasado por parametro al campo precio del puntero a pasajero
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param precio: El precio a colocar en la lista.
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setPrecio(Passenger* this, float precio);

/**

 * @brief obtiene el precio del puntero a pasajero y lo guarda en el puntero a precio
 *
 * @param this
 * @param precio
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getPrecio(Passenger* this, float* precio);

/**

 * @brief asigna el valor de codigo de vuelo pasado por parametro al campo codigoVuelo del puntero a pasajero
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param codigoVuelo: El codigo de vuelo a colocar en la lista.
 * @return retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);

/**

 * @brief obtiene el codigo de vuelo del puntero a pasajero y lo guarda en el puntero a codigoVuelo
 *
 * @param this
 * @param codigoVuelo
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

/**

 * @brief asigna el valor de tipo de pasajero pasado por parametro al campo tipoPasajero del puntero a pasajero
 *
 * @param this: Este es un elemento a buscar en la lista.
 * @param tipoPasajero: El tipo de pasajero a colocar en la lista.
 * @return retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);

/**

 * @brief obtiene el tipo de pasajero del puntero a pasajero y lo guarda en el puntero a tipoPasajero
 *
 * @param this
 * @param tipoPasajero
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

/**

 * @brief segun el numero pasado por parametro, copia un valor en la cadena descripciontipo
 *
 * @param tipoPasajero
 * @param descripcionTipo
 * @return retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getdescripcionTipoPasajero(int tipoPasajero , char* descripcionTipo);

/**
 * @brief asigna el valor de estado de vuelo pasado por parametro al campo estadoVuelo del puntero a pasajero
 *
 * @param this
 * @param estadoVuelo
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);

/**

 * @brief obtiene el estado de vuelo del puntero a pasajero y lo guarda en el puntero a estadoVuelo
 *
 * @param this
 * @param estadoVuelo
 * @return  retorna 1 si pudo hacerlo. 0 si no
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

/** @brief segun el numero pasado por parametro, copia un valor en la cadena descripciontipo
*
* @param estadoVuelo
* @param descripcionEstadoVuelo
* @return retorna 1 si pudo hacerlo. 0 si no
*/
int Passenger_getdescripcionEstadoVuelo(int estadoVuelo , char* descripcionEstadoVuelo);

/**
 * @brief imprime en pantalla los datos del pasajero pasado por parametro
 *
 * @param pasajero
 */
void Passenger_mostrarUnPasajero(Passenger* pasajero);

/**
 * @brief pide los datos del pasajero al usuario
 *
 * @return retorna NULL si no pudo cargar, o el puntero al pasajero si pudo
 */
Passenger* Passenger_altaPasajero();


/**
 * @brief compara los id de los elementos pasado por parametro
 *
 * @param a: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param b: El puntero que apunta a la direccion de memomoria del 2da direccion.
 * @return retorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorId(void* a, void* b);

/**

 * @brief compara los nombres de los elementos pasado por parametro
 *
 * @param a
 * @param b
 * @return retorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorNombre(void* a, void* b);

/**

 * @brief compara los apellidos de los elementos pasado por parametro
 * @param a
 * @param b
 * @return retorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorApellido(void* a, void* b);

/**

 * @brief compara los precios de los elementos pasado por parametro
 * @param a
 * @param b
 * @return retorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorPrecio(void* a, void* b);

/**

 * @brief compara los codigos de vuelo de los elementos pasado por parametro
 *
 * @param a
 * @param b
 *  * @return retorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorCodigoDeVuelo(void* a, void* b);

/**

 * @brief compara los tipos de  pasajero de los elementos pasado por parametro
 *
 * @param a
 * @param b
 * @return retorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorTipoPasajero(void* a, void* b);

/**

 * @briefcompara los estados de vuelo de los elementos pasado por parametro
 * @param a
 * @param b
 * @returnretorna 0 si son iguales, 1 si el de a es mayor al de b, y -1 cuando el de b es mayor al de a
 */
int Passenger_ordenarPorEstadoVuelo(void* a, void* b);

/**
 * @brief Esta funcion guarda el ultimo id ingresado en la lista en un archivo texto.
 *
 * @param idAnterior
 * @return Retorna 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Passenger_actualizarUltimoId(int idAnterior);

/*
 * passenger.h
 *
 *  Created on: May 8, 2022
 *      Author: Dell
 */

#include "statusFlight.h"
#include "typePassenger.h"


#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;


/// @brief Muestra el menu de opciones y pide al usuario que ingrese un numero
///
/// @param opcion Puntero al espacio de memoria donde se alojara la opcion que haya ingresado el usuario
/// @return Devuelve 0 si consiguio una opcion valida, -1 si no
int menuPrincipal(int *opcion);


int menuInformes(int* opcion);


/// @brief Muestra un menu de opciones y pide al usuario que ingrese un numero
///
/// @param opcionModificar Puntero al espacio de memoria donde se alojara la opcion que el usuario haya elegido
/// @return Devuelve 0 si se ingreso una opcion valida, -1 si no
int menuModificarPasajero(int* opcionModificar);


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger *list, int len);


/// @brief Busca en el vector un lugar libre, donde la bandera isEmpty valga 1
///
/// @param list Es el vector
/// @param len Es el tamanio del vector
/// @param pPosicion Es el puntero al espacio de memoria donde se alojara la posicion libre o bien -1 si no encontro lugar
/// @return Retorna 0 si hay algun error de parametros, 1 si estan bien
int buscarPosicionLibre(Passenger* list, int len, int* pPosicion);


/// @brief Pide al usuario y carga todos los campos del tipo Passenger, excepto por el campo id que es autoincremental
///
/// @param list Es el vector de pasajeros
/// @param lenP Es el largo del vector pasajeros
/// @param pIndex Es el puntero al espacio de memoria, que tiene guardado el valor del id, y al cual se le incrementa +1 cuando se ejecuta esta funcion
/// @param status Es el vector de estados de vuelo
/// @param lenS Es el largo del vector de estados de vuelo
/// @param types Es el vector de tipo de pasajero
/// @param lenT Es el largo del vector de tipo de pasajero
/// @return Retorna 0 si hubo error de parametros, 1 si los datos se cargaron bien
int cargarPasajero(Passenger* list, int lenP, int* pIndex, eStatusFlight* status, int lenS, eTypePassenger* types, int lenT);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);


/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int lenP, eTypePassenger* types, int lenT, int order);

/// @brief Imprime en pantalla todos los datos del pasajero
///
/// @param aPassenger Es el pasajero a mostrar
/// @param types Es el vector de tipos de pasajero
/// @param lenT Es el largo del vector tipos de pasajero
/// @param status Es el vector de estados de vuelo
/// @param lenS Es el largo del vector estados de vuelo
/// @return Retorna 0 si hay algun error de parametros, y 1 si pudo mostrar los datos correctamente
int mostrarPasajero(Passenger aPassenger, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS);

/// @brief Muestra la lista de pasajeros, despliega un menu de opciones para que el usuario elija que dato quiere modificar a traves
/// 		del id del pasajero y lo modifica
/// @param list Es el vector de pasajeros
/// @param lenP Es el largo del vector pasajeros
/// @param types Es el vector de tipo de pasajero
/// @param lenT Es el largo del vector tipo de pasajero
/// @param status Es el vector de estados de vuelo
/// @param lenS Es el largo del vector de estados de vuelo
/// @return Retorna 0 si hay error de parametros o si no encuentra el id ingresado, y 1 si los parametros estan bien
int modificarPasajero(Passenger *list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS);


/// @brief Elimina a un pasajero de la lista pidiendo el id, y asi cambia isEmpty a 1
///
/// @param list Es el vector de pasajeros
/// @param len Es la longitud del vector de pasajeros
/// @return Retorna -1 si hubo algun error de parametros, 0 si no y 1 si lo pudo eliminar
int darBajaPasajero(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS);


/// @brief  Muestra un menu de opciones para que el usuario elija el informe que desea ver, luego lo imprime
///
/// @param list Es el vector de pasajeros
/// @param lenP Es el largo del vector pasajeros
/// @param types Es el vector de tipo de pasajero
/// @param lenT Es el largo del vector tipos de pasajero
/// @param status Es el vector de estados de vuelo
/// @param lenS Es el largo del vector estados de vuelo
/// @return Devuelve 0 si hay error de parametros, 1 si no
int mostrarInformes(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);


/// @brief Muestra en pantalla una lista de pasajeros cuyo vuelo sea Activo
///
/// @param list Es el vector de pasajeros
/// @param lenP Es el largo del vector pasajeros
/// @param types Es el vector de tipos de pasajero
/// @param lenT Es el largo del vector tipos de pasajero
/// @param status Es el vector estados de vuelo
/// @param lenS Es el largo del vector estados de vuelo
/// @param criterio Es el criterio con el que va a ordenar las datos (0,1)
/// @return Devuelve 0 si hay error de parametros, 1 si no
int listarPasajerosConVueloActivo(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status,int lenS, int criterio);

/// @brief Informa la suma de precios de todos los vuelos, el promedio y la cantidad de pasajeros que superan el precio promedio
///
/// @param list Es el vector de pasajeros
/// @param len Es el largo del vector
/// @return Devuelve 1 si pudo realizar los calculos con exito, 0 si no
int informarPrecioTotalYPromedioYPasajeros(Passenger* list, int len);


/// @brief Cuenta a los pasajeros de la lista que superan el precio promedio de todos los vuelos, que le es pasado por parametro
///
/// @param list Es el vector de pasajeros
/// @param len Es el largo del vector pasajeros
/// @param precioPromedio Es el precio promedio
/// @param pCantidad Es el puntero al espacio de memoria donde se alojara la cantidad de pasajeros que superan el precio promedio
/// @return Devuelve 0 si hay error de parametros, 1 si no
int contarPasajerosSuperanPrecioPromedio(Passenger* list, int len, float precioPromedio, int* pCantidad);


/// @brief Calcula el precio total de todos los vuelos y el promedio
///
/// @param list Es el vector de pasajeros
/// @param len Es el largo del vector pasajeros
/// @param pPrecioTotal Es el puntero al espacio de memoria donde se guardara el acumulado de todos los precios
/// @param pPromedio Es el puntero al espacio de memoria donde se alojara el precio promedio de  los vuelos
/// @return Devuelve 0 si hubo algun error de parametros, 1 si no
int calcularTotalYPromedioDePrecios(Passenger* list, int len, float* pPrecioTotal, float* pPromedio);


/// @brief Muestra una lista de pasajeros ordenados por apellido, y por tipo de pasajero
///
/// @param list Es el vector de pasajeros
/// @param lenP Es el largo del vector pasajeros
/// @param types Es el vector de tipos de pasajeros
/// @param lenT Es el largo del vector tipos de pasajeros
/// @param status Es el vector de estados de vuelo
/// @param lenS Es el largo del vector estados de vuelo
/// @param criterio Es el criterio por el que se ordenara la lista (0,1)
/// @return Devuelve 0 si hay error de parametros, 1 si no
int listarPasajerosPorApellidoYTipo(Passenger* list, int lenP, eTypePassenger* types, int lenT, eStatusFlight* status, int lenS, int criterio);

int hardcodearPasajeros(Passenger* list , int len, int cant, int* pIndex);

#endif /* PASSENGER_H_ */

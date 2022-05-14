/*
 * typePassenger.h
 *
 *  Created on: May 10, 2022
 *      Author: Dell
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct{
	int id;
	char descripcion[20];
}eTypePassenger;

#endif /* TYPEPASSENGER_H_ */

/// @brief Imprime el id y la descripcion de cada tipo de pasajero en una lista
///
/// @param estados Es el vector de typePassenger
/// @param tam Es el tamanio del vector
/// @return Devuelve 0 si hay error de parametros, 1 si no
int listarTiposPasajero(eTypePassenger* tipos, int tam);


/// @brief Busca un tipo de pasajero que exista, a traves de un id, y devuelve la posicion donde se encuentra por medio de un puntero
///
/// @param estados Es el vector de type Passenger
/// @param tam Es el tamanio del vector
/// @param id Es el id que se va a buscar en el vector
/// @param pIndice Es el puntero al espacio de memoria donde se alojara el indice encontrado o -1 si no lo encontro
/// @return Retorna 0 si hubo algun error de parametros, o 1 si no
int buscarTipoPasajero(eTypePassenger* tipos, int tam, int id, int* pIndice);


/// @brief Busca en el vector de tipos de pasajero el id pasado por parametro
///
/// @param estados Es el vector de tipos de pasajero
/// @param tam Es el tamanio del vector
/// @param id Es el id que se buscara en el vector
/// @return Devuelve 1 si el tipo de pasajero existe, 0 si no
int validarTipoPasajero(eTypePassenger* tipos, int tam, int id);


/// @brief Busca a traves de un id un type Passenger que exista y guarda en el puntero la descripcion de ese tipo
///
/// @param estados Es el vector de tipos de pasajero
/// @param tam Es el tamanio del vector
/// @param id Es el id que se va a buscar en el vector
/// @param descripcion Puntero al espacio de memoria donde se guardara la descripcion del tipo de pasajero
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int cargarDescripcionTipoPasajero(eTypePassenger* tipos, int tam, int id, char* descripcion);

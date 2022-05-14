/*
 * statusFlight.h
 *
 *  Created on: May 10, 2022
 *      Author: Dell
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct{
	int id;
	char descripcion[20];
}eStatusFlight;

#endif /* STATUSFLIGHT_H_ */

/// @brief Imprime el id y la descripcion de cada estado de vuelo en una lista
///
/// @param estados Es el vector de statusFlight
/// @param tam Es el tamanio del vector
/// @return Devuelve 0 si hay error de parametros, 1 si no
int listarEstadosDeVuelo(eStatusFlight* estados, int tam);


/// @brief Busca un Status Flight que exista, a traves de un id, y devuelve la posicion donde se encuentra por medio de un puntero
///
/// @param estados Es el vector de Status Flight
/// @param tam Es el tamanio del vector
/// @param id Es el id que se va a buscar en el vector
/// @param pIndice Es el puntero al espacio de memoria donde se alojara el indice encontrado o -1 si no lo encontro
/// @return Retorna 0 si hubo algun error de parametros, o 1 si no
int buscarEstadoDeVuelo(eStatusFlight* estados, int tam, int id, int* pIndice);


/// @brief Busca en el vector de Status Flight el id pasado por parametro
///
/// @param estados Es el vector de Status Flight
/// @param tam Es el tamanio del vector
/// @param id Es el id que se buscara en el vector
/// @return Devuelve 1 si el Status Flight existe, 0 si no
int validarEstadoDeVuelo(eStatusFlight* estados, int tam, int id);


/// @brief Busca a traves de un id un Status Flight que exista y guarda en el puntero la descripcion de ese Status
///
/// @param estados Es el vector de Status Flight
/// @param tam Es el tamanio del vector
/// @param id Es el id que se va a buscar en el vector
/// @param descripcion Puntero al espacio de memoria donde se guardara la descripcion del Status Flight
/// @return Devuelve 0 si hubo error de parametros, 1 si no
int cargarDescripcionEstadoDeVuelo(eStatusFlight* estados, int tam, int id, char* descripcion);

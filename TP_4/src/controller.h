/*
 * controller.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
/**
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param path
 * @param pArrayListPassenger
 * @return  retorna 1 si pudo cargar el archivo, -1 si no
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * @param path
 * @param pArrayListPassenger
 * @return retorna 1 si pudo cargar el archivo, -1 si no
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief agrega un pasajero a la lista
 *
 * @param pArrayListPassenger
 * @return retorna -1 si no pudo agregarlo, 1 si lo logro
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief muestra al usuario un menu de opciones y modifica el campo del pasajero elegido por el usuario
 *
 * @param pArrayListPassenger
 * @return reetorna -1 si hubo errores de parametro, 1 si no
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief pide al usuario un id de un pasajero y lo elimina
 *
 * @param pArrayListPassenger
 * @return retorna -1 si huho error de parametros , 1 si no
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * @brief imprime en pantalla la lista de pasajeros
 *
 * @param pArrayListPassenger
 * @return retorna -1 si hubo error de parametros, 1 si no
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**

 * @brief muestra un usuario un menu de opciones y segun lo elegido, ordena la lista de pasajeros
 *
 * @param pArrayListPassenger
 * @return retorna -1 si hubo error de parametros, 1 si no
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief Esta funcion Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * @param path
 * @param pArrayListPassenger
 * @return retorna -1 si hubo error de parametros, 1 si pudo guardar, 0 si no pudo
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief Esta funcion Guarda los datos de los empleados en el archivo dataBinaria.bin (modo binario).
 *
 * @param path
 * @param pArrayListPassenger
 * @returnretorna -1 si hubo error de parametros, 1 si no
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief Esta funcion crea un archivo de texto y guarda el ultimo id encontrado en la lista de pasajeros.
 *
 * @return  retorna el ultimo id encontrado el lista de pasajeros.
 */
int controller_getUltimoId();

/**
 * @brief Esta funcion se encarga de encontrar la index de donde se encuentra un Id pasado por parametro.
 *
 * @param pArrayListPassenger
 * @param idPasajero
 * @return retorna el indice de la posicion encontrada pasada por parametro o si no la encontro un -1.
 */
int controller_buscarIdPasajero(LinkedList* pArrayListPassenger, int idPasajero);


/** \brief Esta funcion crea una sub lista,que comienza y termina segun lo ingresado por el usuario
 *
 * \param pArrayListPassenger LinkedList*
 * \return retorna -1 si hubo error, 0 si no
 *
 */
int controller_InformeSubListadoPorRangoSelecionado(LinkedList* pArrayListPassenger);

/** \brief
 *
 * \param pArrayListPassenger LinkedList*
 * \return
 *
 */
int controller_ListPassengerInforme(LinkedList* pArrayListPassenger);

/** \brief Esta funcion busca el menor precio de los vuelos y elimina el pasajero con ese precio de la lista.
 *
 * \param pArrayListPassenger LinkedList*
 * \return retorna -1 si hubo error de parametros
 *
 */
int controller_InformeEliminarPasajeroMenorPrecio(LinkedList* pArrayListPassenger);

/** \brief Esta funcion da de alta un pasajero en una posicion selecionada por el usuario.
 *
 * \param pArrayListPassenger LinkedList*
 * \return retorna -1 si hubo error de paraetros, 1 si pudo dar de alta
 *
 */
int controller_InformeAltaEnPosicionSelecionada(LinkedList* pArrayListPassenger);

/** \brief muestra un menu y permite al usuario elegir el informe a imprimir por pantalla
 *
 * \param pArrayListPassenger LinkedList*: Lista de los pasajeros.
 * \return retorna -1 si hubo error de parametros, 0 si no
 *
 */
int controller_informarListas(LinkedList* pArrayListPassenger);

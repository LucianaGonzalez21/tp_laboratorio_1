/*
 * utn.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Dell
 */

#ifndef UTN_H_
#define UTN_H_

/**
* \brief Solicita un numero al usuario, lueego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero minimo a ser aceptado
* \param maximo Es el numero maximo a ser aceptado
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se dejara el caracter
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el caracter minimo a ser aceptado
* \param maximo Es el caracter maximo a ser aceptado
* \return Retorna 0 si se obtuvo el caracter  y -1 si no
*/
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, char reintentos);

/**
* \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
* \param pResultado Puntero al espacio de memoria donde se guardara el numero flotante
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero flotante minimo a ser aceptado
* \param maximo Es el numero flotante maximo a ser aceptado
* \return Retorna 0 si se obtuvo el numero flotante y -1 si no
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* UTN_H_ */

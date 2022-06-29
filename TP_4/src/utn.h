/*
 * utn.h
 *
 *  Created on: Jun 28, 2022
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

/// @fn int GetString(char[], int, char[], char[], int)
/// @brief Solicita al usuario un texto, luego de verificarlo devuelve el resultado
///
/// @param cadena Puntero al espacio de memoria donde se guardará el texto luego de validarlo
/// @param longitud Largo de la cadena
/// @param mensaje Mensaje para ser mostrado al usuario
/// @param mensajeError Mensaje de error a ser mostrado al usuario
/// @param reintentos Cantidad de reintentos para poder ingresar un texto
/// @return Devuelve -1 si hay un error de parametros, 0 si OK
int utn_getString(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos);


/// @brief Solicita al usuario un texto, luego de verificarlo devuelve el resultado
///
/// @param cadena Puntero al espacio de memoria donde se guardará el texto luego de validarlo
/// @param longitud Largo de la cadena
/// @param mensaje Mensaje para ser mostrado al usuario
/// @param mensajeError Mensaje de error a ser mostrado al usuario
/// @param reintentos Cantidad de reintentos para poder ingresar un texto
/// @return Devuelve -1 si hay un error de parametros, 0 si OK
int utn_getStringAlfaNumerico(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos);


int utn_getStringFloat(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos);

int utn_getStringInt(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos);

int ingresoChar(char* letra, char* mensaje);

#endif /* UTN_H_ */

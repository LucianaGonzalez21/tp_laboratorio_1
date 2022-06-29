/*
 * menus.h
 *
 *  Created on: Jun 10, 2022
 *      Author: Dell
 */

#ifndef MENUS_H_
#define MENUS_H_



#endif /* MENUS_H_ */


int menuPrincipal(int *opcion);

/**
 * @brief Muestra un menu y pide al usuario una opcion
 *
 * @return Retrona la opcion elegida por el usuario.
 */
int menuModificaciones();

/**
 * @brief Muestra un menu y pide al usuario una opcion
 *
 * @return Retrona la opcion elegida por el usuario.
 */
int menuPrincipalOrdenamiento();

/**
 * @brief Muestra un menu y pide al usuario una opcion
 *
 * @param tipo
 * @return Retrona 1 si el parametro no es valido, 0 si es valido
 */
int menuCriterioOrdenamiento(int* tipo);

/** \brief Muestra un menu y pide al usuario una opcion
 *
 * \return  Retrona la opcion elegida por el usuario.
 */
int menuInformes();

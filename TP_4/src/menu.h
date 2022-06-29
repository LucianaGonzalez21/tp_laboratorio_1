/*
 * menu.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */

#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */
/**
 * @brief Muestra un menu y pide al usuario una opcion
 *
 * @return Retrona la opcion elegida por el usuario.
 */
int menuPrincipal();

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

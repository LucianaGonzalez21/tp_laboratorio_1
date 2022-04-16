/*
 * menu.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Dell
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief Muestra el menu
///
void mostrarMenu();

/// @brief Muestra en pantalla el valor de los precios con debito, con credito, con bitcoin y precio por kilometro
///
/// @param titulo: Es el mensaje donde escribir la aerolinea
/// @param precioDebito: float
/// @param precioCredito: float
/// @param precioBitcoin: float
/// @param precioUnitario: float
/// @return Devuelve 1 si pudo mostrar, 0 si no
int mostrarResultados(char* titulo, float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario);

#endif /* MENU_H_ */

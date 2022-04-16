/*
 * calculos.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Dell
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


/// @brief Calcula el precio con descuento y lo guarda en la direccion apuntada por el puntero
///
/// @param precio: Es el valor al que se le va a calcular el descuento
/// @param descuento: Es el porcentaje que se le va a descontar al precio
/// @param pTotal: Es un puntero al espacio de memoria donde se va a alojar el precio final con descuento
/// @return Devuelve 1 si pudo calcular el precio con el descuento, 0 si no
int calcularPrecioDebito(float precio, int descuento, float* pTotal);

/// @brief Calcula el precio con interes y lo guarda en la direccion apuntada por el puntero
///
/// @param precio: Es el valor al que se le va a calcular el interes
/// @param interes: Es el porcentaje que se le va a sumar al precio
/// @param pTotal: Es un puntero al espacio de memoria donde se va a alojar el precio final con interes
/// @return Devuelve 1 si pudo calcular el precio con interes, 0 si no
int calcularPrecioCredito(float precio, int interes, float* pTotal);

/// @brief Convierte a bitcoin el precio ingresado en pesos y lo guarda en la direccion apuntada por el puntero
///
/// @param precioPesos: Es el precio en pesos a ser convertido
/// @param precioBitcoin: Es el valor del bitcoin
/// @param pTotal: Puntero al espacio de memoria donde se alojara el precio convertido a bitcoin
/// @return Devuelve 1 si pudo convertirlo, 0 si no
int calcularPrecioBitcoin(float precioPesos, float precioBitcoin, float* pTotal);

/// @brief Calcula el precio por kilometro y lo guarda en la direccion apuntada por el puntero
///
/// @param precio: Float
/// @param kilometros: Float
/// @param pTotal: Puntero al espacio de memoria donde se guardara el precio por kilometro (precio unitario)
/// @return Devuelve 1 si pudo calcularlo, 0 si no
int calcularPrecioUnitario(float precio, float kilometros, float* pTotal);

/// @brief Calcula la diferencia entre dos precios y lo guarda en la direccion apuntada por el puntero
///
/// @param precioUno: float
/// @param precioDos: Float
/// @param pTotal: Puntero al espacio de memoria donde se guardara la diferencia entre ambos precios
/// @return Devuelve 1 si pudo calcular, 0 si no
int calcularDiferenciaPrecios(float precioUno, float precioDos, float* pTotal);

/// @brief Calcula el precio pagando con debito, con credito, con bitcoin, el precio por kilometro y la diferencia entre dos precios
///
/// @param precio float
/// @param kilometros float
/// @param precioDebito float* Puntero al espacio de memoria donde se guardara el precio pagando con debito
/// @param precioCredito float* Puntero al espacio de memoria donde se guardara el precio pagando con credito
/// @param precioConBitcoin float* Puntero al espacio de memoria donde se guardara el precio pagando con bitcoin
/// @param precioUnitario float* Puntero al espacio de memoria donde se guardara el precio por kilometro
/// @param interes int El interes que se le aplicara al precio
/// @param descuento int El descuento que se le aplicara al precio
/// @param bitcoin float El precio del bitcoin para poder realizar la conversion
/// @return Devuelve 1 si pudo calcular todo, 0 si no
int calcularCostos(float precio, float kilometros, float* precioDebito, float* precioCredito, float* precioConBitcoin, float* precioUnitario, int interes, int descuento, float bitcoin);


#endif /* CALCULOS_H_ */

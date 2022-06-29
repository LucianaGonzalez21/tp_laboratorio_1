/*
 * utn.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


static int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
static int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/**
* \brief Verifica si la cadena ingresada es numerica
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {

            *pResultado = atoi(buffer);
            retorno = 0;
        }

    }
    return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reintentos--;
    }
    return retorno;
}


int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, char reintentos)
{
    int retorno=-1;
    char buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &buffer);
            //buffer = tolower(buffer);
            if(buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);

    }

    return retorno;
}

static int esFlotante (char* cadena)
{
	int i=0;
	int retorno=-1;
	int contadorPuntos=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		retorno=1;
		for(i=0;cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				if(cadena[i] == '.' && contadorPuntos ==0)
				{
					contadorPuntos++;
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}
	return retorno;
}

/// @fn int getFloat(int*)
/// @brief Verifica si la cadena ingresada es flotante
///
/// @param pResultado Puntero al espacio de memoria donde se dejará el resultado de la funcion
/// @return retorna 0 si se obtiene un numero flotante y -1 si no
static int getFloat (float* pResultado)
{
	int retorno = -1;
	char buffer [100];

	if(pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esFlotante (buffer) == 1)
		{
			*pResultado = atof (buffer);
			retorno =0;
		}
	}

	return retorno;
}

int utn_getFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float buffer;


	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			if (getFloat(&buffer)==0 && buffer>= minimo && buffer<=maximo)
			{
				*pResultado = buffer;
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}

	return retorno;
}

////////////////////////------------------//////////////////////////

static int esSoloLetras(char str[])
{
	int i=0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			return 0;
			break;  //agregado
		}
			i++;
	}
	return 1;
}


int utn_getString(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos)
{
    int retorno;
    char buffer[longitud];
    retorno=-1;

    if(cadena != NULL && longitud>0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            if(myGets(buffer, longitud)==0 && esSoloLetras(buffer)==1)
            {
                strncpy(cadena,buffer,longitud);
                retorno =0;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }while(reintentos>=0);

    }

    return retorno;

}

static int esAlfaNumerico(char str[])
{
	int i=0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i]> '9'))
		{
			return 0;
			break;
		}
			i++;
	}
	return 1;
}

/// @brief Solicita al usuario un texto, luego de verificarlo devuelve el resultado
///
/// @param cadena Puntero al espacio de memoria donde se guardará el texto luego de validarlo
/// @param longitud Largo de la cadena
/// @param mensaje Mensaje para ser mostrado al usuario
/// @param mensajeError Mensaje de error a ser mostrado al usuario
/// @param reintentos Cantidad de reintentos para poder ingresar un texto
/// @return Devuelve -1 si hay un error de parametros, 0 si OK
int utn_getStringAlfaNumerico(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos)
{
    int retorno;
    char buffer[longitud];
    retorno=-1;

    if(cadena != NULL && longitud>0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            if(myGets(buffer, longitud)==0 && esAlfaNumerico(buffer)==1)
            {
                strncpy(cadena,buffer,longitud);
                retorno =0;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }while(reintentos>=0);

    }

    return retorno;

}

int utn_getStringFloat(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos)
{
    int retorno;
    char buffer[longitud];
    retorno=-1;

    if(cadena != NULL && longitud>0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            if(myGets(buffer, longitud)==0 && esFlotante(buffer)==1)
            {
                strncpy(cadena,buffer,longitud);
                retorno =0;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }while(reintentos>=0);

    }
    return retorno;
}

int utn_getStringInt(char cadena[], int longitud, char mensaje [], char mensajeError[], int reintentos)
{
    int retorno;
    char buffer[longitud];
    retorno=-1;

    if(cadena != NULL && longitud>0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            if(myGets(buffer, longitud)==0 && esNumerica(buffer)==1)
            {
                strncpy(cadena,buffer,longitud);
                retorno =0;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }while(reintentos>=0);

    }

    return retorno;

}

int ingresoChar(char* letra, char* mensaje)
{
    int todoOk=-1;

    if(letra!=NULL && mensaje!=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        *letra=getchar();

        todoOk=1;
    }

    return todoOk;
}

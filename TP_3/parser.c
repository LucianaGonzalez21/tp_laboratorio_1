#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	Passenger* auxiliar;
	int retorno;
	int retorno2;
	char buffer[7][50];

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		todoOk = 1;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2], buffer[3], buffer[4], buffer[5],buffer[6]);

		while (!feof(pFile))
		{
			retorno = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2], buffer[3], buffer[4], buffer[5],
					buffer[6]);

			if (retorno == 7)
			{
				auxiliar = Passenger_newParametros(buffer[0], buffer[1],buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

				if (auxiliar != NULL)
				{
					retorno2 = ll_add(pArrayListPassenger, auxiliar);

					if (retorno2 != 0)
					{
						Passenger_delete(auxiliar);
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}

    return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	int retorno;	//inicializo??
	Passenger* pasajero = Passenger_new();

	if(pFile!=NULL && pArrayListPassenger!=NULL && pasajero!=NULL)
	{
		todoOk=1;

		do
		{
			retorno = fread(pasajero, sizeof(Passenger), 1, pFile);

			if(retorno)
			{
				ll_add(pArrayListPassenger, pasajero);
				pasajero = Passenger_new();
			}
		}while(retorno);

		free(pasajero);

		fclose(pFile);

	}
	return todoOk;
}

/*
 * parser.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Dell
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "passenger.h"
#include "controller.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	Passenger* auxPassenger;
	int contadorIdIncialLista=controller_getUltimoId();
	char buffer[7][50];
	int aux;



	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
			if(aux == 7)
			{
				auxPassenger = Passenger_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

				if(auxPassenger != NULL)
				{

					auxPassenger->id=contadorIdIncialLista;
					contadorIdIncialLista++;
					aux = ll_add(pArrayListPassenger, auxPassenger);


					if(aux != 0)
					{
						Passenger_delete(auxPassenger);
						break;
					}
					else
					{
						todoOk = 1;
					}
				}
			}
			else
			{
				break;
			}
		}
		Passenger_actualizarUltimoId(contadorIdIncialLista-1);
	}
	return todoOk;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOK=0;
	int contadorIdIncialLista=controller_getUltimoId();

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		int fin=1;
		Passenger* auxPassenger=Passenger_new();
		do
		{
			fin =fread(auxPassenger, sizeof(Passenger), 1, pFile);
			if(fin)
			{
				auxPassenger->id=contadorIdIncialLista;
				contadorIdIncialLista++;
				ll_add(pArrayListPassenger, auxPassenger);
				auxPassenger=Passenger_new();
			}
		}while(fin);
		Passenger_actualizarUltimoId(contadorIdIncialLista);
		free(auxPassenger);

		fclose(pFile);
		todoOK=1;
	}

	return todoOK;
}

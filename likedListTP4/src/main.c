/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../testing/inc/main_test.h"
#include "LinkedList.h"


int main(void)
{
	setbuf(stdout, NULL);
		char salir='n';
		int flagLoad=0;
		int dioAlMenosUnAlta=0;
		int altasNoGuardadas=0;
		char confirmaGuardarTxt;
		char confirmaReiniciarLista;
		int guardoLista=0;

		LinkedList* listaEmpleados = ll_newLinkedList();
		do{
			switch(menu())
			{
				case 1:
					if(flagLoad)
					{
						printf("Ya cargo la lista, no se puede cargarla 2 veces la lista\n");
					}
					else
					{

						if(controller_loadFromText("data.csv",listaEmpleados))
						{
							printf("se cargo la lista con exito\n");
							flagLoad=1;
						}
					}
					break;

				case 2:
					if(dioAlMenosUnAlta || flagLoad)
					{
						controller_EliminarEmpleadoConMayorSueldo(listaEmpleados);
					}
					else
					{
						printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
					}
					break;

				case 3:
					if(flagLoad)
					{
						utn_getCaracter(&confirmaReiniciarLista, "Esta seguro que desea reiniciar la lista (se le eliminaran todos los elementos)?  (s/n): ", "Error\n", 'a', 'z', 2);
						if(confirmaReiniciarLista=='s')
						{
							if(!ll_clear(listaEmpleados))
							{
								printf("Se reinicio la lista correctamente\n");

							}
							else
							{
								printf("No se pudo reiniciar la lista correctamente\n");
							}
						}
						else
						{
							printf("Se cancelo correctamente la reinicializacion\n");
						}
					}
					else
					{
						printf("Primero debe cargar la lista para poder reiniciarla\n");
					}
					break;

				case 4:
					if(dioAlMenosUnAlta || flagLoad)
					{
						ll_crearSubLista(listaEmpleados);
					}
					else
					{
						printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
					}
					break;

				case 5:

					if(dioAlMenosUnAlta || flagLoad)
					{
						controller_remplazarUnEmpleado(listaEmpleados);
					}
					else
					{
						printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
					}

					break;

				case 6:
					if(controller_addEmployee(listaEmpleados))
					{
						dioAlMenosUnAlta=1;
						altasNoGuardadas++;
					}
					break;

				case 7:
					if(dioAlMenosUnAlta || flagLoad)
					{
						controller_editEmployee(listaEmpleados);

					}
					else
					{
						printf("No hay empleados para modificar\n");
					}
					break;

				case 8:
					if(dioAlMenosUnAlta || flagLoad)
					{
						controller_removeEmployee(listaEmpleados);
					}
					else
					{
						printf("No hay empleados para dar de baja\n");
					}
					break;

				case 9:
					if(dioAlMenosUnAlta || flagLoad)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("No hay empleados para listar\n");
					}
					break;

				case 10:
					if(dioAlMenosUnAlta || flagLoad)
					{
						controller_sortEmployee(listaEmpleados);

					}
					else
					{
						printf("No hay empleados para ordenar\n");
					}
					break;

				case 11:
					if(dioAlMenosUnAlta || flagLoad)
					{
						if(controller_altaEmpleadoEligiendoLugar(listaEmpleados))
						{
							dioAlMenosUnAlta=1;
							altasNoGuardadas++;
						}
					}
					else
					{
						printf("Primero debe dar de alta al menos un empleado o cargar la lista\n");
					}
					break;

				case 12:
					if(dioAlMenosUnAlta==0 && !flagLoad)
					{
						printf("No se puede guardar la lista sin antes cargarla o dar de alta al menos un empleado\n");
					}
					else if(flagLoad && altasNoGuardadas>0)
					{
						utn_getCaracter(&confirmaGuardarTxt, "Usted modifico la lista, esta seguro que desea guardarla? Si guarda se sobreescribiran todos los datos (s/n): ", "Error\n", 'a', 'z', 2);
						if(confirmaGuardarTxt=='s')
						{
							controller_saveAsText("data.csv", listaEmpleados);
							guardoLista++;

							altasNoGuardadas=0;
						}
						else
						{
							printf("Se cancelo guardar la lista\n");
						}
					}
					else if (!flagLoad && dioAlMenosUnAlta)
					{
						printf("AVISO, no cargo la lista, todo lo que haya en ella se sobreescribiran por los %d empleados nuevos que cargo\n", altasNoGuardadas);
						validarCaracter(&confirmaGuardarTxt, "Esta seguro que desea guardar?  (s/n): ", "Respuesta invalida. 's' para confirmar guardar. 'n' para cancelar: ", 's', 'n');
						if(confirmaGuardarTxt=='s')
						{
							controller_saveAsText("data.csv", listaEmpleados);
							guardoLista++;

							altasNoGuardadas=0;
						}
						else
						{
							printf("Se cancelo guardar la lista\n");
						}
					}
					else
					{
						printf("No hay nada que guardar, en la lista estan los mismos datos que antes\n");
					}

					break;

				case 13:

					if(altasNoGuardadas>0 && flagLoad)
					{
						printf("AVISO: dio de alta a %d nuevos empleados y no los guardo, ", altasNoGuardadas);
						validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
						if(salir=='s')
						{
							ll_deleteLinkedList(listaEmpleados);
							printf("Salida exitosa\n");
						}
					}
					else
					{
						validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
						ll_deleteLinkedList(listaEmpleados);
						printf("Salida exitosa\n");
					}
					break;

				default:
				printf("Opcion invalida!\n");
					break;
			}

		}while(salir=='n');

	    return 0;
}

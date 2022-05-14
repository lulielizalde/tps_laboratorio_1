#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#define TAM 2000

int main(void)
{

	setbuf(stdout, NULL);

	eTypePassenger typeid[2] ={{1,"PRIMERA CLASE"},{2,"TURISTA"}};
	eStatusFlight estadodevueloid[3]={{1,"EN HORARIO"},{2,"DEMORADO"},{3,"CANCELADO"}};
	Passenger listaDePasajeros[TAM];

	int r;
	int id;
	int opcion;
	char opcionChar[5];
	int order;
	int bandera=0;

	initPassengers(listaDePasajeros, TAM);

	do
	{
		printf( "\n  ---> BIENVENIDO <---  \n"
				"                          \n"
				"       1 ) ALTA           \n"
				"       2 ) MODIFICAR      \n"
				"       3 ) BAJA           \n"
				"       4 ) INFORMAR       \n"
				"       5 ) CARGA FORZADA  \n"
				"       6 ) SALIR          \n"
				"                          \n"
				"---> INGRESE UNA OPCION:  ");

		scanf("%s", opcionChar);
		r = validarNumero(opcionChar);
		while(r==0){
			printf("---> INGRESE UNA OPCION VALIDA: ");
			scanf("%s", opcionChar);
			r = validarNumero(opcionChar);
		}
		opcion = atoi(opcionChar);

		while(opcion < 1 || opcion > 5){
			printf("---> INGRESE UNA OPCION VALIDA: ");
			scanf("%d", &opcion);
		}
		limpiar();
		switch(opcion){
		case 1:
			CargarDatos(listaDePasajeros, TAM);
			bandera=1;
			break;
		case 2:
			if(bandera == 1){
				ModificarPasajero(listaDePasajeros, TAM);
			}else{
				printf("---> PORFAVOR CARGUE LOS DATOS:\n\n");
			}
			break;
		case 3:
			if(bandera == 1){
					printf("---> INGRESE ID DEL PASAJERO QUE BUSCA ELIMINAR:");
					scanf("%d", &id);
					r = removePassenger(listaDePasajeros, TAM, id);
					if(r == 0){
						printf("---> PASAJERO ELIMINADO CON EXITO.\n");
					}
				}else{
					printf("---> PORFAVOR CARGUE LOS DATOS:");
				}
			break;
		case 4:
			if(bandera == 1){
					printf("---> INGRESE EL METODO PARA ORDENAR LA LISTA\n ---> (1) ASCENDENTE\n ---> (-1) DESCENDENTE\n ---> INGRESE LA OPCION: ");
					scanf("%d", &order);
					while(order !=1 && order != -1){
						printf("---> INGRESE EL METODO PARA ORDENAR LA LISTA\n ---> (1) ASCENDENTE\n ---> (-1) DESCENDENTE\n ---> INGRESE LA OPCION: ");
						scanf("%d", &order);
					}
					 sortPassengers(listaDePasajeros, TAM, order);
					printPassenger(listaDePasajeros, estadodevueloid, typeid, TAM);
					system("pause");
				}else{
					printf("---> PORFAVOR CARGUE LOS DATOS:");
				}
			break;
		case 5:
			CargaForzada (listaDePasajeros, 4);
			bandera = 1;
			break;
		case 6:
			printf("---> SALIENDO . . .\n");
			break;
		default:
			printf("---> INGRESE UNA OPCION VALIDA: ");
			break;
		}
	}while(opcion != 7);
	return 0;
}


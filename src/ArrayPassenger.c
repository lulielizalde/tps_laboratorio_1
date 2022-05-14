#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"

int initPassengers (Passenger listaDePasajeros[],int size){
	int resultado;
	if (size < 0 || size > 2000){
		resultado =-1;
	}else{
		resultado=0;
	}
	for(int i=0;i<size;i++){
		listaDePasajeros[i].isEmpty = 0;
	}
	return resultado;
}
int addPassengers (Passenger listaDePasajeros[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight){
	int index;
	int retorno = -1;

	index = buscarEspacioLibre(listaDePasajeros,TAM);
	if(index !=-1){
		strcpy(listaDePasajeros[index].name,name);
		strcpy(listaDePasajeros[index].lastName,lastName);
		strcpy(listaDePasajeros[index].flycode,flycode);

		listaDePasajeros[index].price=price;
		listaDePasajeros[index].idtypePassenger=typePassenger;
		listaDePasajeros[index].id=id;
		listaDePasajeros[index].isEmpty=1;
		listaDePasajeros[index].idStatusFlight=statusFlight;

		retorno = 0;
	}
	return retorno;
}
int findPassengerById(Passenger listaDePasajeros[], int size, int id)
{
	int index;
	index = -1;
	for(int i=0;i<size;i++){
		if(listaDePasajeros[i].id==id && listaDePasajeros[i].isEmpty==1){
			index = i;
			break;
		}
	}
	return index;
}
int removePassenger(Passenger listaDePasajeros[], int size, int id){
	int index;
	int seguro = -1;
	int retorno = -1;
	index = findPassengerById(listaDePasajeros, size, id);
	if (index != -1){
		printf( "PASAJERO A ELIMINAR:\n "
				"ID: %d\n"
				"NOMBRE: %s\n"
				"APELLIDO: %s\n"
				"CODIGO DE VUELO: %s", listaDePasajeros[index].id,listaDePasajeros[index].name,listaDePasajeros[index].lastName,listaDePasajeros[index].flycode);
		printf("\n SI DESEA BORRAR EL PASAJERO PRESIONE INGRESE (1) ");
		scanf("%d", &seguro);
		if(seguro ==1){
			listaDePasajeros[index].isEmpty=0;
			retorno = 0;
		}else{
			printf("ACCION CANCELADA\n");
		}
	}else{
		printf("PASEJERO NO ENCONTRADO\n");
	}

	return retorno;
}
int sortPassengers(Passenger listaDePasajeros[], int size, int order){
	int retorno = -1;


	Passenger typeAux;
	Passenger apellidoAux;

	for (int i=0;i<size-1;i++){
		for (int j=0;j<size;j++){
			if(strcmp(listaDePasajeros[i].lastName,listaDePasajeros[j].lastName)==order){
				apellidoAux=listaDePasajeros[i];
				listaDePasajeros[i]=listaDePasajeros[j];
				listaDePasajeros[j]= apellidoAux;
			}else{
				if(strcmp(listaDePasajeros[i].lastName,listaDePasajeros[j].lastName) == 0){
					if(order < 0){
						if(listaDePasajeros[i].idtypePassenger < listaDePasajeros[j].idtypePassenger){
									typeAux=listaDePasajeros[i];
									listaDePasajeros[i]=listaDePasajeros[j];
									listaDePasajeros[j]=typeAux;
							}
					}else{
						if(listaDePasajeros[i].idtypePassenger > listaDePasajeros[j].idtypePassenger){
									typeAux=listaDePasajeros[i];
									listaDePasajeros[i]=listaDePasajeros[j];
									listaDePasajeros[j]=typeAux;
						}
					}
				}
			}
		}
	}
	return retorno;
}
void printPassenger(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int size){
	printf("   ID             APELLIDO                 NOMBRE                  PRECIO                  CODIGO              TIPO PASAJE                  STATUS        \n");
	printf("                                                                                                                                                          \n");

	for (int i=0;i<size;i++){
		MostrarPasajero(listaDePasajeros[i], estadodevueloid, typeid, size);
	}
	system("pause");
	limpiar();

}

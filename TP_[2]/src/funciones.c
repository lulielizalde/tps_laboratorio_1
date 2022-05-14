#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"

void CargarDatos (Passenger listaDePasajeros[], int size){
	int carga;
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;

	id = obtenerID();

	CargarCadena(name,"Ingrese su nombre ---> ","ERROR, Ingrese su nombre ---> ",1);
	CargarCadena(lastName,"Ingrese su apellido ---> ","ERROR, Ingrese su apellido ---> ",1);

	price = pedirFlotante( "Ingrese el precio del vuelo ---> ", "ERROR, Ingrese el precio del vuelo ---> ");

	CargarCadena(flycode,"Ingrese el codigo de vuelo ---> ","0",0);
	printf("Ingrese el tipo de pasajero (1) para primera clase y (2) para clase turista ---> ");
	scanf("%d", &typePassenger);

	while(typePassenger!=1 && typePassenger != 2){
		printf("Ingrese el tipo de pasajero (1) para primera clase y (2) para clase turista ---> ");
		scanf("%d", &typePassenger);
	}
	printf("Ingrese el estado de vuelo\n1.EN HORARIO\n2.DEMORADO\n3.CANCELADO ---> ");
	scanf("%d", &statusFlight);
	while(statusFlight!=1 && statusFlight != 2 && statusFlight!= 3){
		printf("Ingrese el estado de vuelo\n1.EN HORARIO\n2.DEMORADO\n3.CANCELADO ---> ");
		scanf("%d", &statusFlight);
	}

	 PasarAMayu (name);
	 PasarAMayu (lastName);

	carga = addPassengers (listaDePasajeros,id, name, lastName, price, flycode, typePassenger, statusFlight);

	if(carga == -1){
		printf("ERROR en la carga; falta espacio! \n");
	}else{
		printf("Se cargo todo correctamente! \n");
	}
}
int validacionDeCaracteres (char cadena[]){
	int size = strlen(cadena);
	int validacion=-1;
	for(int i=0;i<size;i++){
		if (isdigit(cadena[i])){
			validacion=0;
		}
	}
	return validacion;
}
int buscarEspacioLibre(Passenger listaDePasajeros[], int size){
    int rtn = -1;
    int indice;

    if(listaDePasajeros != NULL){
        if (size >= 0){
            for (indice = 0; indice < size; indice++){
                if(listaDePasajeros[indice].isEmpty == 0){
                    rtn = indice;
                    break;
                }
            }
        }
    }
    return rtn;
}
int obtenerID(){
	static int idIncremental = 1000;
	return idIncremental++;
}
int ModificarPasajero(Passenger listaDePasajeros[],int size){
	int idIngresado;
	int index;
	int opcion;
	int seguir = 1;

	printf("Ingrese el ID del pasajero ---> ");
	scanf("%d", &idIngresado);

	index = findPassengerById(listaDePasajeros, size, idIngresado);
	if(index == -1){
		printf("No se ha encontrado el ID\n");
		seguir = -1;
	}
	while(seguir == 1){
		int validacion;
		char name[51];
		char lastName[51];
		char price[20];
		int typePassenger;
		int statusFlight;
		limpiar();
		printf(     "______________________________\n"
				    "|                            |\n"
					"|      1) NOMBRE             |\n"
					"|      2) APELLIDO           |\n"
					"|      3) PRECIO             |\n"
					"|      4) TIPO DE PASAJERO   |\n"
					"|      5) CODIGO DE VUELO    |\n "
				    "|       6) ESTADO DE VUELO   |\n"
					"|      7) SALIR              |\n"
					"|____________________________|\n"

					"\n"
					"Ingrese una opcion ---> ");

			scanf("%d", &opcion);

			while(opcion < 1 || opcion > 7){
					printf("ERROR opcion no valida, Ingrese nuevamente una opcion ---> ");
					scanf("%d", &opcion);
				}

			switch(opcion){
				case 1:

					printf("Ingrese su nombre ---> \n");
					scanf("%s", name);
					validacion= validacionDeCaracteres(name);
					while(validacion==0){
						printf("Ingrese su nombre ---> (Utilice unicamente letras, porfavor.) \n");
						scanf("%s", name);
						validacion= validacionDeCaracteres(name);
					}
					strcpy(listaDePasajeros[index].name,name);
					break;
				case 2:

					printf("Ingrese su apellido --->\n ");
					scanf("%s", lastName);
					validacion= validacionDeCaracteres(lastName);
					while(validacion==0){
						printf("Ingrese su apellido ---> (Utilice unicamente letras, porfavor.)\n");
						scanf("%s", lastName);
						validacion= validacionDeCaracteres(lastName);
					}
					strcpy(listaDePasajeros[index].lastName,lastName);
					break;
				case 3:

					printf("Ingrese el precio del viaje ---> \n ");
					scanf("%s", price);
					validacion= validacionDeCaracteres(price);
					while(validacion==1){
							printf("Ingrese el precio del vuelo ---> (Utilice unicamente numeros, porfavor.): \n");
							scanf("%s", price);
							validacion= validacionDeCaracteres(price);
						}
						listaDePasajeros[index].price=atof(price);
					break;
				case 4:
					printf("Ingrese el tipo de pasajero ( 1 ) para primera clase y ( 2 ) para clase turista:\n ");
					scanf("%d", &typePassenger);
					while(typePassenger!=1 || typePassenger!=2){
						printf("Ingrese el tipo de pasajero ( 1 ) para primera clase y ( 2 ) para clase turista:\n ");
						scanf("%d", &typePassenger);
					}
					listaDePasajeros[index].idtypePassenger=typePassenger;
					break;
				case 5:
					printf("ingrese el codigo de vuelo:\n ");
					scanf("%s", listaDePasajeros[index].flycode);
					break;
				case 6:
					printf("ingrese el estado de vuelo\n1.EN HORARIO\n2.DEMORADO\n3.CANCELADO ---> ");
						scanf("%d", &statusFlight);
						while(statusFlight!=1 || statusFlight != 2 || statusFlight!= 3){
							printf("ingrese el tipo de pasajero (1) para primera clase y (2) para clase turista) ---> ");
							scanf("%d", &statusFlight);
						}
						listaDePasajeros[index].idStatusFlight=statusFlight;
					break;
				case 7:
					seguir=-1;
				break;
				}
	}
		return 0;
}
int validarNumero (char numeros[]){
	int validacion=-1;
	for(int i=0;i<strlen(numeros);i++){
		if(!(numeros[i]>=48 && numeros[i]<=57)){

			validacion=0;
		}
	}
	return validacion;
}
void PasarAMayu (char cadena []){
    int i;
    int size;

    size = strlen(cadena);
    strlwr(cadena);

    for(i= 0; i<size; i++){
        if(cadena[i-1]==32 || i==0){
        	cadena[i] = toupper(cadena[i]);
        }
    }
}
void MostrarPasajero(Passenger listaDePasajeros,eStatusFlight estadodevueloid[],eTypePassenger typeid[], int size){

	int indexType;
	int idexStatus;

	if(listaDePasajeros.isEmpty==1){

		idexStatus=descripcionStatusFlight( listaDePasajeros, estadodevueloid, 3);
		indexType=descripcionTypePassengerr( listaDePasajeros, typeid,  2);

		printf(
				"|  %2d   |      %12s      |        %8s       |    %10.2f   |      %10s     |      %15s       |      %13s     |\n"
				,listaDePasajeros.id ,listaDePasajeros.lastName,listaDePasajeros.name,listaDePasajeros.price,listaDePasajeros.flycode,typeid[indexType].typePassenger,estadodevueloid[idexStatus].StatusFlight);

	}
}
int descripcionStatusFlight(Passenger listaDePasajeros,eStatusFlight estadodevueloid[], int size){
	int index;

	for(int i=0;i<size;i++){
		if(listaDePasajeros.idStatusFlight==estadodevueloid[i].idStatusFlight){
			index=i;
			break;
		}
	}
	return index;
}
int descripcionTypePassengerr(Passenger listaDePasajeros,eTypePassenger typeid[], int size){
	int index;

	for(int i=0;i<size;i++){
		if(listaDePasajeros.idtypePassenger==typeid[i].idtypePassenger){
			index=i;
			break;
		}
	}
	return index;
}
void CargaForzada (Passenger listaDePasajeros[], int size){
	int id[] = {1000,1001,1002,1003,1004};
	char name[][51]={"Marco","Lionel","Irina","Lautaro"};
	char lastName[][51]= {"Valenzuela","Messi","Saccani","Sakihara"};
	float price[]={50000,25000,600,30000};
	char flycode[][10]={"ABC123","CBA321","ZZZ222","LM10LM"};
	int typePassenger[]={1,2,1,2};
	int statusFlight[]={1,3,2,1};

	for(int i=0;i<size;i++){
		listaDePasajeros[i].id=id[i];

		strcpy(listaDePasajeros[i].name,name[i]);
		strcpy(listaDePasajeros[i].lastName,lastName[i]);

		listaDePasajeros[i].price=price[i];

		strcpy(listaDePasajeros[i].flycode,flycode[i]);

		listaDePasajeros[i].idtypePassenger=typePassenger[i];
		listaDePasajeros[i].idStatusFlight=statusFlight[i];
		listaDePasajeros[i].isEmpty=1;
	}
	printf("---> SE CARGO EXITOSAMENTE <--- \n");
	system("pause");

}
float pedirFlotante(char mensaje[], char mensajeError[]){
    int retorno = -1;
    char numeroCadena[100];
    int validacion;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", numeroCadena);
	validacion = validarNumero(numeroCadena);
	while(validacion==0){
		printf("%s", mensajeError);
		scanf("%s", numeroCadena);
		validacion = validarNumero (numeroCadena);
		}

	retorno = atof(numeroCadena);

    return retorno;
}
int CargarCadena(char cadena[], char mensaje[], char mensajeError[], int validar){
    int retorno = -1;
    char buffer[256];
    int validacion;

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL){
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);

        if(validar==1){
		  validacion = validacionDeCaracteres (buffer);
		  while(validacion==0){
				printf("%s", mensajeError);
				scanf("%s", buffer);
				validacion = validacionDeCaracteres (buffer);
			}
        }
        strcpy(cadena, buffer);
        retorno = 0;
    }
    return retorno;
}
void limpiar(void){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


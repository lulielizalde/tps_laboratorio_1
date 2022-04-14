#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void menu(){

	fflush(stdin);
	setbuf(stdout, NULL);
	int opcion; // variable de tipo entero para determinar iteraciones.
	float x = 0; // ingreso de kilometros.
	float y = 0; // ingreso precio aerolineas.
	float z = 0; // ingreso precio latam.
	float precioDebitoAero = 0;
	float precioCreditoAero = 0;
	float bitcoinAero = 0;
	float precioUnitarioAero = 0;
	float precioDebitoLatam = 0;
	float precioCreditoLatam = 0;
	float bitcoinLatam = 0;
	float precioUnitarioLatam = 0;
	float diferenciaPrecio = 0;

	do {
		mostrarSeparador();
		printf("1- Ingresar kilometros: ");
		printf("\n2- Ingresar precios de Aerolineas y Latam: ");
		printf("\n3- Calcular todos los costos.");
		printf("\n4- Informar resultados.");
		printf("\n5- Carga forzada de datos.");
		printf("\n6- Salir.\n");
		mostrarSeparador();
		fflush(stdin);
		scanf("%d", &opcion);

		while(opcion > 6){
			printf("Porfavor, ingrese una opcion valida. Del 1 al 6.");
			scanf("%d", &opcion);
			limpiar();
		}
		switch(opcion){
		case 1:
			x = ingreseNumero("Ingrese los kilometros: ");
			limpiar();
			break;
		case 2:
			printf("Ingrese precio de sus vuelos: \n");
			y = ingreseNumero("Ingrese el precio por Aerolineas: ");
			z = ingreseNumero("Ingrese el precio por Latam: ");
			limpiar();
			break;
		case 3:
			if(opcion == 3 && x == 0 && y == 0 && z == 0){
				printf("Porfavor, ingrese valores para poder realizar las operaciones.");
				system("pause"); // el sistema espera que el usuario presione una tecla.
				limpiar();
			} else {
				precioDebitoAero = CalcularDebito(y);
				precioCreditoAero = CalcularCredito(y);
				bitcoinAero = CalcularBitcoin(y);
				precioUnitarioAero = CalcularPrecioUnitario(y, x);

				precioDebitoLatam = CalcularDebito(z);
				precioCreditoLatam = CalcularCredito(z);
				bitcoinLatam = CalcularBitcoin(z);
				precioUnitarioLatam = CalcularPrecioUnitario(z, x);

				diferenciaPrecio = CalcularDiferenciaPrecio(y, z);

				printf("Se calcularon todos los costos \n");
				system("pause");
				limpiar();
			}
			break;
		case 4:
			MostrarCostos(x, y, z, precioDebitoAero, precioCreditoAero, bitcoinAero, precioUnitarioAero, precioDebitoLatam, precioCreditoLatam, bitcoinLatam, precioUnitarioLatam, diferenciaPrecio);

			system("pause");
			limpiar();
			break;
		case 5:
			printf("Carga forzada: \n");
			x = 7090;
			y = 162965;
			z = 159339;

			precioDebitoAero = CalcularDebito(y);
			precioCreditoAero = CalcularCredito(y);
			bitcoinAero = CalcularBitcoin(y);
			precioUnitarioAero = CalcularPrecioUnitario(y, x);

			precioDebitoLatam = CalcularDebito(z);
			precioCreditoLatam = CalcularCredito(z);
			bitcoinLatam = CalcularBitcoin(z);
			precioUnitarioLatam = CalcularPrecioUnitario(z, x);

			diferenciaPrecio = CalcularDiferenciaPrecio(y, z);

			printf("\n A- Precio por Aerolineas: %f", y);
			printf("\n B- Precio con tarjeta de debito por Aerolineas: %f", precioDebitoAero);
			printf("\n C- Precio con tarjeta de credito por Aerolineas: %f", precioCreditoAero);
			printf("\n D- Precio en BITCOIN por Aerolineas: %f", bitcoinAero);
			printf("\n E- Precio Unitario por Aerolineas: %f", precioUnitarioAero);
			printf("\n");
			printf("\n A- Precio por Latam: %f", z);
			printf("\n B- Precio con tarjeta de debito por Latam: %f", precioDebitoLatam);
			printf("\n C- Precio con tarjeta de credito por Latam: %f", precioCreditoLatam);
			printf("\n D- Precio en BITCOIN por Latam: %f", bitcoinLatam);
			printf("\n E- Precio Unitario por Latam: %f", precioUnitarioLatam);
			printf("\n");
			printf("\n La diferencia de precio es: %f", diferenciaPrecio);

			system("pause");
			limpiar();
			break;
		case 6:
			printf("Saliendo. \n");
			break;
		}

	}while(opcion != 6);

}




#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define BITCOIN 4606954.55

void limpiar(void){
	printf("\n\n\n\n\n\n\n\n");
}
void mostrarSeparador(void){
	printf("==========================================\n");
}
float ingreseNumero(char mensaje[]){
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}
float CalcularDebito(float precioIngresado){
	float resultado;
	float descuento;

	descuento = 10;
	resultado = precioIngresado - (precioIngresado / 100 * descuento);
	return resultado;
}
float CalcularCredito(float precioIngresado){
	float resultado;
	float interes;
	float precioConAumento;

	interes = 25;
	precioConAumento = precioIngresado * interes / 100;
	resultado = precioIngresado + precioConAumento;
	return resultado;
}
float CalcularBitcoin(float precioIngresado){
	float resultado;

	resultado = precioIngresado / BITCOIN;
	return resultado;
}
float CalcularPrecioUnitario(float precioIngresado, float x){
	float resultado;

	resultado = precioIngresado / x;
	return resultado;
}
float CalcularDiferenciaPrecio(float y, float z){
	float resultado;

	if (z > y){
		resultado = z - y;
	} else {
	resultado = y - z;
	}

	return resultado;
}
void MostrarCostos(float x, float y, float z, float precioDebitoAero, float precioCreditoAero, float bitcoinAero, float precioUnitarioAero, float precioDebitoLatam, float precioCreditoLatam, float bitcoinLatam, float precioUnitarioLatam, float diferenciaPrecio){
	if(x == 0 && y == 0 && z == 0 && precioDebitoAero == 0 && precioCreditoAero == 0 && bitcoinAero == 0 && precioUnitarioAero == 0 && precioDebitoLatam == 0 && precioCreditoLatam == 0 && bitcoinLatam == 0 && precioUnitarioLatam == 0 && diferenciaPrecio == 0){
		printf("Porfavor, ingrese datos para poder mostrar. \n");
	} else {
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
	}
}


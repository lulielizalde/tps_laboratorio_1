
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// @brief aborda el switch con el menu de opciones.
///
void menu();
/// @brief limpia la consola.
///
void limpiar(void);
/// @brief luego de limpiar la consola, muestra un separador con las opciones.
///
void mostrarSeparador(void);
/// @brief funcion para pedir numero.
///
/// @param mensaje
/// @return el numero que se ingreso.
float ingreseNumero(char mensaje[]);
/// @brief funcion para el costo de la tarjeta de debito.
///
/// @param precioIngresado
/// @return el precio con tarjeta de credito.
float CalcularDebito(float precioIngresado);
/// @brief funcion para el costo de la tarjeta de credito.
///
/// @param precioIngresado
/// @return el precio con tarjeta de credito.
float CalcularCredito(float precioIngresado);
/// @brief funcion para el precio con bitcoin.
///
/// @param precioIngresado
/// @return precio con bitcoin.
float CalcularBitcoin(float precioIngresado);
/// @brief funcion de costo por kilometros.
///
/// @param precioIngresado
/// @param km
/// @return costo por kilometros.
float CalcularPrecioUnitario(float precioIngresado, float km);
/// @brief funcion para determinar por una resta la diferencia entre precios.
///
/// @param y
/// @param z
/// @return numero resultado de la resta.
float CalcularDiferenciaPrecio(float y, float z);
/// @brief funcion para mostrar los costos, y en caso de no ser ingresados, pedir que se haga.
///
/// @param x
/// @param y
/// @param z
/// @param precioDebitoAero
/// @param precioCreditoAero
/// @param bitcoinAero
/// @param precioUnitarioAero
/// @param precioDebitoLatam
/// @param precioCreditoLatam
/// @param bitcoinLatam
/// @param precioUnitarioLatam
/// @param diferenciaPrecio
void MostrarCostos(float x, float y, float z, float precioDebitoAero, float precioCreditoAero, float bitcoinAero, float precioUnitarioAero, float precioDebitoLatam, float precioCreditoLatam, float bitcoinLatam, float precioUnitarioLatam, float diferenciaPrecio);




#endif /* FUNCIONES_H_ */

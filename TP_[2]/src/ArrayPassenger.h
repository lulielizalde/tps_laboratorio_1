#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TAM 2000

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idtypePassenger;
	int isEmpty;
	int idStatusFlight;

}typedef Passenger;

struct
{
	int idtypePassenger;
	char typePassenger[20];

}typedef eTypePassenger;

struct
{
	int idStatusFlight;
	char StatusFlight[20];

}typedef eStatusFlight;

Passenger listaDePasajeros[TAM];

/// @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
///
/// @param listaDePasajeros
/// @param size
/// @return
int initPassengers (Passenger listaDePasajeros[],int size);
/// @brief add in a existing list of passengers the values received as parameters in the first empty position
///
/// @param listaDePasajeros
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param flycode
/// @param typePassenger
/// @param statusFlight
/// @return
int addPassengers (Passenger listaDePasajeros[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight);
/// @brief find a Passenger by Id en returns the index position in array.
///
/// @param listaDePasajeros
/// @param size
/// @param id
/// @return
int findPassengerById(Passenger listaDePasajeros[], int size,int id);
/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
///
/// @param listaDePasajeros
/// @param size
/// @param id
/// @return
int removePassenger(Passenger listaDePasajeros[], int size, int id);
/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param listaDePasajeros
/// @param size
/// @param order
/// @return
int sortPassengers(Passenger listaDePasajeros[], int size, int order);
/// @brief print the content of passengers array
///
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param size
void printPassenger(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int size);

/* */

/// @brief limpia la consola
///
void limpiar();
/// @brief
///
/// @param listaDePasajeros
/// @param size
void CargarDatos (Passenger listaDePasajeros[],int size);
/// @brief
///
/// @param cadena
/// @return
int validacionDeCaracteres (char cadena[]);
/// @brief
///
/// @param listaDePasajeros
/// @param size
/// @return
int buscarEspacioLibre(Passenger listaDePasajeros[], int size);
/// @brief
///
/// @return
int obtenerID();
/// @brief
///
/// @param listaDePasajeros
/// @param size
/// @return
int ModificarPasajero(Passenger listaDePasajeros[],int size);
/// @brief
///
/// @param numeros
/// @return
int validarNumero (char numeros[]);
/// @brief
///
/// @param cadena
void PasarAMayu (char cadena []);
/// @brief
///
/// @param mensaje
/// @param mensajeError
/// @return
float pedirFlotante(char mensaje[], char mensajeError[]);
/// @brief
///
/// @param cadena
/// @param mensaje
/// @param mensajeError
/// @param validar
/// @return
int CargarCadena(char cadena[], char mensaje[], char mensajeError[], int validar);
/// @brief
///
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param size
void MostrarPasajero(Passenger listaDePasajeros,eStatusFlight estadodevueloid[],eTypePassenger typeid[], int size);
/// @brief
///
/// @param listaDePasajeros
/// @param typeid
/// @param size
/// @return
int descripcionTypePassengerr(Passenger listaDePasajeros,eTypePassenger typeid[], int size);
/// @brief
///
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param size
/// @return
int descripcionStatusFlight(Passenger listaDePasajeros,eStatusFlight estadodevueloid[], int size);
/// @brief carga forzada de datos
///
/// @param listaDePasajeros
/// @param size
void CargaForzada (Passenger listaDePasajeros[], int size);

#endif /* ARRAYPASSENGER_H_ */

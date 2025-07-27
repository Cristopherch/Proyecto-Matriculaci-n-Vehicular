#ifndef MIVEHICULO_H
#define MIVEHICULO_H

#define VEHICULOS_MAX 100


extern int numVehiculo;

typedef struct{
	char placa[9];
	char cedula[12];
	char tipo[VEHICULOS_MAX];
	int anio;
	double avaluo;
}Vehiculo;

Vehiculo registroVehicular(const char* placa, const char* cedula, const char* tipo, int anio, double avaluo);

void imprimirVehiculo(Vehiculo registrado);

void imprimirTodosVehiculo(Vehiculo lista[]);

void menuVehicular();

void metodoPago();

int busquedaPlaca(Vehiculo placaBuscada[],char placaBusqueda[]);

void horaActual(char* hora, int longitud);

int guardarDatos(Vehiculo lista[], char* hora);


#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mivehiculo.h"
#include "matricular.h"
#define VEHICULOS_MAX 100

int numVehiculo = 0;

Vehiculo registroVehicular(const char* placa, const char* cedula, const char* tipo, int anio, double avaluo){
	Vehiculo anadirVehiculo;

	strncpy(anadirVehiculo.placa, placa, VEHICULOS_MAX - 1);
	anadirVehiculo.placa[VEHICULOS_MAX- 1] = '\0';

	strncpy(anadirVehiculo.cedula, cedula, VEHICULOS_MAX - 1);
	anadirVehiculo.cedula[VEHICULOS_MAX - 1] = '\0';

	strncpy(anadirVehiculo.tipo, tipo, VEHICULOS_MAX - 1);
	anadirVehiculo.tipo[VEHICULOS_MAX - 1] = '\0';

	anadirVehiculo.anio = anio;
	anadirVehiculo.avaluo = avaluo;
	
	return anadirVehiculo;
}


void imprimirVehiculo(Vehiculo registrado){
	printf("Placa: %s \n", registrado.placa);
	printf("Cedula: %s \n", registrado.cedula);
	printf("Tipo: %s\n", registrado.tipo);
	printf("Año: %d \n", registrado.anio);
	printf("Avaluo: %.2lf \n", registrado.avaluo);
}

void imprimirTodosVehiculo(Vehiculo lista[]){
	if (numVehiculo == 0){
	printf("No hay vehiculos registrados");
	} else {
		printf("\n==================================================");
		printf("\n             Vehiculos Registrados              \n");
		printf("==================================================\n");
		for (int i = 0; i < numVehiculo; i++){
			printf("Vehiculo %d:\n", i + 1);
			imprimirVehiculo(lista[i]);
		}
	}
	printf("\n-----Fin de la lista-----\n");
}

int busquedaPlaca(Vehiculo placaBuscada[],char placaBusqueda[]){
	if (numVehiculo == 0){
		printf("No hay vehiculos registrados\n");
		return -1;
	}
	for (int i = 0; i < numVehiculo; i++){
		if (strcmp(placaBuscada[i].placa, placaBusqueda) == 0){
			return i;
		}
	}
	return -1;
}

int guardarDatos(Vehiculo lista[]){
	FILE *archivo = fopen("datosVehiculares.txt", "w");
		
	if (archivo == NULL){
		printf("No se pudo abrir el archivo");
		return 1;
	}
		
	for (int i = 0; i < numVehiculo; i++){
		fprintf(archivo, "Placa: %s\nCedula: %s\nTipo: %s\nAño: %d\nAvaluo: %.2lf\n", lista[i].placa, lista[i].cedula, lista[i].tipo, lista[i].anio, lista[i].avaluo);
	}
		
	fclose(archivo);
	printf("Los datos se guardaron correctamente");
	return 0;
}

void menuVehicular(){
	printf("\n================================================");
	printf("\n                REGISTRO VEHICULAR            \n");
	printf("================================================\n");
	printf("1. Registrar datos del vehiculo\n");
	printf("2. Calcular matricula\n");
	printf("3. Buscar vehículo por placa\n");
	printf("4. Imprimir listado de vehiculos matriculados\n");
	printf("5. Salir\n");
}



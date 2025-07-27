#ifndef MATRICULAR_H
#define MATRICULAR_H

#include "mivehiculo.h"

#define VEHICULOS_MAX 100

typedef struct{
	int tasaMatricula;
	double impuestoVehicular;
	double impuestoRodaje;
	double rtv[2];
	double recargos;
	double multas;
	double retrasoMatriculacion;
	double totalMatricula;
}Matriculacion;

Matriculacion arregloMatricula(int tasaMatricula, double impuestoVehicular, double impuestoRodaje, double rtv, double recargos, double multas, double retrasoMatriculacion);

double calcularYMostrarMatricula(Vehiculo vehiculo, int revisionesCumplidas, int mesesRetraso, double multas, Matriculacion *matricula);

double calcularTotalMatricula(Matriculacion *matricula);

int asginarPosicionMatricula(Matriculacion posicionMatricula[], int pos, Matriculacion posicionMatricular);

int guardarDatosVehiculares(Vehiculo lista[], Matriculacion *matricula, int posicion, double totalMatricula, char* hora);

#endif

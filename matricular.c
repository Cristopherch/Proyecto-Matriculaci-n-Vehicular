#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "matricular.h"
#include "mivehiculo.h"
#include "logerrores.h"
#define VEHICULOS_MAX 100

Matriculacion arregloMatricula(int tasaMatricula, double impuestoVehicular, double impuestoRodaje, double rtv, double recargos, double multas, double retrasoMatriculacion){
	Matriculacion matriculaVehiculo;
	
	matriculaVehiculo.tasaMatricula = tasaMatricula;
	
	matriculaVehiculo.impuestoVehicular = impuestoVehicular;
	
	matriculaVehiculo.impuestoRodaje = impuestoRodaje;
	
	matriculaVehiculo.rtv[0] = rtv;
	
	matriculaVehiculo.rtv[1] = rtv;
	
	matriculaVehiculo.recargos = recargos;
	
	matriculaVehiculo.multas = multas;
	
	matriculaVehiculo.retrasoMatriculacion = retrasoMatriculacion;
	
	
	return matriculaVehiculo;
	
}
	
double calcularTotalMatricula(Matriculacion *matricula) {
	return matricula->impuestoVehicular + matricula->impuestoRodaje + matricula->recargos + matricula->multas + matricula->retrasoMatriculacion;
}	
	
int asginarPosicionMatricula(Matriculacion posicionMatricula[], int pos, Matriculacion posicionMatricular){
	posicionMatricula[pos] = posicionMatricular;
	return 1;
}

double calcularYMostrarMatricula(Vehiculo vehiculo, int revisionesCumplidas, int mesesRetraso, double multas, Matriculacion *matricula) {
	
	char hora[40];
	horaActual(hora, sizeof(hora));
	
	int tasaMatricula = (strcmp(vehiculo.tipo, "liviano") == 0)? 2 : 5; // % para liviano, 5% para pesado
	double impuestoVehicular = vehiculo.avaluo * (tasaMatricula / 100.0);
	double impuestoRodaje = (strcmp(vehiculo.tipo, "pesado") == 0) ? 300.0 : 100.0; // Fijo según tipo
	// Asignar revisiones técnicas
	double rtv1 = (revisionesCumplidas > 0) ? 1 : 0; // Suponiendo que hay al menos una revisión cumplida
	double rtv2 = (revisionesCumplidas > 1) ? 1 : 0; // Suponiendo que hay al menos dos revisiones cumplidas
	
	double recargos = (2 - (rtv1 + rtv2)) * (0.05 * impuestoVehicular); // Recargos por revisiones
	double retrasoMatriculacion = mesesRetraso * 25.0; // Suponiendo que no hay retraso
			
	matricula->tasaMatricula = tasaMatricula;
	matricula->impuestoVehicular = impuestoVehicular;
	matricula->impuestoRodaje = impuestoRodaje;
	matricula->rtv[0] = rtv1;
	matricula->rtv[1] = rtv2;
	matricula->recargos = recargos;
	matricula->multas = multas;
	matricula->retrasoMatriculacion = retrasoMatriculacion;
	
	double totalMatricula = calcularTotalMatricula(matricula);
	
	// Imprimir comprobante con todos los datos y total
	printf("\n==========================================");
	printf("\n        Comprobante de Matriculacion      \n");
	printf("==========================================\n");
	printf("%s\n", hora);
	printf("Cédula: %s\n", vehiculo.cedula);
	printf("Año: %d\n", vehiculo.anio);
	printf("Tipo: %s\n", vehiculo.tipo);
	printf("Avalúo: %.2lf\n", vehiculo.avaluo);
	printf("Impuesto Vehicular: %.2lf\n", matricula->impuestoVehicular);
	printf("Impuesto Rodaje: %.2lf\n", matricula->impuestoRodaje);
	printf("Revisiones Técnicas (RTV1, RTV2): %.0lf, %.0lf\n", matricula->rtv[0], matricula->rtv[1]);
	printf("Recargos: %.2lf\n", matricula->recargos);
	printf("Multas: %.2lf\n", matricula->multas);
	printf("Retraso Matriculacion: %.2lf\n", matricula->retrasoMatriculacion);
	printf("\n=========================================\n");
	printf("Valor Total a Pagar Matrícula: %.2lf\n", totalMatricula);
	printf("=========================================\n\n");
	
	return totalMatricula;
}



int guardarDatosVehiculares(Vehiculo lista[], Matriculacion *matricula, int posicion, double totalMatricula, char* hora){
	
	FILE *archivo = fopen("datosVehicularesMatriculacion.txt", "a");
	
	if (archivo == NULL){
		printf("No se pudo abrir el archivo");
		errorLog("No se pudo abrir el archivo datosVehicularesMatriculacion.txt");
		return 1;
	}
	
	fprintf(archivo, "\n--------------MATRICULAS--------------\n");
	fprintf(archivo, "======================================\n");
	fprintf(archivo, "PLACA: %s\nCEDULA: %s\nTIPO: %s\nAÑO: %d\nAVALUO: %.2lf\n",
			lista[posicion].placa,
			lista[posicion].cedula,
			lista[posicion].tipo,
			lista[posicion].anio,
			lista[posicion].avaluo);
	fprintf(archivo, "IMPUESTO VEHICULAR: %.2lf\nIMPUESTO RODAJE: %.2lf\nREVISIONES TÉCNICAS(RTV1, RTV2): %.0lf, %0lf	\nRECARGOS: %.2lf\nMULTAS: %.2lf\nRETRASO MATRICULACION: %.2lf\n",
			matricula->impuestoVehicular,
			matricula->impuestoRodaje,
			matricula->rtv[0], matricula->rtv[1],
			matricula->recargos,
			matricula->multas,
			matricula->retrasoMatriculacion);
	fprintf(archivo, "---------------------------------------\n");
	fprintf(archivo, "\nTotal a pagar de la matricula %.2lf\n", totalMatricula);
	fprintf(archivo, "---------------------------------------\n");
	fprintf(archivo, "GUARDADO DE MATRICULA: %s\n", hora);
	fprintf(archivo, "======================================\n");
	fclose(archivo);
	printf("Los datos se guardaron correctamente.\n");
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "matricular.h"
#include "mivehiculo.h"
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
	
double calcularYMostrarMatricula(Vehiculo vehiculo, int revisionesCumplidas, int mesesRetraso, double multasUsuario, Matriculacion *matricula) {
	int tasaMatricula = (strcmp(vehiculo.tipo, "liviano") == 0)? 2 : 5; // % para liviano, 5% para pesado
	double impuestoVehicular = vehiculo.avaluo * (tasaMatricula / 100.0);
	double impuestoRodaje = (strcmp(vehiculo.tipo, "pesado") == 0) ? 300.0 : 100.0; // Fijo según tipo
	// Asignar revisiones técnicas
	double rtv1 = (revisionesCumplidas > 0) ? 1 : 0; // Suponiendo que hay al menos una revisión cumplida
	double rtv2 = (revisionesCumplidas > 1) ? 1 : 0; // Suponiendo que hay al menos dos revisiones cumplidas
	
	double recargos = (2 - (rtv1 + rtv2)) * (0.05 * impuestoVehicular); // Recargos por revisiones
	double multas = ((rtv1 + rtv2) ==0) ? 100.0 : 0; // Multa si no hay revisiones
	double retrasoMatriculacion = mesesRetraso * 25.0; // Suponiendo que no hay retraso
			
	matricula->tasaMatricula = tasaMatricula;
	matricula->impuestoVehicular = impuestoVehicular;
	matricula->impuestoRodaje = impuestoRodaje;
	matricula->rtv[0] = rtv1;
	matricula->rtv[1] = rtv2;
	matricula->recargos = recargos;
	matricula->multas = multasUsuario;
	matricula->retrasoMatriculacion = retrasoMatriculacion;
	
	double totalMatricula = calcularTotalMatricula(matricula);
	
	// Imprimir comprobante con todos los datos y total
	printf("\n==========================================");
	printf("\n        Comprobante de Matriculacion      \n");
	printf("==========================================\n");
	printf("Cédula: %s\n", vehiculo.cedula);
	printf("Año: %d\n", vehiculo.anio);
	printf("Tipo: %s\n", vehiculo.tipo);
	printf("Avalúo: %.2lf\n", vehiculo.avaluo);
	printf("Impuesto Vehicular: %.2lf\n", matricula->impuestoVehicular);
	printf("Impuesto Rodaje: %.2lf\n", matricula->impuestoRodaje);
	printf("Revisiones Técnicas (RTV1, RTV2): %.0lf, %.0lf\n", matricula->rtv[0], matricula->rtv[1]);
	printf("Recargos: %.2lf\n", matricula->recargos);
	printf("Multas: %.2lf\n", matricula->multas);
	printf("Retraso Matriculación: %.2lf\n", matricula->retrasoMatriculacion);
	printf("\n=========================================\n");
	printf("Valor Total a Pagar Matrícula: %.2lf\n", totalMatricula);
	printf("=========================================\n\n");
	
	return totalMatricula;
}



int guardarDatosVehiculares(Vehiculo lista[], Matriculacion *matricula, int posicion, double totalMatricula){
	
	FILE *archivo = fopen("datosVehicularesMatriculacion.txt", "a");
	
	if (archivo == NULL){
		printf("No se pudo abrir el archivo");
		return 1;
	}
	
	fprintf(archivo, "Placa: %s\nCedula: %s\nTipo: %s\nAño: %d\nAvalúo: %.2lf\nImpuesto Vehicular: %.2lf\nImpuesto Rodaje: %.2lf\nRevisiones Tecnicas(RTV1, RTV2): %.0lf, %0lf	\nRecargos: %.2lf\nMultas: %.2lf\nRetaso Matriculacion: %.2lf\nTotal a pagar de la matricula %.2lf\n\n\n", 
			lista[posicion].placa,
			lista[posicion].cedula,
			lista[posicion].tipo,
			lista[posicion].anio,
			lista[posicion].avaluo,
			matricula->impuestoVehicular,
			matricula->impuestoRodaje,
			matricula->rtv[0], matricula->rtv[1],
			matricula->recargos,
			matricula->multas,
			matricula->retrasoMatriculacion,
			totalMatricula);
	
	fclose(archivo);
	printf("Los datos se guardaron correctamente.\n");
	return 0;
}

#include "mivehiculo.h"
#include "validaciones.h"
#include "matricular.h"
#include "usuario.h"
#include "logerrores.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main() {
	Vehiculo listaVehicular[100];
	char placa[20], cedula[25], tipo[VEHICULOS_MAX], placaBusqueda[20], hora[50];
	int opcion, anio, existencia, validaContra, validacionCampo, validacionLetra, validacionSigno, validacionNumero, validacionCe, validacionTi, validarAnio, validarAvaluo, placaEncontrada;
	int metodoPago;
	double avaluo, avaluoTemp, totalMatricula;
	Matriculacion matricula;
	char contrasena[50], entrada[10], entrada1[10], respuesta[10], respuesta3[10], respuesta1[10], respuesta2[10], anio1[20], avaluo1[20], multas1[20];
	
	while(1){
		printf("\n==================================================");
		printf("\n   BIENVENIDO AL SISTEMA DE MATRICULACION 2025   \n"); //Menú de inicio de sesión antes de ingresar al menú vehicular
		printf("==================================================\n");
		printf("               Inicio de sesion            \n\n");
		do{
			printf("=================================================\n");
			printf("USUARIO:\n");
			printf("-------------------------------------------------\n");
			printf("Ingrese Cedula (Ejemplo: 1234567890):");
			fgets(cedula, sizeof(cedula), stdin);
			cedula[strcspn(cedula, "\n")] = '\0';
			validacionCe = validacionCedula(cedula);
			
			if (validacionCe == 0){
				system("cls");
				printf("ERROR: campo incompleto y solo debe tener 10 digitos\n");
			}
			
		} while(validacionCe == 0 );
				
		do {
			printf("\n-------------------------------------------------\n");
			printf("CONTRASENA:\n");
			printf("-------------------------------------------------\n");
			printf("Ingrese su contraseña (8-10 caracteres): ");
			scanf("%s", contrasena);
			getchar();
			validaContra = validacionContrasena(contrasena);//recibe el número que retorna la función
			if (validaContra == 0){
				printf("La contraseña debe tener de 8 a 10 caracteres.\n");//Si es 0 entonces la contraseña ingresada no era de la forma correcta
			}
			
		} while(validaContra == 0);
		
		system("cls");
		
		existencia = validacionUsuario(cedula, contrasena);//retrona el valor de la función
		if (existencia == 1){
			system("cls");
			printf("\n================================\n");
			printf("    Inicio de sesion exitoso    \n");//Si es 1 entonces el correo y contraseña ingresadas existen y esta registrados
			printf("================================\n");
			printf("Presione Enter para continuar...\n");
			while(getchar() != '\n');
			system("cls");
			
			do {
				menuVehicular();
				do {
					printf("Ingrese una opcion (1-5): ");
					fgets(entrada, sizeof(entrada), stdin);
					
					// Eliminar el salto de línea
					entrada[strcspn(entrada, "\n")] = '\0';
					
					// Comprobar que solo tiene un carácter numérico entre '1' y '6'
					if (strlen(entrada) == 1 && entrada[0] >= '1' && entrada[0] <= '5') {
						opcion = entrada[0] - '0'; // Convertir carácter a número
						break;
					} else {
						printf("Error: debe ingresar un numero del 1 al 6.\n");
					}
				} while (1);
				
				switch(opcion){
				case 1:
					system("cls");
					printf("\n==========================================");
					printf("\n       Registro de Nuevo Vehiculo       \n");
					printf("===========================================\n");
					
					do{
						printf("\nIngrese Placa (Ejemplo: ABC-1234): ");
						fgets(placa, sizeof(placa), stdin);
						aMayusculas(placa);
						
						validacionCampo = validacionCampoPlaca(placa);
						validacionLetra = validacionLetraPlaca(placa);
						validacionSigno = validacionSignoPlaca(placa);
						validacionNumero = validacionNumeroPlaca(placa);
						if (validacionCampo == 0){
							printf("ERROR: no ha completado el campo\n");
						}
						if (validacionLetra == 0){
							printf("ERROR: no introdujo letras primero\n");
						}
						if (validacionSigno == 0){
							printf("ERROR: no ha ingresado el signo guión\n");
						}
						if (validacionNumero == 0){
							printf("ERROR: no ha ingresado digitos en las últimas 3 posiciones\n");
						}
					} while(validacionLetra == 0 || validacionSigno == 0 || validacionNumero == 0);
					
					do{
						printf("Ingrese Tipo de vehículo (liviano o pesado): ");
						fgets(tipo, sizeof(tipo), stdin);
						tipo[strcspn(tipo, "\n")] = '\0';
						aMinusculas(tipo);
						
						validacionTi = validacionTipo(tipo);
						if (validacionTi == 0){
							printf("No ha ingresado el tipo de vehículo\n");
						}
					} while(validacionTi == 0);
					
					
					do{
						printf("Ingrese el año(2000 a 2025): ");
						fgets(anio1, sizeof(anio1), stdin);
						validarAnio = esNumero(anio1);
						if (validarAnio == 0){
							printf("ERROR: año invalido\n");
							continue;
						}
						
						anio = atoi(anio1);
						if (anio == 0 && anio1[0] != '0') {
							errorLog("Conversión inválida de cadena a número");
						}
						
						if (anio < 2000 || anio > 2025){
							printf("El año debe ser entre 2000 y 2025.\n");
							validarAnio = 0;
							continue;
						}
					} while(validarAnio == 0);
					
					
					do{
						printf("Ingrese el avalúo ($2000.00 hasta $400000.00):");
						fgets(avaluo1, sizeof(avaluo1), stdin);
						avaluo1[strcspn(avaluo1, "\n")] = '\0';
						validarAvaluo = esNumero(avaluo1);
						if (validarAvaluo == 0){
							printf("ERROR: avaluo invalido\n");
							continue;
						}
						
						avaluo = atof(avaluo1);
						if (avaluo == 0 && avaluo1[0] != '0') {
							errorLog("Conversión inválida de cadena a número");
							validarAvaluo = 0;
							continue;
						}
						
						avaluoTemp = validacionAvaluo(avaluo);
						if (avaluoTemp == 0){
							printf("El avaluó no cumple con las condiciones.\n");
							validarAvaluo = 0;
							continue;
						}
					} while(validarAvaluo == 0);
					
					
					if (numVehiculo >= VEHICULOS_MAX) {
						printf("La lista de vehiculos esta llena. No se puede registrar mas.\n");
					} else {
						listaVehicular[numVehiculo] = registroVehicular(placa, cedula, tipo, anio, avaluo);
						numVehiculo++;
					}
					
					system("cls");//limpiar pantalla
					
					printf("\n==================================================");
					printf("\n   LOS DATOS SE HAN REGISTRADO CORRECTAMENTE   \n");
					printf("==================================================\n");
					printf("Presione Enter para continuar...\n");
					while (getchar() != '\n');
					system("cls");
					break;
				case 2:
					system("cls");
					printf("==================================================================================\n");
					printf("                                CALCULAR MATRICULA                                \n");
					printf("==================================================================================\n");
					// Imprimir comprobante de matrícula para un vehículo específico
					printf("Ingrese placa del vehiculo para calcular matrícula (Ejemplo: ABC-1234): ");
					fgets(placaBusqueda, sizeof(placaBusqueda), stdin);
					aMayusculas(placaBusqueda);
					placaBusqueda[strcspn(placaBusqueda, "\n")] = '\0';
					
					placaEncontrada = busquedaPlaca(listaVehicular, placaBusqueda);
					if (placaEncontrada == -1) {
						printf("---------------------------------------------------------------------");
						printf("\nVehiculo con placa '%s' no encontrado, saldra al menu principal.\n", placaBusqueda);
						printf("Presione Enter...");
						while (getchar() != '\n'); // Limpiar buffer
						system("cls");
						break;
					} else {
						Vehiculo vehiculo = listaVehicular[placaEncontrada];
						
						// Solicitar número de revisiones técnicas cumplidas
						int revisionesCumplidas;
						do {
							printf("Ingrese numero de revisiones técnicas cumplidas (0 - 2): ");
							if (scanf("%d", &revisionesCumplidas) != 1) {
								printf("Entrada invalida. Por favor, ingrese un numero.\n");
								while(getchar() != '\n'); // Clear the input buffer
								continue;
							}
							
							if (revisionesCumplidas == 0) {
								while (getchar() != '\n');
								printf("\n---------------------------------------------------------------------");
								printf("\nERROR: El vehículo debe tener al menos 1 revisión técnica cumplida\n");
								printf("El proceso de matriculación no puede continuar.\n");
								printf("----------------------------------------------------------------------\n");
								printf("Presione Enter...");
								while (getchar() != '\n'); // Limpiar buffer
								system("cls");
								break; // Salir del case sin continuar
							}
							
							if (revisionesCumplidas < 0 || revisionesCumplidas > 2) {
								printf("Numero invalido, debe estar entre 0 y 2.\n");
							} else {
								break;
							}
						} while (1);
						
						if(revisionesCumplidas == 0) {
							continue; // Regresa al menú principal
						}
						
						// Resto del proceso de matriculación solo si hay revisiones >= 1
						while(getchar() != '\n'); // Limpiar buffer
						
						int mesesRetraso;
						do {
							printf("Ingrese los meses de retraso en la matriculación (0 - 12): ");
							if (scanf("%d", &mesesRetraso) != 1) {
								printf("Entrada inválida. Por favor, ingrese un número.\n");
								while(getchar() != '\n'); // Clear the input buffer
								continue;
							}
							if (mesesRetraso < 0 || mesesRetraso > 12) {
								printf("Meses inválidos, debe ser 0 - 12.\n");
							} else {
								break;
							}
						} while (1);
						
						while(getchar() != '\n');
						
						double multas;
						do {
							printf("Ingrese el valor de las multas ($0 a $4600): ");
							if (fgets(multas1, sizeof(multas1), stdin) == NULL){
								printf("Entrada no valida. Intente de nuevo.\n");
								continue;
							}
							
							if (!doubleValido(multas1)){
								printf("Ingrese un valor válido.\n");
								continue;
							}
							
							multas = strtod(multas1, NULL);
							
							if (multas < 0 || multas > 4600){
								printf("Valor fuera del límite, ingrese un valor válido. \n");
								continue;
							}
							break;
						} while(1);
						
						system("cls");
						
						totalMatricula = calcularYMostrarMatricula(vehiculo, revisionesCumplidas, mesesRetraso, multas, &matricula);
						
						do{
							printf("¿DESEA PAGAR LA MATRICULA AHORA?(s/n)\n");
							fgets(respuesta3, sizeof(respuesta3), stdin);
							
							if (respuesta3[0] == 's' || respuesta3[0] == 'S'){
								printf("------------------------------\n");
								printf("SELECCIONE METODO DE PAGO: \n");
								printf("1. Efectivo\n");
								printf("2. Transferencia\n");
								do {
									printf("Ingrese una opcion (1-2): ");
									fgets(entrada1, sizeof(entrada1), stdin);
									
									// Eliminar el salto de línea
									entrada1[strcspn(entrada1, "\n")] = '\0';
									
									// Comprobar que solo tiene un carácter numérico entre '1' y '2'
									if (strlen(entrada1) == 1 && entrada[0] >= '1' && entrada1[0] <= '2') {
										metodoPago = entrada1[0] - '0'; // Convertir carácter a número
										break;
									} else {
										printf("Error: debe ingresar un numero del 1 al 2\n");
									}
								} while (1);
								
								switch(metodoPago){
								case 1: 
									printf("------------------------------\n");
									printf("Acerquese a pagar a caja...\n");
									printf("------------------------------\n");
									break;
								case 2:
									printf("---------------------------------\n");
									printf("Esperando confirmación de pago...\n");
									printf("---------------------------------\n");
									break;
								default:
									printf("Opcion invalida");
									break;
								}
								
								
								printf("------------------------\n");
								printf("    PAGO CONFIRMADO    \n");
								printf("-----------------------\n");
								printf("Presione Enter...\n");
								getchar();
								
								break;
							}else if (respuesta3[0] == 'n' || respuesta3[0] == 'N'){
									printf("\n==============================================================================\n");
									printf("    RECUERDE QUE TIENE UN PLAZO DE 15 DIAS PARA PAGAR EL VALOR DE LA MATRICULA  \n");
									printf("================================================================================\n");
									printf("Presione Enter...");
									getchar();
									system("cls");
									break;
							} else {
								printf("Intente de nuevo.\n");
							}
						} while(respuesta3[0] != 's' && respuesta3[0] != 'S' && respuesta3[0] != 'n' && respuesta3[0] != 'N');
						
						do{
							printf("¿Desea guardar los datos?(s/n):\n");
							fgets(respuesta, sizeof(respuesta), stdin);
							
							system("cls");
							
							if (respuesta[0] == 's' || respuesta[0] == 'S'){
								system("cls");
								horaActual(hora, sizeof(hora));
								printf("\n=======================================\n");
								guardarDatosVehiculares(listaVehicular, &matricula, placaEncontrada, totalMatricula, hora);
								printf("=======================================\n");
								printf("Presione Enter...");
								while (getchar() != '\n');
								system("cls");
							} else if (respuesta[0] == 'n' || respuesta[0] == 'N'){
								system("cls");
								printf("\n===========================\n");
								printf("    Datos no guardados    \n");
								printf("=========================\n");
								printf("Presione Enter...");
								while (getchar() != '\n');
								system("cls");
								break;
								
							} else {
								system("cls");
								printf("Intentelo de nuevo.\n");
							}
							break;
						} while(respuesta[0] != 's' && respuesta[0] != 'S' && respuesta[0] != 'n' && respuesta[0] != 'N');
					}
					break;
					
				case 3:
					system("cls");
					printf("\n===========================================\n");
					printf("          BUSQUEDA DE VEHICULOS          \n");
					printf("===========================================\n");
					printf("Ingrese la placa del vehiculo que desea buscar (Ejemplo: ABC-1234):\n");
					fgets(placaBusqueda, sizeof(placaBusqueda), stdin);
					placaBusqueda[strcspn(placaBusqueda, "\n")] = '\0';
					
					placaEncontrada = busquedaPlaca(listaVehicular, placaBusqueda);
					if (placaEncontrada == -1){
						printf("------------------------------------------\n");
						printf("Vehiculo con placa %s no encontrado\n", placaBusqueda);
						printf("Presione Enter...\n");
						while (getchar() != '\n');
						system("cls");
					} else{
						printf("\nDatos vehiculares: \n");
						printf("------------------------------------------\n");
						imprimirVehiculo(listaVehicular[placaEncontrada]);
						printf("------------------------------------------\n");
						printf("Presione Enter...\n");
						while (getchar() != '\n');
						system("cls");
					}
					break;
				case 4:
					system("cls");
					imprimirTodosVehiculo(listaVehicular);
					horaActual(hora, sizeof(hora));
					if (numVehiculo != 0){
						do{
							printf("\nDesea guardar los datos de los vehiculos registrados ?(s/n):\n");
							fgets(respuesta2, sizeof(respuesta2), stdin);
							if (respuesta2[0] == 's' || respuesta2[0] == 'S'){
								printf("=====================================\n");
								guardarDatos(listaVehicular, hora);
								printf("\nPresione Enter...\n");
								while(getchar() != '\n');
								system("cls");
							} else if(respuesta2[0] == 'n' || respuesta2[0] == 'N'){
								printf("=====================================\n");
								printf("Datos no guardados \n");
								printf("Presione Enter para continuar...\n");
								while(getchar() != '\n');
								system("cls");
							} else{
								printf("Intentelo de nuevo.\n");
							}
						} while(respuesta2[0] != 'S' && respuesta2[0] != 's' && respuesta2[0] != 'n' && respuesta2[0] != 'N');
					} else{
						printf("No hay datos a guardar\n");
						printf("Presione Enter para continuar...\n");
						while(getchar() != '\n');
						system("cls");
					}
					break;
				case 5:
					system("cls");
					printf("\n=========================================");
					printf("\n  Saliendo del programa. Hasta la proxima  \n");
					printf("===========================================\n");
					break;
				default:
					printf("Opcion invalida\n");
					break;
				};
			} while(opcion!=5);
			break;
		} else if (existencia == 2){
			printf("Contrasena incorrecta, no coincide con la registrada.\n");//Si es entonces la contraseña del correo registrado no es correcta
		} else{
			do{
				printf("---------------------------------------------------\n");
				printf("Usuario sin registrar. ¿Desea registrarse? (s/n): ");
				printf("\n---------------------------------------------------\n");
				fgets(respuesta1, sizeof(respuesta1), stdin);
				
				if (tolower(respuesta1[0]) == 's') {
					system("cls");
					printf("\n=================================\n");
					registroUsuario(cedula, contrasena);
					printf("    Ahora puede iniciar sesión    \n");//Si pone que desea registrarse, el correo y contraseña ingresados se guardan como registrados
					printf("===================================\n");
					printf("Presione Enter para continuar...\n");
					while(getchar() != '\n');
					system("cls");
					break;
				} else if (tolower(respuesta1[0]) == 'n'){
					system("cls");
					printf("\n=================================\n");
					printf("   No se registró ningún usuario   \n");//Si no, entonces le devuelve a que inicie sesión
					printf("=================================\n");
					printf("Presione Enter para continuar...\n");
					while(getchar() != '\n');
					system("cls");
					break;
				} else {
					system("cls");
					printf("Comando invalido. Intentelo de nuevo.\n");
				}
			} while(respuesta1[0] != 's' && respuesta1[0] != 'n');
		}
	}
	return 0;
}

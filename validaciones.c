#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#define VEHICULOS_MAX 100

int validacionCampoPlaca(char placa[]){
	int maxCaracteres = 8;
	size_t longitud = strlen(placa);
	if (longitud > 0 && placa[longitud - 1] == '\n'){
		placa[longitud - 1] = '\0';
		longitud--;
	}
	
	if (longitud != maxCaracteres){
		return 0;
	} else{
		return 1;
	}
}
	
int validacionLetraPlaca(char placa[]){
	int validacion;
	for (int i = 1; i < 3; i++){
		if (!isalpha(placa[i])){
			validacion = 0;
			break;
		}
	}
	if (validacion == 0){
		return 0;
	} else {
		return 1;
	}
}
	
int validacionNumeroPlaca(char placa[]){
	int validacion;
	for (int i = 4; i < 8; i++){
		if (!isdigit(placa[i])){
			validacion = 0;
			break;
		}else{
			validacion = 1;
		}
	}
	if (validacion == 0){
		return 0;
	} else {
		return 1;
	}
}
	
int validacionSignoPlaca(char placa[]){
	if (placa[3] != '-'){
		return 0;
	} else {
		return 1;
	}
}
	
int validacionCedula(char cedula[]){
	int maxCaracteres = 10;
	size_t longitud = strlen(cedula);
	if (longitud > 0 && cedula[longitud - 1] == '\n'){
		cedula[longitud - 1] = '\0';
		longitud--;
	}
	
	if (longitud != maxCaracteres){
		return 0;
	} 
	for (size_t i = 0; i < longitud; i++){
		if (!isdigit(cedula[i])){ // isdigit() verifica si el caracter es un dígito (0-9)
			return 0; // Error: contiene caracteres no numéricos
		}
	}
	
	return 1;
}
	
int validacionTipo(char tipo[]){
	if (strcmp(tipo, "LIVIANO") == 0 || strcmp(tipo, "PESADO") == 0 || strcmp(tipo, "liviano") == 0 || strcmp(tipo, "pesado") == 0){
		return 1;
	} else{
		return 0;
	}
}
	
int validacionAnio(int anio){
	if(anio >= 2000 && anio < 2026){
		return 1;
	} else {
		return 0;
	}
}
	
int validacionAvaluo(double avaluo){
	if (avaluo < 2000 || avaluo > 400000){
		return 0;
	} else {
		return 1;
	}
}

void aMinusculas(char* cadena) {
	for (int i = 0; cadena[i]; i++) {
		cadena[i] = tolower(cadena[i]);
	}
}

void aMayusculas(char* cadenas){
	for (int i = 0; cadenas[i]; i++){
		cadenas[i] = toupper(cadenas[i]);
	}
}

int validacionContrasena(const char *contrasena){
	int longitud = strlen(contrasena);
	if (longitud < 8 && longitud > 10){
		return 0;
	}
	return 1;
}

int esNumero(const char* cadena) {
	int i = 0;
	int puntoEncontrado = 0;
	int digitos = 0;
	
	// Ignorar espacios al inicio
	while (cadena[i] == ' ') i++;
	
	// Si está vacía, no es número
	if (cadena[i] == '\0' || cadena[i] == '\n')
		return 0;
	
	// Verificar que cada carácter sea dígito
	for (; cadena[i] != '\0' && cadena[i] != '\n'; i++) {
		if (isdigit(cadena[i])){
			digitos++;
		} else if (cadena[i] == '.'){
			if (puntoEncontrado) return 0;
			puntoEncontrado = 1;
		} else {
			return 0;
		}
	}
		
	return (digitos > 0);
}

int doubleValido(const char* cadena){
	char* ptr;
	strtod(cadena, &ptr);
	
	if (cadena == ptr || (*ptr != '\n' && *ptr != '\0')){
		return 0;
	}
	
	return 1;
}

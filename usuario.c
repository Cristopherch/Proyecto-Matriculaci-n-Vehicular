#include "usuario.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include "logerrores.h"



void registroUsuario(const char* cedula, const char* contrasena){//Se registra en el archivo el correo y contraseña que el usuario ingrese
	FILE *file = fopen("usuario.txt", "a");
	if (file == NULL){
		printf("Error al abrir el archivo.\n");
		errorLog("No se pudo abrir el archivo usuario.txt");
		return;
	}
	
	fprintf(file, "Usuario: %s | Contraseña: %s\n", cedula, contrasena);
	fclose(file);
	printf("    Usuario registrado con exito  \n");
	
}
	
	
int validacionUsuario(const char* cedula, const char* contrasena) {
	// Verifica que el correo y contraseña que se ingresó estén en el archivo
	FILE *file = fopen("usuario.txt", "r");
	if (file == NULL) return 0;
	char cedulaValidacion[50];
	char contrasenaValidacion[50];
	int usuarioEncontrado = 0;
	while (fscanf(file, "Usuario: %s | Contraseña: %s\n", cedulaValidacion, contrasenaValidacion) != EOF) {
		if (strcmp(cedula, cedulaValidacion) == 0) {
			usuarioEncontrado = 1; // Se encontró la cédula
			if (strcmp(contrasena, contrasenaValidacion) == 0) {
				fclose(file);
				return 1; // Contraseña correcta
			} else {
				fclose(file);
				return 2; // Contraseña incorrecta
			}
		}
	}
	fclose(file);
	return usuarioEncontrado ? 2 : 0; // Si se encontró la cédula pero la contraseña es incorrecta, retorna 2; si no se encontró, retorna 0
}

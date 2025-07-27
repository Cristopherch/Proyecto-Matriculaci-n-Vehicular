#include "usuario.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include "logerrores.h"



void registroUsuario(const char* cedula, const char* contrasena){//Se registra en el archivo el correo y contrase�a que el usuario ingrese
	FILE *file = fopen("usuario.txt", "a");
	if (file == NULL){
		printf("Error al abrir el archivo.\n");
		errorLog("No se pudo abrir el archivo usuario.txt");
		return;
	}
	
	fprintf(file, "Usuario: %s | Contrase�a: %s\n", cedula, contrasena);
	fclose(file);
	printf("    Usuario registrado con exito  \n");
	
}
	
	
int validacionUsuario(const char* cedula, const char* contrasena) {
	// Verifica que el correo y contrase�a que se ingres� est�n en el archivo
	FILE *file = fopen("usuario.txt", "r");
	if (file == NULL) return 0;
	char cedulaValidacion[50];
	char contrasenaValidacion[50];
	int usuarioEncontrado = 0;
	while (fscanf(file, "Usuario: %s | Contrase�a: %s\n", cedulaValidacion, contrasenaValidacion) != EOF) {
		if (strcmp(cedula, cedulaValidacion) == 0) {
			usuarioEncontrado = 1; // Se encontr� la c�dula
			if (strcmp(contrasena, contrasenaValidacion) == 0) {
				fclose(file);
				return 1; // Contrase�a correcta
			} else {
				fclose(file);
				return 2; // Contrase�a incorrecta
			}
		}
	}
	fclose(file);
	return usuarioEncontrado ? 2 : 0; // Si se encontr� la c�dula pero la contrase�a es incorrecta, retorna 2; si no se encontr�, retorna 0
}

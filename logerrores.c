#include <stdio.h>
#include <time.h>
#include "logerrores.h"

void errorLog(const char* mensaje){
	FILE *archivo = fopen("log.txt", "a");
	if (archivo == NULL){
		return;
	}
	
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);
	char fechaHora[26];
	strftime(fechaHora, 26, "%Y-%m-%d %H:%M:%S", tm_info);
	
	fprintf(archivo, "[%s] ERROR: %s\n", fechaHora, mensaje);
	fclose(archivo);
}

#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#define VEHICULOS_MAX 100

int validacionCampoPlaca(char placa[]);

int validacionLetraPlaca(char placa[]);

int validacionSignoPlaca(char placa[]);

int validacionNumeroPlaca(char placa[]);

int validacionCedula(char cedula[]);

int validacionTipo(char tipo[]);

int validacionAnio(int anio);

int validacionAvaluo(int avaluo);

void aMinusculas(char* cadena);

void aMayusculas(char* cadenas);

int validacionContrasena(const char *contrasena);

int esNumero(const char* cadena);

int doubleValido(const char* cadena);

#endif

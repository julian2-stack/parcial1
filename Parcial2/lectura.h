/* Lectura validada por consola. Devuelve 0 al terminar la entrada. */
#ifndef LECTURA_H
#define LECTURA_H

int leerEntero(const char *mensaje, int *valor);
int leerFloat(const char *mensaje, float *valor);
int leerDatos(float *tara, float *carga, float *costo);

#endif

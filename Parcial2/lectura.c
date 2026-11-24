#include "lectura.h"
#include "registro.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/* Lee una linea completa; descarta entradas demasiado largas.
   Devuelve 0 ante fin de entrada para que main libere la memoria. */
static int leerLinea(const char *mensaje, char *linea, int capacidad) {
    int c;
    for (;;) {
        printf("%s", mensaje);
        fflush(stdout);
        if (fgets(linea, capacidad, stdin) == NULL) return 0;
        if (strchr(linea, '\n') != NULL || feof(stdin)) return 1;
        while ((c = getchar()) != '\n' && c != EOF) { }
        puts("Entrada demasiado larga. Intente de nuevo.");
        if (c == EOF) return 0;
    }
}

int leerEntero(const char *mensaje, int *valor) {
    char linea[128], extra;
    double numero;
    while (leerLinea(mensaje, linea, sizeof linea)) {
        /* Leer primero como double permite comprobar el rango de int. */
        if (sscanf(linea, "%lf %c", &numero, &extra) == 1 &&
            isfinite(numero) && numero >= 0 && numero <= INT_MAX &&
            numero == (int)numero) {
            *valor = (int)numero;
            return 1;
        }
        puts("Ingrese un entero no negativo dentro del rango permitido.");
    }
    return 0;
}

int leerFloat(const char *mensaje, float *valor) {
    char linea[128], extra;
    double numero;
    while (leerLinea(mensaje, linea, sizeof linea)) {
        if (sscanf(linea, "%lf %c", &numero, &extra) == 1 &&
            isfinite(numero) && numero >= 0 && numero <= FLT_MAX) {
            *valor = (float)numero;
            return 1;
        }
        puts("Ingrese un numero finito no negativo. Use punto decimal.");
    }
    return 0;
}

int leerDatos(float *tara, float *carga, float *costo) {
    for (;;) {
        if (!leerFloat("Peso vacio (tara): ", tara) ||
            !leerFloat("Peso de carga: ", carga) ||
            !leerFloat("Costo: ", costo)) return 0;
        if (datosValidos(*tara, *carga, *costo)) return 1;
        puts("La suma de los pesos supera el rango de float. Repita los datos.");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "competidor.h"

static void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

/* Pide un entero y repite hasta que el usuario escriba un numero valido. */
static int leerEntero(const char *mensaje) {
    int valor;
    int resultado;

    while (1) {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);

        if (resultado == EOF) {
            printf("\nSe termino la entrada de datos.\n");
            exit(1);
        }

        limpiarBuffer();

        if (resultado == 1) {
            return valor;
        }

        printf("Entrada no valida. Debe escribir un numero entero.\n");
    }
}

Competidor *crearCompetidores(int cantidad) {
    Competidor *competidores;

    /* calloc deja todo en 0 en lugar de datos basura */
    competidores = calloc(cantidad, sizeof(Competidor));

    if (competidores == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return NULL;
    }

    return competidores;
}

/* Calcula el promedio de los puntajes usando el apuntador al competidor. */
void calcularPromedio(Competidor *competidor) {
    int suma = 0;

    for (int i = 0; i < NUM_PUNTAJES; i++) {
        suma += competidor->puntajes[i];
    }

    competidor->promedio = (double)suma / NUM_PUNTAJES;
}

void registrarCompetidores(Competidor *competidores, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        Competidor *actual = &competidores[i];

        printf("\nCompetidor %d\n", i + 1);

        actual->id = leerEntero("Ingrese el ID (numero): ");

        printf("Ingrese el nombre (sin espacios): ");
        if (scanf("%49s", actual->nombre) != 1) {
            printf("\nSe termino la entrada de datos.\n");
            exit(1);
        }
        limpiarBuffer();

        for (int j = 0; j < NUM_PUNTAJES; j++) {
            printf("Puntaje %d de %d - ", j + 1, NUM_PUNTAJES);
            actual->puntajes[j] = leerEntero("ingrese el valor (numero): ");
        }

        calcularPromedio(actual);
    }
}

void mostrarCompetidores(const Competidor *competidores, int cantidad) {
    printf("\n%-8s %-16s", "ID", "NOMBRE");
    for (int j = 0; j < NUM_PUNTAJES; j++) {
        printf(" P%-5d", j + 1);
    }
    printf(" %-10s\n", "PROMEDIO");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        const Competidor *c = &competidores[i];

        printf("%-8d %-16s", c->id, c->nombre);
        for (int j = 0; j < NUM_PUNTAJES; j++) {
            printf(" %-6d", c->puntajes[j]);
        }
        printf(" %-10.2f\n", c->promedio);
    }
}

void liberarCompetidores(Competidor *competidores) {
    free(competidores);
}
#include <stdio.h>
#include <stdlib.h>

#include "competidor.h"
#include "ordenamiento.h"

// Funcion main para ejecutar los métodos de ordenamientos base #CP
// Funcion main para ejecutar los métodos de ordenamientos base #NoBorrar
// Autor: Julián Camilo Córdoba Caicedo
// El ordenamiento se realiza por el promedio de los puntajes de cada competidor.

int main(void) {
    int cantidad;
    int opcion;
    int ascendente;
    int salir = 0;

    printf("=== SISTEMA DE CLASIFICACION DE COMPETIDORES ===\n");
    printf("Ingrese la cantidad de competidores: ");

    if (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
        printf("Error: la cantidad debe ser un entero positivo.\n");
        return 1;
    }

    Competidor *competidores = crearCompetidores(cantidad);

    if (competidores == NULL) {
        return 1;
    }

    registrarCompetidores(competidores, cantidad);

    printf("\n=== TABLA ORIGINAL ===\n");
    mostrarCompetidores(competidores, cantidad);

    while (!salir) {
        printf("\n========== MENU ==========\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Mostrar competidores\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no valida.\n");
            liberarCompetidores(competidores);
            return 1;
        }

        switch (opcion) {
            case 1:
            case 2:
            case 3:
                printf("1. Ascendente (menor a mayor)\n");
                printf("0. Descendente (mayor a menor)\n");
                printf("Seleccione el orden: ");

                if (scanf("%d", &ascendente) != 1 ||
                    (ascendente != 0 && ascendente != 1)) {
                    printf("Orden no valido.\n");
                    liberarCompetidores(competidores);
                    return 1;
                }

                printf("\n=== ANTES DEL ORDENAMIENTO ===\n");
                mostrarCompetidores(competidores, cantidad);

                if (opcion == 1) {
                    bubbleSort(competidores, cantidad, ascendente);
                } else if (opcion == 2) {
                    selectionSort(competidores, cantidad, ascendente);
                } else {
                    insertionSort(competidores, cantidad, ascendente);
                }

                printf("\n=== DESPUES DEL ORDENAMIENTO ===\n");
                mostrarCompetidores(competidores, cantidad);
                break;

            case 4:
                mostrarCompetidores(competidores, cantidad);
                break;

            case 0:
                salir = 1;
                break;

            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    }

    liberarCompetidores(competidores);

    printf("Memoria liberada. Programa finalizado.\n");

    return 0;
}
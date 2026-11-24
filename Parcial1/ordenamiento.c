#include "ordenamiento.h"

void bubbleSort(Competidor *competidores, int cantidad, int ascendente) {
    Competidor temporal;

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1 - i; j++) {

            int debeIntercambiar;

            if (ascendente) {
                debeIntercambiar =
                    competidores[j].promedio >
                    competidores[j + 1].promedio;
            } else {
                debeIntercambiar =
                    competidores[j].promedio <
                    competidores[j + 1].promedio;
            }

            if (debeIntercambiar) {
                temporal = competidores[j];
                competidores[j] = competidores[j + 1];
                competidores[j + 1] = temporal;
            }
        }
    }
}


void selectionSort(Competidor *competidores, int cantidad, int ascendente) {
    Competidor temporal;

    for (int i = 0; i < cantidad - 1; i++) {
        int indice = i;

        for (int j = i + 1; j < cantidad; j++) {
            int esMejor;

            if (ascendente) {
                esMejor = competidores[j].promedio < competidores[indice].promedio;
            } else {
                esMejor = competidores[j].promedio > competidores[indice].promedio;
            }

            if (esMejor) {
                indice = j;
            }
        }

        if (indice != i) {
            temporal = competidores[i];
            competidores[i] = competidores[indice];
            competidores[indice] = temporal;
        }
    }
}

void insertionSort(Competidor *competidores, int cantidad, int ascendente) {
    for (int i = 1; i < cantidad; i++) {
        Competidor actual = competidores[i];
        int j = i - 1;

        while (j >= 0 && (ascendente
                ? competidores[j].promedio > actual.promedio
                : competidores[j].promedio < actual.promedio)) {
            competidores[j + 1] = competidores[j];
            j--;
        }

        competidores[j + 1] = actual;
    }
}
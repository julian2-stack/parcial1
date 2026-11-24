#ifndef COMPETIDOR_H
#define COMPETIDOR_H

#define MAX_NOMBRE 50
#define NUM_PUNTAJES 3

typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    int puntajes[NUM_PUNTAJES];
    double promedio;
} Competidor;

Competidor *crearCompetidores(int cantidad);
void calcularPromedio(Competidor *competidor);
void registrarCompetidores(Competidor *competidores, int cantidad);
void mostrarCompetidores(const Competidor *competidores, int cantidad);
void liberarCompetidores(Competidor *competidores);

#endif

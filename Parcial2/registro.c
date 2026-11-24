/* Operaciones del registro: insercion, busqueda, actualizacion,
   eliminacion, recorridos y liberacion de memoria. Libro: unidad 7. */
#include "registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int datosValidos(float tara, float carga, float costo) {
    return isfinite(tara) && isfinite(carga) && isfinite(costo) &&
           tara >= 0 && carga >= 0 && costo >= 0 &&
           (double)tara + (double)carga <= FLT_MAX;
}

/* O(1): ultimo evita recorrer toda la lista para insertar. */
int insertar(Lista *lista, float tara, float carga, float costo) {
    Contenedor *nuevo;
    if (!datosValidos(tara, carga, costo) || lista->ultimoId == INT_MAX)
        return 0;
    nuevo = malloc(sizeof *nuevo);
    if (nuevo == NULL) return 0;
    nuevo->id = ++lista->ultimoId;
    nuevo->tara = tara;
    nuevo->carga = carga;
    nuevo->total = tara + carga;
    nuevo->costo = costo;
    nuevo->anterior = lista->ultimo;
    nuevo->siguiente = NULL;
    if (lista->ultimo != NULL)
        lista->ultimo->siguiente = nuevo;
    else
        lista->primero = nuevo;
    lista->ultimo = nuevo;
    return nuevo->id;
}

/* O(n): busqueda secuencial por identificador. */
Contenedor *buscar(const Lista *lista, int id) {
    Contenedor *actual = lista->primero;
    while (actual != NULL) {
        if (actual->id == id) return actual;
        actual = actual->siguiente;
    }
    return NULL;
}

int actualizar(Lista *lista, int id, float tara, float carga, float costo) {
    Contenedor *actual = buscar(lista, id);
    if (actual == NULL || !datosValidos(tara, carga, costo)) return 0;
    actual->tara = tara;
    actual->carga = carga;
    actual->total = tara + carga;
    actual->costo = costo;
    return 1;
}

int eliminar(Lista *lista, int id) {
    Contenedor *actual = buscar(lista, id);
    if (actual == NULL) return 0;
    /* Reconectar el vecino izquierdo o cambiar el inicio. */
    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;
    else
        lista->primero = actual->siguiente;
    /* Reconectar el vecino derecho o cambiar el final. */
    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;
    else
        lista->ultimo = actual->anterior;
    free(actual);
    return 1;
}

void mostrar(const Contenedor *actual) {
    printf("ID: %d | Tara: %.2f | Carga: %.2f | Total: %.2f | Costo: %.2f\n",
           actual->id, actual->tara, actual->carga, actual->total, actual->costo);
}

void listar(const Lista *lista, int inverso) {
    Contenedor *actual = inverso ? lista->ultimo : lista->primero;
    if (actual == NULL) puts("No hay contenedores registrados.");
    while (actual != NULL) {
        mostrar(actual);
        actual = inverso ? actual->anterior : actual->siguiente;
    }
}

void liberarLista(Lista *lista) {
    Contenedor *actual = lista->primero;
    while (actual != NULL) {
        /* Conservar el siguiente ANTES de liberar el nodo actual. */
        Contenedor *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    lista->primero = NULL;
    lista->ultimo = NULL;
}


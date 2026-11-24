/* Pruebas del registro y de los enlaces en ambos sentidos. */
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include "registro.h"

void verificar(const Lista *lista, const int ids[], int cantidad) {
    Contenedor *actual = lista->primero, *previo = NULL;
    int i;
    for (i = 0; i < cantidad; i++) {
        assert(actual != NULL && actual->id == ids[i]);
        assert(actual->anterior == previo);
        previo = actual;
        actual = actual->siguiente;
    }
    assert(actual == NULL && previo == lista->ultimo);
    actual = lista->ultimo;
    previo = NULL;
    for (i = cantidad - 1; i >= 0; i--) {
        assert(actual != NULL && actual->id == ids[i]);
        assert(actual->siguiente == previo);
        previo = actual;
        actual = actual->anterior;
    }
    assert(actual == NULL && previo == lista->primero);
}

int main(void) {
    Lista lista = {NULL, NULL, 0};
    int ids[] = {1, 2, 3};
    verificar(&lista, ids, 0);
    assert(buscar(&lista, 1) == NULL);
    assert(!eliminar(&lista, 1));
    assert(!actualizar(&lista, 1, 1, 2, 3));
    assert(!insertar(&lista, -1, 2, 3));
    assert(!insertar(&lista, NAN, 2, 3));
    assert(!insertar(&lista, FLT_MAX, FLT_MAX, 3));
    assert(insertar(&lista, 2.5f, 10.25f, 100) == 1);
    assert(insertar(&lista, 3, 20, 200) == 2);
    assert(insertar(&lista, 4, 30, 300) == 3);
    verificar(&lista, ids, 3);
    assert(buscar(&lista, 1)->total == 12.75f);
    assert(actualizar(&lista, 2, 5, 6, 400));
    assert(buscar(&lista, 2)->total == 11);
    assert(buscar(&lista, 2)->costo == 400);
    assert(!actualizar(&lista, 2, -5, 6, 400));
    assert(buscar(&lista, 2)->total == 11);
    assert(eliminar(&lista, 2)); /* Intermedio. */
    ids[1] = 3;
    verificar(&lista, ids, 2);
    assert(eliminar(&lista, 1)); /* Primero. */
    ids[0] = 3;
    verificar(&lista, ids, 1);
    assert(insertar(&lista, 0, 0, 0) == 4);
    ids[1] = 4;
    verificar(&lista, ids, 2);
    assert(eliminar(&lista, 4)); /* Ultimo. */
    verificar(&lista, ids, 1);
    assert(eliminar(&lista, 3)); /* Unico. */
    verificar(&lista, ids, 0);
    assert(insertar(&lista, 1, 2, 3) == 5); /* No reutiliza IDs. */
    assert(insertar(&lista, 1, 2, 3) == 6);
    liberarLista(&lista);
    verificar(&lista, ids, 0);
    lista.ultimoId = INT_MAX;
    assert(!insertar(&lista, 1, 2, 3));
    liberarLista(&lista);
    puts("Todas las pruebas pasaron.");
    return 0;
}

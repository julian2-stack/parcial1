/* Tipos y operaciones de la lista doblemente enlazada. */
#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct Contenedor {
    int id;
    float tara;
    float carga;
    float total;
    float costo;
    struct Contenedor *anterior;
    struct Contenedor *siguiente;
} Contenedor;

typedef struct {
    Contenedor *primero;
    Contenedor *ultimo;
    int ultimoId;
} Lista;

/* Devuelve 1 si los pesos y el costo son validos; 0 en otro caso. */
int datosValidos(float tara, float carga, float costo);
/* Devuelve el ID asignado; 0 si no se puede insertar. */
int insertar(Lista *lista, float tara, float carga, float costo);
/* Devuelve el nodo encontrado o NULL. */
Contenedor *buscar(const Lista *lista, int id);
/* Devuelven 1 si se realizo la operacion; 0 si no fue posible. */
int actualizar(Lista *lista, int id, float tara, float carga, float costo);
int eliminar(Lista *lista, int id);
void mostrar(const Contenedor *actual);
/* inverso: 0 para avanzar, 1 para retroceder. */
void listar(const Lista *lista, int inverso);
void liberarLista(Lista *lista);

#endif

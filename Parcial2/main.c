/* Menu principal: coordina la entrada y las operaciones del registro. */
#include <stdio.h>
#include "registro.h"
#include "lectura.h"

int main(void) {
    Lista lista = {NULL, NULL, 0};
    int opcion, id;
    float tara, carga, costo;
    Contenedor *encontrado;
    puts("GESTION DE CONTENEDORES PORTUARIOS");
    puts("Use la misma unidad para los pesos y punto para los decimales.");
    for (;;) {
        puts("\n1. Insertar\n2. Buscar\n3. Actualizar\n4. Eliminar"
             "\n5. Listar hacia adelante\n6. Listar hacia atras\n0. Salir");
        if (!leerEntero("Opcion: ", &opcion) || opcion == 0) break;
        if (opcion == 1) {
            if (!leerDatos(&tara, &carga, &costo)) break;
            id = insertar(&lista, tara, carga, costo);
            if (id != 0) printf("Contenedor registrado con ID %d.\n", id);
            else puts("No se pudo insertar: memoria o identificadores agotados.");
        } else if (opcion >= 2 && opcion <= 4) {
            if (!leerEntero("ID del contenedor: ", &id)) break;
            encontrado = buscar(&lista, id);
            if (encontrado == NULL) {
                puts("Contenedor no encontrado.");
                continue;
            }
            if (opcion == 2) mostrar(encontrado);
            else if (opcion == 3) {
                if (!leerDatos(&tara, &carga, &costo)) break;
                if (actualizar(&lista, id, tara, carga, costo))
                    puts("Contenedor actualizado.");
            } else {
                eliminar(&lista, id);
                puts("Contenedor eliminado.");
            }
        } else if (opcion == 5 || opcion == 6) {
            listar(&lista, opcion == 6);
        } else puts("Opcion invalida. Elija de 0 a 6.");
    }
    liberarLista(&lista);
    puts("Memoria liberada. Programa finalizado.");
    return 0;
}

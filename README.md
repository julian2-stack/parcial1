# Parcial 1 - Estructuras de Datos

Sistema de clasificación de competidores (modularidad, apuntadores y ordenamiento básico en C).

## Compilación separada con GCC

```
gcc -Wall -Wextra -std=c11 -c main.c -o main.o
gcc -Wall -Wextra -std=c11 -c competidor.c -o competidor.o
gcc -Wall -Wextra -std=c11 -c ordenamiento.c -o ordenamiento.o
gcc main.o competidor.o ordenamiento.o -o parcial
```

Ejecutar: `.\parcial` (Windows)

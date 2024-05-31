#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresarProducto(Producto **productos, int *numProductos) {
    *productos = realloc(*productos, (*numProductos + 1) * sizeof(Producto));
    if (*productos == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    printf("Ingresar nombre del producto: ");
    scanf("%s", (*productos)[*numProductos].nombre);
    printf("Ingresar cantidad: ");
    scanf("%d", &(*productos)[*numProductos].cantidad);
    printf("Ingresar precio: ");
    scanf("%f", &(*productos)[*numProductos].precio);
    printf("Ingresar categoría: ");
    scanf("%s", (*productos)[*numProductos].categoria);
    (*numProductos)++;
}

void editarProducto(Producto *productos, int numProductos) {
    char nombre[50];
    printf("Ingresar nombre del producto a editar: ");
    scanf("%s", nombre);
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) {
            printf("Producto encontrado. Ingresar nueva cantidad: ");
            scanf("%d", &productos[i].cantidad);
            printf("Ingresar nuevo precio: ");
            scanf("%f", &productos[i].precio);
            printf("Ingresar nueva categoría: ");
            scanf("%s", productos[i].categoria);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(Producto **productos, int *numProductos) {
    char nombre[50];
    printf("Ingresar nombre del producto a eliminar: ");
    scanf("%s", nombre);
    for (int i = 0; i < *numProductos; i++) {
        if (strcmp((*productos)[i].nombre, nombre) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                (*productos)[j] = (*productos)[j + 1];
            }
            *productos = realloc(*productos, (*numProductos - 1) * sizeof(Producto));
            if (*productos == NULL && *numProductos - 1 > 0) {
                printf("Error al asignar memoria\n");
                exit(1);
            }
            (*numProductos)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listarProductos(Producto *productos, int numProductos) {
    if (numProductos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    printf("+----------------------------+----------+---------+----------------------------+\n");
    printf("| Nombre                     | Cantidad | Precio  | Categoría                  |\n");
    printf("+----------------------------+----------+---------+----------------------------+\n");

    for (int i = 0; i < numProductos; i++) {
        printf("| %-26s | %-8d | %-7.2f | %-26s |\n",
               productos[i].nombre, productos[i].cantidad, productos[i].precio, productos[i].categoria);
    }

    printf("+----------------------------+----------+---------+----------------------------+\n");
}

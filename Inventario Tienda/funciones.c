#include "funciones.h"
#include <stdio.h>
#include <string.h>

#define FILE_NAME "productos.txt"

void guardarProductos(Producto productos[], int numProductos) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para escribir\n");
        return;
    }
    for (int i = 0; i < numProductos; i++) {
        fprintf(file, "%s %d %.2f %s\n", productos[i].nombre, productos[i].cantidad, productos[i].precio, productos[i].categoria);
    }
    fclose(file);
}

void cargarProductos(Producto productos[], int *numProductos) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No se encontró el archivo de productos, se creará uno nuevo.\n");
        return;
    }
    *numProductos = 0;
    while (fscanf(file, "%s %d %f %s", productos[*numProductos].nombre, &productos[*numProductos].cantidad, &productos[*numProductos].precio, productos[*numProductos].categoria) != EOF) {
        (*numProductos)++;
    }
    fclose(file);
}

void ingresarProducto(Producto productos[], int *numProductos) {
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("Límite de productos alcanzado\n");
        return;
    }
    printf("Ingresar nombre del producto: ");
    scanf("%s", productos[*numProductos].nombre);
    printf("Ingresar cantidad: ");
    scanf("%d", &productos[*numProductos].cantidad);
    printf("Ingresar precio: ");
    scanf("%f", &productos[*numProductos].precio);
    printf("Ingresar categoría: ");
    scanf("%s", productos[*numProductos].categoria);
    (*numProductos)++;
    guardarProductos(productos, *numProductos);
}

void editarProducto(Producto productos[], int numProductos) {
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
            guardarProductos(productos, numProductos);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(Producto productos[], int *numProductos) {
    char nombre[50];
    printf("Ingresar nombre del producto a eliminar: ");
    scanf("%s", nombre);
    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            (*numProductos)--;
            guardarProductos(productos, *numProductos);
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listarProductos(Producto productos[], int numProductos) {
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


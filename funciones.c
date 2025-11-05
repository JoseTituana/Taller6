#include <stdio.h>
#include <string.h>

#define MAX_PROD 10

char nombres[MAX_PROD][50];
float precios[MAX_PROD];
int cantidad = 0;
void ingresarProductos() {
    int i;
    printf("\nCuantos productos deseas ingresar (maximo 10)? ");
    scanf("%d", &cantidad);

    if (cantidad > MAX_PROD) {
        cantidad = MAX_PROD;
        printf("Solo se guardaran los primeros 10.\n");
    }

    for (i = 0; i < cantidad; i++) {
        printf("Nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);

        printf("Precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}
void mostrarProductos() {
    int i;
    if (cantidad == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}
void calcularTotal() {
    float total = 0;
    int i;
    for (i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    printf("\nEl precio total del inventario es: $%.2f\n", total);
}
void mostrarMasCaroYMasBarato() {
    if (cantidad == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    int i;
    int posCaro = 0;
    int posBarato = 0;

    for (i = 1; i < cantidad; i++) {
        if (precios[i] > precios[posCaro])
            posCaro = i;
        if (precios[i] < precios[posBarato])
            posBarato = i;
    }

    printf("\nProducto mas caro: %s ($%.2f)\n", nombres[posCaro], precios[posCaro]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[posBarato], precios[posBarato]);
}
void calcularPromedio() {
    if (cantidad == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    float suma = 0;
    int i;
    for (i = 0; i < cantidad; i++) {
        suma += precios[i];
    }

    printf("\nEl precio promedio es: $%.2f\n", suma / cantidad);
}
void buscarProducto() {
    if (cantidad == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    char nombreBuscado[50];
    int i, encontrado = 0;

    printf("\nEscribe el nombre del producto que quieres buscar: ");
    scanf("%s", nombreBuscado);

    for (i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El precio de %s es: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}
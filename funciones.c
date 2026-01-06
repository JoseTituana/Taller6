#include <stdio.h>
#include <string.h>
#include "funciones.h"

/* REGISTRAR VEHICULO */
void registrarVehiculo() {
    FILE *archivo = fopen("vehiculos.txt", "a");
    Vehiculo v;

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Codigo del vehiculo: ");
    scanf("%d", &v.codigo);

    printf("Anio: ");
    scanf("%d", &v.anio);

    printf("Marca: ");
    scanf("%s", v.marca);

    printf("Modelo: ");
    scanf("%s", v.modelo);

    printf("Color: ");
    scanf("%s", v.color);

    printf("Precio: ");
    scanf("%f", &v.precio);

    printf("Es nuevo? (1=Si, 0=No): ");
    scanf("%d", &v.esNuevo);

    v.disponible = 1;

    fprintf(archivo, "%d %d %s %s %s %.2f %d %d\n",
            v.codigo, v.anio, v.marca, v.modelo,
            v.color, v.precio, v.esNuevo, v.disponible);

    fclose(archivo);
    printf("Vehiculo registrado correctamente.\n");
}

/* MOSTRAR VEHICULOS */
void mostrarVehiculos() {
    FILE *archivo = fopen("vehiculos.txt", "r");
    Vehiculo v;

    if (archivo == NULL) {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    printf("\n--- LISTA DE VEHICULOS ---\n");
    while (fscanf(archivo, "%d %d %s %s %s %f %d %d",
                  &v.codigo, &v.anio, v.marca, v.modelo,
                  v.color, &v.precio, &v.esNuevo, &v.disponible) == 8) {

        printf("Codigo: %d | %s %s | $%.2f | %s | %s\n",
               v.codigo, v.marca, v.modelo, v.precio,
               v.esNuevo ? "Nuevo" : "Usado",
               v.disponible ? "Disponible" : "Vendido");
    }

    fclose(archivo);
}

/* BUSCAR VEHICULOS POR PRESUPUESTO ±5000 */
void buscarVehiculos(float presupuesto, char marca[]) {
    FILE *archivo = fopen("vehiculos.txt", "r");
    Vehiculo v;
    int encontrado = 0;

    float minimo = presupuesto - 5000;
    float maximo = presupuesto + 5000;

    if (archivo == NULL) {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    printf("\nVehiculos marca %s con precios entre %.2f y %.2f:\n",
           marca, minimo, maximo);

    while (fscanf(archivo, "%d %d %s %s %s %f %d %d",
                  &v.codigo, &v.anio, v.marca, v.modelo,
                  v.color, &v.precio, &v.esNuevo, &v.disponible) == 8) {

        if (strcmp(v.marca, marca) == 0 &&
            v.precio >= minimo &&
            v.precio <= maximo &&
            v.disponible == 1) {

            printf("Codigo: %d | %s %s | $%.2f\n",
                   v.codigo, v.marca, v.modelo, v.precio);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron vehiculos con esas condiciones.\n");
    }

    fclose(archivo);
}

/* REGISTRAR VENTA */
void registrarVenta() {
    FILE *vehiculos = fopen("vehiculos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *ventas = fopen("ventas.txt", "a");

    Vehiculo v;
    char cliente[40];
    int codigoBuscado;
    int vendido = 0;

    if (vehiculos == NULL || temp == NULL || ventas == NULL) {
        printf("Error al procesar la venta.\n");
        return;
    }

    printf("Nombre del cliente: ");
    scanf("%s", cliente);

    printf("Codigo del vehiculo: ");
    scanf("%d", &codigoBuscado);

    while (fscanf(vehiculos, "%d %d %s %s %s %f %d %d",
                  &v.codigo, &v.anio, v.marca, v.modelo,
                  v.color, &v.precio, &v.esNuevo, &v.disponible) == 8) {

        if (v.codigo == codigoBuscado && v.disponible == 1 && !vendido) {
            v.disponible = 0;
            fprintf(ventas, "%s %d %s %s %.2f\n",
                    cliente, v.codigo, v.marca, v.modelo, v.precio);
            vendido = 1;
            printf("Venta registrada correctamente.\n");
        }

        fprintf(temp, "%d %d %s %s %s %.2f %d %d\n",
                v.codigo, v.anio, v.marca, v.modelo,
                v.color, v.precio, v.esNuevo, v.disponible);
    }

    fclose(vehiculos);
    fclose(temp);
    fclose(ventas);

    remove("vehiculos.txt");
    rename("temp.txt", "vehiculos.txt");

    if (!vendido) {
        printf("Vehiculo no disponible o codigo incorrecto.\n");
    }
}

#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;

    do {
        printf("\n MENU \n");
        printf("1. Ingresar productos\n");
        printf("2. Mostrar productos\n");
        printf("3. Calcular total del inventario\n");
        printf("4. Producto mas caro y mas barato\n");
        printf("5. Calcular promedio de precios\n");
        printf("6. Buscar producto por nombre\n");
        printf("7. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarProductos();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                calcularTotal();
                break;
            case 4:
                mostrarMasCaroYMasBarato();
                break;
            case 5:
                calcularPromedio();
                break;
            case 6:
                buscarProducto();
                break;
            case 7:
                printf("GRACIAS \n");
                break;
            default:
                printf("Opcion no valida. Intenta otra vez.\n");
                break;
        }
    } while(opcion != 7);

    return 0;
}
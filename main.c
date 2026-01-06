#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    float presupuesto;
    char marca[30];

    do {
        printf("\n--- SISTEMA Ruedas de Oro ---\n");
        printf("1. Registrar vehiculo\n");
        printf("2. Mostrar vehiculos\n");
        printf("3. Buscar vehiculos por presupuesto y marca\n");
        printf("4. Registrar venta\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarVehiculo();
                break;
            case 2:
                mostrarVehiculos();
                break;
            case 3:
                printf("Presupuesto: ");
                scanf("%f", &presupuesto);
                printf("Marca: ");
                scanf("%s", marca);
                buscarVehiculos(presupuesto, marca);
                break;
            case 4:
                registrarVenta();
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}

#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    int codigo;
    int anio;
    char marca[30];
    char modelo[30];
    char color[20];
    float precio;
    int esNuevo;
    int disponible;
} Vehiculo;

void registrarVehiculo();
void mostrarVehiculos();
void buscarVehiculos(float presupuesto, char marca[]);
void registrarVenta();

#endif

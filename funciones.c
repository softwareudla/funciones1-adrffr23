#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarCantidad() {
    int cantidad;
    printf("Ingrese el número de productos (máximo %d): ", MAX_PRODUCTOS);
    scanf("%d", &cantidad);
    getchar(); // Limpiar el buffer

    // Validar cantidad de productos
    do{
        if (cantidad > MAX_PRODUCTOS) {
        printf("No se puede ingresar más de %d productos.\n", MAX_PRODUCTOS);
        printf("Ingrese el número de productos (máximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &cantidad);
        getchar();
    }
    }while(cantidad > MAX_PRODUCTOS);
    return cantidad;
}

void ingresarDatos(char productos[][30], float precios[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nIngrese el nombre del Producto %d: ", i + 1);
        //getchar();
        fgets(productos[i], 30, stdin);
        productos[i][strcspn(productos[i], "\n")] = 0; // Eliminar salto de línea

        printf("Ingrese el precio del Producto %d: ", i + 1);
        while (scanf("%f", &precios[i]) != 1) {
            printf("Entrada invalida. Ingrese el precio del Producto %d: ", i + 1);
            while (getchar() != '\n'); // Limpiar buffer
        }
        getchar(); // Limpiar el buffer
    }
}

float calcularTotal(float precios[MAX_PRODUCTOS], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}
void encontrarCaros(float precios[MAX_PRODUCTOS], char productos[MAX_PRODUCTOS][30], int cantidad, char productoCaro[30], char productoBarato[30]) {
    float maxPrecio = precios[0];
    float minPrecio = precios[0]; // Inicializa con el primer precio

    for (int i = 0; i < 30; i++) {
        productoCaro[i] = productos[0][i]; // Inicializa con el primer producto
        productoBarato[i] = productos[0][i]; // Inicializa con el primer producto
    }

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > maxPrecio) {
            maxPrecio = precios[i];
            for (int j = 0; j < 30; j++) {
                productoCaro[j] = productos[i][j]; // Actualiza el producto más caro
            }
        }
        if (precios[i] < minPrecio) {
            minPrecio = precios[i];
            for (int j = 0; j < 30; j++) {
                productoBarato[j] = productos[i][j]; // Actualiza el producto más barato
            }
        }
    }

    printf("Producto mas caro: %s\n", productoCaro);
    printf("Producto mas barato: %s\n", productoBarato);
}
float calcularPromedio(float precios[MAX_PRODUCTOS], int cantidad) {
    if (cantidad == 0) return 0;
    return calcularTotal(precios, cantidad) / cantidad;
}

void buscarProducto(char productos[MAX_PRODUCTOS][30], float precios[MAX_PRODUCTOS], int cantidad, char nombreBuscado[30]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcasecmp(productos[i], nombreBuscado) == 0) {
            printf("El precio de %s es: %.2f\n", productos[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

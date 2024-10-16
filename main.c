#include <stdio.h>
#include "funciones.h"
#include <string.h>

int main() {
    char productos[MAX_PRODUCTOS][30];
    float precios[MAX_PRODUCTOS];
    int cantidad;
    int continuar;

    do {
         int n=ingresarCantidad();
        // Ingreso de datos
        ingresarDatos(productos, precios, n);

        // Cálculo del total
        float total = calcularTotal(precios, n);
        printf("\nTotal del inventario: %.2f\n", total);

        // Encontrar productos más caro y más barato
        char productoCaro[30], productoBarato[30];
        encontrarCaros(precios, productos, n, productoCaro, productoBarato);
        
        // Cálculo del precio promedio
        float promedio = calcularPromedio(precios, n);
        printf("Precio promedio: %.2f\n", promedio);

        // Búsqueda de producto
        char nombreBuscado[30];
        char buscarOtro;
        do {
            printf("Ingrese el nombre del producto a buscar: ");
            fgets(nombreBuscado, 30, stdin);
            nombreBuscado[strcspn(nombreBuscado, "\n")] = 0; // Eliminar el salto de línea
            buscarProducto(productos, precios, n, nombreBuscado);

            printf("Desea buscar otro producto? (s/n): ");
            scanf(" %c", &buscarOtro);
            getchar(); // Limpiar el buffer
        } while (buscarOtro == 's' || buscarOtro == 'S');
        continuar= 0;
    } while (continuar == 1);

    return 0;
}

#define MAX_PRODUCTOS 10

void ingresarDatos(char productos[MAX_PRODUCTOS][30], float precios[MAX_PRODUCTOS], int cantidad);
float calcularTotal(float precios[MAX_PRODUCTOS], int cantidad);
void encontrarCaros(float precios[MAX_PRODUCTOS], char productos[MAX_PRODUCTOS][30], int cantidad, char productoCaro[30], char productoBarato[30]);
float calcularPromedio(float precios[MAX_PRODUCTOS], int cantidad);
void buscarProducto(char productos[MAX_PRODUCTOS][30], float precios[MAX_PRODUCTOS], int cantidad, char nombreBuscado[30]);
int ingresarCantidad();
void ingresarDatos(char productos[][30], float precios[], int cantidad);
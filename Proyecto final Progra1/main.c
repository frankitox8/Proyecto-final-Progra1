#include <stdio.h>
#include <stdlib.h>
#define DIMTEXTO 30
typedef struct{
int id;
char nombre[DIMTEXTO];
float precio;

}stProducto

typedef struct{
int id;
char categoria[DIMTEXTO];
}stTransporte

typedef struct{
    int id;
    int dni;
    char nombre[DIMTEXTO];
    int edad;
    char puesto[DIMTEXTO];
}stEmpleado

typedef struct{
    int id;
    int dni;
    char nombre[DIMTEXTO];
    stProducto carrito[DIMTEXTO];
}stCliente

int main()
{


    return 0;
}



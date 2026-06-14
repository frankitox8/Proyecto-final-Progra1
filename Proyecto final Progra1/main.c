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

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op = 0;
    do
    {
        printf("\nIngrese la opcion: \n");
        printf("_________________________________\n");
        printf("| [1] |\n")
        printf("| [2] |\n")
        printf("| [3] |\n")
        printf("| [4] |\n")
        printf("| [5] |\n")
        printf("| [6] |\n")
        printf("| [7] |\n")
        printf("| [0] FINALIZAR EL PROGRAMA     |\n");
        printf("---------------------------------");
    }while(op != 0);
}

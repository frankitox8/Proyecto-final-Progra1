#include <stdio.h>
#include <stdlib.h>

#define DIMTEXTO 30

typedef struct
{
    int id;
    char nombre[DIMTEXTO];
    float precio;
}stProducto;

typedef struct
{
    int id;
    char categoria[DIMTEXTO];
}stTransporte;

typedef struct
{
    int id;
    int dni;
    char nombre[DIMTEXTO];
    int edad;
    char puesto[DIMTEXTO];
}stEmpleado;

typedef struct
{
    int id;
    int dni;
    char nombre[DIMTEXTO];
    stProducto carrito[DIMTEXTO];
}stCliente;

int main()
{
    return 0;
}

//ABMCL DE CLIENTE
//ALTA CLIENTE
stCliente crearCliente()
{
    stCliente aux;
    printf("_______________________________\n");
    printf("Ingrese el ID del cliente: \n");
    scanf("%i", &aux.id);
    printf("Ingrese el DNI del cliente: \n");
    scanf("%i", &aux.dni);
    printf("Ingrese el nombre del cliente: \n");
    scanf(" %s", &aux.nombre);
    printf("-------------------------------\n");
    return aux;
}

void altaArchivoDeClientes(char nombre[])
{
    stCliente aux;
    FILE *archi = fopen(nombre, "ab");
    if(archi != NULL)
    {
        aux = crearCliente();
        if()
        {

        }
        fclose(archi);
    }
}

int verificacionDeElementos(FILE *archi, stCliente clienteNuevo)
{
    int existe = 0;
    if()
    {

    }
    return existe;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
    int activo;
}stCliente;

void menu();
void barraCarga();
void menuClientes();
void menuProducto();
void menuEmpleado();
//ALTA
stCliente crearCliente();
void altaClientesArchivo(char nombre[]);
int verificacionDeElementos(FILE *archi, stCliente clienteNuevo);
//BAJA
void bajaDeClienteDeArchivo(char nombre[], int id);
//MODIFICACION
void modificarClienteDeArchivo(char nombre[], int id);
stCliente modificarCliente(FILE *archi, int id);
//CONSULTA


int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    do
    {
            printf("Ingrese una opcion:\n");
            printf("_________________\n");
            printf("|\x1b[34m[1] CLIENTE\x1b[0m    |\n");
            printf("|\x1b[33m[2] EMPLEADO\x1b[0m   |\n");
            printf("|\x1b[32m[3] PRODUCTO\x1b[0m   |\n");
            printf("|\x1b[31m[0] SALIR\x1b[0m      |\n");
            printf("-----------------\n");
            if (scanf("%i", &op) != 1)
            {
                printf("Error:~ ~ ~ DEBE INGRESAR UNA OPCION VALIDA ~ ~ ~\n");
                while (getchar() != '\n');
                op = -1;
                system("pause");
            }
            system("cls");
        switch(op)
        {
        default:
            {
                printf("~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~\n");
                system("pause");
                system("cls");
            }break;
        case 1:
            {
                barraCarga();
                menuClientes();
            }break;
        case 2:
            {
                menuEmpleado();
            }break;
        case 3:
            {
                menuProducto();
            }break;
        case 0:
            {
                printf("- - - FINALIZANDO EL PROGRAMA - - -\n");
            }break;
        }
    }while(op != 0);
}

void barraCarga()
{
    system("cls");
    char cian[] = "\x1b[36m";
    char verde[] = "\x1b[32m";
    char reset[] = "\x1b[0m";
    printf("\n\n\n\n\n");
    printf("                                    %sCargando sistema...%s\n", cian, reset);
    printf("                                    [");
    for (int i = 0; i < 25; i++)
    {
        printf("%s%c%s", verde, 219, reset);
        Sleep(80);
    }
    printf("] 100%%\n");
    Sleep(500);
    system("cls");
}

void menuClientes()
{

}

void menuEmpleado()
{

}

void menuProducto()
{

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
    aux.activo = 1;
    printf("-------------------------------\n");
    return aux;
}

void altaClientesArchivo(char nombre[])
{
    int existe;
    stCliente aux;
    FILE *archi = fopen(nombre, "a+b");
    if(archi != NULL)
    {
        aux = crearCliente();
        verificacionDeElementos(archi, aux);
        if(existe == 1)
        {
            printf("\n- - - ESTE CLIENTE YA EXISTE - - -\n");
        }
        else
        {
            fwrite(&aux, sizeof(stCliente), 1, archi);
        }
        fclose(archi);
    }
}

int verificacionDeElementos(FILE *archi, stCliente clienteNuevo)
{
    stCliente aux;
    int existe = 0;
    fseek(archi, 0, SEEK_SET);
    while(fread(&aux, sizeof(stCliente), 1, archi) > 0)
    {
        if(aux.id == clienteNuevo.id && aux.dni == clienteNuevo.dni)
        {
            existe = 1;
        }
    }
    return existe;
}

//BAJA DE CLIENTE
void bajaDeClienteDeArchivo(char nombre[], int id)
{
    stCliente aux;
    FILE *archi = fopen(nombre, "r+b");
    if(archi != NULL)
    {
        if(fread(&aux, sizeof(stCliente), 1, archi) > 0)
        {
            if(aux.id == id)
            {
                aux.activo = 0;
            }
        }
        fclose(archi);
    }
}

//MODIFICACION DE CLIENTE
void modificarClienteDeArchivo(char nombre[], int id)
{
    FILE *archi = fopen(nombre, "r+b");
    if(archi != NULL)
    {
        modificarCliente(archi, id);
        fclose(archi);
    }
}

stCliente modificarCliente(FILE *archi, int id)
{
    char op = 'n';
    stCliente aux;
    if(fread(&aux, sizeof(stCliente), 1, archi) > 0)
        {
            if(aux.id == id)
            {
                printf("Quiere modificar el DNI? (s/n): ");
                if(op == 's')
                {
                    printf("\nIngrese el nuevo DNI: ");
                    scanf("%i", &aux.dni);
                }
                printf("Quiere modificar el nombre? (s/n): ");
                if(op == 's')
                {
                    printf("\nIngrese el nuevo nombre: ");
                    scanf(" %s", &aux.nombre);
                }
                printf("Quiere modificar el carrito? (s/n): ");
                if(op == 's')
                {
                    printf("\nIngrese el nuevo carrito: ");
                    //LLAMAR FUNCION DE CREAR CARRITO !!!!
                }
            }
        }
    return aux;
}

//CONSULTA DE CLIENTE
void mostrarClienteEnArchivo()
{

}

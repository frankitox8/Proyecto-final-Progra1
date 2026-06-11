#include <stdio.h>
#include <stdlib.h>
#define DIMTEXTO 30
typedef struct
{
    int id;
    char nombre[DIMTEXTO];
    float precio;

} stProducto;

typedef struct
{
    int id;
    char categoria[DIMTEXTO];
} stTransporte;

typedef struct
{
    int id;
    int dni;
    char nombre[DIMTEXTO];
    int edad;
    char puesto[DIMTEXTO];
    int alta;
} stEmpleado;

typedef struct
{
    int id;
    int dni;
    char nombre[DIMTEXTO];
    stProducto carrito[DIMTEXTO];
} stCliente;

void crearUnEmpleado(stEmpleado* aux, int *id);
void altaEmpleado(char nombreArchivo[],int *id);

int main()
{
    char archiEmpleado[]="empleados.bin";
    int rta;

    printf("ingrese una opcion: "
           "1. Sistema Empleados.\n"
           "2. Sistema Cliente.\n"
           "3. salir.\n\n");
           scanf(" %i", &rta);

           switch(rta){

       case 1: int opcionE, int dniEmpleado;

       printf("ingrese su dni: ");
       scanf(" %i", &dniEmpleado);

       if(consultaEmpleado(dniEmpleado, archiEmpleado)==1){
           do{
           printf("\n----- Menu Empleados -----\n\n");

           printf("Ingrese una opcion: "
                  "1. Alta empleado."
                  "2. Baja empleado."
                  "3. Modificar Empleado."
                  "4. Buscar Empleado."
                  "5. Listar Empleado Actual.");
                  scanf(" %i",&opcionE);

                  switch(opcionE){
                  case 1: altaEmpleado(archiEmpleado,&idEmpleado);
                  break;

                  case 2: bajaEmpleado(dniEmpleado,archiEmpleado);
                  }

           }
       }

        break;

       case 2:
        break;
        printf("Gracias. ");
        case 3: return 0;

        default: printf("ingrese una opcion valida.\n");
           }

    altaEmpleado(archiEmpleado,&idEmpleado);

    return 0;
}

void crearUnEmpleado(stEmpleado* aux, int *id)
{
    (*id)++;

    (*aux).id=(*id);
    (*aux).alta=1;
    printf("ingrese dni: ");
    scanf(" %i",&(*aux).dni);

    int edadAux;
    do
    {

        printf("ingrese edad: ");
        scanf(" %i",&edadAux);
    }
    while(edadAux<18 || edadAux>60);

    printf("ingrese nombre: ");
    scanf(" %s",&(*aux).nombre);

    printf("ingrese puesto: ");

    scanf(" %s",&(*aux).puesto);
}

void altaEmpleado(char nombreArchivo[],int *id)
{
    FILE *archi=fopen(nombreArchivo,"ab");


    if(archi!=NULL)
    {
        stEmpleado aux;
        char rta='s';

        while(rta=='s')
        {


            crearUnEmpleado(&aux,id);
            fwrite(&aux,sizeof(stEmpleado),1,archi);

            printf("ingrese(s) para seguir cargando empleados: ");
            scanf(" %c", &rta);
        }
        fclose(archi);
    }
}

void mostrarUnEmpleado(stEmpleado aux)
{

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("id: %i \n",aux.id);

    printf("nombre: %s \n",aux.nombre);
    printf("Dni: %i \n",aux.dni);
    printf("puesto: %s \n",aux.puesto);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}

void listarEmpleadoRecursiva(FILE*archi)
{
    stEmpleado aux;

    if(fwrite(&aux,sizeof(stEmpleado),1,archi)>0)
    {
        if(aux.alta==1)
        {
            mostrarUnEmpleado(aux);
        }
        listarEmpleadoRecursiva(archi);
    }
}

int bajaEmpleado(int dniBuscado, char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo,"r+b");
    int flag=0;

    if(archi!=NULL)
    {
        int dim=ftell(archi)/sizeof(stEmpleado);
        stEmpleado arr[dim];
        int i=0;

        fread(&arr,sizeof(stEmpleado),dim,archi);

        while(i<dim && flag==0)
        {
            if(arr[i].dni==dniBuscado)
            {
                arr[i].alta--;
                flag++;
            }
        }
        i=0;

        if(flag==1)
        {
            fseek(archi,0,SEEK_SET);

            while(i<dim)
            {
                fwrite(&arr[i],sizeof(stEmpleado),1,archi);
            }
        }

        fclose(archi);
    }
    return flag;
}
stEmpleado modificarUnEmpleado(stEmpleado original, char nombreArchivo[]){
int opcion;
stEmpleado moddeado;
char rta='s';

while(rta=='s'){
printf("ingrese una opcion: ");
printf("1. dni.\n"
       "2. nombre.\n"
       "3.Puesto.\n"
       "4. edad.\n"
       "5. alta.\n\n");

       printf("estado actual: ");
       mostrarUnEmpleado(original);
       printf("\n");

        scanf("%i", &opcion);


       switch (opcion){
           case 1: printf("ingrese nuevo dni: ");
                    scanf("%i",&original.dni);
                    printf("\n");
                    break;

        case 2: printf("ingrese nuevo nombre: ");
                gets(original.nombre);
                printf("\n");
                break;

        case 3: printf("ingrese nuevo puesto: ");
                gets(original.puesto);
                printf("\n");
                break;

        case 4: do{printf("ingrese nueva edad (recordar ser mayor de 18 y menor a 60): ");
                    scanf("%i",&original.edad);
                    printf("\n");
                    }while(original.edad<18 || original.edad>60);

        case 5: if(original.alta==0){
        original.alta=1;
        }
        else{
        printf("opcion invalida; usar opcion Baja de empleado para esto.\n");
        }
        break;

        default: printf("opcion invalida, intentelo nuevamente.\n");

}
printf("ingrese (s) para continuar: ");
scanf(" %c", &rta);
}
}

int consultaEmpleado(char nombreArchivo[], int dniEmpleado){
FILE *archi= fopen(nombreArchivo,"rb");
 int flag=0;

if(archi!=NULL){
    stEmpleado aux;

    while(fread(&aux,sizeof(stEmpleado),1,archi)>0 && flag ==0){
        if(aux.dni==dniEmpleado){
            flag++;
        }
    }


fclose(archi);
}
return flag;
}

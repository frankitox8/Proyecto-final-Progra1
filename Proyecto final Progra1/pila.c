#include "pila.h"


void inicpila(P_Pila p)
{
       stEmpleado *aux;            ///mod empleado?
       aux = (stEmpleado *)malloc(50*sizeof(stEmpleado));
       p->valores = aux;
       p->postope=0;
}
                        ///mod. empleado?
void apilar(P_Pila p, stEmpleado dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

stEmpleado desapilar(P_Pila p)
{
       int z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

stEmpleado tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}

#include <stdio.h>
#include <malloc.h>
#define Pila struct _Pila
#define P_Pila struct _Pila *

struct _Pila
{
    stEmpleado *valores;
    int postope;
};

void inicpila(P_Pila p);
void apilar(P_Pila p, stEmpleado dato);
void apilar(P_Pila p, stEmpleado dato);
stEmpleado desapilar(P_Pila p);
stEmpleado tope(P_Pila p);
int pilavacia(P_Pila p);

void mostrar(P_Pila p);



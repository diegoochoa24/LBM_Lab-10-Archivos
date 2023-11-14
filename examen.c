#include "estructuras.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){
    srand(time(NULL));
    int n;

    printf("Dime la cantidad de figuras por hacer: \n");
    scanf("%d", &n);

    QUAD *lista = (QUAD*)calloc(n, sizeof(QUAD));

    for(int i = 0; i < n; i ++){
        crearFigura(&lista[n]);
        calcularPropiedades(&lista[n]);
        imprimirFigura(lista[n]);
    }

    free(lista);

    return 0;
}

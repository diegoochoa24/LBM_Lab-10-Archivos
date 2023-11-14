#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void crearFigura(QUAD *figura){
    (figura)->width = rand() % 5 + 1;
    (figura)->height = rand() % 5 + 1;
    (figura)->c.x = rand() % 5 + 1;
    (figura)->c.y = rand() % 5 + 1;
}


void calcularPropiedades(QUAD *figura){
    (figura)->p.centro = calcularCentro(figura);
    (figura)->p.area = calcularArea(figura);
    (figura)->p.perimetro = calcularPerimetro(figura);
}

float m(segmento xy){
    float m = (xy.a.y - xy.b.y)/(xy.a.x - xy.b.x);
    return m;
}

float d(segmento xy){
    float d = sqrt(pow(xy.a.x - xy.b.x, 2) + pow(xy.a.y - xy.b.y, 2));
    return d;
}


coordenada calcularCentro(QUAD *lista){

    coordenada c1 = {lista->c.x, lista->c.y};
    coordenada c2 = {lista->c.x + lista->width, lista->c.y};
    coordenada c3 = {lista->c.x + lista->width, lista->c.y + lista->height};
    coordenada c4 = {lista->c.x, lista->c.y + lista->height};

    segmento bd = {c2, c4};

    segmento ac = {c1, c3};

    float xc = (-1 * m(bd) * (lista->c.x + lista->height) + m(ac) * lista->c.x + lista->width) / (m(ac) - m(bd));

    float yc = m(bd)*(xc - lista->c.x) + lista->c.y;

    coordenada centro = {xc, yc};
    return centro;
}

float calcularArea(QUAD *lista){
    coordenada c1 = {lista->c.x, lista->c.y};
    coordenada c2 = {lista->c.x + lista->width, lista->c.y};
    coordenada c3 = {lista->c.x + lista->width, lista->c.y + lista->height};

    segmento ab = {c1 , c2};
    segmento bc = {c2, c3};

    float A = d(ab) * d(bc);
    return A;
}

float calcularPerimetro(QUAD *lista){
    coordenada c1 = {lista->c.x, lista->c.y};
    coordenada c2 = {lista->c.x + lista->width, lista->c.y};
    coordenada c3 = {lista->c.x + lista->width, lista->c.y + lista->height};

    segmento ab = {c1 , c2};
    segmento bc = {c2, c3};

    float A = 2*(d(ab) + d(bc));
    return A;
}
 
 void imprimirFigura(QUAD lista){

    coordenada c1 = {lista.c.x, lista.c.y};
    coordenada c2 = {lista.c.x + lista.width, lista.c.y};
    coordenada c3 = {lista.c.x + lista.width, lista.c.y + lista.height};
    coordenada c4 = {lista.c.x, lista.c.y + lista.height};

    printf("\n==== QUAD ==== \n");
    printf("[d](%.2f, %.2f)", c4.x, c4.y);
    printf(" -------------- ");
    printf("(%.2f, %.2f)[c] \n",  c3.x, c3.y);
    printf("| \t\t(%.2f, %.2f)\t\t | \n", lista.p.centro.x, lista.p.centro.y);
    printf("[a](%.2f, %.2f)", c1.x, c1.y);
    printf(" -------------- ");
    printf("(%.2f, %.2f)[b] \n",  c2.x, c2.y);
    printf("Area =  %.2f\n", lista.p.area);
    printf("Perimetro = %.2f \n", lista.p.perimetro);
 }


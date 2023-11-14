#pragma once
#include "estructuras.h"

// funciones examen

void crearFigura(QUAD *lista);

float m(segmento xy);
float d(segmento xy);

void calcularPropiedades(QUAD *lista);
coordenada calcularCentro(QUAD *lista);
float calcularArea(QUAD *lista);
float calcularPerimetro(QUAD *lista);
float calcularDistancia(QUAD *lista);

void imprimirFigura(QUAD lista);



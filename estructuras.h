#pragma once

typedef struct coordenada
{
    float x;
    float y;  
} coordenada;

typedef struct segmento
{
    coordenada a;
    coordenada b; 
} segmento;

typedef struct propiedades
{
    coordenada centro;
    float area;
    float perimetro;
    
} propiedades;

typedef struct QUAD
{
    coordenada c;
    float width;
    float height;
    propiedades p; 
} QUAD;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fgets(nombre, sizeof(nombre), stdin);

#define ANHO_ACT 2026
#define MAX_PANDAS 24
typedef struct {
    int dia;
    int mes;
    int anho;
} Fecha;

typedef struct {
    char *nombre;
    float peso;
    int anac;
    char sexo;
    Fecha *ingreso;
} Panda;

int edad_panda(Panda *p);
int tenerBebe(Panda *p);
void imprimePanda(Panda *p);
void agregarPanda(Panda Poblacion[], int tp);
Panda *buscarPanda(Panda Poblacion[],int, char *n);
void listarPandas(Panda Poblacion[], int total);
void listarReproductivas(Panda Poblacion[], int total);
int contarIngresos(Panda Poblacion[], int total, int anho);
Panda *masViejo(Panda Poblacion[], int total);
Panda *masJoven(Panda Poblacion[], int total);

void prueba_edad();
void prueba_imprimePanda();
void prueba_agregarPanda();
void prueba_buscarPanda();



#include "funciones.h"

void prueba_edad()
{      
    Panda p;
    p.anac = 2020;
    printf("Edad del panda: %d\n", edad_panda(&p));
}

void prueba_imprimePanda()
{
    Fecha f = {10, 3, 2022};
    Panda p;

    p.nombre = "Pandicius JR";
    p.peso = 95.5;
    p.anac = 2018;
    p.sexo = 'H';
    p.ingreso = &f;

    imprimePanda(&p);
}

void prueba_agregarPanda()
{
    Panda poblacion[5];

    agregarPanda(poblacion, 0);
    imprimePanda(&poblacion[0]);

    agregarPanda(poblacion, 1);
    imprimePanda(&poblacion[1]);
}

void prueba_buscarPanda()
{
    Fecha f = {10, 3, 2022};
    Panda poblacion[2];
    Panda *encontrado;

    poblacion[0].nombre = "Erling Panda";
    poblacion[0].peso = 95.5;
    poblacion[0].anac = 2018;
    poblacion[0].sexo = 'H';
    poblacion[0].ingreso = &f;

    poblacion[1].nombre = "Panda AA";
    poblacion[1].peso = 110.0;
    poblacion[1].anac = 2015;
    poblacion[1].sexo = 'M';
    poblacion[1].ingreso = &f;

    encontrado = buscarPanda(poblacion, 2, "Panda AA");
    if (encontrado != NULL)
        imprimePanda(encontrado);
    else
        printf("No se encontro el panda\n");

    encontrado = buscarPanda(poblacion, 2, "Panda G");
    if (encontrado != NULL)
        imprimePanda(encontrado);
    else
        printf("No se encontro el panda\n");
}

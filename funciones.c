#include "funciones.h"

int edad_panda(Panda *p)
{
    return ANHO_ACT - p->anac;
}

int tenerBebe(Panda *p)
{
    if (p->sexo == 'H' && edad_panda(p) > 5)
        return 1;
    else
        return 0;
}

void imprimePanda(Panda *p)
{
    printf("\nNombre: %s", p->nombre);
    printf("\nSexo: %c", p->sexo);
    printf("\nPeso: %.2f", p->peso);
    printf("\nAnho de nacimiento: %d", p->anac);
    printf("\nEdad: %d años", edad_panda(p));
    printf("\nFecha de ingreso: %d/%d/%d\n",
    p->ingreso->dia, p->ingreso->mes, p->ingreso->anho);
}

void agregarPanda(Panda Poblacion[], int tp)
{
    Panda *p = &Poblacion[tp];

    p->nombre = malloc(50);
    printf("\nNombre: ");
    fgets(p->nombre, 50, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    do
    {
    printf("Peso: ");
    scanf("%f", &p->peso);
    if (p->peso <= 0)
    printf("El peso debe ser mayor a 0\n");
    } while (p->peso <= 0);

    do
    {
    printf("Anho de nacimiento: ");
    scanf("%d", &p->anac);
    } while (p->anac > ANHO_ACT || p->anac <= 0);

    do
    {
        printf("Sexo (H = hembra, M = macho): ");
        scanf(" %c", &p->sexo);
        if (p->sexo != 'H' && p->sexo != 'M')
            printf("Revisa tu entrada. Ingresa un valor valido\n");
    } while (p->sexo != 'H' && p->sexo != 'M');

    p->ingreso = malloc(sizeof(Fecha));
    printf("Datos de ingreso del panda\n");
    printf("Dia: ");
    scanf("%d", &p->ingreso->dia);
    printf("Mes: ");
    scanf("%d", &p->ingreso->mes);
    printf("Anio de ingreso: ");
    scanf("%d", &p->ingreso->anho);
    getchar();   
}

Panda *buscarPanda(Panda Poblacion[], int total, char *n)
{
    int i;

    for (i = 0; i < total; i++)
    {
        if (strcmp(Poblacion[i].nombre, n) == 0)
            return &Poblacion[i];
    }

    return NULL;
}

void listarPandas(Panda Poblacion[], int total)
{
    int i;

    for (i = 0; i < total; i++)
        imprimePanda(&Poblacion[i]);
}

void listarReproductivas(Panda Poblacion[], int total)
{
    int i, encontrados = 0;

    for (i = 0; i < total; i++)
    {
        if (tenerBebe(&Poblacion[i]))
        {
            imprimePanda(&Poblacion[i]);
            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("\nNo hay ejemplares en edad reproductiva\n");
}

int contarIngresos(Panda Poblacion[], int total, int anho)
{
    int i, cuenta = 0;

    for (i = 0; i < total; i++)
    {
        if (Poblacion[i].ingreso->anho == anho)
            cuenta++;
    }

    return cuenta;
}

Panda *masViejo(Panda Poblacion[], int total)
{
    int i;
    Panda *viejo;

    if (total == 0)
        return NULL;

    viejo = &Poblacion[0];
    for (i = 1; i < total; i++)
    {
        if (Poblacion[i].anac < viejo->anac)
            viejo = &Poblacion[i];
    }

    return viejo;
}

Panda *masJoven(Panda Poblacion[], int total)
{
    int i;
    Panda *joven;

    if (total == 0)
        return NULL;

    joven = &Poblacion[0];
    for (i = 1; i < total; i++)
    {
        if (Poblacion[i].anac > joven->anac)
            joven = &Poblacion[i];
    }

    return joven;
}
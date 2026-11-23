#include "funciones.h"

    //prueba_edad();
    //prueba_imprimePanda();
    //prueba_agregarPanda();
    //prueba_buscarPanda();

int main()
{  
    Panda poblacion[MAX_PANDAS];
    int total = 0, opcion, anho;
    char nombre[50];
    Panda *p;

    do
    {
        printf("\n--- REGISTRO DE PANDAS ---");
        printf("\n1. Agregar un panda");
        printf("\n2. Lista de todos los ejemplares");
        printf("\n3. Ejemplares que estan en edad reproductiva");
        printf("\n4. Ejemplares que ingresaron en un anho");
        printf("\n5. Buscar panda por nombre");
        printf("\n6. Panda mas joven");
        printf("\n7. Panda mas viejo");
        printf("\n0. Salir");
        printf("\nQue consulta deseas hacer: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
            case 1:
                if (total < MAX_PANDAS)
                {
                    agregarPanda(poblacion, total);
                    total++;
                }
                else
                    printf("\nYa no hay espacio para mas pandas\n");
                break;
            case 2:
                listarPandas(poblacion, total);
                break;
            case 3:
                listarReproductivas(poblacion, total);
                break;
            case 4:
                printf("Anio a consultar: ");
                scanf("%d", &anho);
                printf("Ingresaron %d ejemplares en %d\n",
                       contarIngresos(poblacion, total, anho), anho);
                break;
            case 5:
                printf("Nombre del panda: ");
                fgets(nombre, 50, stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                p = buscarPanda(poblacion, total, nombre);
                if (p != NULL)
                    imprimePanda(p);
                else
                    printf("No se encontro el panda\n");
                break;
            case 6:
                if (total == 0)
                    printf("\nNo hay pandas registrados\n");
                else
                    imprimePanda(masJoven(poblacion, total));
                break;
            case 7:
                if (total == 0)
                    printf("\nNo hay pandas registrados\n");
                else
                    imprimePanda(masViejo(poblacion, total));
                break;
            case 0:
                printf("Hasta la proxima!\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 0);
    return 0;
}
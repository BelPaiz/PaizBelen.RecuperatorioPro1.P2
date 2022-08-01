#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char marca[20];
    int tipo;
    float peso;
    }eVehiculo;

eVehiculo* eVehiculo_new();
eVehiculo* new_vehiculoParam(int id, char* marca, int tipo,  float peso);
int main()
{
    eVehiculo* unVehiculo = new_vehiculoParam(125, "Ford", 95, 235.42);
    if(unVehiculo != NULL)
    {
        FILE* f = fopen("vehiculo.csv", "w");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        else
        {
            fprintf(f,"%d,%s,%d,%f\n", unVehiculo->id, unVehiculo->marca, unVehiculo->tipo, unVehiculo->peso);
            fclose(f);
        }

        FILE* b = fopen("vehiculo.bin", "wb");
        if(b == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        else
        {
            fwrite(unVehiculo, sizeof(eVehiculo), 1, b);
            fclose(b);
        }

    }

    return 0;
}

eVehiculo* eVehiculo_new()
{
    eVehiculo* nuevVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
    if(nuevVehiculo != NULL)
    {
        nuevVehiculo->id = 0;
        strcpy(nuevVehiculo->marca, "");
        nuevVehiculo->tipo = 0;
        nuevVehiculo->peso = 0;
    }
    return nuevVehiculo;
}

eVehiculo* new_vehiculoParam(int id, char* marca, int tipo,  float peso)
{
    eVehiculo* nuevVehiculo = eVehiculo_new();
    if(nuevVehiculo != NULL && marca != NULL)
    {
        if(!(nuevVehiculo->id = id) &&
        (strcpy(nuevVehiculo->marca, marca)) &&
        (nuevVehiculo->tipo = tipo) &&
        (nuevVehiculo->peso = peso))
        {
           free(nuevVehiculo);
            nuevVehiculo = NULL;
        }

    }

    return nuevVehiculo;
}

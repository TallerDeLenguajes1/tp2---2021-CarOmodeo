#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct computadora
{
    int velocidad;
    int anio;
    int cantNucleos;
    char *tipo_cpu;
} PC;

void cargarEstructura(PC *arreglo, int tamanio, char *tipos);
PC devolverPC(PC estructura, char *tipos);
void mostrar(PC *arreglo, int indice);
int masVieja(PC *arreglo, int tamanio);
int masRapido(PC *arreglo, int tamanio);

int main(){
    srand(time(NULL));
    int cantidad, Vieja, rapida;
    PC *arregloCompus;
    PC maquina;
    char tipos[6][10] = {"Interl", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    printf("Cantidad de computadoras a ingresar: ");
    scanf("%d", &cantidad);

    arregloCompus = (PC*)malloc(sizeof(PC)*cantidad);

    cargarEstructura(arregloCompus, cantidad, &tipos[0][0]);

    maquina = devolverPC(maquina, &tipos[0][0]);

    printf("Las caractereisticas de la PC son: \n");
    mostrar(&maquina, 0);
    free(maquina.tipo_cpu);

    printf("\n");

    for(int i = 0; i < cantidad; i++){
        printf("Las caractereisticas de la PC %d son: \n", i);
        mostrar(arregloCompus, i);
    }

    printf("\n");

    Vieja = masVieja(arregloCompus, cantidad);

    printf("Las PC mas vieja es: \n");
    mostrar(arregloCompus, Vieja);

    printf("\n");

    rapida = masRapido(arregloCompus, cantidad);

    printf("Las PC mas rapida es: \n");
    mostrar(arregloCompus, rapida);
    
    for(int i = 0; i <cantidad; i++){
        free((arregloCompus)->tipo_cpu);
        free(arregloCompus + i);
    }
    free(arregloCompus);

    return 0;
}

PC devolverPC(PC estructura, char *tipos)
{
    int indiceTipoCpu;
    estructura.velocidad = rand() % 3 + 1;
    estructura.anio = rand() % 17 + 2000;
    estructura.cantNucleos = rand() % 4 + 1;
    indiceTipoCpu = rand() % 6;
    estructura.tipo_cpu = (char*)malloc(sizeof(char)*10);
    strcpy(estructura.tipo_cpu, (tipos + (indiceTipoCpu*10)));
    return estructura;
}

void cargarEstructura(PC *arreglo, int tamanio, char *tipos)
{
    int indiceTipoCpu;
    
    for(int i = 0; i < tamanio; i++){
        (arreglo + i)->velocidad = rand() % 3 + 1;
        (arreglo + i)->anio = rand() % 17 + 2000;
        (arreglo + i)->cantNucleos = rand() % 4 + 1;
        indiceTipoCpu = rand() % 6;
        (arreglo + i)->tipo_cpu = (char*)malloc(sizeof(char)*10); 
        strcpy((arreglo + i)->tipo_cpu, (tipos + indiceTipoCpu*10));
    }
}

void mostrar(PC *arreglo, int indice)
{    
    printf("Velocidad: %d Ghz \n", (arreglo + indice)->velocidad);
    printf("Anio: %d \n", (arreglo + indice)->anio);
    printf("Cantidad de Nucleos: %d \n", (arreglo + indice)->cantNucleos);
    printf("Tipo de CPU: %s \n", (arreglo + indice)->tipo_cpu);
}

int masVieja(PC *arreglo, int tamanio)
{
    int min = 10000;
    int indice;
    for(int i = 0; i < tamanio; i++){
        if((arreglo + i)->anio < min){
            min = (arreglo + i)->anio;
            indice = i;
        }
    }
    return indice;
}

int masRapido(PC *arreglo, int tamanio)
{
    int max = 0;
    int indice;
    for(int i = 0; i < tamanio; i++){
        if((arreglo + i)->velocidad > max){
            max = (arreglo + i)->velocidad;
            indice = i;
        }
    }
    return indice;
}
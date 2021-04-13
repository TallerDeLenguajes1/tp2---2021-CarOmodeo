#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 15

int esPar(int num);

int main(){
    srand(time(NULL));
    int **mt;
    int *pares;
    int c, contPar;

    mt = (int**)malloc(sizeof(int*)*N);
    pares = (int*)malloc(sizeof(int)*N);
    c = rand()% 11 + 5;

    for(int i = 0; i < N; i++){
        *(mt + i) = (int*)malloc(sizeof(int)*c);

        for(int j = 0; j < c; j++){
            *(*(mt + i)+ j) = rand()% 900 + 100;
        }
    }

    for(int i = 0; i < N; i++){
        for (int j = 0; j < c; j++){
            printf("%d ", *(*(mt + i)+ j));
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        contPar = 0;
        for(int j = 0; j < c; j++){
            contPar += esPar(*(*(mt + i) + j));
        }

        printf("La fila %d tiene %d numeros pares \n", i, contPar);
        
        //Apartado B
        *(pares + i) = contPar; 
    }

    printf("El vector de la cantidad de pares por fila es: \n");
    for(int i = 0; i < N; i++){
        printf("%d ", *(pares + i));
    }

    return 0;
}

//Apartado A
int esPar(int num){
    if(num % 2 != 0){
        return 0;
    }
    return 1;
}
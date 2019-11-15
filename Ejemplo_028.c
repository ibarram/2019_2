#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int aleatorio(float *pX, int n, float max, float min)
{
    int i;
    srand(time(NULL));
    if(pX==NULL)
        return -1;
    for(i=0; i<n; i++)
        pX[i] = (((max-min)*rand())/RAND_MAX)+min;
    return 0;
}

int imprimir(float *pX, int n)
{
    int i;
    if(pX==NULL)
        return -1;
    for(i=0; i<n; i++)
        printf("X[%d] = %f\n", i+1, pX[i]);
    return 0;
}

int imprimir2(float **ppX, int n)
{
    int i;
    if(ppX==NULL)
        return -1;
    for(i=0; i<n; i++)
        printf("X[%d] = %f\n", i+1, *(ppX[i]));
    return 0;
}

int inicializar(float **ppX, float *pX, int n)
{
    int i;
    if(ppX==NULL)
        return -1;
    if(pX==NULL)
        return -2;
    for(i=0; i<n; i++)
        ppX[i]=pX+i; // ppX[i]=&pX[i];->ppX[i]=&*(pX+i);->ppX[i]=pX+i;
    return 0;
}

int burbujar(float **ppX, int n)
{
    int i, j;
    float *aux;
    if(ppX==NULL)
        return -1;
    for(i=0; i<(n-1); i++)
        for(j=i+1;j<n; j++)
            if(*(ppX[i])>*(ppX[j]))
            {
                aux=ppX[i];
                ppX[i]=ppX[j];
                ppX[j]=aux;
            }
    return 0;
}

int main(int argc, char *argv[])
{
    int n;
    float max, min, *pX, **ppX;
    do{
        printf("Ingrese el valor de n: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrese el maximo: ");
    scanf("%f", &max);
    printf("Ingese el minimo: ");
    scanf("%f", &min);
    if(max<min)
    {
        max+=min;
        min=max-min;
        max-=min;
    }
    pX=(float*)malloc(n*sizeof(float));
    if(pX==NULL)
    {
        printf("Error al asignar la memoria.\n");
        return -1;
    }
    ppX=(float**)malloc(n*sizeof(float*));
    if(ppX==NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pX);
        return -2;
    }
    aleatorio(pX, n, max, min);
    printf("Vector desordenado.\n");
    imprimir(pX, n);
    inicializar(ppX, pX, n);
    printf("Vector desordenado.\n");
    imprimir2(ppX, n);
    burbujar(ppX, n);
    printf("Vector ordenado.\n");
    imprimir2(ppX, n);
    free(pX);
    free(ppX);
    return 0;
}
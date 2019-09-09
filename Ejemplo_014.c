#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

int main(int argc, char *argv[])
{
    float x[N], aux, max, min;
    int i, j, n;
    srand(time(NULL));
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    }while(n>N||n<1);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);
    printf("Ingrese le valor maximo: ");
    scanf("%f", &max);
    if(max<min)
    {
        aux=min;
        min=max;
        max=aux;
    }
    printf("[%f, %f]\n", min, max);
    for(i=0; i<n; i++)
    {
        x[i]=((max-min)*rand())/RAND_MAX+min;
        printf("x[%d] = %f\n", i+1, x[i]);
    }
    for(i=1; i<n; i++)
    {
        aux=x[i];
        j=i-1;
        while(aux<x[j])
        {
            x[j+1]=x[j];
            j--;
            if(j<0)
                break;
        }
        x[j+1]=aux;
    }
    for(i=0; i<n; i++)
        printf("x[%d] = %f\n", i+1, x[i]);
    return 0;
}

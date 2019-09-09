#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

int main(int argc, char *argv[])
{
    int i, j, n, x[N], aux, max, min, h[N];
    srand(time(NULL));
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    }while(n>N||n<1);
    printf("Ingrese el valor minimo: ");
    scanf("%d", &min);
    printf("Ingrese le valor maximo: ");
    scanf("%d", &max);
    if(max<min)
    {
        aux=min;
        min=max;
        max=aux;
    }
    printf("[%d, %d]\n", min, max);
    for(i=0; i<n; i++)
    {
        x[i]=(rand()%(max-min+1))+min;
        printf("x[%d] = %d\n", i+1, x[i]);
    }

    for(i=0; i<n; i++)
        printf("x[%d] = %d\n", i+1, x[i]);
    return 0;
}

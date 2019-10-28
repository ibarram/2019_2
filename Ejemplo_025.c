#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int i, j, N;
    float max, min, *pA;
    srand(time(NULL));
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &N);
    }while(N<1);
    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);
    if(max<min)
    {
        max+=min;
        min=max-min;
        max-=min;
    }
    pA=(float*)malloc(N*sizeof(float));
    if(pA==NULL)
    {
        printf("Errror al asignar la memoria.\n");
        return 1;
    }
    for(i=0; i<N; i++)
    {
        pA[i] = ((max-min)*rand())/RAND_MAX+min;
        printf("pA[%d] = %f\n", i+1, pA[i]);
    }
    for(i=0; i<(N-1); i++)
        for(j=(i+1); j<N; j++)
            if(pA[i]>pA[j])
            {
                pA[i]+=pA[j];
                pA[j]=pA[i]-pA[j];
                pA[i]-=pA[j];
            }
    for(i=0; i<N; i++)
        printf("pA[%d] = %f\n", i+1, pA[i]);
    free(pA);
    return 0;
}
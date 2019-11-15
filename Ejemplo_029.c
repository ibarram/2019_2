#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
    float *pA, *pB, *pC, max, min;
    int N1, M1, N2, M2, i, j, k;
    srand(time(NULL));
    do{
        printf("Ingrese el numero de columnas de A: ");
        scanf("%d", &N1);
    }while(N1<1);
    do
    {
        printf("Ingrese el numero de renglones de A: ");
        scanf("%d", &M1);
    } while (M1 < 1);
    do
    {
        printf("Ingrese el numero de columnas de B: ");
        scanf("%d", &N2);
    } while (N2 < 1);
    do
    {
        printf("Ingrese el numero de renglones de B: ");
        scanf("%d", &M2);
    } while (M2 < 1);
    if(M1!=N2)
    {
        printf("Error en el tamanio de las matrices.\n");
        return 1;
    }
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
    pA=(float*)malloc(N1*M1*sizeof(float));
    if(pA==NULL)
    {
        printf("Error al asignar la memoria.\n");
        return 2;
    }
    pB=(float*)malloc(N2*M2*sizeof(float));
    if(pB==NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        return 3;
    }
    pC=(float*)calloc(N1*M2, sizeof(float));
    if(pC==NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        free(pB);
        return 4;
    }
    for (i = 0; i < N1 * M1; i++)
        pA[i] = ((max - min) * rand()) / RAND_MAX + min;
    for (i = 0; i < N2 * M2; i++)
        pB[i] = ((max - min) * rand()) / RAND_MAX + min;
    for (i = 0; i < N1; i++)
        for (j = 0; j < M1; j++)
            printf("A[%d][%d] = %f\n", i + 1, j + 1, pA[i * M1 + j]);
    for (i = 0; i < N2; i++)
        for (j = 0; j < M2; j++)
            printf("B[%d][%d] = %f\n", i + 1, j + 1, pB[i * M2 + j]);
    for(i=0; i<N1; i++)
        for(j=0; j<M2; j++)
            for(k=0; k<M1; k++)
                pC[i*M2+j]+=(pA[i*M1+k]*pB[k*M2+j]);
    for (i = 0; i < N1; i++)
        for (j = 0; j < M2; j++)
            printf("C[%d][%d] = %f\n", i + 1, j + 1, pC[i * M2 + j]);
    free(pA);
    free(pB);
    free(pC);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
    float *pA, *pB, *pC, **A, **B, **C, max, min;
    int i, j, k, N1, M1, N2, M2;
    srand(time(NULL));
    do
    {
        printf("Ingrese el numero de columnas de A: ");
        scanf("%d", &N1);
    } while (N1 < 1);
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
    if (M1 != N2)
    {
        printf("Error en el tamanio de las matrices.\n");
        return 1;
    }
    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);
    if (max < min)
    {
        max += min;
        min = max - min;
        max -= min;
    }
    pA=(float*)malloc(N1*M1*sizeof(float));
    if(pA==NULL)
    {
        printf("Error al asignar la memoria.\n");
        return 2;
    }
    A=(float**)malloc(N1*sizeof(float*));
    if(A==NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        return 3;
    }
    for(i=0; i<N1; i++)
        A[i]=pA+i*M1;
    for(i=0; i<N1; i++)
        for(j=0; j<M1; j++)
            A[i][j] = ((max-min)*rand())/RAND_MAX+min;
    pB = (float *)malloc(N2 * M2 * sizeof(float));
    if (pB == NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        free(A);
        return 4;
    }
    B = (float **)malloc(N2 * sizeof(float *));
    if (B == NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        free(A);
        free(pB);
        return 5;
    }
    for (i = 0; i < N2; i++)
        B[i] = pB + i * M2;
    for (i = 0; i < N2; i++)
        for (j = 0; j < M2; j++)
            B[i][j] = ((max - min) * rand()) / RAND_MAX + min;
    pC = (float *)calloc(N1 * M2, sizeof(float));
    if (pC == NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        free(A);
        free(pB);
        free(B);
        return 6;
    }
    C = (float **)malloc(N1 * sizeof(float *));
    if (C == NULL)
    {
        printf("Error al asignar la memoria.\n");
        free(pA);
        free(A);
        free(pB);
        free(B);
        free(pC);
        return 7;
    }
    for (i = 0; i < N1; i++)
        C[i] = pC + i * M2;
    for (i = 0; i < N1; i++)
        for (j = 0; j < M2; j++)
            for(k = 0; k < M1; k++)
                C[i][j]+=(A[i][k]*B[k][j]);
    for (i = 0; i < N1; i++)
        for (j = 0; j < M1; j++)
            printf("A[%d][%d] = %f\n", i + 1, j + 1, A[i][j]);
    for (i = 0; i < N2; i++)
        for (j = 0; j < M2; j++)
            printf("B[%d][%d] = %f\n", i + 1, j + 1, B[i][j]);
    for (i = 0; i < N1; i++)
        for (j = 0; j < M2; j++)
            printf("C[%d][%d] = %f\n", i + 1, j + 1, C[i][j]);
    free(pA);
    free(A);
    free(pB);
    free(B);
    free(pC);
    free(C);
    return 0;
}
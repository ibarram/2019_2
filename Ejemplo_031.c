#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int captura_i(int *N, char *s1, char *s2)
{
    do
    {
        printf("Ingrese el numero de %s en %s: ", s1, s2);
        scanf("%d", N);
    } while (*N < 1);
    return 0;
}

int swap(float* max, float *min)
{
    float aux;
    if (*max < *min)
    {
        aux = *max;
        *max = *min;
        *min = aux;
    }
}

float **crear_m(int N, int M)
{
    int i;
    float **ptr;
    ptr = (float **)malloc(N * sizeof(float *));
    if (ptr == NULL)
        return ptr;
    for (i = 0; i < N; i++)
    {
        ptr[i] = (float *)malloc(M * sizeof(float));
        if (ptr[i] == NULL)
        {
            for (--i; - 1 < i; i--)
                free(ptr[i]);
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}

float **crear_mi(int N, int M)
{
    int i;
    float **ptr;
    ptr = (float **)malloc(N * sizeof(float *));
    if (ptr == NULL)
        return ptr;
    for (i = 0; i < N; i++)
    {
        ptr[i] = (float *)calloc(M, sizeof(float));
        if (ptr[i] == NULL)
        {
            for (--i; - 1 < i; i--)
                free(ptr[i]);
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}

void imprimir(float **ptr, int N, int M, char *str)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            printf("%s[%d][%d] = %f\n", str, i + 1, j + 1, ptr[i][j]);
}

void aleatorio(float **ptr, int N, int M, float max, float min)
{
    int i, j;
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            ptr[i][j]=((max-min)*rand())/RAND_MAX+min;
}

void capturar(float **ptr, int N, int M, char *str)
{
    int i, j;
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
        {
            printf("%s[%d][%d] = ", str, i+1, j+1);
            scanf("%f", ptr[i]+j);
        }
}

void multiplicar(float **ptr1, float **ptr2, float **ptr3, int N, int M, int K)
{
    int i, j, k;
    for(i=0; i<N; i++)
        for(j=0; j<K; j++)
            for(k=0; k<M; k++)
                ptr3[i][j]+=(ptr1[i][k]*ptr2[k][j]);
}

void liberar(float **ptr, int N)
{
    int i;
    for(i=0; i<N; i++)
        free(ptr[i]);
    free(ptr);
}

int main(int argc, char *argv[])
{
    float **A, **B, **C, max, min;
    int N1, M1, N2, M2, i, j, k;
    srand(time(NULL));
    captura_i(&N1, "renglones", "A");
    captura_i(&M1, "columnas", "A");
    captura_i(&N2, "renglones", "B");
    captura_i(&M2, "columnas", "B");
    if(M1!=N2)
    {
        printf("Error en el tamano de las matrices.\n");
        return 1;
    }
    printf("Ingrese el maximo: ");
    scanf("%f", &max);
    printf("Ingrese el minimo: ");
    scanf("%f", &min);
    swap(&max, &min);
    printf("[%f, %f]\n", max, min);
    A = crear_m(N1, M1);
    if (A == NULL)
    {
        printf("Error al asignar la memoria.\n");
        return 2;
    }
    B = crear_m(N2, M2);
    if (B == NULL)
    {
        printf("Error al asignar la memoria.\n");
        liberar(A, N1);
        return 3;
    }
    C = crear_mi(N1, M2);
    if (C == NULL)
    {
        printf("Error al asignar la memoria.\n");
        liberar(A, N1);
        liberar(B, N2);
        return 4;
    }
    aleatorio(A, N1, M2, max, min);
    imprimir(A, N1, M1, "A");
    capturar(B, N2, M2, "B");
    multiplicar(A, B, C, N1, M1, M2);
    imprimir(C, N1, M2, "C");
    liberar(A, N1);
    liberar(B, N2);
    liberar(C, N2);
    return 0;
}
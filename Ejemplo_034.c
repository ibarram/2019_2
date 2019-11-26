#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct V{
    int n;
    float *x;
    float m;
    float v;
}V;

typedef V *pV;

int capturar(pV V1, float max, float min)
{
    int i;
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &(V1->n));
    }while(V1->n<1);
    V1->x=(float*)malloc(V1->n*sizeof(float));
    if(V1->x==NULL)
        return 1;
    for(i=0; i<V1->n; i++)
        V1->x[i]=((max-min)*rand())/RAND_MAX+min;
    return 0;
}

float media(float *x, int n)
{
    float m;
    int i;
    for(i=0, m=0; i<n; i++)
        m+=x[i];
    return m/n;
}

int imprimir(V V1)
{
    int i;
    for(i=0; i<V1.n; i++)
        printf("X[%d] = %f\n", i+1, V1.x[i]);
    return 0;
}

int varianza(pV V1)
{
    int i;
    for(i=0, V1->v=0; i<V1->n; i++)
        V1->v += ((V1->x[i] - V1->m) * (V1->x[i] - V1->m));
    V1->v/=V1->n;
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    V v1;
    int i;
    fp=fopen(argv[1], "rt");
    if(fp==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    fscanf(fp, "%d", &v1.n);
    v1.x = (float*)malloc(v1.n*sizeof(float));
    if(v1.x==NULL)
    {
        printf("Error al asignar la memoria.\n");
        return 2;
    }
    for(i=0; i<v1.n; i++)
        fscanf(fp, "%f", v1.x+i);
    fscanf(fp, "%f\n%f", &v1.m, &v1.v);
    printf("N = %d\n", v1.n);
    imprimir(v1);
    printf("Media = %f\nVarianza = %f\n", v1.m, v1.v);
    free(v1.x);
    return 0;
}
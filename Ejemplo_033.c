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
    V V1;
    float max, min;
    int i;
    FILE *fp;
    srand(time(NULL));
    printf("Ingrese el valor de maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor de minimo: ");
    scanf("%f", &min);
    if(max<min)
    {
        max+=min;
        min=max-min;
        max-=min;
    }
    capturar(&V1, max, min);
    imprimir(V1);
    V1.m=media(V1.x, V1.n);
    varianza(&V1);
    printf("La media es %f\n", V1.m);
    printf("La varianza es %f.\n", V1.v);
    fp=fopen("Prueba.txt", "w+t");
    if(fp==NULL)
    {
        printf("Error al crear el archivo.\n");
        return 1;
    }
    fprintf(fp, "%d\n", V1.n);
    for(i=0; i<V1.n; i++)
        fprintf(fp, "%f\n", V1.x[i]);
    fprintf(fp, "%f\n", V1.m);
    fprintf(fp, "%f\n", V1.v);
    fclose(fp);
    fp = fopen("Prueba.xls", "w+t");
    if (fp == NULL)
    {
        printf("Error al crear el archivo.\n");
        return 1;
    }
    for (i = 0; i < (V1.n-1); i++)
        fprintf(fp, "%f\n", V1.x[i]);
    fprintf(fp, "%f", V1.x[i]);
    fclose(fp);
    fp = fopen("Prueba.dat", "w+b");
    fwrite(&V1, sizeof(V), 1, fp);
    fwrite(V1.x, sizeof(float), V1.n, fp);
    fclose(fp);
    free(V1.x);
    return 0;
}
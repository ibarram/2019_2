#include <stdio.h>
#define N_MAX 100
#define M_MAX 100

int main(int argc, char *argv[])
{
    float A[M_MAX][N_MAX], B[M_MAX][N_MAX], C[M_MAX][N_MAX];
    int i, j, k, N1, M1, N2, M2;
    do{
        printf("Ingrese el numero de renglones de A: ");
        scanf("%d", &M1);
        printf("Ingrese el numero de columnas de A: ");
        scanf("%d", &N1);
    }while(M1<1||M1>M_MAX||N1<1||N1>N_MAX);
    do
    {
        printf("Ingrese el numero de renglones de B: ");
        scanf("%d", &M2);
        printf("Ingrese el numero de columnas de B: ");
        scanf("%d", &N2);
    } while (M2 < 1 || M2 > M_MAX || N2 < 1 || N2 > N_MAX);
    if(N1!=M2)
    {
        printf("Error en el tamanio de las matrices.\n");
        return 1;
    }
    for(i=0;i<M1;i++)
        for(j=0;j<N1;j++)
        {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%f",&A[i][j]);
        }
    for(i=0;i<M2;i++)
        for(j=0;j<N2;j++)
        {
            printf("B[%i][%i]=",i+1,j+1);
            scanf("%f",&B[i][j]);
        }
    for(k=0;k<M1;k++)
        for(j=0;j<N2;j++)
            for(i=0, C[k][j]=0;i<N1;i++)
                C[k][j]+=A[k][i]*B[i][j];
    for(i=0;i<M1;i++)
        for(j=0;j<N2;j++)
            printf("C[%i][%i]=%f\n",i+1,j+1,C[i][j]);
    return 0;
}
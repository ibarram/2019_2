#include<stdio.h>

#define N 1000

int main(int argc, char *argv[])
{
    float A[N], x, fx;
    int i, n;
    do{
        printf("Ingrese el grado del polinomio: ");
        scanf("%d", &n);
    }while(n<1||n>N);
    for(i=0; i<=n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%f", &A[i]);
    }
    printf("f(x)=");
    for(i=n; i>-1; i--)
    {
        switch(i)
        {
            case 1:
                printf("%+fx",A[i]);
                break;
            case 0:
                printf("%+f",A[i]);
                break;
            default:
                if(i==n)
                    printf("%fx^%d", A[i], i);
                else
                    printf("%+fx^%d", A[i], i);
        }
    }
    printf("\n");
    do{
        printf("Ingrese el valor de x: ");
        scanf("%f", &x);
        fx = A[n]*x+A[n-1];
        for(i=2; i<=n; i++)
        {
            fx*=x;
            fx+=A[n-i];
        }
        printf("f(%f)=%f\n", x, fx);
    }while(x);
    return 0;
}

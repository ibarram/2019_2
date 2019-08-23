#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, n, den;
    float ex, x, num;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrse el valor de x: ");
    scanf("%f", &x);
    for(i=0, ex=0, num=1, den=1; i<n; i++)
    {
        ex+=(num/den);
        num *= x;
        den *= (i + 1);
    }
    printf("exp(%f)=%f\n", x, ex);
    return 0;
}
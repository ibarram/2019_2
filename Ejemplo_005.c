#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, j, n, den;
    float ex, x, num;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrse el valor de x: ");
    scanf("%f", &x);
    for(i=0, ex=0; i<n; i++)
    {
        for(j=0, num=1, den=1; j<i; j++)
        {
            num*=x;
            den*=(j+1);
        }
        ex+=(num/den);
    }
    printf("exp(%f)=%f\n", x, ex);
    return 0;
}
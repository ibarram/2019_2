#include<stdio.h>

float pot(float x, int n)
{
    if(n==0)
        return 1;
    else if(n>0)
        return x*pot(x, n-1);
    else
        return (1/x)*pot(x, n+1);
}

int main(int argc, char argv[])
{
    int n;
    float x, px;
    printf("Ingrese la potencia: ");
    scanf("%d", &n);
    printf("Ingrese el valor: ");
    scanf("%f", &x);
    px = pot(x, n);
    printf("%f^%d=%f\n", x, n, px);
    return 0;
}
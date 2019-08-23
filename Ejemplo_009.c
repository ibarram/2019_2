#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, n, s, den;
    float x, sx, num;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);
    for(i=0, sx=0, s=1, num=x, den=1; i<n; i++)
    {
        sx+=(s*num/den);
        num *= (x*x);
        den *= ((2*i+2)*(2*i+3));
        s*=(-1);
    }
    printf("sin(%f)=%f\n", x, sx);
    return 0;
}
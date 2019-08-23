#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, j, n, s, den;
    float x, sx, num;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);
    for(i=0, sx=0, s=1; i<n; i++)
    {
        for(j=0, num=1, den=1; j<(2*i+1); j++)
        {
            num*=x;
            den*=(j+1);
        }
        sx+=(s*num/den);
        s*=(-1);
    }
    printf("sin(%f)=%f\n", x, sx);
    return 0;
}
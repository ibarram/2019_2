#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, n;
    float ex, x, fct;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrse el valor de x: ");
    scanf("%f", &x);
    for(i=0, ex=0, fct=1; i<n; i++)
    {
        ex+=(fct);
        fct*=(x/(i+1));
    }
    printf("exp(%f)=%f\n", x, ex);
    return 0;
}
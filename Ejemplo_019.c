#include<stdio.h>

float exp_s(float x, int n);
float sin_s(float x, int n);

int main(int argc, char *argv[])
{
    int n;
    float ex, x, sx;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    printf("Ingrse el valor de x: ");
    scanf("%f", &x);
    ex = exp_s(x, n);
    sx = sin_s(x, n);
    printf("exp(%f)=%f\n", x, ex);
    printf("sin(%f)=%f\n", x, sx);
    return 0;
}

float exp_s(float x, int n)
{
    int i;
    float fct, ex;
    for (i = 0, ex = 0, fct = 1; i < n; i++)
    {
        ex += (fct);
        fct *= (x / (i + 1));
    }
    return ex;
}

float sin_s(float x, int n)
{
    int i, j, s, den;
    float sx, num;
    for (i = 0, sx = 0, s = 1; i < n; i++)
    {
        for (j = 0, num = 1, den = 1; j < (2 * i + 1); j++)
        {
            num *= x;
            den *= (j + 1);
        }
        sx += (s * num / den);
        s *= (-1);
    }
    return sx;
}
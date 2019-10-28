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

float seno(float x, int n)
{
    float fctg;
    static float fct=1;
    static int i=2, s=-1;
    fct *= (( x / i) * (x / (i + 1)));
    fctg=s*x*fct;
    //printf("%d\t%d\t%d\t%f\t%f\n", n, s, i, fct, fctg);
    i+=2;
    s*=-1;
    if(n>1)
        return fctg+seno(x,n-1);
    else
        return x;
}

int main(int argc, char *argv[])
{
    int n, i;
    float x, px, sx;
    printf("%d\n", argc);
    for(i=0; i<argc; i++)
        printf("%s\n", argv[i]);
    printf("Ingrese la potencia: ");
    scanf("%d", &n);
    printf("Ingrese el valor: ");
    scanf("%f", &x);
    px = pot(x, n);
    sx = seno(x, n);
    printf("%f^%d=%f\n", x, n, px);
    printf("seno(%f) = %f\n", x, sx);
    return 0;
}
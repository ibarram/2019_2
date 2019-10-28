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

int c2i(char str[])
{
    int n=0, i=0, s=1;
    if(str[i]==45)
    {
        s=-1;
        i++;
    }
    while (str[i] > 47 && str[i] < 58)
    {
        n*=10;
        n += (str[i]-48);
        i++;
    }
    return s*n;
}

float c2f(char str[])
{
    int n = 0, i = 0, s = 1;
    float m = 0, aux, p10;
    if (str[i] == 45)
    {
        s = -1;
        i++;
    }
    while (str[i] > 47 && str[i] < 58)
    {
        n *= 10;
        n += (str[i] - 48);
        i++;
    }
    p10 = 0.1;
    if(str[i]==46)
    {
        i++;
        while (str[i] > 47 && str[i] < 58)
        {
            aux = (str[i] - 48)*p10;
            p10*=.1;
            m += aux;
            i++;
        }
    }
    return (s * n + s*m);
}

int main(int argc, char *argv[])
{
    int n, i;
    float x, px, sx;
    switch(argc)
    {
        case 1:
            printf("Ingrese la potencia: ");
            scanf("%d", &n);
            printf("Ingrese el valor: ");
            scanf("%f", &x);
            break;
        case 2:
            n = c2i(argv[1]);
            printf("Ingrese el valor: ");
            scanf("%f", &x);
            break;
        default:
            n = c2i(argv[1]);
            x = c2f(argv[2]);
    }
    px = pot(x, n);
    sx = seno(x, n);
    printf("%f^%d=%f\n", x, n, px);
    printf("seno(%f) = %f\n", x, sx);
    return 0;
}
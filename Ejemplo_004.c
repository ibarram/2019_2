#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, n, s, den;
    float pi;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    for(i=0, pi=0, s=1; i<n; i++)
    {
        den=(i<<1)+1;
        pi+=(s*4.0/den);
        s*=(-1);
    }
    printf("PI = %f\n", pi);
    return 0;
}
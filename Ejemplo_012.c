#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 2000

int main(int argc, char *argv[])
{
    float X[N], min, max, media, var1, Sx2, Sx, var2;
    int n, i;
    srand(time(NULL));
    do{
        printf("Ingrese el numero de elementos: ");
        scanf("%d", &n);
    }while(n<1||n>N);
    printf("Ingrese el valor maximo: ");
    scanf("%f", &max);
    printf("Ingrese el valor minimo: ");
    scanf("%f", &min);
    if(max<min)
    {
        max += min;
        min = max-min;
        max -= min;
    }
    for(i=0, media=0, Sx2=0, Sx=0; i<n; i++)
    {
        X[i]=((max-min)*rand())/RAND_MAX+min;
        media+=X[i];
        Sx+=X[i];
        Sx2+=(X[i]*X[i]);
        printf("X[%d] = %f\n", i+1, X[i]);
    }
    media/=n;
    var2 = (Sx2-(Sx*Sx)/n)/n;
    for(i=0, var1=0; i<n; i++)
        var1+=((X[i]-media)*(X[i]-media));
    var1/=n;
    printf("Media = %f\n", media);
    printf("Varianza = %f\n", var1);
    printf("Varianza = %f\n", var2);
    return 0;
}
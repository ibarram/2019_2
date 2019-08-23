#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, n;
    float asx, x, fct1, fct2;
    do{
        printf("Ingrese el numero de terminos: ");
        scanf("%d", &n);
    }while(n<1);
    do{
        printf("Ingrese el valor de x: ");
        scanf("%f", &x);
    }while(x<-1||x>1);
    for(i=0, asx=0, fct1=1, fct2=x; i<n; i++)
    {
        asx += (fct1*fct2);
        fct1*=((2*i+1.0)/(2*i+2));
        fct2*=(((2*i+1)*x*x)/(2*i+3));
    }
    printf("asin(%f)=%.10f\n", x, asx);
    return 0;
}
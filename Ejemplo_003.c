#include<stdio.h>

int main(int arhc, char *argv[])
{
    int N, M, X, Y, E;
    scanf("%d %d %d %d", &N, &M, &X, &Y);
    E = (int)((M+N*Y)/(X+Y));
    printf("%d\n", E);
    return 0;
}
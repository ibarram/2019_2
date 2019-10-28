#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio(float *x, int n, float max, float min)
{
	int i;
	if(x==NULL)
		return 1;
	srand(time(NULL));
	for(i=0; i<n; i++)
		x[i]=((max-min)*rand())/RAND_MAX+min;
	return 0;
}

int imprimir(float *x, int n)
{
	int i;
	if(x==NULL)
		return 1;
	for(i=0; i<n; i++)
		printf("X[%d] = %f\n", i+1, x[i]);
	return 0;
}

float media1(float *x, int n)
{
	float m;
	int i;
	for(i=0, m=0; i<n; i++)
		m+=x[i];
	return m/n;
}

float varianza1(float *x, int n)
{
	float m1, m2;
	int i;
	for(i=0, m1=0, m2=0; i<n; i++)
	{
		m1+=x[i];
		m2+=(x[i]*x[i]);
	}
	return (m2-(m1*m1)/n)/n;
}

float media2(float *x, int n, int f)
{
	static int i=0;
	if(f)
	{
		f=0;
		i=0;
	}
	if(i==n)
		return 0;
	else
	{
		i++;
		return x[0]/n+media2(x+1, n, f);
	}
}

float suma2(float *x, int n, int f)
{
	static int i=0;
	if(f)
	{
		f=0;
		i=0;
	}
	if(i==n)
		return 0;
	else
	{
		i++;
		return (x[0]*x[0])+suma2(x+1, n, f);
	}
}

float varianza2(float *x, int n)
{
	float m1, m2;
	m1 = media2(x, n, 1);
	m2 = suma2(x, n, 1)/n;
	return (m2-m1*m1);
}

float varianza3(float *x, int n, int f)
{
	static int i=0;
	static float m1=0, m2=0;
	if(f)
	{
		f=0;
		i=0;
		m1=0;
		m2=0;
	}
	if(i==n)
		return (m2-m1*m1);
	else
	{
		i++;
		m2+=((x[0]*x[0])/n);
		m1+=(x[0]/n);
		return varianza3(x+1,n,0);
	}
}

int main(int argc, char *argv[])
{
	int n;
	float *pX, max, min;
	do{
		printf("Ingrese el numer de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Igrese el maximo: ");
	scanf("%f", &max);
	printf("Ingrese el minimo: ");
	scanf("%f", &min);
	if(max<min)
	{
		max+=min;
		min=max-min;
		max-=min;
	}
	pX = (float*)malloc(n*sizeof(n));
	if(pX==NULL)
	{
		printf("Error al asignar la memoria.\n");
		return 1;
	}
	aleatorio(pX, n, max, min);
	imprimir(pX, n);
	printf("media = %f\n", media1(pX, n));
	printf("varianza = %f\n", varianza1(pX, n));
	printf("media = %f\n", media2(pX, n,1));
	printf("varianza = %f\n", varianza2(pX, n));
	printf("varianza = %f\n", varianza3(pX, n, 1));
	free(pX);
	return 0;
}
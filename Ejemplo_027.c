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

int burbuja(float *x, int n)
{
	int i, j;
	float aux;
	if(x==NULL)
		return 1;
	for(i=0; i<(n-1); i++)
		for(j=(i+1);j<n; j++)
			if(x[i]>x[j])
			{
				aux=x[i];
				x[i]=x[j];
				x[j]=aux;
			}
	return 0;
}

int interc(float *x, int n)
{
	int i, j;
	float aux;
	if(x==NULL)
		return 1;
	for(i=1;i<n;i++)
	{
		aux=x[i];
		j=i-1;
		while(x[j]>aux)
		{
			x[j+1]=x[j];
			j--;
			if(j<0)
				break;
		}
		x[j+1]=aux;
	}
	return 0;
}

int buscar(float *x, float valor, int i, int f)
{
	int m;
	interc(x, f+1);
	while(f>=i)
	{
		m=(i+f)/2;
		if((int)(10*valor)==(int)(10*x[m]))
			return m;
		if(valor<x[m])
			f=m-1;
		else
			i=m+1;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int n, i;
	float *pX, max, min, valor;
	do{
		printf("Ingrese el numero de elementos: ");
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
	printf("Vector aleatorio:\n");
	imprimir(pX, n);
	do{
		printf("Ingrese el valor a buscar: ");
		scanf("%f", &valor);
	}while(valor<min||valor>max);
	burbuja(pX, n);
	printf("Vector ordenado:\n");
	imprimir(pX, n);
	i = buscar(pX, valor, 0, n-1);
	if(i+1)
		printf("El valor %f (%f) esta en la posicion %d\n", pX[i], valor, i+1);
	else
		printf("No se encontro el valor %f\n", valor);
	free(pX);
	return 0;
}
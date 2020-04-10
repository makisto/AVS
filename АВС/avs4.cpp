#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int a = 5;

void saxpyblas(int n)
{
	int* x = new int[n];
	int* y = new int[n];
	for(int i = 0; i < n; i++)
	{
		x[i] = rand() % n;
		y[i] = rand() % n - 1;
		y[i] += a * x[i];	
	}
}

void dgemmblas(int n)
{
	double** x = new double*[n];
	double** y = new double*[n];
	double** z = new double*[n];
	for(int i = 0; i < n; i++)
	{
		x[i] = new double[n];
		y[i] = new double[n];
		z[i] = new double[n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			x[i][j] = (double)rand() / RAND_MAX;
			y[i][j] = (double)rand() / RAND_MAX;
			z[i][j] = 0;	
		}	
	}
	for(int i = 0; i < n; i++)
	{	
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				z[i][j] += x[i][k] * y[k][j];
			}	
		}	
	}	
}

int main()
{
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	dgemmblas(n);	
	return 0;
}

#include <stdio.h>
#include <math.h>
#include "euler003.h"
#include <stdlib.h>

int main( int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("The prime factors of 13195 are 5, 7, 13 and 29.\n");
		printf("What is the largest prime factor of the number 600851475143 ?\n");
		int primes[100];
		int p = 0;
		prime_factor(600851475143L, &p, primes);
		int max = 0;
		for ( int i = 0; i < p; i++)
			if(primes[i] > max) max = primes[i];
		printf("Answer: %d\n", max);
	}
	else 
	{
		unsigned long factor = atol(argv[1]);
		int primes[100];
		int p = 0;
		prime_factor(factor, &p, primes);
		printf("%lu:", factor);
		bubblesort(primes, p);
		for( int i = 0; i < p; i++)
			printf(" %d", primes[i]);
		printf("\n");
	}
}

void bubblesort(int *array, int p)
{
	int sane = 0;
	while(!sane) 
	{
		sane = 1;
		for( int i = 0; i < p-1; i++)
		{
			if (array[i+1] < array[i]) 
			{
				int tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				sane = 0;
 			}
		}
	}
}

void prime_factor(long n, int *p, int *primes)
{
	long a;
	long b;
	factor(n, &a, &b);
	if ( a == 1 && b != 1 )
	{
		primes[(*p)++] = b;
	}
	else if ( a != 1 && b == 1 ) 
	{
		primes[(*p)++] = a;
	}
	else if (a != 0 && b != 0)
	{
		prime_factor(a, p, primes);
		prime_factor(b, p, primes);
	}
	
}

void factor(long n, long *factor1, long *factor2)
{
	double a = ceil(sqrt(n));
	double b2 = a*a - n;
	if( (n & 1) == 0) // is even
	{
		*factor1 = n/2;
		*factor2 = 2;
	}
	else if( is_square(n) )
	{
		*factor1 = (int)sqrt(n);
		*factor2 = (int)sqrt(n);
	} 
	else
	{
		while( !is_square(b2) )
		{
			a = a+1;
			b2 = a*a - n;
		}
		*factor1 = (int)(a - sqrt(b2));
		*factor2 = (int)(a + sqrt(b2));
	}
}

int is_square(long x)
{
	return ( sqrt(x) == (long)sqrt(x) );
}

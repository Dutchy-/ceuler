#include <stdio.h>
#include <math.h>
#include "euler003.h"

int main( int argc, char *argv[])
{
	printf("The prime factors of 13195 are 5, 7, 13 and 29.\n");
	printf("What is the largest prime factor of the number 600851475143 ?\n");

	//printf("Answer factor 600851475143: %lu\n", factor(600851475143)[0]);
	int primes[100];
	int p = 0;
//	prime_factor(105, &p, primes);
//	p = 0;
//	prime_factor(44, &p, primes);
//	p = 0;
//	prime_factor(1234509, &p, primes);
	prime_factor(600851475143L, &p, primes);
	int max = 0;
	for ( int i = 0; i < p; i++)
		if(primes[i] > max) max = primes[i];
	printf("Answer: %d\n", max);
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

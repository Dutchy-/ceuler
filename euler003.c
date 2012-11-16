#include <stdio.h>
#include <stdlib.h>

#include "euler003.h"
#include "algebra.h"

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

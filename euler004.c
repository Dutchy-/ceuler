#include <stdio.h>
#include <stdbool.h>
#include "str_util.h"

int main( int argc, char * argv[])
{
	printf("A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.\n");
	printf("Find the largest palindrome made from the product of two 3-digit numbers.\n");

	const int length = 7;
	char buffer[length];
	int max = 0;
	int res;
	for ( int i = 999; i > 900; i-- ) {
		for ( int j = 999; j > 900; j-- ) {
			res = i*j;
			snprintf( buffer, length, "%d", res);
			if ( is_palindrome(buffer) && res > max )
				max = res;
		}
	}

	printf("Answer: %d\n", max);
	return 0;
}


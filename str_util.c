#include "str_util.h"
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char * str) 
{
	bool result = true;
	int len = strlen(str);
	for( int i = 0; i < len/2 && result; i++ ) {
		result &= str[i] == str[len-i-1];
	}
	return result;
}

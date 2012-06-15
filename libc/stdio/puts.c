#include <stdio.h>


// Takes a pointer to a string and loops over it calling putchar till it hits NULL
int puts( int *str ) {
	if (str == 0) return -1;	// Check for invalid string
	
	unsigned i = 0;
	while( str[i] != '\0' ) putchar( str[i++] );

	return i;
}


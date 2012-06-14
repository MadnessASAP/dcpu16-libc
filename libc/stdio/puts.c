#include <stdio.h>

int puts( int *str ) {
		if (str == 0) return -1;	// Check for invalid string
		
		int i = 0;	// Index in string
		while( str[i] != 0 ) {
			putchar( str[i++] );	// Display charachter and increment index
		}

		return i;
}


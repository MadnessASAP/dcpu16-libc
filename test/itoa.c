#include <stdio.h>

int main() {
	initConsole();
	char str[16];
	for( unsigned n = 0; n <= 0xFF; n++ ) {
		itoa( n, 16, str );
		puts( str );
		putchar( ' ' );
	}
	asm( "SUB PC, 1" );
}

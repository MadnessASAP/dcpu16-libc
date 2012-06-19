#include <stdio.h>

int main() {
	initConsole();
	char str[16];
	for( int n = -10; n <= 10; n++ ) {
		itoa( n, 10, str );
		puts( str );
		putchar( ' ' );
	}

	for( unsigned n = 0; n <= 20; n++ ) {
		utoa( n, 2, str );
		puts( str );
		putchar( ' ' );
	}
	asm( "SUB PC, 1" );
}

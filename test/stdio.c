#include <stdio.h>

int main() {
	initConsole();
	char str[16];
	puts( "START\n" );
	for( int i = -10; i <= 10; i++ ) {
		itoa( i, 10, str );
		puts( str );
		putchar( '\n' );
	}

	asm volatile ( "SUB PC, 1" );
	return 0;
}

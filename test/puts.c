#include <stdio.h>


void main() {
	initConsole();
	putchar('I');
	const char str[] = "Hello World!" ;
	putchar('A');
	puts( str );
	putchar('B');
	asm volatile( "SUB PC, 1" : : : );
	return;
}

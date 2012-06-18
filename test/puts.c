#include <stdio.h>


void main() {
	initConsole();
	const char str[] = "Hello World!" ;
	puts( str );
	asm volatile( "SUB PC, 1" : : : );
	return;
}

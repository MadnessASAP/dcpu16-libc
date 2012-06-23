#include <stdio.h>

void main() {
	initConsole();
	

	unsigned args[1] = { 0 };
	printf( "Hello", args );
	asm volatile( "SUB PC, 1" );
	return;
}

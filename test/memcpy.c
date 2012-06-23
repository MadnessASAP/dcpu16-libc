#include <string.h>
#include <stdio.h>

int main() {
	initConsole();
	putchar( 'C' );
	const unsigned A[] = { 0x0123, 0x4567, 0x89AB, 0xCDEF, 0xFEDC, 0xBA98, 0x7654, 0x3210 };
	unsigned B[sizeof(A)];
	//char C[] = "Hello World!";
	//char D[sizeof(C)];

	puts("Start!");

	memcpy( B, A, sizeof(A) );
	for( int i = 0; i < sizeof(A); i++ ) {
		if( A[i] != B[i] ) {
			puts( "U MEMCPY FAIL!" );
			asm volatile ( "SUB PC, 1" );
		}
	}
	puts ( "U MEMCPY PASS!" );

//	memcpy( D, C, sizeof(C) );
//	for( int i = 0; i < sizeof(C); i++ ) {
//		if( C[i] != D[i] ) {
//			puts( "C MEMCPY FAIL!" );
//			asm volatile ( "SUB PC, 1" );
//		}
//	}
//	puts( "C MEMCPY PASS!" );
	asm volatile ( "SUB PC, 1" );
	return 0;
}
	

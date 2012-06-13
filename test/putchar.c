#include <stdio.h>

unsigned __heap_start[0x1000];
unsigned *__heap_end = __heap_start + sizeof( __heap_start ) - 1;

void main() {
	for (int i = 0; i < 128; i++) {
		putchar(i);
	}
	while(0) {}
    return;
}


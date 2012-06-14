#include <stdio.h>

void main() {
	initConsole();
	while(1 == 1) {
		for (int i = 0; i < 128; i++) {
			putchar(i);
		}
	}
    return;
}


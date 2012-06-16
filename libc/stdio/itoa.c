#include <stdio.h>

int itoa(unsigned n, unsigned base, char* str) {
	unsigned i = 0;
	unsigned digits[16];
	while (base < n) {
		digits[i++] = n % base;
		n /= base;
	}
	
	while ( i-- > 0 ) {
		*str = '0' + digits[i];
		str++;
	}
	*str = 0;
	return 0;
}

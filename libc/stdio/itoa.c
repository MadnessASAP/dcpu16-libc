#include <stdio.h>

int itoa(unsigned n, unsigned base, char* str) {
	int i = 0;
	unsigned digits[16];
	while (n >= base) {
		digits[i++] = n % base;
		n /= base;
	}
	digits[i++] = n;

	while ( i-- > 0 ) {
		*str = (digits[i] < 10) ? ( '0' + digits[i] ) : ( 'A' + digits[i] - 10 );
		str++;
	}
	*str = 0;
	return 0;
}

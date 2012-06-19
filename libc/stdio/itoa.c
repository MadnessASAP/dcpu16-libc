#include <stdio.h>

int utoa(unsigned n, unsigned base, char* str) {
	int i = 0;
	unsigned digits[16];
	if ( base < 2 ) return -1;
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

int itoa( int n, unsigned base, char* str ) {
	if( n < 0 ) {
		*str++ = '-';
		n = ~n + 1;
	};

	return utoa( (unsigned) n, base, str );
}




#include <stdio.h>


void main() {
	initConsole();
	int str[13];
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = ' ';
	str[6] = 'W';
	str[7] = 'o';
	str[8] = 'r';
	str[9] = 'l';
	str[10] = 'd';
	str[11] = '!';
	str[12] = '\0';
	puts( str );
	asm volatile( "SUB PC, 1" : : : );
	return;
}

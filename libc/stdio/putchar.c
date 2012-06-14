#include <dcpu.h>
#include <string.h>
#include <stdio.h>

int putchar( int ch ) {
	static unsigned x = 0;
	static unsigned y = 0;
	
    if ( x >= SCREEN_WIDTH ) {
		x = 0; y++; }
	if ( y >= SCREEN_HEIGHT ) {
		y = 0;
/*		memmove(	_display,
					_display + SCREEN_WIDTH,
					sizeof( _display ) - SCREEN_WIDTH );
		memset( _display + sizeof( _display ) - SCREEN_WIDTH,
				0x0000,
				SCREEN_WIDTH );
		y = SCREEN_HEIGHT - 1; */
	}

    _display[x++ + SCREEN_WIDTH * y] = LEM_GLYPH( ch, 0, 0xF, 0x0 );
    return ch;
}


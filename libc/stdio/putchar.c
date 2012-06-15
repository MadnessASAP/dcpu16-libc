#include <dcpu.h>
#include <string.h>
#include <stdio.h>


// This function takes a char and places it onto the screen into the next position on the display
// in the process it checks that the current index is on the screen.
// This function ultimately handles all writes to the screen and should therefore be as fast as possible
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


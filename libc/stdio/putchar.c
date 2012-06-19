#include <dcpu.h>
#include <stdio.h>
#include <string.h>


// This function takes a char and places it onto the screen into the next position on the display
// in the process it checks that the current index is on the screen.
// This function ultimately handles all writes to the screen and should therefore be as fast as possible
int putchar( int ch ) {
	static unsigned pos = 0;
	if ( ch == '\n' ) {
		pos = ((pos/SCREEN_WIDTH) + 1) * SCREEN_WIDTH;
		return ch;
	}		
	if (pos >= SCREEN_WIDTH * SCREEN_HEIGHT) {
		memcpy( _display, _display+SCREEN_WIDTH, (SCREEN_HEIGHT - 1) * SCREEN_WIDTH );	// Copy screen up 1 line
		memset( _display + (SCREEN_HEIGHT - 1) * SCREEN_WIDTH, ' ', SCREEN_WIDTH );		// Blank last line
	}

	_display[pos++] = LEM_GLYPH( ch, 0, 0xF, 0x0 );
    return ch;
}


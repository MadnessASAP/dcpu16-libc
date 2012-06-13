#include <dcpu.h>

#define SCREEN_WIDTH  32
#define SCREEN_HEIGHT 12

static unsigned display[SCREEN_WIDTH * SCREEN_HEIGHT];

// Find and setup the display, this should only be run once
// but currently running it more then once is consequence free.
static unsigned displayInit() {
    struct device_information devInfo;
    unsigned devID = 0xFFFF;		// Hardware ID of device

    for (unsigned i = 0; i < get_number_of_devices(); i++) {
		get_device_information(i, &devInfo);
		if ( devInfo.id_lo == LEM_ID_LO && devInfo.id_hi == LEM_ID_HI ) {	// TODO: More robust ID checking
			devID = i;		// Save the devID
			break;			// We use the first screen we find.
		}
    }
	if (devID == 0xFFFF) return 0xFFFF;		// No display found, 0xFFFF indicates that to caller
    lem_set_border_color( devID, 0x2 );		// Early indication that the display has been found
    lem_memmap_screen( devID, display );	// Map the display to our memory.

    return devID;
}




int putchar( int ch ) {
    static unsigned pos = 0;
	static unsigned devID = 0xFFFF;
	
    if ( devID == 0xFFFF ) {
			devID = displayInit();		// Displays not setup yet, do so.
			if ( devID == 0xFFFF ) return -1;	// Setting up display failed, return.
	}
    if ( pos >= ( SCREEN_WIDTH * SCREEN_HEIGHT ) ) pos = 0;	// Wrap around to top of screen
															// TODO: Make scrolling a thing

    display[pos++] = LEM_GLYPH( ch, 0, 0xF, 0x0 );	// Store the char and increment pos
    return ch;
}


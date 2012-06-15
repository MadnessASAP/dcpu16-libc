#include <dcpu.h>
#include <stdio.h>


// This seems the most logical place to actually define these extern variables
// Not deadset on it though.
unsigned _display[SCREEN_WIDTH * SCREEN_HEIGHT];
unsigned _devID = 0xFFFF;


// This function loops through all devices until it finds the screen
// then sets the border to green, maps it too our memory area and saves the id.

int initConsole() {
	for( int i = 0; i < get_number_of_devices(); i++ ) {
		struct device_information devInfo;
		get_device_information( i, &devInfo );
		if(	devInfo.id_lo	== LEM_ID_LO &&
			devInfo.id_hi	== LEM_ID_HI &&
			devInfo.version	== LEM1802_VERSION &&
			devInfo.manufacturer_lo == NYA_ELEKTRISKA_LO &&
			devInfo.manufacturer_hi == NYA_ELEKTRISKA_HI ) {

			_devID = i;
			lem_set_border_color( i, 0x02 );
			lem_memmap_screen( i, _display );
			return 0;
		}
	}
	return -1;
}




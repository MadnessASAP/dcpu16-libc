#include <dcpu.h>
#include <stdio.h>

unsigned _display[SCREEN_WIDTH * SCREEN_HEIGHT];
unsigned _devID = 0xFFFF;

int initConsole() {
	for( int i = 0; i < get_number_of_devices(); i++ ) {
		struct device_information devInfo;
		get_device_information( i, &devInfo );
		if(	devInfo.id_lo	== 0xf615 &&
			devInfo.id_hi	== 0x7349 &&
			devInfo.version	== 0x1802 &&
			devInfo.manufacturer_lo == 0x8b36 &&
			devInfo.manufacturer_hi == 0x1c6c ) {

			_devID = i;
			lem_set_border_color( i, 0x02 );
			lem_memmap_screen( i, _display );
			return 0;
		}
	}
	return -1;
}




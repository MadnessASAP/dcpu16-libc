//TODO: Make a real stdio.h (Or copy one)

#define SCREEN_WIDTH  32
#define SCREEN_HEIGHT 12

unsigned extern _display[SCREEN_WIDTH * SCREEN_HEIGHT];
unsigned extern _devID;

int initConsole();

int putchar( int );

int puts( const char* );

int utoa( unsigned, unsigned, char* );
int itoa( int, unsigned, char* );

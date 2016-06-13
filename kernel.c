#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// The height and width of the screen in terms of rows and columns
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

// Initialization of console variables
size_t row = 0;
size_t column = 0;
uint8_t color = 0b00001011;						// Set color = 0x<BACKGROUND><FOREGROUND>
uint16_t* buffer = (uint16_t*) 0xB8000;		// Video memory address

/* Color Codes
0 = BLACK 
1 = BLUE
2 = GREEN
3 = CYAN
4 = RED
5 = MAGENTA
6 = BROWN
7 = LIGHT_GREY
8 = DARK_GREY
9 = LIGHT_BLUE
A = LIGHT_GREEN
B = LIGHT_CYAN
C = LIGHT_RED
D = LIGHT_MAGENTA
E = LIGHT_BROWN
F = WHITE
*/

// Blank out the console screen
void clear_screen()
{
	// Iterate through each character position on the screen setting each to blank
	for( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			buffer[ index ] = 0x20 | color << 8;
		}
	}
}

// Get the length of a string
size_t strlen( const char* str )
{
	size_t count = 0;

	// While a character exists at the position, add 1 to the character counter
	while( str[ count ] != 0 )
	{
		count++;
	}

	return count;
}

// Print a character to the screen
void print_char( char c )
{
	// If a newline character is encountered, advance 1 line aligning to the left side of the screen
	if( c == '\n' )
	{
		column = 0;
		row++;
		return;
	}
		
	const size_t index = row * VGA_WIDTH + column;

	// Enter the character into the video memory at the index along with the global color
	buffer[ index ] = c | color << 8;

	// Increase the column by 1 while also checking if it reached the end of a line.
	// If it has, then set the column to the left side of the screen and increase the row by 1.
	if( ++column == VGA_WIDTH ) 
	{
		column = 0;

		// Increase row while checking if it reached the end
		if( ++row == VGA_HEIGHT )
		{
			row = 0;
		}
	}
}

// Print a string to the screen
void print_string( const char* str )
{
	// Get the length of the string
	size_t length = strlen( str );

	// Iterate through each character of the string, printing each one in order
	for( size_t i = 0; i < length; i++ )
	{
		print_char( str[ i ] );
	}
}

void scroll()
{
	
}


// *where is c char define*** The main function of the kernel **** //
void kmain()
{
	clear_screen();

	print_string( "Hello, World!" );
}

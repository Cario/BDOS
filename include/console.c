#include "console.h"

// The height and width of the screen in terms of rows and columns
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

// Initialization of console variables
size_t row = 0;
size_t column = 0;
uint8_t color = 0x0B;						// Set color = 0x<BACKGROUND><FOREGROUND>
uint16_t* buffer = (uint16_t*) 0xB8000;		// Display memory address

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

// Blank out the console screen
void clear_screen()
{
	// Iterate through each character position on the screen setting each to blank
	for( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			buffer[ index ] = ' ' | color << 8;
		}
	}
}

// Scroll by moving all lines up and dropping the top line
void scroll()
{
	for( size_t y = 0; y < VGA_HEIGHT - 1; y++ )
	{
		for( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			buffer[ index ] = buffer[ index + VGA_WIDTH ];
		}
	}

	for( size_t x = 0; x < VGA_WIDTH; x++ )
	{
		const size_t index = ( VGA_HEIGHT - 1 ) * VGA_WIDTH + x;
		buffer[ index ] = ' ' | color << 8;
	}

	row--;
}

// Print a character to the screen
void print_char( char c )
{
	// If a newline character is encountered, advance 1 line aligning to the left side of the screen
	if( c == '\n' )
	{
		column = 0;

		// Increase row while checking if it reached the end
		if( ++row == VGA_HEIGHT )
		{
			scroll();
		}

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
			scroll();
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

// Make a colorful mess all over the screen
void colorful()
{
	// Reset color down to the lowest value to start
	color = 0;

	// Iterate through each character position on the screen setting each to a different color character
	for( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			buffer[ index ] = color | color << 8;

			// Increase color without allowing it to equal or exceed 256
			color = ( color + 1 ) % 256;					
		}
	}
}

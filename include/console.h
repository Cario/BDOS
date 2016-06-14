#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef CONSOLE_H_
#define CONSOLE_H_

size_t strlen( const char* str );

void clear_screen();
void scroll();
void print_char( char c );
void print_string( const char* str );
void colorful();

#endif

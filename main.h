#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_buff(char buffer[], int *b_index);

#endif

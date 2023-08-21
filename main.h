#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define VOID(x) (void)(x)

/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* sizes */
#define S_LONG 2
#define S_SHORT 1


/**
 * struct fmt - Struct operation
 *
 * @fmt: The string format.
 * @f: The function pointer.
 */
typedef struct fmt
{
	char fmt;
	int (*f)(va_list, char[], int, int, int, int);
} format;


int _printf(const char *format, ...);
void print_buff(char buffer[], int *b_index);
int handle_print(const char *fmt, int *ind, va_list args, char buffer[],
		int flag, int width, int precision, int size);

/*print helper functions*/
int print_ch(va_list args, char buffer[],
		int flag, int width, int precision, int size);
int print_str(va_list args, char buffer[],
		int flag, int width, int precision, int size);
int print_mod(va_list args, char buffer[],
		int flag, int width, int precision, int size);

/* write handling helper functions */
int handle_write_ch(char c, char buffer[],
		int flag, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flag(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_prec(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

/*utility functions*/
int is_digit(char ch);

#endif

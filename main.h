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

/* write to stdout functions*/
int _printf(const char *format, ...);
void print_buff(char buffer[], int *b_index);

/* print handler*/
int handle_print(const char *fmt, int *ind, va_list args, char buffer[],
		int flag, int width, int precision, int size);

/* Options handler functions */
int get_flag(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_prec(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

/* write helper functions */
int write_number_handler(int negative, int ind, char buffer[],
		int flag, int width, int prec, int size);
int write_num(int ind, char buffer[],
		int flag, int width, int prec,
		int length, char pad, char extra_char);
int handle_write_ch(char c, char buffer[],
		int flag, int width, int precision, int size);
int write_unsigned(int negative, int index,
		char buffer[],
		int flag, int width, int prec, int size);
int write_pointer(char buffer[], int index, int len,
		int width, int flag, char pad, char extra_ch, int pad_start);

/* print functions*/
int print_ch(va_list args, char buffer[],
		int flag, int width, int precision, int size);
int print_str(va_list args, char buffer[],
		int flag, int width, int precision, int size);
int print_mod(va_list args, char buffer[],
		int flag, int width, int precision, int size);
int print_int(va_list args, char buffer[],
		int flag, int width, int prec, int size);
int print_bin(va_list args, char buffer[],
		int flag, int width, int prec, int size);

int print_unsigned(va_list args, char buffer[],
		int flag, int width, int prec, int size);
int print_octal(va_list args, char buffer[],
		int flag, int width, int prec, int size);
int print_hexa_num(va_list args, char map_num[], char buffer[],
		int flag, char flag_ch, int width, int prec, int size);
int print_hexa_lower(va_list args, char buffer[],
		int flag, int width, int prec, int size);
int print_hexa_upper(va_list args, char buffer[],
		int flag, int width, int prec, int size);

int print_pointer(va_list args, char buffer[],
		int flag, int width, int prec, int size);
int print_reverse(va_list args, char buffer[],
           	int flag, int width, int prec, int size);

/*utility functions*/
int is_digit(char ch);
long int convert_num_size(long int num, int size);
long int convert_unsigned(unsigned long int num, int size);

#endif

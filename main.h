#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/*SIZES*/
#define S_SHORT 1
#define S_LONG 2

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct
 *
 * @fmt: The format.
 * @fn: The function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *p,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print out chars and strings */
int print_char(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list list, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print out numbers */
int print_int(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_x(va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_upper(va_list list, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list list, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print out non printable characters */
int print_un_printable(va_list list, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print out memory address */
int print_pointer(va_list list, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle specifiers */
int get_flags(const char *format, int *p);
int get_width(const char *format, int *p, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *p);

/*Function to print a string in reverse*/
int print_rev(va_list list, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13(va_list list, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int conv_size_number(long int num, int size);
long int conv_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

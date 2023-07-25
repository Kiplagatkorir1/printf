#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Macro to suppress unused variable warnings */
#define UNUSED(x) (void)(x)

/* Buffer size for printing */
#define BUFF_SIZE 1024

/* Flags */
#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16

/* Length Modifiers */
#define LONG 2
#define SHORT 1

/* Function prototypes */

/* Functions for handling formatting and conversion */
unsigned char handle_flags(const char *flag, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
        unsigned char, int, int, unsigned char);

/* Conversion functions */
unsigned int convert_c(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_s(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_di(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_b(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_x(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_X(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);

/* Buffer structure definition */
typedef struct buffer_s
{
    char start;        / Pointer to the start of the buffer */
    int len;            /* Length of data in the buffer */
    int index;          /* Index to the current position in the buffer */
} buffer_t;

/* Function prototypes for buffer operations */
buffer_t *init_buffer(void);
int _memcpy(buffer_t *output, const char *str, int n);
void free_buffer(buffer_t *buffer);
void clear_buffer(buffer_t *buffer);
int write_buffer(buffer_t *buffer, const char *str, int n);
int print_width(buffer_t *output, int printed, unsigned char flags, int width);
int print_neg_width(buffer_t *output, int printed, unsigned char flags, int width);
int print_string_width(buffer_t *output, unsigned char flags,
        int width, int precision, int len);
unsigned int convert_ubase(buffer_t *output, unsigned long int num,
        const char *digits, unsigned char flags, int width, int precision);

#endif /* MAIN_H */

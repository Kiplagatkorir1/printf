#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int char_count = 0;
    char ch;

    while ((ch = *format++) != '\0')
    {
        if (ch == '%')
        {
            ch = *format++;
            if (ch == '\0')
                break;

            switch (ch)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    char_count++;
                    break;
                case 's':
                {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0')
                    {
                        putchar(*str);
                        char_count++;
                        str++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    int is_negative = 0;

                    if (num < 0)
                    {
                        putchar('-');
                        char_count++;
                        // Convert negative number to positive for further processing
                        num = -num;
                        is_negative = 1;
                    }

                    // Count the number of digits in the number
                    int temp_num = num;
                    int num_digits = 0;
                    do
                    {
                        temp_num /= 10;
                        num_digits++;
                    } while (temp_num > 0);

                    // Print the digits in reverse order
                    for (int i = 0; i < num_digits; i++)
                    {
                        int digit = num % 10;
                        putchar('0' + digit);
                        char_count++;
                        num /= 10;
                    }

                    // Handle the case of 0
                    if (num_digits == 0)
                    {
                        putchar('0');
                        char_count++;
                    }

                    // If the number was negative, we already printed the '-' sign
                    // Otherwise, print a space for positive numbers
                    if (!is_negative)
                    {
                        putchar(' ');
                        char_count++;
                    }

                    break;
                }
                case '%':
                    putchar('%');
                    char_count++;
                    break;
                default:
                    putchar('%');
                    putchar(ch);
                    char_count += 2;
                    break;
            }
        }
        else
        {
            putchar(ch);
            char_count++;
        }
    }

    va_end(args);
    return char_count;
}

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

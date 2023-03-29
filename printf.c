#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...) {
    va_list arg_list;
    int char_count = 0;

    va_start(arg_list, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c':
                    char_count += putchar(va_arg(arg_list, int));
                    break;

                case 's':
                    char_count += printf("%s", va_arg(arg_list, char *));
                    break;

                case '%':
                    char_count += putchar('%');
                    break;

                default:
                    char_count += putchar('%');
                    char_count += putchar(*format);
                    break;
            }
        } else {
            char_count += putchar(*format);
        }

        format++;
    }

    va_end(arg_list);

    return char_count;
}

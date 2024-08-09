/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** to display
*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nbr)
{
    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + 48);
    }
    if (nbr < 0) {
        my_putchar('-');
        my_put_nbr(nbr * (- 1));
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
}

int my_put_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

static int to_display(va_list args, int i, char const *format)
{
    int nbr = 0;
    int d = i + 1;

    if (format[d] == 'd' || format[d] == 'i') {
        nbr = (va_arg(args, int));
        my_put_nbr(nbr);
    }
    if (format[d] == 's') {
        my_put_str(va_arg(args, char *));
    }
    if (format[d] == 'c') {
        my_putchar(va_arg(args, int));
    }
    if (format[d] == '%') {
        my_putchar('%');
    }
    return d;
}

int mini_printf(char const *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] != '%') {
            my_putchar(format[i]);
        }
        if (format[i] == '%') {
            i = to_display(args, i, format);
        }
        i++;
    }
    va_end(args);
    return i;
}

int main(int ac, char **av)
{
    mini_printf("daniel a %d ans", 19);
    return 0;
}

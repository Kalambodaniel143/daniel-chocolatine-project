/*
** EPITECH PROJECT, 2024
** units_tests
** File description:
** mi_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std ( void )
{
cr_redirect_stdout () ;
cr_redirect_stderr () ;
}

Test (mini_printf, simple_string , .init = redirect_all_std)
{
    mini_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (mini_printf, int_string , .init = redirect_all_std)
{
    mini_printf("hello world %d", 4);
    cr_assert_stdout_eq_str("hello world 4");
}

Test (mini_printf, int_i_string , .init = redirect_all_std )
{
    mini_printf("hello world %i", 154);
    cr_assert_stdout_eq_str("hello world 145");
}

Test (mini_printf, char_s_string , .init = redirect_all_std )
{
    mini_printf("hello %s world", "DANIEL");
    cr_assert_stdout_eq_str("hello DANIEL world");
}

Test (mini_printf, char_c_string , .init = redirect_all_std )
{
    mini_printf("Bonjour %c world", 'D');
    cr_assert_stdout_eq_str("Bonjour D world");
}

Test (mini_printf, special_case, .init = redirect_all_std )
{
    mini_printf("hello %% world");
    cr_assert_stdout_eq_str("hello % world");
}

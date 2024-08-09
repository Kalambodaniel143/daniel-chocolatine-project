##
## EPITECH PROJECT, 2024
## MY EPITECH PROJET
## File description:
## MY MINI PRINTF MAKEFILE
##

NAME = print_hello

SRC = mi_printf.c \

all :
	gcc -o $(NAME) $(SRC) -lm -g3

clean :
	rm -rf *o
	rm -f *~
	rm -f *#

fclean : clean
	rm -f $(NAME)

re : fclean all

code : fclean
	clear
	coding-style . .
	cat coding-style-reports.log
	rm -rf coding-style-reports.log

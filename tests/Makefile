##
## EPITECH PROJECT, 2024
## MY EPITECH PROJET
## File description:
## MY MINI PRINTF MAKEFILE
##

NAME = print_hello

SRC = test_mini_print.c\

all :
	gcc -o $(NAME) $(SRC) unit_tests --coverages -lcriterion -lgcov

clean :
	rm -rf *o
	rm -f *~
	rm -f *#

fclean : clean
	rm -f $(NAME)

re : fclean all

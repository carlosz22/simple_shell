all:
	 gcc -Wall -Werror -Wextra -pedantic -g *.c -o shell
	valgrind --leak-check=full --show-leak-kinds=all ./shell

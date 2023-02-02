# Para ejecutar este archivo solo corra el comando
#
#	make
#
# Se compila solo, el único problema es si ha cambiado ../src/pilas.c o
# ../src/pilas.h, que habría que correr `make' en el directorio superior.

test: src/main.c ../libpilas.so
	gcc src/main.c					\
		-Wall -Werror -g			\
		-I../include -L.. -lpilas -Wl,-rpath=..	\
		-o test

# End of File

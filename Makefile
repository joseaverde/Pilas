libpilas.so: src/pilas.c include/pilas.h
	gcc -shared -fPIC -Wall -Werror -g -Iinclude src/pilas.c -o libpilas.so

.PHONY: clean
clean:
	@rm libpilas.so

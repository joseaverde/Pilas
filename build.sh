#!/bin/bash
# La primera línea es la /shebang/ contiene el programa que ejecuta el archivo.
# Para hacer este archivo ejecutable ejecute:
#
#     chmod +x build.sh
#
# O bien, utilice el intérprete de `bash' para ejecutarlo.
#
#     bash build.sh
#
# El archivo solo compila el código. También puede usar la Makefile.

gcc -Wall -Werror -g -shared -fPIC -Iinclude src/pilas.c -o libpilas.so

# End of file

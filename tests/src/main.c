/* main.c
 * ======
 * Este es un programa simple para probar la biblioteca de pilas. Hay que
 * enlazarlo con `libpilas.so'. Nótese en el Makefile la opción:
 *
 *    -Wl,-rpath=..
 *
 * Ese argumento (que se pasa al enlazador `ld') añade a las direcciones donde
 * buscar las bibliotecas el directorio inmediatamente superior al ejecutable.
 * Se puede dar cualquier directorio. Esto se hace porque si no, cuando
 * ejecutes el archivo, el enlazador `ld', no sabe dónde encontrar la
 * biblioteca.
 *
 * AUTOR : José Antonio Verde Jiménez  <joseaverde@protonmail.com>
 * FECHA : 2023-02-02
 */

#include "pilas.h"
#include <stdio.h>

int main ( int argc, char *argv[] ) {

   pila_t *pila = NULL ;
   int valor ;

   pila = nueva_pila () ;
   for ( int i = 0 ; i < 10 ; i++ ) {
      printf ( "Apilando %d...\n", i ) ;
      apilar_pila ( pila, i ) ;
   }

   while ( longitud_pila ( pila ) != 0 ) {
      desapilar_pila ( pila, &valor ) ;
      printf ( "%d desapilado\n", valor ) ;
   }

   printf ( "Intentado desapilar...\n" ) ;
   if ( desapilar_pila ( pila, &valor ) ) {
      printf ( "Error, como era de esperar\n" ) ;
   }

   destruir_pila ( pila ) ;

   return 0 ;
}

/* End of File */

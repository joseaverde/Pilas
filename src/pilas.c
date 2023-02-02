/* pilas.c
 * =======
 * Implementación de las pilas de enteros.
 *
 * Buenas prácticas:
 *  - Declarar todas las variables al inicio. (Ninguna en el medio a no ser que
 *    tratemos con otro alcance /scope/).
 *  - TODOS LOS PUNTEROS DEBEN INICIALIZARSE A NULL.
 *  - Comprobar que el puntero no sea NULL, y ponerlo a NULL cuando se haya
 *    destruido/finalizado.
 *
 * AUTOR : José Antonio Verde Jiménez  <joseaverde@protonmail.com>
 * FECHA : 2023-02-02
 */

#include "pilas.h"
#include <stdlib.h>     // Contiene el malloc, free y NULL

// En primer lugar declaramos el tipo nodo.
typedef struct _nodo nodo_t ;
struct _nodo {
   nodo_t *siguiente ;
   int    valor ;
} ;

// Y unas primitivas para crearlo y destruirlo. Las declaramos `static' para
// que solo se puedan acceder desde este archivo y no sean visibles en la
// librería cuando lo compilemos.
static nodo_t *nuevo_nodo ( int valor, nodo_t *siguiente ) {

   // Tenemos que /castear/ al tipo puntero a nodo (`nodo_t*'), no es
   // estríctamente necesario, pero siempre es buena práctica. Porque malloc
   // devuelve un puntero genérico (`void*').
   // Dentro de malloc tenemos que escribir el tamaño del nodo, para ello
   // utilizamos el `sizeof'.
   // XXX: Cuidado con el `sizeof', porque no te da el tamaño de ningún vector
   //      que se haya declarado DINÁMICAMENTE. (Da el tamaño del puntero)
   nodo_t *self = NULL ;
   self = (nodo_t*)malloc ( sizeof(nodo_t) ) ;
   // IMPORTANTE: malloc puede devolver NULL, si nos quedamos sin memoria,
   // SIEMPRE SIEMPRE SIEMPRE, comprobar que no sea NULL, porque dereferenciar
   // (acceder) a NULL da una violación del segmento (segmentation fault)
   if ( NULL == self ) return NULL ;
   // Si se utiliza el `calloc' se initializa a 0, en nuestro caso ya tenemos
   // valores iniciales (parámetros).
   self->valor = valor ;
   self->siguiente = siguiente ;
   // Nótese que se utiliza `->' para acceder a los miembros de la estructura
   // en vez de `.', esto se debe a que `self' es de tipo puntero (`nodo_t*')
   return self ;
}

// La de destrucción es simple, solo que hay que tener cuidad con que `self'
// no sea NULL (nos podríamos fiar del usuario, pero siempre es bueno
// comprobar).
static void destruir_nodo ( nodo_t *self ) {

   if ( NULL != self ) free ( self ) ;
}

// Por fin podemos definir la pila
struct _pila {
   nodo_t *cima ;
   int    longitud ;
} ;

// La de creación es similar a la de `nuevo_nodo'
pila_t *nueva_pila () {

   pila_t *self = NULL ;
   self = (pila_t*)malloc ( sizeof(pila_t) ) ;
   if ( self == NULL ) return NULL ;
   self->cima = NULL ;
   self->longitud = 0 ;
   return self ;
}

void apilar_pila ( pila_t *self, int n ) {

   nodo_t *nodo = NULL ;
   nodo = nuevo_nodo ( n, self->cima ) ;
   if ( nodo == NULL ) return ;
   self->cima = nodo ;
   self->longitud++ ;
}

int desapilar_pila ( pila_t *self, int *n ) {

   // Obtenemos la cima
   nodo_t *nodo = NULL ;
   int ret = cima_pila ( self, n ) ;
   if ( ret != 0 ) return ret ;
   // Desapilamos
   nodo = self->cima ;
   self->cima = nodo->siguiente ;
   self->longitud-- ;
   destruir_nodo ( nodo ) ;
   return ret ;      // Que debe ser 0  :)
}

// La de destrucción es parecida, pero tenemos que desapilar.
void destruir_pila ( pila_t *self ) {

   if ( NULL == self ) return ;
   int dummy ;    // Para guardar el valor de desapilado.
   while ( self->longitud != 0 ) {
      desapilar_pila ( self, &dummy ) ;
   }
   free ( self ) ;
}

int cima_pila ( pila_t *self, int *n ) {

   if ( 0 == self->longitud ) {
      // Subdesbordamiento
      return -1 ;
   }
   *n = self->cima->valor ;
   return 0 ;
}

// La longitud de la pila es trivial, porque la tenemos en la estructura.
int longitud_pila ( pila_t *self ) {

   return self->longitud ;
}

/* End of File */

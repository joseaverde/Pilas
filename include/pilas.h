/* pilas.h
 * =======
 * Este encabezado contiene las declaraciones para pilas de enteros escritas en
 * C. Lea el README.md para más información.
 *
 * AUTOR : José Antonio Verde Jiménez  <joseaverde@protonmail.com>
 * FECHA : 2023-02-02
 */

/* En los archivos *.h se encuentran las DECLARACIONES de cualquier componente
 * de una aplicación de una librería. .h viene de su nombre en inglés /header/.
 * Por lo general todo archivo .h empieza con una guarda:
 */
#ifndef _PILAS_H
#define _PILAS_H

/* El
 *
 *    #ifndef _PILAS_H
 *
 * comprueba si no está definido el símbolo de preprocesador _PILAS_H, en cuyo
 * caso el preprocesador continúa con el archivo hasta encontrar el
 *
 *    #endif
 *
 * Que indique dónde parar. Justo después del #ifndef, escribimos
 *
 *    #define _PILAS_H
 *
 * Esto define el símbolo, y si el archivo se incluye (#include) otra vez, el
 * código no se copiará:
 *
 *    #ifndef _PILAS_H    (es equivalente a)    if not defined(_PILAS_H):
 *    #define _PILAS_H                             define(_PILAS_H)
 *    // Declaraciones                             // Declaraciones
 *    #endif
 *
 * Por ejemplo puedes tener un archivo "main.c" que incluye "a.h" y "pilas.h".
 * Sin embargo "a.h" también incluye "pilas.h". ¿Qué pasa? Que si no está la
 * guarda, se declarará todo este archivo DOS VECES, y aparecerá un error muy
 * largo. Para eso se usan las guardas.
 */

/* Podemos utilizar el typedef antes de declarar el struct. En este caso, he
 * utilizado el guion bajo delante de `_pila', para decir que es preferible
 * utilizar `pila_t' en su lugar. La declaración del `pila_t' está en el
 * archivo "pilas.c", no es necesario que el usuario sepa cómo es `pila_t' por
 * dentro.
 */
typedef struct _pila pila_t ;

// Declaramos unas primitivas

/* Esta función devuelve una nueva pila, si no se ha podido reservar memoria,
 * devuelve NULL.
 *
 * @return
 * La dirección de la pila.
 */
pila_t *nueva_pila () ;

/* Esta función vacía y libera una pila.
 */
void destruir_pila ( pila_t *self ) ;

/* Esta función apila un elemento de tipo entero (`int') en la cima de la pila.
 *
 * @param self
 * El puntero a una pila NO NULA.
 *
 * @param n
 * El entero a apilar.
 */
void apilar_pila ( pila_t *self, int n ) ;

/* Esta función desapila el entero en la cima de la pila y lo devuelve como
 * parámetro.
 *
 * @param self
 * El puntero a una pila NO NULA.
 *
 * @param n
 * El puntero a la dirección de memoria de un entero donde guardar el valor
 * desapilado. En el caso de que haya un subdesbordamiento, el valor no se
 * cambia.
 *
 * @return
 * Devuelve un entero 0 no hubo ningún problema, y distinto de 0 si hubo un
 * subdesbordamiento de pila.
 */
int desapilar_pila ( pila_t *self, int *n ) ;

/* Esta función devuelve la longitud de la pila en número de elementos.
 *
 * @param self
 * La dirección de la pila NO NULA cuya longitud se quiere obtener.
 *
 * @return
 * La longitud de la pila
 */
int longitud_pila ( pila_t *self ) ;

/* Esta función devuelve el elemento en la cima de la pila como parámetro.
 *
 * @param self
 * La dirección de la pila NO NULA cuya cima se quiere obtener.
 *
 * @param n
 * La dirección de memoria donde almacenar el valor de la cima. En el caso en
 * el que haya un subdesbordamiento, el valor en `n' no será modificado.
 *
 * @devuelve
 * Devuelve un entero 0 no hubo ningún problema, y distinto de 0 si hubo un
 * subdesbordamiento de pila.
 */
int cima_pila ( pila_t *self, int *n ) ;

// Nota: El comentario al final del #endif no es necesario, se suele poner para
// decir qué símbolo se estaba comprobando.
#endif//_PILAS_H

/* End of File */

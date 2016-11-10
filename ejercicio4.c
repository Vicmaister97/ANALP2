/***********************************************************/
/* Programa: P2_4                  Fecha: 10/11/2016       */
/* Autores: Alfonso Villar                                 */
/*          Victor Garcia                                  */
/* Programa que escribe en un fichero                      */
/* el tiempo promedio de ejecucion, maximo, minimo y       */
/* promedio de operaciones basicas del algoritmo de        */
/* ordenacion Quicksort                                    */
/*                                                         */
/* Entrada: Linea de comandos                              */
/* -num_min: numero minimo de elementos de la tabla        */
/* -num_max: numero maximo de elementos de la tabla        */
/* -incr: incremento                                       */
/* -numP: Introduce el numero de permutaciones a promediar */
/* -fichSalida: Nombre del fichero de salida               */
/* Salida: 0 si hubo error                                 */
/* -1 en caso contrario                                    */
/***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordenacion.h"
#include "tiempos.h"

int main(int argc, char** argv)
{
  int i, num_min, num_max, incr, n_perms;
  char nombre[256];
  short ret;

  srand(time(NULL));

  if (argc != 11) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -num_min <int> -num_max <int> -incr <int>\n", argv[0]);
    fprintf(stderr, "\t\t -numP <int> -fichSalida <string> \n");
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, "-num_min: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-num_max: numero minimo de elementos de la tabla\n");
    fprintf(stderr, "-incr: incremento\n");
    fprintf(stderr, "-numP: Introduce el numero de permutaciones a promediar\n");
    fprintf(stderr, "-fichSalida: Nombre del fichero de salida\n");
    exit(-1);
  }

  printf("Practica numero 2, apartado 4\n");
  printf("Realizada por: Alfonso Villar y Victor Garcia\n");
  printf("Grupo: 12\n");

  /* comprueba la linea de comandos */
  for(i = 1; i < argc ; i++) {
    if (strcmp(argv[i], "-num_min") == 0) {
      num_min = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-num_max") == 0) {
      num_max = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-incr") == 0) {
      incr = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-numP") == 0) {
      n_perms = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-fichSalida") == 0) {
      strcpy(nombre, argv[++i]);
    } else {
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
    }
  }

  /* calculamos los tiempos */
  ret = genera_tiempos_ordenacion(quicksort, nombre, num_min, num_max, incr, n_perms);
  if (ret == ERR) { /* ERR_TIME debera ser un numero negativo */
    printf("Error en la funcion Time_Ordena\n");
    exit(-1);
  }
  printf("Salida correcta \n");

  return 0;
}
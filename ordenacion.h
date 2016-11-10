/**
 *
 * Descripcion: Funciones de cabecera para ordenacion 
 *
 * Fichero: ordenacion.h
 * Autor: Alfonso Villar y Victor Garcia
 * Version: 1.0
 * Fecha: 21-10-2016
 *
 */

#ifndef ORDENACION_H
#define ORDENACION_H

/* constantes */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

/* definiciones de tipos */
typedef int (* pfunc_ordena)(int*, int, int);

/* Funciones */

int mergesort(int* tabla, int ip, int iu);
int merge(int* tabla, int ip, int iu, int imedio);
int quicksort(int* tabla, int ip, int iu);
int quicksort_stat(int* tabla, int ip, int iu);
int quicksort_avg(int* tabla, int ip, int iu);
int partir(int* tabla, int ip, int iu, int *pos);
int partir_stat(int* tabla, int ip, int iu, int *pos);
int partir_avg(int* tabla, int ip, int iu, int *pos);
int medio(int *tabla, int ip, int iu,int *pos);
int medio_stat(int *tabla, int ip, int iu,int *pos);
int medio_avg(int *tabla, int ip, int iu,int *pos);

#endif
/**
 *
 * Descripcion: Implementacion de funciones de ordenacion 
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2016
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenacion.h"

/***************************************************/
/* Funcion: mergesort Fecha: 21/10/2016            */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= iu                        */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int mergesort(int* tabla, int ip, int iu){
	int m;
	int n;

	if (ip > iu)
		return ERR;

	if (ip == iu)
		return OK;

	m = (int)(ip + iu) / 2;
	n = mergesort(tabla, ip, m);
	if (n == ERR)
		return ERR;

	n = mergesort(tabla, m+1, iu);
	if (n == ERR)
		return ERR;

	return merge(tabla, ip, iu, m);
}

/***************************************************/
/* Funcion: merge Fecha: 21/10/2016                */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= imedio <= iu              */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/* int imedio: Posicion del elemento medio de la   */
/* tabla                                           */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int merge(int* tabla, int ip, int iu, int imedio){
	int i;
	int j;
	int k;
	int cont;
	int* tabla2;
	tabla2 = (int*)malloc((iu-ip+1)*sizeof(int));
	if (tabla2 == NULL)
		return ERR;

	i = ip;
	j = imedio + 1;
	k = 0;
	cont = 0;

	while (i <= imedio && j <= iu){
		if (tabla[i] < tabla[j]){ /*OB del algoritmo*/
			tabla2[k] = tabla[i];
			i++;
			cont++;
		}
		else{
			tabla2[k] = tabla[j];
			j++;
		}
		k++;
	}

	if (i > imedio){ /*copia el resto de la tabla derecha*/
		while (j <= iu){
			tabla2[k] = tabla[j];
			cont++;
			j++;
			k++;
		}
	}
	
	else if (j > iu){ /*copia el resto de la tabla izquierda*/
		while (i <= imedio){
			tabla2[k] = tabla[i];
			cont++;
			i++;
			k++;
		}
	}

	for(i=ip, j = 0; i <= iu; i++, j++){
		tabla[i] = tabla2[j];
	}
	
	free(tabla2);

	return cont;
}

/***************************************************/
/* Funcion: quicksort Fecha: 4/11/2016             */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= iu                        */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int quicksort(int* tabla, int ip, int iu){
	int m;
	int* pos = NULL;

	if (ip > iu)
		return ERR;

	if (ip == iu)
		return OK;

	else{
		m = partir(tabla, ip, iu, pos);
		if (ip < m-1)
			quicksort (tabla, ip, m-1);
		
		if (m+1 < iu)
			quicksort (tabla, m+1, iu);
	}

	return OK;
}

/***************************************************/
/* Funcion: partir Fecha: 4/11/2016                */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= iu                        */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int partir(int* tabla, int ip, int iu,int *pos){
	int m;
	int k;
	int aux;
	int i;

	m = medio (tabla, ip, iu, pos);
	k = tabla[m];

	aux = tabla[ip];
	tabla[ip] = tabla[m];
	tabla[m] = aux;

	m = ip;

	for (i = ip +1; i <= iu; i++){
		if (tabla[i] < k){
			m++;
			aux = tabla[i];
	        tabla[i] = tabla[m];
	        tabla[m] = aux;
		}
	}

	aux = tabla[ip];
	tabla[ip] = tabla[m];
	tabla[m] = aux;

	return m;
}

/***************************************************/
/* Funcion: medio Fecha: 4/11/2016                 */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= iu                        */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int medio(int *tabla, int ip, int iu,int *pos){
	*pos = ip;
	return 0;
}


/***************************************************/
/* Funcion: medio_avg Fecha: 4/11/2016             */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= iu                        */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int medio_avg(int *tabla, int ip, int iu,int *pos){
	*pos = ip;
	return (ip+iu)/2;
}


/***************************************************/
/* Funcion: medio_stat Fecha: 4/11/2016            */
/* Autores: Alfonso Villar y Victor Garcia         */
/*                                                 */
/* Entrada:   0 <= ip <= iu                        */
/* int *tabla: Tabla con los numeros               */
/* int ip: Posicion del primer elemento a ordenar  */
/* int iu: Posicion del ultimo elemento a ordenar  */
/*                                                 */
/* Salida: devuelve el numero de veces que se ha   */
/* ejecutado la OB si se ha ordenado la tabla o en */
/* caso de error devuelve ERR                      */
/***************************************************/

int medio_stat(int *tabla, int ip, int iu,int *pos){
	int m= (int) (ip+iu)/2;
	if (ip<m) {
		if (m<iu) return m;
		else { 
			if (ip<iu) return iu;
			return ip;}}
	else {
		if (iu<m) return m;
		else {
			if (ip<iu) return ip;
			return iu;}}
	}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordina.h"

/*T(n) = theta(n+k)*/
/*k rappresenta il range di variazione (=26 lettere), n rappresenta il numero di elementi (stringhe)*/
void counting_sort(char A[][STRLUNG], int k, int n, int posiz)
{
    int i, j;
    int *C;
    char **B = (char **) malloc(sizeof(char *)*n);  /*B: matrice di riordino delle stringhe*/

    for(i=0; i<n; i++){
        B[i]=(char *) malloc(sizeof(char)*STRLUNG);
    }
    C = (int *) malloc(sizeof(int)*k);         /*C: vettore di conteggio per ogni lettera*/

    for (i = 0; i < k; i++)         /*inizializzo a 0 il vettore delle occorrenze delle lettere*/
        C[i] = 0;
    for (j = 0; j < n; j++){        /*incremento il conteggio delle occorrenze di ogni lettera del vett C*/
        C[(int)(A[j][posiz])-97] = C[(int)(A[j][posiz])-97] + 1;
    }

/*    for (i = 1; i < k; i++)        *for per ordinamento CRESCENTE*
        C[i] = C[i] + C[i-1]; */

    for (i = k-2; i >= 0; i--)      /*for per ordinamento DECRESCENTE*/
        C[i] = C[i] + C[i+1];

    for (j = n-1; j >= 0; j--)
    {
        for(i=0; i<STRLUNG; i++){
            B[(int)(C[(A[j][posiz])-97])-1][i]=A[j][i];
        }
        C[(A[j][posiz])-97] = C[(A[j][posiz])-97] - 1;
    }

    for(i=0; i<n; i++){
        strcpy(A[i],B[i]);
    }
}


void ordina(char v[][STRLUNG], int dim){
    int i;
    for(i=STRLUNG-2; i>=0; i--)
        counting_sort(v, 26, dim, i);
}

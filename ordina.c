#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordina.h"

/*k rappresenta il range di variazione (=26 lettere), n rappresenta il numero di elementi (stringhe)*/
void counting_sort(char A[][STRLUNG], int k, int n, int posiz)
{
    int i, j, l;
    /*char *str;*/
    /*char *str = (char *) malloc(sizeof(char)*STRLUNG);*/
    char **B = (char **) malloc(sizeof(char *)*n);  /*B: matrice di riordino delle stringhe*/
    char **D = (char **) malloc(sizeof(char *)*n);
    printf("fatto questo\n");
    for(i=0; i<n; i++){
        B[i]=(char *) malloc(sizeof(char)*STRLUNG);
//        B[i][STRLUNG]='\0';
//        B[i]=A[i];
//        printf("B[%d] = %s\n", i, B[i]);
//        strcpy(B[i],A[i]);
//        printf("B[%d] = %s\n", i, B[i]);
    }
    printf("fatto anche questo\n");
    int *C = (int *) malloc(sizeof(int)*k);         /*C: vettore di conteggio per ogni lettera*/

    for (i = 0; i < k; i++)         /*inizializzo a 0 il vettore delle occorrenze delle lettere*/
        C[i] = 0;
    for (j = 0; j < n; j++){        /*incremento il conteggio delle occorrenze di ogni lettera del vett C*/
        C[(int)(A[j][posiz])-97] = C[(int)(A[j][posiz])-97] + 1;
        printf("C[A[j][posiz]-97 = %d\n",C[A[j][posiz]-97]);
    }

//    for (i = 1; i < k; i++){        /*for per ordinamento CRESCENTE*/
//        C[i] = C[i] + C[i-1];
////        printf("C[%d] = %d\n",i,C[i]);
//    }

    for (i = k-2; i >= 0; i--)      /*for per ordinamento DECRESCENTE*/
        C[i] = C[i] + C[i+1];

    for (j = n-1; j >= 0; j--)
    {
        printf("arrivato anche qui\n");
        printf("A[%d] = %s\n",j,A[j]);
        for(i=0; i<STRLUNG; i++){
            B[(int)(C[(A[j][posiz])-97])-1][i]=A[j][i];
        }
//        B[(int)(C[(A[j][posiz])-97])-1][i]='\0';
//        strcpy(B[(int)(C[(A[j][posiz])-97])-1],A[j]);
//        B[(int)(C[(A[j][posiz])-97])-1] = A[j];
//        printf("B[%d] = %s\n",j,B[(int)(C[(A[j][posiz])-97])-1]/*, B[j]*/);
        C[(A[j][posiz])-97] = C[(A[j][posiz])-97] - 1;
    }


    for(i=0; i<n; i++)
        printf("B[%d] = %s\n", i, B[i]);

    for(i=0; i<n; i++){
//        for(l=0; l<STRLUNG; l++)
//            A[i][l]=B[i][l];
//        A[i][l]='\0';
        strcpy(A[i],B[i]);
//        printf("A[%d] = %s\n", i, A[i]);
//        printf("B[%d] = %s\n", i, B[i]);
//        strcpy(B[i],A[i]);
//        printf("B[%d] = %s\n", i, B[i]);
    }
}

/*void radix_sort(char v[][STRLUNG], int dim){
    int i;
    for(i=dim-1; i>=0; i--){
        counting_sort(v, 26, dim, dim-1);
    }
}*/

void ordina(char v[][STRLUNG], int dim){
    int i;
    for(i=STRLUNG-2; i>=0; i--)
        counting_sort(v, 26, dim, i);
}

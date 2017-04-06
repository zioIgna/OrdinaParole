#include <stdio.h>
#include <stdlib.h>
#include "ordina.h"

int main(){
    int i;
    /*char **matr;
    char str0[STRLUNG]="caso";
    char str1[STRLUNG]="casa";
    char str2[STRLUNG]="cono";
    char str3[STRLUNG]="cena";
    char str4[STRLUNG]="bisi";
    matr=(char **) malloc(sizeof(char *)*STRLUNG);
    matr[0]=str0;
    matr[1]=str1;
    matr[2]=str2;
    matr[3]=str3;
    matr[4]=str4;*/

    char matr[5][STRLUNG]={"caso","casa","cono","cena","bisi"};

    for(i=0;i<5;i++)
        printf("%s\n",matr[i]);

    printf("(int)(C[A[j][posiz]])-97 = %d\n", (int)(matr[0][0]-97));

    ordina(matr, 5);

    printf("\nstampa finale:\n");
    for(i=0;i<5;i++)
        printf("%s\n",matr[i]);

    return 0;
}

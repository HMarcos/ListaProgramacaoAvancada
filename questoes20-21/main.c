#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char** argv){
    //char comando_libgc[50];
    //char comando_mf[50];
    char aux[10];
    int i,n = 10000000;

    for(i=0; i<=n; i+=100000){
        printf("Execução %d:\n ", i);
        char comando_libgc[50] = "./libgc ";
        char comando_mf[50]= "./malloc_free ";
        sprintf(aux,"%i",i);
        strcat(comando_libgc,aux);
        strcat(comando_mf,aux);
        system(comando_libgc);
        system(comando_mf);
        printf("--------------------------\n");

    }
    

    return 0;
}
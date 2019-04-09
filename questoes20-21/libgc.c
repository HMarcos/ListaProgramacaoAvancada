#include "gc.h"
#include<assert.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main (int argc, char** argv){
    unsigned int i;
    clock_t start, end;
    double time_libgc;
    unsigned int n;
    n = atoi(argv[1]);
    GC_INIT();
    start = clock();
    for (i=0; i<n; i++){
            int **p = (int **) GC_MALLOC(sizeof(int*));
            int *q = (int*) GC_MALLOC_ATOMIC(sizeof(int));
            *p = (int*) GC_REALLOC(q, 2*sizeof(int));
        }
    end = clock();
    time_libgc = ((double) end -start)/CLOCKS_PER_SEC;
    printf("Tempo usando a LIBGC: %.8f\n", time_libgc);
}
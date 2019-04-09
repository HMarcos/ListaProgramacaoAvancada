#include<assert.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main (int argc, char** argv){
    unsigned int i;
    clock_t start, end;
    double time_mf;
    unsigned int n;
    
    n = atoi(argv[1]);

    start = clock();
    for (i=0; i<n; i++){
            int **p = (int **) malloc(sizeof(int*));
            int *q = (int*) malloc(sizeof(int));
            *p = (int*) realloc(q, 2*sizeof(int));
            free(*p);
            free(p);
        }

    end = clock();
    time_mf = ((double) end -start)/CLOCKS_PER_SEC;
    printf("Tempo usando apenas MALLOC e FREE: %.8f\n", time_mf);
}

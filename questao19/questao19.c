#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprimir(int **a,int l,int c){
    int i, j;
    for (i=0;i<l;i++) {
        for (j=0;j<c;j++) {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
}

void multiplicarmatriz(int **A, int **B, int **C,int nlA, int ncA, int ncB){
   int i, j, k, soma;
   for (i=0;i<nlA;i++) {
       for (j=0;j<ncB;j++) {
           soma =0;
           for (k=0;k<ncA;k++) {
               soma = soma + A[i][k]*B[k][j];
           }
          C[i][j] = soma;
       }
   }
   imprimir(C, nlA, ncB);
}

int main()
{
    int **a, **b, **c;
    int i, j;
    int la, ca, lb, cb;
    
    printf("defina os parametros da matriz A : \n");
    printf("numero de linhas :");
    scanf("%i", &la);
    printf("numero de colunas :");
    scanf("%i", &ca);
    printf("agora defina os parametros da matriz B \n:");
    printf("numero de colunas (o numero de linhas deve ser o mesmo que o numero de colunas em A) :");
    scanf("%i", &cb);
    
    lb = ca;

    a = (int **)malloc(la*sizeof (int*));
    
    a[0] = (int *)malloc(la*ca*sizeof (int));
    for (i=1;i<la;i++) {
        a[i] = a[i-1] + ca;
    }

    b = (int **)malloc(lb*sizeof (int*));
    b[0] = (int *)malloc(lb*cb*sizeof (int));
    for (i=1;i<lb;i++) {
        b[i] = b[i-1] + cb;
    }

    c = (int **)malloc(la*sizeof (int*));
    c[0] = (int *)malloc(la*cb*sizeof (int));
    for (i=1;i<la;i++) {
        c[i] = c[i-1] + cb;
    }

    for (i=0;i<la;i++) {
        for (j=0;j<ca;j++) {
            a[i][j] = i+j;
        }
    }

    for (i=0;i<lb;i++) {
        for (j=0;j<cb;j++) {
            b[i][j] = i*j;
        }
    }


    printf("Matriz A: \n");
    imprimir(a, la, ca);
    printf("\n");
    printf("Matriz B: \n");
    imprimir(b, lb, cb);
    printf("\n");
    printf("Matriz C=AxB: \n");
    multiplicarmatriz(a,b,c,la,ca,cb);
    //imprimir(c, la, cb);
    printf("\nMatriz C=BxA: \n");
    multiplicarmatriz(b,a,c,lb,cb,ca);
    

    free(a[0]);
    free(b[0]);
    free(c[0]);
    free(a);
    free(b);
    free(c);
    return 0;
}

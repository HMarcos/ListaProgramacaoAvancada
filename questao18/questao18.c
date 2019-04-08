#include <stdio.h>
#include <stdlib.h>

void somar(int *s, int *a, int *b, int n){
    int i;
    for (i=0;i<n;i++){
        s[i] = a[i] + b[i];
    }

}

int main(void){
    int *a, *b, *s;
    int n, i;
    printf("escolha o tamanho dos vetores: ");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    b = (int*)malloc(n*sizeof(int));
    s = (int*)malloc(n*sizeof(int));
    printf("defina o vetor 1: \n");
    for(i=0;i<n;i++){
        printf("a[%d] = ",i);
        scanf("%d", a+i);
    }

    printf("defina o vetor 2: \n");
    for(i=0;i<n;i++){
        printf("b[%d] = ",i);
        scanf("%d", b+i);
    }

    printf("vetor soma: \n");
    somar(s, a, b, n);
    for(i=0;i<n;i++){
        printf("%d ", s[i]);
    }
    printf("\n");
    free(a);
    free(b);
    free(s);
  return 0;
}

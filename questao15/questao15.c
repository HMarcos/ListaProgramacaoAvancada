

/*Utiliza-se agora o qsort() para fazer a ordenação do array. Deve-se criar, então, uma função para comparar dois const void ponteiros e retornar o valor
da diferença entre eles, pois dependendo desse valor, o qsort() entenderá como sendo positivo ou negativo e influenciará na ordenação do array.*/

#include <stdio.h>
#include <stdlib.h>

    int comparar (const void * a, const void * b)
    {
        return ( *(int*)a - *(int*)b ); //a função que recebe dois ponteiros gen�ricos e retorna a diferença entre seu conteúdo.
    }

int main(void){
    float *a;
    int n, i;
    printf("escolha o tamanho do vetor: ");
    scanf("%i", &n);
    a = (float*)malloc(n*sizeof(float));
    printf("defina o vetor: ");
    for(i=0;i<n;i++){
        scanf("%f", a+i);
    }
    printf("vetor antes da ordenacao: \n");
    for(i=0;i<n;i++){
        printf("%.1f ", a[i]);
    }
    printf("\n");
    printf("vetor apos a ordenacao: \n");
    qsort(a,n,sizeof(float),comparar);
    // a função solicita o ponteiro com o numero de elementos,
    //com o tamanho do tipo de elemento e a função comparadora para fazer a ordenação.
    for(i=0;i<n;i++){
        printf("%.1f ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}
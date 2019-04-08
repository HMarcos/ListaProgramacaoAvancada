#include <stdio.h>
#include <stdlib.h>

// Implementação do Método Bolha de Ordenação
void metodo_bolha( int n, float *v){
    int i;
    float aux;
    int ultimo = n;
    bool troca = true;
    while(troca){
        troca = false;
        for (i=0;i<ultimo-1;i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = true;
            }
        }
        ultimo--;
    }
    
}

int main(){
    float *a;
    int n, i;
    printf("escolha o tamanho do vetor: ");
    scanf("%i", &n);
    a = (float *)malloc(n*sizeof(float));
    printf("defina o vetor:\n");
    for(i=0;i<n;i++){
        printf("v[%d] = ",i);
        scanf("%f", a+i);
    }
    printf("vetor antes da ordenacao: \n");
    for(i=0;i<n;i++){
        printf("%.1f ", a[i]);
    }
    printf("\n");
    printf("vetor apos a ordenacao: \n");
    metodo_bolha(n, a);
    for(i=0;i<n;i++){
        printf("%.1f ", a[i]);
    }
    printf("\n");
    free(a);
  return 0;
}
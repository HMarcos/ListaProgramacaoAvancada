#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

// Função que retorna a diferença entre números
int compara (const void* a, const void *b){
    return (*(int*)a - *(int*)b);
}

// Implementação do Método Bolha de Ordenação utilizando ponteiro para função
void metodo_bolha( int n, float *v, int(*comparacao)(const void* a, const void *b)){
    int i;
    float aux;
    int ultimo = n;
    bool troca = true;
    while(troca){
        troca = false;
        for (i=0;i<ultimo-1;i++){
            if(comparacao((v+i),(v+i+1))>0){ // Chamada função que realiza a diferença entre dois números
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = true;
            }
        }
        ultimo--;
    }
    
}

// Função para imprimir um array
void imprime_array(int n, float *v){
  int i;
  for(i = 0; i < n; i++)
    {
        printf("%.1f ", v[i]);
    }
    printf("\n");
}


int main(){
    float *v1, *v2;
    int n = 1<<20; // Tamanho do Array
    int i;
    clock_t start, end;
    double cpu_time_used;
    double diferenca_tempos;

    // Alocando a memória para dois vetores que receberão os mesmos valores
    v1 = (float*)malloc(n*sizeof(float));
    v2 = (float*)malloc(n*sizeof(float));
    
    // Inicializando a semente com o tempo do computador da função que "gera" números aleatórios
    srand(time(NULL));
    
    //Preenchendo os dois vetores com números aleatórios
    for(i=0; i<n; i++){
        v1[i] = rand()%100 + i*(0.1);
        v2[i] = v1[i]; 
    }

    printf("Ordenando um array com %d numeros\n",n);
    // Imprime o vetor gerado aleatoriamente 
    printf("Array aleatório: \n");
    //imprime_array(n,v1);

    
    start = clock(); // Tempo realativo ao início da execução do método bolha
    metodo_bolha(n,v1,compara);
    end = clock(); // Tempo realativo ao fim da execução do método bolha

    // Calculando o tempo gasto para ordenação do vetor utilizando o método bolha
    // Há nesse comando a conversão do tempo em CLOCKS para SEGUNDOS
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  
    diferenca_tempos = cpu_time_used;
    
    printf("Array ordenado - Método Bolha: \n");
    //imprime_array(n,v1);
    printf("Tempo gasto: %.8fs\n",cpu_time_used);


    start = clock(); // Tempo realativo ao início da execução do método qsort
    qsort(v2,n,sizeof(float),compara);
    end = clock(); // Tempo realativo ao fim da execução do método qsort

    // Calculando o tempo gasto para ordenação do vetor utilizando o método qsort
    // Há nesse comando a conversão do tempo em CLOCKS para SEGUNDOS
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    diferenca_tempos -= cpu_time_used;
    
    printf("Array ordenado - Método Qsort: \n");
    //imprime_array(n,v2);
    printf("Tempo gasto: %.8fs\n",cpu_time_used);

    if(diferenca_tempos>0){ 
        printf("A funcao qsort foi mais rapida cerca de: %.8fs\n",diferenca_tempos);
    }
    else{
        printf("A funcao metodo_bolha foi mais rapida cerca de: %.8fs\n",diferenca_tempos);
    } 

    // Liberando a memoria
    free(v1);
    free(v2);
    
    return 0;
}
#include <stdio.h> 
// Uma função normal do tipo void com um parâmetro do tipo inteiro 

void function(int a) 
{ 
    printf("Valor de a eh: %d\n", a); 
} 
  
int main() 
{ 
    // function_ptr é um ponteiro para a função function  
    void (*function_ptr)(int) = &function; 
  
    // Invocando function() usando function_ptr 
    (*function_ptr)(10); 
  
    return 0; 
} 

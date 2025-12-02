#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFFER 1000


int verificar(uint64_t valor){
    char aux[BUFFER];
    sprintf(aux, "%llu", valor); 
    
    int len = strlen(aux);
    
    if (len % 2 != 0) return 0;
    
    int metade = len / 2;
    if (strncmp(aux, aux + metade, metade) == 0) {
        return 1; 
    }
    
    return 0;
}

int main(){
    FILE *f;
    f = fopen("input.txt", "r");
    uint64_t valor = 0; 
    
    if (f == NULL) {
        printf("Erro ao abrir ficheiro\n");
        return 1;
    }
    
    char primeiro[BUFFER];
    char segundo[BUFFER];

    char comma;  // Para ler a vírgula
    
    while (fscanf(f, "%999[^-]-%999[^,]", primeiro, segundo) == 2) {
        
        printf("\nPrimeiro: %s Segundo: %s", primeiro, segundo);
        uint64_t prim = _atoi64(primeiro);
        uint64_t segun = _atoi64(segundo);
        for(uint64_t i = prim;i<=segun;i++){
            if(verificar(i)==1){
                valor += i;
            }
        }
        int result = fscanf(f, "%c", &comma);
        printf("\n\n%lld",valor);

        if (result != 1) break;
    }
    printf("\n\n%lld",valor);
    
    fclose(f);
    return 0;
}

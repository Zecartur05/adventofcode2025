#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define START 50

int main() {
    FILE *file;
    char s[2];
    int i;
    int start = START;
    int aux;
    int password = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Erro: Nao foi possivel abrir input.txt\n");
        return 1;
    }

    while(fscanf(file,"%1s%d\n",s,&i) != EOF){
        aux = start;
        int zeros = 0;

        if(s[0] == 'R'){
            start = (start + i) % 100;
            zeros = (aux + i) / 100;
        } else {
            int paraesqeuerda = i;

            start = (start - paraesqeuerda) % 100;
            if (start < 0) start += 100;

            int posicaoinicial = (aux == 0) ? 100 : aux;
            
            if (paraesqeuerda >= posicaoinicial) {
                zeros = 1 + (paraesqeuerda - posicaoinicial) / 100;
            } else {
                zeros = 0;
            }
        }
        password += zeros; 
    }

    printf("Resultado final: %d\n", password);

    fclose(file);
    
    return 0; 
}
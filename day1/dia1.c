#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define START 50


int main(){
    FILE *file;
    char s[2];
    int i;
    int start = START;

    int password = 0; 

    file = fopen("input.txt", "r");

    while(fscanf(file,"%1s%d\n",s,&i) != EOF){
        if(s[0] == 'R'){
            start = (start + i) % 100;
        }else{
            start = (start - i + 100) % 100;
        }
        if(start == 0){
            password++;
        }
    }
    printf("%d",password);
    fclose(file);
    return 1;
}
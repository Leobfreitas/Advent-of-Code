#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontraNumero(char str[]){
    int tam, primeiro = -1, ultimo = -1, n = 0;
    for(tam = 0; str[tam] != '\0'; tam++);

    for(int i = 0, j = tam-1; i < tam; i++, j--){
        if(str[i] >= '0' && str[i] <= '9' && primeiro == -1){
            primeiro = str[i]-'0';
        }
        if(str[j] >= '0' && str[j] <= '9' && ultimo == -1){
            ultimo = str[j]-'0';
        }
    }

    if(primeiro != -1 && ultimo != -1){
        return n += primeiro*10+ultimo;
    } else if(primeiro == -1){
        return n += ultimo*10+ultimo;
    } else{
        return n += primeiro*10+primeiro;
    }
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[100];
    int soma = 0;

    if(!f){
        return;
    }

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
        soma += encontraNumero(str);
    }

    printf("[%d]\n", soma);
}

int main(){
    readFile("input.txt");
}
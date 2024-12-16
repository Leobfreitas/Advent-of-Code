#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char str[], int pos){
    if(strncmp(&str[pos], "one", 3) == 0){
        return 1;
    }
    if(strncmp(&str[pos], "two", 3) == 0){
        return 2;
    }
    if(strncmp(&str[pos], "three", 5) == 0){
        return 3;
    }
    if(strncmp(&str[pos], "four", 4) == 0){
        return 4;
    }
    if(strncmp(&str[pos], "five", 4) == 0){
        return 5;
    }
    if(strncmp(&str[pos], "six", 3) == 0){
        return 6;
    }
    if(strncmp(&str[pos], "seven", 5) == 0){
        return 7;
    }
    if(strncmp(&str[pos], "eight", 5) == 0){
        return 8;
    }
    if(strncmp(&str[pos], "nine", 4) == 0){
        return 9;
    }
    if(strncmp(&str[pos], "zero", 4) == 0){
        return 0;
    }

    return -1;
}

int encontraNumero(char str[]){
    int tam, primeiro = -1, ultimo = -1, k = 0, n = 0;
    for(tam = 0; str[tam] != '\0'; tam++);

    for(int i = 0; i < tam; i++){
        if(str[i] >= '0' && str[i] <= '9' & k == 0){
            primeiro = str[i]-'0';
            k = 1;
        } else if(str[i] >= '0' && str[i] <= '9' & k != 0){
            ultimo = str[i]-'0';
        } else if(isNumber(str, i) != -1 && k == 0){
            primeiro = isNumber(str, i);
            k = 1;
        } else if(isNumber(str, i) != -1 && k != 0){
            ultimo = isNumber(str, i);
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
        //printf("[%d]\n", encontraNumero(str));
        soma += encontraNumero(str);
    }

    printf("[%d]\n", soma);
}

int main(){
    readFile("input.txt");
}
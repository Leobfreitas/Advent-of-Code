#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotacaoEsq(int atual, int rotacao){
    atual -= rotacao;
    while(atual < 0){
        atual += 100;
    }
    return atual;
}

int rotacaoDir(int atual, int rotacao){
    atual += rotacao;
    while(atual > 99){
        atual -= 100;
    }
    return atual;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char c;
    int valor = 50, rotacao, cont = 0;    

    if(!f){
        return;
    }

    while(!feof(f)){
        fscanf(f, "%c%d\n", &c, &rotacao);
        if(c == 'L'){
            valor = rotacaoEsq(valor, rotacao);
        } else if(c == 'R'){
            valor = rotacaoDir(valor, rotacao);
        }
        if(valor == 0){
            cont++;
        }
    }

    printf("%d", cont);

}

int main(){
    readFile("input.txt");
    return 0;
}
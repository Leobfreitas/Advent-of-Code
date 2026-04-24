#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotacaoEsq(int *atual, int rotacao){
    int cont = 0;
    while(rotacao > 0){
        rotacao--;
        *atual-=1;
        if(*atual == 0){
            cont++;
        }
        if(*atual < 0){
            *atual += 100;
        }
    }
    return cont;
}

int rotacaoDir(int *atual, int rotacao){
    int cont = 0;
    while(rotacao > 0){
        rotacao--;
        *atual+=1;
        if(*atual > 99){
            *atual -= 100;
            cont++;
        }
    }
    return cont;
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
            cont += rotacaoEsq(&valor, rotacao);
        } else if(c == 'R'){
            cont += rotacaoDir(&valor, rotacao);
        }
    }

    printf("%d", cont);

}

int main(){
    readFile("input.txt");
    return 0;
}
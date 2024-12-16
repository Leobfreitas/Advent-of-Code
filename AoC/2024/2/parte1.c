#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void inicializaMatriz(int matriz[][10], int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < 10; j++){
            matriz[i][j] = -1;
        }
    }
}

void imprimeMatriz(int matriz[][10], int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < 10; j++){
            if(matriz[i][j] != -1){
                printf("[%d] ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

int isDigito(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int montaNumero(char str[], int pos, int *fwd){
    int casas = 0;
    while(isDigito(str[pos+casas])){
        casas++;
    }
    int i = 0, n = 0;
    while(i < casas){
        n += pow(10, (double) casas-(i+1)) * (str[pos+i] - '0');
        i++;
    }
    *fwd = casas;
    return n;
}

int preencheMatriz(char str[], int matriz[][10], int linha){
    int i, tam = 0, casas;
    for(i = 0; str[i] != '\0'; i++){
        if(isDigito(str[i])){
            casas = 0;
            matriz[linha][tam] = montaNumero(str, i, &casas);
            tam++;
            i+=casas-1;
        }
    }
    return tam;
}

int isDecrescente(int matriz[][10], int tam, int linha){
    int flag = 1, x;
    for(int i = 1; matriz[linha][i] != -1; i++){
        x = matriz[linha][i] - matriz[linha][i-1];
        if(x > -1 || x < -3){
            flag = 0;
        }
    }
    return flag;
}

int isCrescente(int matriz[][10], int tam, int linha){
    int flag = 1, x;
    for(int i = 1; matriz[linha][i] != -1; i++){
        x = matriz[linha][i] - matriz[linha][i-1];
        if(x < 1 || x > 3){
            flag = 0;
        }
        if(linha == 723){
            //printf("%d\n", x);
            //printf("%d\n\n", matriz[linha][8]);
        }
    }
    return flag;
}

int contaSafes(int matriz[][10], int tam){
    int cont = 0, a ,b;
    for(int i = 0; i < tam; i++){
        a = isCrescente(matriz, tam, i);
        b = isDecrescente(matriz, tam, i);         
        if(a || b){
            //printf("%d\n", i+1);
            cont++;
        }
    }
    return cont;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];

    if(!f){
        return;
    }

    int i = 0, col, matriz[10000][10];

    inicializaMatriz(matriz, 1000);

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
        col = preencheMatriz(str, matriz, i);
        i++;
    }

    imprimeMatriz(matriz, i);

    printf("%d", contaSafes(matriz, 1000));


}

int main(){
    readFile("teste.txt");
}
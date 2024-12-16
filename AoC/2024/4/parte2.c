#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeMatriz(char matriz[][141], int tamMatriz){
    for(int i = 0; i < tamMatriz; i++){
        for(int j = 0; j < tamMatriz; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int isXmas(char matriz[][141], int linha, int coluna, int tamMatriz){
    if(linha > 0){
        if(coluna > 0){
            if(matriz[linha-1][coluna-1] == 'M'){
                if(matriz[linha+1][coluna+1] == 'S'){
                    if(matriz[linha-1][coluna+1] == 'M'){
                        if(matriz[linha+1][coluna-1] == 'S'){
                            return 1;
                        }
                    }
                    if(matriz[linha+1][coluna-1] == 'M'){
                        if(matriz[linha-1][coluna+1] == 'S'){
                            return 1;
                        }
                    }
                }
            }
        }
        if(coluna < tamMatriz-1){
            if(matriz[linha-1][coluna+1] == 'M'){
                if(matriz[linha+1][coluna-1] == 'S'){
                    if(matriz[linha-1][coluna-1] == 'M'){
                        if(matriz[linha+1][coluna+1] == 'S'){
                            return 1;
                        }
                    }
                    if(matriz[linha+1][coluna+1] == 'M'){
                        if(matriz[linha-1][coluna-1] == 'S'){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if(linha < tamMatriz-1){
        if(coluna > 0){
            if(matriz[linha+1][coluna-1] == 'M'){
                if(matriz[linha-1][coluna+1] == 'S'){
                    if(matriz[linha-1][coluna-1] == 'M'){
                        if(matriz[linha+1][coluna+1] == 'S'){
                            return 1;
                        }
                    }
                    if(matriz[linha+1][coluna+1] == 'M'){
                        if(matriz[linha-1][coluna-1] == 'S'){
                            return 1;
                        }
                    }
                }
            }
        }
        if(coluna < tamMatriz-1){
            if(matriz[linha+1][coluna+1] == 'M'){
                if(matriz[linha-1][coluna-1] == 'S'){
                    if(matriz[linha-1][coluna+1] == 'M'){
                        if(matriz[linha+1][coluna-1] == 'S'){
                            return 1;
                        }
                    }
                    if(matriz[linha+1][coluna-1] == 'M'){
                        if(matriz[linha-1][coluna+1] == 'S'){
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int contaPalavras(char matriz[][141], int tamMatriz){
    int cont = 0, i, j;
    for(int i = 0; i < tamMatriz; i++){
        for(int j = 0; j < tamMatriz; j++){
            if(matriz[i][j] == 'A'){
                cont += isXmas(matriz, i, j, tamMatriz);
            }
        }
    }
    return cont;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char matriz[141][141];
    int tamMatriz = 140;

    if(!f){
        return;
    }

    int i, j;

    while(!feof(f)){
        for(i = 0; i < tamMatriz; i++){
            for(j = 0; j < tamMatriz; j++){
                fscanf(f, "%c", &matriz[i][j]);
            }
            fscanf(f, "\n");
        }
    }
    
    printf("%d\n", contaPalavras(matriz, tamMatriz));

}

int main(){
    readFile("input.txt");
}
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
    int cont = 0;
    if(linha > 2){
        if(coluna > 2){
            if(matriz[linha-1][coluna-1] == 'M'){
                if(matriz[linha-2][coluna-2] == 'A'){
                    if(matriz[linha-3][coluna-3] == 'S'){
                        cont++;
                    }
                }
            }
        }
        if(matriz[linha-1][coluna] == 'M'){
            if(matriz[linha-2][coluna] == 'A'){
                if(matriz[linha-3][coluna] == 'S'){
                    cont++;
                }
            }
        }    
        if(coluna < tamMatriz-3){
            if(matriz[linha-1][coluna+1] == 'M'){
                if(matriz[linha-2][coluna+2] == 'A'){
                    if(matriz[linha-3][coluna+3] == 'S'){
                        cont++;
                    }
                }
            }    
        }
    }
    if(coluna > 2){
        if(matriz[linha][coluna-1] == 'M'){
            if(matriz[linha][coluna-2] == 'A'){
                if(matriz[linha][coluna-3] == 'S'){
                    cont++;
                }
            }
        }
    }
    if(coluna < tamMatriz-3){
        if(matriz[linha][coluna+1] == 'M'){
            if(matriz[linha][coluna+2] == 'A'){
                if(matriz[linha][coluna+3] == 'S'){
                    cont++;
                }
            }
        }    
    }
    if(linha < tamMatriz-3){
        if(coluna > 2){
            if(matriz[linha+1][coluna-1] == 'M'){
                if(matriz[linha+2][coluna-2] == 'A'){
                    if(matriz[linha+3][coluna-3] == 'S'){
                        cont++;
                    }
                }
            }
        }
        if(matriz[linha+1][coluna] == 'M'){
            if(matriz[linha+2][coluna] == 'A'){
                if(matriz[linha+3][coluna] == 'S'){
                    cont++;
                }
            }
        }    
        if(coluna < tamMatriz-3){
            if(matriz[linha+1][coluna+1] == 'M'){
                if(matriz[linha+2][coluna+2] == 'A'){
                    if(matriz[linha+3][coluna+3] == 'S'){
                        cont++;
                    }
                }
            }    
        }
    }
    return cont;
}

int contaPalavras(char matriz[][141], int tamMatriz){
    int cont = 0, i, j;
    for(int i = 0; i < tamMatriz; i++){
        for(int j = 0; j < tamMatriz; j++){
            if(matriz[i][j] == 'X'){
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
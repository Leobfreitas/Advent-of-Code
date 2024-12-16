#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isDigito(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int contaCasasDigito(char matriz[][141], int linha, int coluna){
    int n = 0;
    while(isDigito(matriz[linha][coluna])){
        n++;
        coluna++;
    }    
    return n;
}

int verificaFronteira(char matriz[][141], int linha, int coluna, int tamMatriz){
    if(linha > 0){
        if(coluna > 0){
            if(matriz[linha-1][coluna-1] != '.' && !isDigito(matriz[linha-1][coluna-1])){
                return 1;
            }
        }
        if(matriz[linha-1][coluna] != '.' && !isDigito(matriz[linha-1][coluna])){
            return 1;
        }
        if(coluna < tamMatriz-2){
            if(matriz[linha-1][coluna+1] != '.' && !isDigito(matriz[linha-1][coluna+1])){
                return 1;
            }                
        }
    }
    if(coluna > 0){
        if(matriz[linha][coluna-1] != '.' && !isDigito(matriz[linha][coluna-1])){
            return 1;
        }
    }
    if(coluna < tamMatriz-2){
        if(matriz[linha][coluna+1] != '.' && !isDigito(matriz[linha][coluna+1])){
            return 1;
        }                
    }
    if(linha < tamMatriz-2){
        if(coluna > 0){
            if(matriz[linha+1][coluna-1] != '.' && !isDigito(matriz[linha+1][coluna-1])){
                return 1;
            }
        }
        if(matriz[linha+1][coluna] != '.' && !isDigito(matriz[linha+1][coluna])){
            return 1;
        }
        if(coluna < tamMatriz-2){
            if(matriz[linha+1][coluna+1] != '.' && !isDigito(matriz[linha+1][coluna+1])){
                return 1;
            }                
        }
    }
    return 0;
}

int montaNumero(char matriz[][141], int linha, int coluna, int *flag){

    int j, n, soma = 0;    

    n = contaCasasDigito(matriz, linha, coluna);

    j = 0;
    while(j < n){
        soma += (int) pow(10, (double) (n-(j+1))) * (matriz[linha][coluna] - '0');

        if(verificaFronteira(matriz, linha, coluna, 141)){
            *flag = 1;
        }

        j++;
        coluna++;
    }
    return soma;
}

void readFile(char nomeArq[], int tamMatriz){
    FILE *f = fopen(nomeArq, "r");
    char matriz[141][141];
    int i, j, soma = 0, n, flag;

    if(!f){
        return;
    }

    while(!feof(f)){
        for(i = 0; i < tamMatriz; i++){
            for(j = 0; j < tamMatriz; j++){
                fscanf(f, "%c", &matriz[i][j]);
            }
            fscanf(f, "\n");
        }
    }

    for(i = 0; i < tamMatriz; i++){
        for(j = 0; j < tamMatriz; j++){
            if(isDigito(matriz[i][j])){
                flag = 0;
                n = montaNumero(matriz, i, j, &flag);
                if(flag){
                    printf("%d\n", n);
                    soma += n;
                }
            }
            j += contaCasasDigito(matriz, i, j);
        }
    }
    printf("%d", soma);

}

int main(){
    readFile("input.txt", 141);
}
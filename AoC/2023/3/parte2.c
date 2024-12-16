#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void inicializaVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        vet[i] = -1;
    }
}

void imprimeVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        if(vet[i] != -1){
            printf("[%d] ", vet[i]);
        }
    }    
    printf("\n");
}

int isDigito(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int montaNumero(char matriz[][140], int linha, int coluna, int tamMatriz){

    int esq = 0, dir = 0, casas, n = 0;
    
    while(coluna-esq-1 >= 0 && isDigito(matriz[linha][coluna-esq-1])){
        esq++;
    }

    while(coluna+dir+1 <= tamMatriz-1 && isDigito(matriz[linha][coluna+dir+1])){
        dir++;
    }

    casas = esq + dir + 1;

    while(isDigito(matriz[linha][coluna-1])){
        coluna--;
    }

    int j = 0;

    while(j < casas){
        n += (int) pow(10, (double) (casas-(j+1))) * (matriz[linha][coluna] - '0');
        coluna++;
        j++;
    }
    return n;
}

int multiplicaVetor(int vet[], int tam, int *qtde){
    int produto = 1;
    
    for(int i = 0; i < tam; i++){
        if(vet[i] != -1){
            if(i == 0 || i == 3 || i == 4 || i == 5){
                produto *= vet[i];
                *qtde+=1;
            } else if(vet[i] != vet[i-1]){
                produto *= vet[i];
                *qtde+=1;
            }
        }
    }
    return produto;
}


/* POSICOES DO VETOR:
0 1 2
3 * 4
5 6 7
*/

int calculaProduto(char matriz[][140], int tamMatriz){

    int i, j;

    int vet[8], tamVet = 0, soma = 0, x = 0, cont;

    for(i = 0; i < tamMatriz; i++){
        for(j = 0; j < tamMatriz; j++){

            if(matriz[i][j] == '*'){
                
                inicializaVetor(vet, 8);

                if(i > 0){
                    if(j > 0){
                        if(isDigito(matriz[i-1][j-1])){
                            vet[0] = montaNumero(matriz, i-1, j-1, tamMatriz);
                        }
                    }
                    if(isDigito(matriz[i-1][j])){
                        vet[1] = montaNumero(matriz, i-1, j, tamMatriz);
                    }
                    if(j < tamMatriz-1){
                        if(isDigito(matriz[i-1][j+1])){
                            vet[2] = montaNumero(matriz, i-1, j+1, tamMatriz);
                        }                
                    }
                }
                if(j > 0){
                    if(isDigito(matriz[i][j-1])){
                        vet[3] = montaNumero(matriz, i, j-1, tamMatriz);
                    }
                }
                if(j < tamMatriz-1){
                    if(isDigito(matriz[i][j+1])){
                        vet[4] = montaNumero(matriz, i, j+1, tamMatriz);
                    }
                }
                if(i < tamMatriz-1){
                    if(j > 0){
                        if(isDigito(matriz[i+1][j-1])){
                            vet[5] = montaNumero(matriz, i+1, j-1, tamMatriz);
                        }
                    }
                    if(isDigito(matriz[i+1][j])){
                        vet[6] = montaNumero(matriz, i+1, j, tamMatriz);
                    }
                    if(j < tamMatriz-1){
                        if(isDigito(matriz[i+1][j+1])){
                            vet[7] = montaNumero(matriz, i+1, j+1, tamMatriz);
                        }                
                    }
                }

                cont = 0;
                imprimeVetor(vet, 8);
                x = multiplicaVetor(vet, 8, &cont);
                if(cont == 2){
                    soma+=x;
                }
            }

        }
    }
    printf("\n\n%d\n", soma);
}

void readFile(char nomeArq[], int tamMatriz){
    FILE *f = fopen(nomeArq, "r");
    char matriz[140][140];

    int i, j;

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

    calculaProduto(matriz, tamMatriz);

}

int main(){
    readFile("input.txt", 140);
}
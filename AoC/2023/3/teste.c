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

int montaNumero(char matriz[][140], int linha, int coluna, int tamMatriz){

    int esq = 0, dir = 0, casas, n = 0;
    
    while(coluna-esq-1 >= 0 && isDigito(matriz[linha][coluna-esq-1])){
        esq++;
    }

    while(coluna+dir+1 <= tamMatriz-1 && isDigito(matriz[linha][coluna+dir+1])){
        dir++;
    }

    casas = esq + dir + 1;

    printf("%d %d %d\n", casas, esq, dir);

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

    printf("%d", montaNumero(matriz, 0, 1, 10));

}

int main(){
    readFile("teste.txt", 10);
}

int multiplicaVetor(int vet[], int tam){
    int produto = 1;
    
    for(int i = 0; i < tam; i++){
        if(vet[i] != -1){
            if(i == 0 || i == 3 || i == 4 || i == 5){
                produto *= vet[i];
            } else if(i == 1){
                if(vet[i] != vet[0]){
                    produto *= vet[i];
                }
            } else if(i == 2){
                
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

int contaOcorrencias(int vet[], int tam, int x){
    int cont = 0;
    for(int i = 0; i < tam; i++){
        if(vet[i] == x){
            cont++;
        }
    }
    return cont;
}

int calculaSimilaridade(int vet1[], int vet2[], int tam){
    int soma = 0;
    for(int i = 0; i < tam; i++){
        soma += vet1[i] * contaOcorrencias(vet2, tam, vet1[i]);
    }
    return soma;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");

    int vet1[1000], vet2[1000], i = 0;

    if(!f){
        return;
    }

    while(!feof(f)){
        fscanf(f, "%d %d\n", &vet1[i], &vet2[i]);
        i++;
    }

    printf("%d\n", calculaSimilaridade(vet1, vet2, i));
}

int main(){
    readFile("input.txt");
}
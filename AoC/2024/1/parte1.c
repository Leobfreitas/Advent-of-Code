#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

void ordenaVetor(int vet[], int tam){
    int posMenor, menor, aux, i, j;
    for(i = 0; i < tam; i++){
        menor = vet[i];
        posMenor = -1;
        for(j = i; j < tam; j++){
           if(vet[j] < menor){
                posMenor = j;
                menor = vet[j];
           } 
        }
        if(posMenor != -1){
            aux = vet[i];
            vet[i] = vet[posMenor];
            vet[posMenor] = aux;
        }
    }
}

int calculaDistancia(int vet1[], int vet2[], int tam){
    int soma = 0;
    for(int i = 0; i < tam; i++){
        if(vet1[i] > vet2[i]){
            soma += vet1[i] - vet2[i];
        } else{
            soma += vet2[i] - vet1[i];
        }
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

    ordenaVetor(vet1, i);
    ordenaVetor(vet2, i);
    printf("%d\n", calculaDistancia(vet1, vet2, i));
}

int main(){
    readFile("input.txt");
}
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

int preencheVetor(char str[], int vet[]){
    int i, tam = 0, casas;
    for(i = 0; str[i] != '\0'; i++){
        if(isDigito(str[i])){
            casas = 0;
            vet[tam] = montaNumero(str, i, &casas);
            tam++;
            i+=casas-1;
        }
    }
    return tam;
}

void imprimeVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

int calculaPossibilidades(int tempo, int distancia){
    int i, press, restante, vitoria = 0;
    for(i = 0; i <= tempo; i++){
        press = tempo - i;
        restante = tempo - press;
        if(press * restante > distancia){
            vitoria++;
        }
    }
    return vitoria;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];

    if(!f){
        return;
    }

    int distancias[100], tempos[100], tamDist, tamTempo;

    fscanf(f, "%[^\n]%*c", str);

    tamTempo = preencheVetor(str, tempos);

    fscanf(f, "%[^\n]%*c", str);

    tamDist = preencheVetor(str, distancias);

    int mult = 1;

    for(int i = 0; i < tamDist; i++){
        mult *= calculaPossibilidades(tempos[i], distancias[i]);
    }

    printf("%d", mult);

}

int main(){
    readFile("input.txt");


    return 0;
}
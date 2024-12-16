#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void eliminaChar(char str[], int pos){
    int i;
    for(i = pos; str[i] != '\0'; i++){
        str[i] = str[i+1];
    }
}

void trim(char str[]){
    int i;
    
    while(str[0] == ' '){
        eliminaChar(str, 0);
    }
    
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            eliminaChar(str, i);
            i--;
        }
    }

    if(str[i-1] == ' '){
        eliminaChar(str, i-1);
    }
}

int isDigito(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

unsigned long long int montaNumero(char str[], int pos, int *fwd){
    int casas = 0;
    while(isDigito(str[pos+casas])){
        casas++;
    }
    unsigned long long int i = 0, n = 0;
    while(i < casas){
        n += pow(10, (double) casas-(i+1)) * (str[pos+i] - '0');
        i++;
    }
    *fwd = casas;
    return n;
}

int preencheVetor(char str[], unsigned long long int vet[]){
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

void imprimeVetor(unsigned long long int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("[%llu] ", vet[i]);
    }
    printf("\n");
}

unsigned long long int calculaPossibilidades(unsigned long long int tempo, unsigned long long int distancia){
    unsigned long long int i, press, restante, vitoria = 0;
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

    unsigned long long int distancias[100], tempos[100], tamDist, tamTempo;

    fscanf(f, "%[^\n]%*c", str);
    trim(str);
    printf("%s\n", str);

    tamTempo = preencheVetor(str, tempos);

    fscanf(f, "%[^\n]%*c", str);
    trim(str);
    printf("%s\n", str);

    tamDist = preencheVetor(str, distancias);

    unsigned long long int mult = 1;

    imprimeVetor(tempos, tamTempo);
    imprimeVetor(distancias, tamDist);

    for(int i = 0; i < tamDist; i++){
        mult *= calculaPossibilidades(tempos[i], distancias[i]);
    }

    printf("%llu", mult);

}

int main(){
    readFile("input.txt");


    return 0;
}
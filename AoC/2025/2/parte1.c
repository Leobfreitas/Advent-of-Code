#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void imprimeVetor(long long int vet[], long long int tam){
    for(int i = 0; i < tam; i++){
        printf("%ld ", vet[i]);
    }
    printf("\n");
}

void inverteVetor(long long int vet[], long long int tam){
    int aux;
    for(int i = 0, j = tam-1; i < j; i++, j--){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
}

long long int isDigito(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

long long int montaNumero(char str[], long long int pos, long long int *fwd){
    long long int casas = 0;
    while(isDigito(str[pos+casas])){
    //    printf("%c ", str[pos+casas]);
        casas++;
    }
    //printf("\n");
    long long int i = 0, n = 0;
    while(i < casas){
        n += pow(10, (double) casas-(i+1)) * (str[pos+i] - '0');
        i++;
    }
    *fwd = casas;
    //printf("%lld\n", n);

    return n;
}

long long int toArray(long long int vet[], long long int x){
    long long int i;
    for(i = 0; x != 0; i++, x = x/10){
        vet[i] = x % 10;
    }
    return i;
}

long long int isSequencia(long long int vet[], long long int tam){
    if(tam % 2 == 1){
        return 0;
    }

    for(int i = 0, j = tam/2; j < tam; i++, j++){
        if(vet[i] != vet[j]){
            return 0;
        }
    }

    return 1;
}

long long int verificaIntervalo(long long int menor, long long int maior){
    long long int vet[100], tam;
    long long int soma = 0;
    while(menor <= maior){
        tam = toArray(vet, menor);
        inverteVetor(vet, tam);
        if(isSequencia(vet, tam)){
            soma += menor;
        }
        menor++;
    }
    return soma;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];
    long long int menor, maior, tam;
    long long int soma = 0;

    if(!f){
        return;
    }

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
    }

    for(int i = 0; str[i] != '\0'; i++){
        if(isDigito(str[i])){
            menor = montaNumero(str, i, &tam);
            i += tam+1;
            maior = montaNumero(str, i, &tam);
            i += tam;
            printf("%lld %lld\n", menor, maior);
            soma += verificaIntervalo(menor, maior);
        }
    }
    printf("%lld", soma);
}

int main(){
    readFile("input.txt");
}
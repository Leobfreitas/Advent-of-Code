#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void imprimeVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void inverteVetor(int vet[], int tam){
    int aux;
    for(int i = 0, j = tam-1; i < j; i++, j--){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
}

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

int toArray(int vet[], int x){
    int i;
    for(i = 0; x != 0; i++, x = x/10){
        vet[i] = x % 10;
    }
    return i;
}

int findSecondOcurrence(int vet[], int tam, int pos, int x){
    while(pos < tam){
        if(vet[pos] == x){
            return pos;
        }
        pos++;
    }
    return -1;
}

int isSequencia(int vet[], int tam){
    int i = 0, j = findSecondOcurrence(vet, tam, 1, vet[0]), aux;
    if(j == -1 || tam % 2 == 1){
        return 0;
    }    
    aux = j;
    while(j < tam){
        if(vet[i] != vet[j]){
            return 0;
        }
        i++;
        j++;
    }
    if(i != aux){
        return 0;
    }
    return 1;
}

long int verificaIntervalo(int menor, int maior){
    int vet[100], tam;
    long int soma = 0;
    while(menor <= maior){
        tam = toArray(vet, menor);
        inverteVetor(vet, tam);
        if(isSequencia(vet, tam)){
            //printf("%d ", menor);
            soma += menor;
        }
        menor++;
    }
    return soma;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];
    int menor, maior, tam;
    long int soma = 0;

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
            printf("%d %d\n", menor, maior);
            soma += verificaIntervalo(menor, maior);
        }
    }
    printf("%ld", soma);
}

int main(){
    readFile("teste.txt");
}
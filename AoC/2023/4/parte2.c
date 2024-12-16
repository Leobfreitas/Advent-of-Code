#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    int info;
    struct no *prox;
} typedef NO_LISTA;

NO_LISTA *insereFinal(NO_LISTA *l, int info){
    if(!l){
        NO_LISTA *l = malloc(sizeof(NO_LISTA));
        l->info = info;
        l->prox = NULL;
        return l;
    } else{
        l->prox = insereFinal(l->prox, info);
        return l;
    }
}

void imprimeLista(NO_LISTA *l){
    if(l){
        printf("[%d] ", l->info);
        imprimeLista(l->prox);
    }
}

NO_LISTA *desalocaLista(NO_LISTA *l){
    while(l){
        NO_LISTA *aux = l;
        l = l->prox;
        free(aux);
    }
    return NULL;
}

int verificaLista(NO_LISTA *l, int info){
    if(!l){
        return 0;
    }
    NO_LISTA *corredor;
    for(corredor = l; corredor != NULL; corredor = corredor->prox){
        if(corredor->info == info){
            return 1;
        }
    }
    return 0;
}

void inicializaVetor(int vet[], int tam){
    for(int i = 1; i <= tam; i++){
        vet[i] = 1;
    }
}

void imprimeVetor(int vet[], int tam){
    for(int i = 1; i <= tam; i++){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

int somaVetor(int vet[], int tam){
    int soma = 0;
    for(int i = 1; i <= tam; i++){
        soma += vet[i];
    }
    return soma;
}

int calculaPontos(NO_LISTA *listaNumeros, NO_LISTA *listaVencedores){

    NO_LISTA *corredor;

    int pontos = 0;

    for(corredor = listaNumeros; corredor != NULL; corredor = corredor->prox){
        if(verificaLista(listaVencedores, corredor->info)){
            pontos++;
        }
    }
    return pontos;
}

void readFile(char nomeArq[], int tam){
    FILE *f = fopen(nomeArq, "r");
    char str[500];

    NO_LISTA *listaVencedores = NULL;
    NO_LISTA *listaNumeros = NULL;

    int resposta[300], i, x, soma = 0, n;

    if(!f){
        return;
    }

    inicializaVetor(resposta, tam);

    int z = 1;
    while(!feof(f)){
        fscanf(f, "%[^:]: ", str);
        for(i = 0; i < 10; i++){
            fscanf(f, "%d ", &x);
            listaVencedores = insereFinal(listaVencedores, x);
        }
        fscanf(f, "| ");
        for(i = 0; i < 24; i++){
            fscanf(f, "%d ", &x);
            listaNumeros = insereFinal(listaNumeros, x);
        }
        fscanf(f, "%d%*c", &x);
        listaNumeros = insereFinal(listaNumeros, x);

        n = calculaPontos(listaNumeros, listaVencedores);

        for(i = 1; i <= n; i++){
            if(z+i <= tam){
                resposta[z+i]+=resposta[z];
            }
        }

        listaVencedores = desalocaLista(listaVencedores);
        listaNumeros = desalocaLista(listaNumeros);
        z++;
    }


    imprimeVetor(resposta, tam);
    printf("\n\n%d", somaVetor(resposta, tam));

    //printf("%d\n", soma);
}

int main(){
    NO_LISTA *l = NULL;

    readFile("input.txt", 223);
}
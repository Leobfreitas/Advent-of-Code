#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct hand{
    int cartas[5];
    int maior;
    int rank;
    int tipo; //6 (5 cartas iguais) - 5 (4 cartas iguais) - 4 (full house) - 3 (trinca) - 2 (2 pares) - 1 (par) - 0 (carta maior)
    int bid;
} typedef HAND;

int isDigito(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int calculaValor(char c){
    if(c >= '0' && c <= '9'){
        return c-'0';
    } else if(c == 'T'){
        return 10;
    } else if(c == 'J'){
        return 11;
    } else if(c == 'Q'){
        return 12;
    } else if(c == 'K'){
        return 13;
    } else if(c == 'A'){
        return 14;
    }
    return 0;    
}

int montaNumero(char str[], int pos){
    int casas = 0;
    while(isDigito(str[pos+casas])){
        casas++;
    }
    int i = 0, n = 0;
    while(i < casas){
        n += pow(10, (double) casas-(i+1)) * (str[pos+i] - '0');
        i++;
    }
    return n;
}

int contaInstancias(int vet[], int x){
    int i, cont = 0;
    for(i = 0; i < 5; i++){
        if(vet[i] == x){
            cont++;
        }
    }
    return cont;
}

void readHand(char str[], HAND hands[], int tam){

    int i;
    for(i = 0; i < 5; i++){
        hands[tam].cartas[i] = calculaValor(str[i]);
    }

    hands[tam].bid = montaNumero(str, i+1);

}

void imprimeHand(HAND h){
    for(int i = 0; i < 5; i++){
        printf("[%d] ", h.cartas[i]);
    }

 //   printf("\n%d\n", h.maior);
    printf("\n%d\n", h.bid);

}

int isFiveEquals(HAND hand){
    if(contaInstancias(hand.cartas, hand.cartas[0]) == 5){
        return 1;
    }
    return 0;
}

int isFourEquals(HAND hand){
    if(contaInstancias(hand.cartas, hand.cartas[0]) == 4 || contaInstancias(hand.cartas, hand.cartas[1]) == 4){
        return 1;
    }
    return 0;
}

int isFullHouse(HAND hand){
    int i, par = 0, trinca = 0;
    for(i = 0; i < 5; i++){
        if(contaInstancias(hand.cartas, hand.cartas[i]) == 2){
            par = 1;
        }
        if(contaInstancias(hand.cartas, hand.cartas[i]) == 3){
            trinca = 1;
        }
    }
    if(par && trinca){
        return 1;
    }
    return 0;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];

    if(!f){
        return;
    }

    int tam = 0;
    HAND hands[2000];
    
    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);

        readHand(str, hands, tam);
        imprimeHand(hands[tam]);
        
    }

}

int main(){
    readFile("teste.txt");
}
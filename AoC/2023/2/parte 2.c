#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 2147483647

struct set{
    int red;
    int green;
    int blue;
} typedef SET;

int qtdeCasasNumericas(char str[], int pos){
    int i = 0;

    while(str[pos] >= '0' && str[pos] <= '9'){
        i++;
        pos++;
    }

    return i;
}

int calculaNumeroPotencia(int x, int pot){
    int soma = pow(10, (double) pot);
    return soma * x;
}

int calculaSet(char str[]){
    SET sets[50];

    int i, n, tam = 0, j, x, c;

    for(i = 0; i < 50; i++){
        sets[i].red = MAX; sets[i].green = MAX; sets[i].blue = MAX;
    }



    for(i = 5; str[i] != '\0'; i++){
        if(str[i] == ';'){
            tam++;
        }
        if(str[i] >= '0' && str[i] <= '9'){
            n = qtdeCasasNumericas(str, i);

            j = 0;
            x = 0;
            while(j < n){
                c = str[i+j] - '0';
                x += calculaNumeroPotencia(c, n-(j+1));
                j++;

            }

            i += j+1;

            if(str[i] == 'r'){
                if(x < sets[tam].red){
                    sets[tam].red = x;
                }
            } else if(str[i] == 'g'){
                if(x < sets[tam].green){
                    sets[tam].green = x;
                }
            } else if(str[i] == 'b'){
                if(x < sets[tam].blue){
                    sets[tam].blue = x;
                }
            }            
        }
    }

    int minR = 0, minG = 0, minB = 0;

    for(i = 0; i <= tam; i++){
        if(sets[i].red > minR && sets[i].red != MAX){
            minR = sets[i].red;
        }
        if(sets[i].green > minG && sets[i].green != MAX){
            minG = sets[i].green;
        }
        if(sets[i].blue > minB && sets[i].blue != MAX){
            minB = sets[i].blue;
        }
    }

    printf("%d %d %d\n", minR, minG, minB);

    return minR*minG*minB;
}


void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];

    if(!f){
        return;
    }

    int total = 0;

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
        total += calculaSet(str);
    }

    printf("%d", total);
}

int main(){
    readFile("input.txt");
}
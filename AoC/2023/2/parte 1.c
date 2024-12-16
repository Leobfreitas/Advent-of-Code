#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*int isColor(char str[], int pos){
    if(strncmp(&str[pos], "red", 3) == 0){
        return 1;
    }
    if(strncmp(&str[pos], "green", 5) == 0){
        return 2;
    }
    if(strncmp(&str[pos], "blue", 4) == 0){
        return 3;
    }
    return 0;
}*/

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

int isPossible(char str[]){
    int n, i, j, x, c;
    int red, green, blue;

    for(i = 5; str[i] != '\0'; i++){
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
                if(x > 12){
                    return 0;
                }
            } else if(str[i] == 'g'){
                if(x > 13){
                    return 0;
                }
            } else if(str[i] == 'b'){
                if(x > 14){
                    return 0;
                }
            }            
        }
        
    }
    return 1;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];
    int i = 1, total = 0;

    if(!f){
        return;
    }

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
        if(isPossible(str)){
            printf("[%d]\n", i);
            total += i;
        }
        i++;
    }

    printf("%d", total);
}

int main(){
    readFile("input.txt");
    return 0;
}
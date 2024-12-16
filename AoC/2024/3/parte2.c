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

int calculaMul(char str[], int pos, int *fwd){
    int i = 0, num1, num2;
    *fwd = 0;

    if(str[pos+i] == 'm'){
        i++;
        if(str[pos+i] == 'u'){
            i++;
            if(str[pos+i] == 'l'){
                i++;
                if(str[pos+i] == '('){
                    i++;
                    if(isDigito(str[pos+i])){
                        num1 = montaNumero(str, pos+i, fwd);
                        i += *fwd;
                        if(str[pos+i] == ','){
                            i++;
                            *fwd = 0;
                            if(isDigito(str[pos+i])){
                                num2 = montaNumero(str, pos+i, fwd);
                                i += *fwd;
                                if(str[pos+i] == ')'){
                                    return num1 * num2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int verificaEnable(char str[], int pos){
    int i = 1;
    if(str[pos+i] == 'o'){
        i++;
        if(str[pos+i] == '('){
            i++;
            if(str[pos+i] == ')'){
                return 1;
            }
        }
        if(str[pos+i] == 'n'){
            i++;
            if(str[pos+i] == '\''){
                i++;
                if(str[pos+i] == 't'){
                    i++;
                    if(str[pos+i] == '('){
                        i++;
                        if(str[pos+i] == ')'){
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int verificaString(char str[], int *flag){
    int cont = 0, tam, x, k = -1;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'm'){
            x = calculaMul(str, i, &tam);
            if(*flag == 1){
                cont += x;
            }
            if(x != 0){
                i += tam;
            }
        }
        if(str[i] == 'd'){
            k = verificaEnable(str, i);
            if(k != -1){
                *flag = k;
            }
        }
    }
    return cont;
}

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[100000];
    int flag = 1;

    if(!f){
        return;
    }

    int cont = 0;

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
        cont += verificaString(str, &flag);
        printf("%d\n", cont);
    }

    printf("%d", cont);

}

int main(){
    readFile("input.txt");
}
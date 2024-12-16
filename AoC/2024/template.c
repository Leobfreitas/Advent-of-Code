#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(char nomeArq[]){
    FILE *f = fopen(nomeArq, "r");
    char str[500];

    if(!f){
        return;
    }

    while(!feof(f)){
        fscanf(f, "%[^\n]%*c", str);
    }

}

int main(){
    readFile("input.txt");
}
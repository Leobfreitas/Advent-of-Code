#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    scanf("%[^\n]%*c", str);
    if(strncmp(&str[2], "one", 3) == 0){
        printf("IGUAL");
    } else{
        printf("NAO");
    }
    return 0;
}
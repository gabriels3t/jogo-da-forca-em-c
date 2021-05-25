#include <stdio.h>

void abertura(int multiplicador){
    printf("tabuada do %d\n\n",multiplicador);
}

int main(){
   int multiplicador = 2; 
    abertura(multiplicador);
    for(int i = 1; i <=10 ;i++){
        printf("%d X %d = %d \n ",multiplicador,i,i*multiplicador);
    }
}
#include <stdio.h>
#include <string.h>

void abertura(){
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta(int chutes,int tentativas){
     char chute;
        scanf(" %c",&chute); // Colocar um espaço antes do %c para nao ocorer um buffer
        chutes[tentativas] = chute;
        tentativas++; 
}

int main(){

    abertura();
    char palavraSecreta[20];
    sprintf(palavraSecreta,"melancia");
    char chutes[26];
    int acertou = 0;
    int inforcou = 0;
    int numeroDeCaracteres = strlen(palavraSecreta);
    int tentativas = 0;

    do{
        
        for(int i = 0; i < numeroDeCaracteres; i++ ){
            
            int achou = 0;

            for(int j=0; j < tentativas; j++){
                if(chutes[j] == palavraSecreta[i]){
                    achou = 1;
                    break;
                }
            }

            if(achou){
                printf("%c ",palavraSecreta[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");
        chuta();
       
    }while(!acertou && !inforcou);
}
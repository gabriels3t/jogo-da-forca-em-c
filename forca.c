#include <stdio.h>
#include <string.h>

char palavraSecreta[20];
char chutes[26];
int tentativas = 0;
void abertura(){
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void escolhePalavra(){
    
    sprintf(palavraSecreta,"melancia");
}
void chuta(){
    char chute;
    scanf(" %c",&chute); // Colocar um espaço antes do %c para nao ocorer um buffer
    chutes[tentativas] = chute;
    tentativas++;
         
}

int jaChutou(char letra){

    int achou = 0;

    for(int j=0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }   
    return achou; 
}
void desenhaForca(){
    
    int numeroDeCaracteres = strlen(palavraSecreta);
    for(int i = 0; i < numeroDeCaracteres; i++ ){
            
        int achou = jaChutou(palavraSecreta[i]);

            if(achou){
                printf("%c ",palavraSecreta[i]);
            }else{
                printf("_ ");
            }
    }
        printf("\n");
}

int main(){
    int acertou = 0;
    int inforcou = 0;
    escolhePalavra();
    abertura();
    do{
        desenhaForca();    
        chuta();
        
    }while(!acertou && !inforcou);
}
#include <stdio.h>
#include <string.h>

//VARIAVEIS GLOBAIS
char palavraSecreta[20];
char chutes[26];
int tentativas = 0;

//MOSTRANDO AS FUNÇÕES QUE EXISTE PRO COMPILADOR NÃO DAR ERRO DE ORDEM
void abertura();
void escolhePalavra();
void chuta();
int jaChutou(char letra);
void desenhaForca();
int acertou();
int inforcou();

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

int acertou(){
    for(int j=0;j<strlen(palavraSecreta);j++){
        if(!jaChutou(palavraSecreta[j])){
            return 0;
        }
    }
    return 1;
}

int inforcou(){
    int erro = 0; 
    for(int i =0; i<tentativas;i++){
        int existe = 0;
        for(int j=0;j<strlen(palavraSecreta);j++){
            if(chutes[i]== palavraSecreta[j]){
                existe =1;
                break;
            }
        }
        if(!existe) erro++;
    }
    return erro>=5;

    
}

int main(){
    escolhePalavra();
    abertura();
    do{
        desenhaForca();    
        chuta();
        
    }while(!acertou() && !inforcou());
}
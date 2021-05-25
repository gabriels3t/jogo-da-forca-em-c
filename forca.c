#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>
//VARIAVEIS GLOBAIS
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int tentativas = 0;



void abertura(){
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void escolhePalavra(){
    FILE* f;
    f = fopen("palavras.txt","r");
    if(f==0){
        printf("Banco de dados falhou tente novamente mais tarde");
        exit(1);
    }else{
        sprintf(palavraSecreta,"melancia");
        int quantidadeDePalavras =0;
        fscanf(f,"%d",&quantidadeDePalavras);
        srand(time(0));
        int random =  rand()%quantidadeDePalavras;
        for(int i =0;i<=random;i++){
            fscanf(f,"%s",palavraSecreta);
        }
        fclose(f);
    }
}


void adicionaPalavra(){
    char quer;
    int escolha = 0;
    do{
        printf("Quer adicionar uma nova palavra? (S/N) \n");
        scanf(" %c",&quer);
        if(quer=='S'){

            char novaPalavra[TAMANHO_PALAVRA];
            FILE* f;
            printf("Qual a nova palavra?(de preferencia para tudo maiusculo)");
            scanf(" %s",&novaPalavra);

            f = fopen("palavras.txt","r+"); // leitura mais escrita
            if(f==0){
                printf("Banco de dados falhou tente novamente mais tarde");
                exit(1);
            }
            int quantidade = 0;
            fscanf(f,"%d",&quantidade);
            quantidade++;
            fseek(f,0,SEEK_SET); // volta pro inicio do arquivo
            fprintf(f,"%d", quantidade);

            fseek(f,0,SEEK_END);
            fprintf(f,"\n%s",novaPalavra);

            fclose(f);

            escolha == 1;
            break;
        }else if(quer=='N'){
            escolha == 1;
            break;
        }else{
            printf("Por favor escolha entre (S/N) \n");
        }
        
    }while(!escolha);

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
    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '),(erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '),(erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '),(erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
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

int chuteserrados() {
    int erros = 0;

    for(int i = 0; i < tentativas; i++) {

        int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++) {
            if(chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros;
}

int enforcou() {
    
    return chuteserrados() >= 5;
}

int main(){
    escolhePalavra();
    abertura();
    
    do{
        desenhaForca();    
        chuta();
        
    }while(!acertou() && !enforcou());
    adicionaPalavra();
}
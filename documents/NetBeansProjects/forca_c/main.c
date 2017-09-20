/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: User
 *
 * Created on 17 de Setembro de 2017, 18:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char palavrasecreta[20];
char letras_chutadas[26];
int tentativas = 0;

/*
 * 
 */
void abertura() {
    printf("*************************************\n");
    printf("* * * * * * Jogo da Forca * * * * * *\n");
    printf("*************************************\n");
}

void escolhe_palavra() {
    sprintf(palavrasecreta, "melancia");
}

void chuta() {
    char chute;
    printf("Chute uma aletra: ");
    scanf(" %c", &chute);
        
    letras_chutadas[tentativas] = chute;
    tentativas++;
}

void desenha_forca() {
    printf("Chute número: %d\n", tentativas);
    
    for(int i = 0; i < strlen(palavrasecreta); i++) {
            
        if(ja_chutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }        
    
    }
    printf("\n");
}

int ja_chutou(char letra) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(letras_chutadas[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

int enforcou() {
    int erros = 0;
    
    for(int i = 0; i < tentativas; i++) {
        int existe = 0;
        
        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(letras_chutadas[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }
        
        if(!existe) erros++;
        
    }

    return erros >= 5;
}


int main() {
    
    int acertou = 0;
    int enforcou = 0;    
    
    abertura();
    escolhe_palavra();
    
    do {
        
        desenha_forca();
        chuta();            
        
    } while(!acertou && !enforcou);
    
    printf("%s", palavrasecreta);
    
    
}


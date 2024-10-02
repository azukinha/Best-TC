#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "votacao.h"

Professor docentes[max];
int qtdeDocentes;

Aluno formandos[max];
int qntdeFormandos;

TC listaTCs[max];
int qtdeTCs;

Eleitor comissao[max];
int qtdeEleitores;

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

void menu1() {
    printf("--------------------------------------\n");
    printf("a) Iniciar nova votacao \nb) Continuar votacao gravada\n\nDigite sua escolha:  ");
    char opcao = valida_opcao("ab");

    switch (opcao) {
        case 'a':
            inicia_nova_votacao();
            break;
        case 'b':
            continua_votacao_gravada();
            break;
    }
}

void inicia_nova_votacao() {
    printf("--------------------------------------\n");
    printf("a) Entrar com voto \nb) Suspender votacao\nc) Concluir votacao\n\nDigite sua escolha:  ");
    char opcao = valida_opcao("abc");

    switch (opcao) {
        case 'a':
            // entra_com_voto();
            break;
        case 'b':
            // suspende_votacao();
            break;
        case 'c':
            //conclui_votacao();
            break;
    }
}

void continua_votacao_gravada(){
    FILE * parcial;
    parcial = fopen("parcial.txt", "r");

    if(parcial == NULL){
        printf("\n--------------------------------------\nNao ha votacao para ser continuada.\n");
        menu1();
    } else {
        inicia_nova_votacao();
    }
    fclose(parcial);
}

char valida_opcao(char opcoes_validas[]){
    char opcao;
    int opcao_valida = 0;

    while(!opcao_valida){
        opcao = tolower(getchar());
        limpa_buffer();

        for(int i = 0; opcoes_validas[i] != '\0'; i++){
            if (opcao == opcoes_validas[i]){
                opcao_valida = 1;
                break;
            }
        }

        if (!opcao_valida){
            printf("Escolha invalida. Digite novamente: ");
        }
    }
    return opcao;
}

void concluir_votacao(){
    FILE * resultado;
    resultado = fopen("resultado.txt", "w");

    fclose(resultado);
}

int valida_arquivo(){

}

int valida_cpf(char cpf[15]){
    int soma1 = 0, soma2 = 0, j = 0, resto1, resto2;
    
    for(int i = 0; i < 14; i++){
        if(i==3 || i==7){
            if(cpf[i] != '.') return 0;} 
            
        if(i==11) {
            if(cpf[i] != '-') return 0;}
        
        if((i!=3 && i!=7 && i!=11)){
            if(!isdigit(cpf[i])) return 0;}
    }
    
    for(int i = 0; i < 14; i++){
        if(isdigit(cpf[i])){
            if(cpf[i] == cpf[0]){
                j++;}
        }
    }

    if(j==11)return 0;
    
    j = 0;
    
    for(int i = 0; i < 11 && j < 10; i++){
        if(isdigit(cpf[i])){
            soma1 += (cpf[i] - '0') * (10-j);
            j++;}
    }

    j = 0;

    for(int i = 0; i < 13 && j < 10; i++){
        if(isdigit(cpf[i])){
            soma2 += (cpf[i] - '0') * (11-j);
            j++;}
    }

    resto1 = (soma1 * 10) % 11;
    resto1 = (resto1 == 10) ? 0 : resto1;
    resto2 = (soma2 * 10) % 11;
    resto2 = (resto2 == 10) ? 0 : resto2;

    if(resto1 == (cpf[12] - '0') && resto2 == (cpf[13] - '0')){
        return 1;} 
    else{return 0;}
}

int valida_aluno(){

}

int valida_professor(){

}

int valida_voto(){

}

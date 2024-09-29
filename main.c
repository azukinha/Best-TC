#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define max 50
#define maxNome 60
#define maxSigla 10

void menu1();
void inicia_nova_votacao();
void continua_votacao_gravada();
char valida_opcao();

typedef struct Pessoa Pessoa;
struct Pessoa {
    char nome[maxNome];
    int idade;
};

typedef struct Professor Professor;
struct Professor {
    Pessoa pes;
    int codigo;
    char depto[maxSigla];
};

typedef struct Aluno Aluno;
struct Aluno {
    Pessoa pes;
    int matricula;
    int ano;
    char depto[maxSigla];
};

typedef struct TC TC;
struct {
    int codigo;
    int autor;
    int orientador;
    char titulo[maxNome];
    int qtdeVotos;
};

typedef struct Eleitor Eleitor;
struct Eleitor {
    char cpf[15];
    bool votou;
    int codigoTC;
};

Professor docentes[max];
int qtdeDocentes;

Aluno formandos[max];
int qntdeFormandos;

TC listaTCs[max];
int qtdeTCs;

Eleitor comissao[max];
int qtdeEleitores;

int main(){
    menu1();
    return 0;
}

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

int valida_cpf(){

}

int valida_aluno(){

}

int valida_professor(){

}

int valida_voto(){

}

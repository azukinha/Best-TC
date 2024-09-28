#include <stdio.h>
#include <ctype.h>

void inicia_programa();
void inicia_nova_votacao();
char valida_opcao();

int main(){
    inicia_programa();
    return 0;
}

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

void inicia_programa() {
    printf("--------------------------------------\n");
    printf("a) Iniciar nova votacao \nb) Continuar votacao gravada\n\nDigite sua escolha:  ");
    char opcao = valida_opcao("ab");

    switch (opcao) {
        case 'a':
            inicia_nova_votacao();
            break;
        case 'b':
            // continua_votacao_gravada();
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

int valida_cpf(){

}

int valida_aluno(){

}

int valida_professor(){

}

int valida_voto(){

}

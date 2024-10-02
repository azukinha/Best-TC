#ifndef VOTACAO_H
#define VOTACAO_H

#include <stdbool.h>

#define max 50
#define maxNome 60
#define maxSigla 10

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
struct TC {
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

void menu1();
void inicia_nova_votacao();
void continua_votacao_gravada();
bool valida_cpf(char cpf[]);
char valida_opcao();

#endif
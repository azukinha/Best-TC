#ifndef VOTACAO_H
#define VOTACAO_H

#define max 50
#define maxNome 60
#define maxSigla 10

extern Professor docentes[max];
extern int qtdeDocentes;

Aluno formandos[max];
int qntdeFormandos;

TC listaTCs[max];
int qtdeTCs;

Eleitor comissao[max];
int qtdeEleitores;

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

#endif
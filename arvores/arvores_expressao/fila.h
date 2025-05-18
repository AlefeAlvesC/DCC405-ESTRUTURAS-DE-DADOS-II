//TAD de estrutura Fila
#ifndef FILA_H
#define FILA_H
#include "arvore.h"

//Tipos exportados
typedef struct no{
    ArvNo* info;
    struct no *prox;
} No;

typedef struct fila{
    int tam;
    No *ini;
    No *fim;
} Fila;

//Função para criar uma estrutura fila
Fila *fila_cria();

//Função para inserir um novo elemento no final da fila
void fila_insere(Fila *f, ArvNo* c);

//Função para remover o elemento no inicio da fila
ArvNo* fila_remove(Fila *f);

//Verifica se a fila esta vazia ou não
int fila_vazia(Fila* f);

//Função para liberar a memória alocada a uma estrutura fila
void fila_libera(Fila *f);

#endif
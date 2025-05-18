#ifndef ARVORE_H
#define ARVORE_H

//TAD de estrutura Árvore

//Tipos exportados

typedef struct arvno{
    char info;
    int prioridade;
    int parenteses;
    struct arvno *esq;
    struct arvno *dir;
} ArvNo;

typedef struct arv{
    ArvNo *raiz;
} Arv;

//Função para criar um novo nó dinamicamente
ArvNo* arv_criano(char c, int parentese);

//Função para criar a estrutura Árvore apartir de nó raiz 
Arv* arv_cria (ArvNo* r);

//Função para criar e imprimir uma árvore binária a partir de uma expressão
//A função tem como argumento o cadeia de caracteres referente a expressão 
void arv_expressao(char *str);

/*
//Função para definir um filho a esquerda
void insere_esquerda(ArvNo* pai, char valor);

//Função para definir um filho a direita
void insere_direita(ArvNo* pai, char valor);

//Função para inserir um novo item na árvore de forma ordenada
void insere_ordenado(char valor);
*/

//Função para imprimir a arvore
void arv_imprime (Arv* a);

//Função para imprimir a arvore de forma estilizada
void arv_imprime_estilizado(Arv* a);

//Função para calcular a altura de uma árvore
int arv_altura(Arv* a);

//Função para liberar a memoria alocada a uma arvore
void arv_libera (Arv* a);

#endif
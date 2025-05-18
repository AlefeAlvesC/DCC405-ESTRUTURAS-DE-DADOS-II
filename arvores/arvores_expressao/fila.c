#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "arvore.h"

Fila *fila_cria(){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->tam = 0;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, ArvNo* c){
    No *novo = (No*) malloc(sizeof(No));
    novo->info = c;
    novo->prox = NULL;

    if(f->tam == 0){
        f->ini = novo;
    }else{
        f->fim->prox = novo;
    }

    f->fim = novo;
    f->tam++;
}

ArvNo* fila_remove(Fila* f){
    No *antigo = f->ini;
    ArvNo *c = antigo->info;

    if(f->tam > 0){
        

        f->ini = antigo->prox;
        if(f->ini == NULL)
            f->fim = NULL;
        
        f->tam--;
        free(antigo);
        return c;
    } 
}

int fila_vazia(Fila* f){
    return (f->tam == 0);
}

void fila_libera(Fila* f){
    while(!fila_vazia(f)){
        fila_remove(f);
    }
}
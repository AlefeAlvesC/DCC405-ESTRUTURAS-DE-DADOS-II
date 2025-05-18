#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "arvore.h"
#include "fila.h"

int prioridade(char c){
    switch (c){
        case '-':
            return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


ArvNo* arv_criano(char c, int parentese){  //ArvNo *esq, ArvNo *dir
    ArvNo* p = (ArvNo*) malloc(sizeof(ArvNo));
    p->info = c;
    p->prioridade = prioridade(c);
    p->parenteses = parentese;
    p->esq = NULL;
    p->dir = NULL;
    return p;
}  

Arv* arv_cria (ArvNo* r){
    Arv* a = (Arv*) malloc(sizeof(Arv));
    a->raiz = r;
    return a;
}

void imprime2(ArvNo* r){
    if (r != NULL ){
        printf("Pai: %c ", r->info);
        if(r->esq != NULL)
            printf("Filho 1: %c ", r->esq->info);    
        else
            printf("Filho 1: vazio ");

        if(r->dir != NULL)
            printf("Filho 2: %c ", r->dir->info);    
        else
            printf("Filho 2: vazio ");
        imprime2(r->esq); /* imprime sae */
        imprime2(r->dir); /* imprime sad */
    }
}

void insere_ordenado(Arv *arv, ArvNo *no){
    ArvNo *atual = arv->raiz;
    ArvNo *pai = NULL;
    while(atual != NULL){
        if(atual->parenteses == no->parenteses){
            //Chegou em uma folha da árvore e é um sinal, ou se tem mesma prioridade que o atual.
            if(atual->prioridade == 0 || atual->prioridade == no->prioridade){//&& atual->prioridade < no->prioridade
                no->esq = atual;
                if(arv->raiz == atual)
                    arv->raiz = no;
                else
                    pai->dir = no;
                return;
            //O sinal a ser inserido tem menor prioridade que o anterior
            }else if(no->prioridade != 0 && atual->prioridade > no->prioridade){
                no->esq = atual;
                if(arv->raiz == atual)
                    arv->raiz = no;
                else
                    pai->dir = no;
                return;
            }
            //Encontrou um sinal de mesma prioridade e será colocado logo após esse
            /*
            }else if(atual->prioridade == no->prioridade && atual->dir->prioridade != no->prioridade){
                no->esq = atual->dir;
                atual->dir = no;
                return;
            */
            //O novo sinal a ser inserido tem mais prioridade que o atual
            else if(atual->prioridade < no->prioridade && atual->dir == NULL){
                //no->esq = atual->dir;
                atual->dir = no;
                return;
            //Caso seja uma folha e chegou na última posição da árvore
            }else if(atual->dir == NULL){
                atual->dir = no;
                return;
            }
        
        }else if(atual->parenteses - 1 == no->parenteses){
            no->esq = atual;
            if(arv->raiz == atual)
                arv->raiz = no;
            else
                pai->dir = no;
            return;
        }else if(atual->parenteses + 1 == no->parenteses && atual->dir == NULL){
            atual->dir = no;
            return;
        }
        
        pai = atual;
        atual = atual->dir;
        
    }
    
    return;
}

void arv_expressao(char *str){
    ArvNo *raiz = arv_criano(str[0], 0);
    Arv *arv = NULL;
    int cont_parent = 0;

    for(int i = 0; str[i] != '\0'; i++){
        //printf("%c", str[i]);
        
        
        if(str[i] == ' ')
            continue;
        
        if(str[i] == '('){
            cont_parent++;
            continue;
        } 

        if(str[i] == ')'){
            cont_parent--;
            continue;
        }

        ArvNo *novo = arv_criano(str[i], cont_parent);
        if (arv == NULL)
            arv = arv_cria(novo);
        else
            insere_ordenado(arv, novo);
    }

    arv_imprime_estilizado(arv);
    //printf("\n");
    //imprime2(arv->raiz);
}

// Insere um nó filho esquerdo
/*
void insere_esquerda(ArvNo* pai, char valor) {
    if (pai == NULL) {
        printf("Pai inválido.\n");
        return;
    }
    pai->esq = arv_criano(valor);
}
*/

// Insere um nó filho direito
/*
void insere_direita(ArvNo* pai, char valor) {
    if (pai == NULL) {
        printf("Pai inválido.\n");
        return;
    }
    pai->dir = arv_criano(valor);
}
*/

//Retorna altura da arvore

int max(int alt_sae, int alt_sad){
    return (alt_sae > alt_sad) ? alt_sae : alt_sad;
}

int arv_altura_no(ArvNo* no){
    if(no == NULL)
        return -1;
        
    return 1 + max(arv_altura_no(no->esq), arv_altura_no(no->dir));
}

int arv_altura(Arv* a){
    return arv_altura_no(a->raiz);
}

//Imprime arvore
void imprime (ArvNo* r){
    if (r != NULL ){
        printf("%c ", r->info); /* mostra informação */
        imprime(r->esq); /* imprime sae */
        imprime(r->dir); /* imprime sad */
    }
}



void arv_imprime (Arv* a){
    imprime(a->raiz); /* imprime recursivamente apartir da raiz */
}

//Imprime com formato de arvore
void imprime_estilizado(ArvNo* r){
    if(r == NULL) return;
    
    int h = arv_altura_no(r) + 1;
    int largura = pow(2, h) * 2; // Largura "virtual" da tela

    Fila* fila_atual = fila_cria();
    Fila* fila_proxima = fila_cria();
    fila_insere(fila_atual, r);

    for (int nivel = 0; nivel < h; nivel++) {
        int num_nos = pow(2, nivel);
        int espaco_entre = largura / num_nos;
        int margem = espaco_entre / 2;

        // Imprimir os nós
        for (int i = 0; i < num_nos; i++) {
            ArvNo* no = fila_remove(fila_atual);
            fila_insere(fila_atual, no);

            // Espaço antes do nó
            if (i == 0)
                printf("%*s", margem, "");

            if (no) {
                printf("%c", no->info);
                fila_insere(fila_proxima, no->esq);
                fila_insere(fila_proxima, no->dir);
            } else {
                printf(" ");
                fila_insere(fila_proxima, NULL);
                fila_insere(fila_proxima, NULL);
            }

            // Espaço entre os nós
            printf("%*s", espaco_entre - 1, "");
        }

        printf("\n");

        // Imprimir conectores "/ \"
        
        if (nivel < h - 1) {
            for (int i = 0; i < num_nos; i++) {
                ArvNo* no = fila_atual->ini ? fila_atual->ini->info : NULL;

                if (i == 0)
                    printf("%*s", margem, "");

                if (no) {
                    printf("%s", no->esq ? "/" : " ");
                    printf("%s", no->dir ? "\\" : " ");
                } else {
                    printf("  ");
                }

                printf("%*s", espaco_entre - 2, "");
                fila_remove(fila_atual); // Para manter a ordem
            }
            printf("\n");
        }
        

        // Trocar filas
        Fila* temp = fila_atual;
        fila_atual = fila_proxima;
        fila_proxima = temp;
    }

    fila_libera(fila_atual);
    fila_libera(fila_proxima);
}



void arv_imprime_estilizado(Arv* a){
    imprime_estilizado(a->raiz);
}


//libera arvore
void libera (ArvNo* r){
    if (r != NULL) {
        libera(r->esq); /* libera a sae */
        libera(r->dir); /* libera a sad */
        free(r); /* libera o nó raiz */
    }
}

void arv_libera (Arv* a){
    libera(a->raiz); /* libera hierarquia de nós */
    free(a); /* libera raiz */
}
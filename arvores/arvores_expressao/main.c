#include <stdio.h>
#include "arvore.h"

int main(){

    char expressao[50];
    printf("Digite uma expressão matematica parentelizada:\n");

    scanf("%49[^\n]", expressao);

    arv_expressao(expressao);

    return 0;
}
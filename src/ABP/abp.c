#include "abp.h"
#include "../profiling/profiling.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}


bool isFolha(ABPNo *no) {
    return (isVazia(no->esquerda) 
            && isVazia(no->direita));
}

ABPNo* maiorNo(ABP arvore) {
    if (isVazia(arvore->direita)) 
        return arvore;
    else 
        return maiorNo(arvore->direita);
}

bool isVazia(ABP arvore) {
    INC_COMP;
    return arvore == NULL;
}

void inicializarABP(ABP *arvore) {
    *arvore = NULL;
}

ABP novaArvore(ABPDado key, char *sinonimo) {
    ABP arvore = (ABP) malloc(sizeof(ABPNo));
    arvore->key = key;
    arvore->sinonimo = sinonimo;
    arvore->esquerda = NULL;
    arvore->direita  = NULL;
    return arvore;
}

void inserirABP(ABP *arvore, ABPDado key, char *sinonimo) {
    if(isVazia(*arvore)) {
        *arvore = novaArvore(key, sinonimo);
        return;
    }

    if (strcmp((*arvore)->key, key)>0) {
        INC_COMP;
        inserirABP(&(*arvore)->esquerda, key, sinonimo);
        return;
    }

    inserirABP(&(*arvore)->direita, key, sinonimo);
    return;
}


ABPNo* removerABP(ABP *arvore, ABPDado key) {
    ABP no = consultaABP(*arvore, key);
        INC_COMP;
    if( no == NULL) {
        return NULL; // Item não existe;
    }
        INC_COMP;
    if ( no == *arvore ) {
        *arvore = NULL;
        return no;
    }

    ABP *pai = arvore;
    
    while (((*pai)->esquerda != no) &&((*pai)->direita != no)) {
        INC_COMP;
        if (strcmp((*pai)->key ,key) > 0) {
            pai = &(*pai)->esquerda;
        } else {
            pai = &(*pai)->direita;
        }
    }
    
    INC_COMP;
    if ((*pai)->esquerda == no) {
        return _removerEsq(pai);
    } else {
        return _removerDir(pai);
    }
}


ABPNo* _removerEsq(ABP *arvore) {
    ABP excluido = (*arvore)->esquerda;
    ABP substituto;
    if (isFolha(excluido)) {
        substituto = NULL;
    } else if (isVazia(excluido->esquerda)) {
        substituto = excluido->direita;
    } else if (isVazia(excluido->direita)) {
        substituto = excluido->esquerda;
        return excluido;
    } else {
        substituto = maiorNo(excluido->esquerda);
        removerABP(arvore, substituto->key);
        substituto ->esquerda = excluido->esquerda;
        substituto -> direita = excluido->direita;
    }

    (*arvore)->esquerda = substituto;
    return excluido;
}

ABPNo* _removerDir(ABP *arvore) {
    ABP excluido = (*arvore)->direita;
    ABP substituto;
    if (isFolha(excluido)) {
        substituto = NULL;
    } else if (isVazia(excluido->esquerda)) {
        substituto = excluido->direita;
    } else if (isVazia(excluido->direita)) {
        substituto = excluido->esquerda;
        return excluido;
    } else {
        substituto = maiorNo(excluido->esquerda);
        removerABP(arvore, substituto->key);
        substituto ->esquerda = excluido->esquerda;
        substituto -> direita = excluido->direita;
    }

    (*arvore)->direita = substituto;
    return excluido;
}

ABPNo* consultaABP(ABP arvore, ABPDado key) {
    if (isVazia(arvore)) return NULL;

    INC_COMP;
    if (strcmp(arvore->key, key) == 0) return arvore;

    INC_COMP;
    if (strcmp(arvore->key, key) > 0) return consultaABP(arvore->esquerda, key);

    return consultaABP(arvore->direita, key);
}

int contaNos(ABP arvore) {
    if (isVazia(arvore)) return 0;
    return contaNos(arvore->esquerda) + contaNos(arvore->direita) + 1;
}

void imprime_caminhamento(ABP arvore) {
    if (isVazia(arvore)) return;
    printf("%s (%s)\n", arvore->key, arvore->sinonimo);
    imprime_caminhamento(arvore->esquerda);
    imprime_caminhamento(arvore->direita);
}

void imprime_identado(ABP arvore) {
    imprime_identado_from(arvore, 0);
}

void imprime_identado_from(ABP arvore, int level) {
    if (isVazia(arvore)) return;
    for (int a = 0; a<level; a++) {
        printf("=");
    }
    printf("%s (%s)\n", arvore->key, arvore->sinonimo);
    imprime_identado_from(arvore->esquerda, level+1);
    imprime_identado_from(arvore->direita, level+1);
}

int getAltura(ABP arvore) {
    if (isVazia(arvore)) {
        return 0;
    }
    return max(getAltura(arvore->direita)+1, getAltura(arvore->esquerda)+1);
}

void pretty_print (ABP arvore) {
    partial_pretty_print(arvore, 0);
}

void partial_pretty_print(ABP arvore, int ident) {
    if (isVazia(arvore)) return;

    partial_pretty_print(arvore->esquerda, ident + 1);
    printf("\n");
    for (int i = 0; i < ident; i++) {
        printf("\t");
    }
    printf("%s (%s)\n", arvore->key, arvore->sinonimo);
    partial_pretty_print(arvore->direita, ident + 1);
}

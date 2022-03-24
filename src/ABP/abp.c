#include "abp.h"
#include <stdlib.h>
#include <string.h>


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
        inserirABP(&(*arvore)->esquerda, key, sinonimo);
        return;
    }

    if (strcmp((*arvore)->key, key)<0) {
        inserirABP(&(*arvore)->direita, key, sinonimo);
        return;
    }
    // Não é possivel inserir na arvore dois itens com mesmo valor;
    return;
}


ABPNo* removerABP(ABP *arvore, ABPDado key) {
    ABP no = consultaABP(*arvore, key);
    if( no == NULL) {
        return NULL; // Item não existe;
    }
    if ( no == *arvore ) {
        *arvore = NULL;
        return no;
    }

    ABP *pai = arvore;
    
    while (((*pai)->esquerda != no) &&((*pai)->direita != no)) {
        if (strcmp((*pai)->key ,key) > 0) {
            pai = &(*pai)->esquerda;
        } else {
            pai = &(*pai)->direita;
        }
    }
    
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

ABPNo*  consultaABP(ABP arvore, ABPDado key) {
    if (arvore == NULL) return NULL;
    if (strcmp(arvore->key ,key) == 0) {
        return arvore;
    } else if (consultaABP(arvore->esquerda, key) != NULL) {
        return consultaABP(arvore->esquerda, key);
    } else if (consultaABP(arvore->direita, key) != NULL) {
        return consultaABP(arvore->direita, key);
    } else return NULL;
}

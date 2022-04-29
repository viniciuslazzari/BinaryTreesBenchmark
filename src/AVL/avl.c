#include "avl.h"
#include "../profiling/profiling.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inicializarAVL(AVLNo **no) {
    *no = NULL;
}

bool estaVazia(AVLNo *no) {
    INC_COMP;

    return no == NULL;
}

AVLNo* novoNo(char *key, char *sinonimo) {
    AVLNo *no = (AVLNo*) malloc(sizeof(AVLNo));

    no->key = key;
    no->sinonimo = sinonimo;
    no->noEsquerdo = NULL;
    no->noDireito = NULL;
    no->altura = 0;

    return no;
}

AVLNo* RotacaoSimplesDireita(AVLNo *no){
    AVLNo *noAux;

    noAux = no->noEsquerdo;
    no->noEsquerdo = noAux->noDireito;
    noAux->noDireito = no;
    no->altura = 0;
    no = noAux;

    return no;
}

AVLNo* RotacaoSimplesEsquerda(AVLNo *no){
    AVLNo *noAux;

    noAux = no->noDireito;
    no->noDireito = noAux->noEsquerdo;
    noAux->noEsquerdo = no;
    no->altura = 0;
    no = noAux;

    return no;
}

AVLNo* RotacaoDuplaDireita(AVLNo *no){
    AVLNo *noAuxNivel1, *noAuxNivel2;

    noAuxNivel1 = no->noEsquerdo;
    noAuxNivel2 = noAuxNivel1->noDireito;

    noAuxNivel1->noDireito = noAuxNivel2->noEsquerdo;
    noAuxNivel2->noEsquerdo = noAuxNivel1;
    no->noEsquerdo = noAuxNivel2->noDireito;
    noAuxNivel2->noDireito = no;

    no->altura = noAuxNivel2->altura == 1 ? -1 : 0;
    INC_COMP;

    noAuxNivel1->altura = noAuxNivel2->altura == -1 ? 1 : 0;
    INC_COMP;

    no = noAuxNivel2;

    return no;
}

AVLNo* RotacaoDuplaEsquerda(AVLNo *no){
    AVLNo *noAuxNivel1, *noAuxNivel2;

    noAuxNivel1 = no->noDireito;
    noAuxNivel2 = noAuxNivel1->noEsquerdo;

    noAuxNivel1->noEsquerdo = noAuxNivel2->noDireito;
    noAuxNivel2->noDireito = noAuxNivel1;
    no->noDireito = noAuxNivel2->noEsquerdo;
    noAuxNivel2->noEsquerdo = no;

    no->altura = noAuxNivel2->altura == -1 ? 1 : 0;
    INC_COMP;

    noAuxNivel1->altura = noAuxNivel2->altura == 1 ? -1 : 0;
    INC_COMP;

    no = noAuxNivel2;

    return no;
}

AVLNo* InsereNo(AVLNo *no, char *key, char *sinonimo, bool *ok){
    if (estaVazia(no)) {
        no = novoNo(key, sinonimo);

        *ok = true;

        return no;
    }

    if (strcmp(no->key, key) > 0) {
        INC_COMP;

        no->noEsquerdo = InsereNo(no->noEsquerdo, key, sinonimo, ok);

        if (*ok) {
            INC_COMP;

            switch (no->altura) {
                case -1: no->altura = 0; *ok = false; break;
                case 0: no->altura = 1; break;
                case 1: no = Caso1(no, ok); break;
            }
        }

        return no;
    }

    no->noDireito = InsereNo(no->noDireito, key, sinonimo, ok);

    if (*ok) {
        INC_COMP;

        switch (no->altura) {
            case 1: no->altura = 0; *ok = false; break;
            case 0: no->altura = -1; break;
            case -1: no = Caso2(no, ok); break;
        }
    }

    return no;
}

AVLNo* Caso1(AVLNo *no , bool *ok){
    int alturaNoEsquerdo;

    alturaNoEsquerdo = no->noEsquerdo->altura;

    no = alturaNoEsquerdo == 1 ? RotacaoSimplesDireita(no) : RotacaoDuplaDireita(no);
    INC_COMP;

    no->altura = 0;
    *ok = false;

    return no;
}

AVLNo* Caso2(AVLNo *no , bool *ok){
    int alturaNoDireito;

    alturaNoDireito = no->noDireito->altura;

    no = alturaNoDireito == -1 ? RotacaoSimplesEsquerda(no) : RotacaoDuplaEsquerda(no);
    INC_COMP;

    no->altura = 0;
    *ok = false;

    return no;
}

void imprime_identado(AVLNo *no) {
    imprime_identado_from(no, 0);
}

void imprime_identado_from(AVLNo *no, int level) {
    if (estaVazia(no)) return;

    imprime_identado_from(no->noDireito, level + 1);

    for (int a = 0; a < level; a++) {
        printf("\t");
    }

    printf("%s (%s)\n", no->key, no->sinonimo);

    imprime_identado_from(no->noEsquerdo, level + 1);
}
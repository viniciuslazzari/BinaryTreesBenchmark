/* AVL = Height Balancing Binary Search Tree */

#include <stdbool.h>
#include <stdlib.h>

#ifndef _AVL_H_
#define _AVL_H_

struct S_AVLNo {
    char* key;
    char* sinonimo;
    int altura;
    struct S_AVLNo *noEsquerdo;
    struct S_AVLNo *noDireito;
};

typedef struct S_AVLNo AVLNo;

void inicializarAVL(AVLNo **no);
bool estaVazia(AVLNo *no);
AVLNo* RotacaoSimplesDireita(AVLNo *no);
AVLNo* RotacaoSimplesEsquerda(AVLNo *no);
AVLNo* RotacaoDuplaDireita(AVLNo *no);
AVLNo* RotacaoDuplaEsquerda(AVLNo *no);
AVLNo* InsereNo(AVLNo *no, char *key, char *sinonimo, bool *ok);
AVLNo* Caso1(AVLNo *no , bool *ok);
AVLNo* Caso2(AVLNo *no , bool *ok);
void imprime_identado(AVLNo *no);
void imprime_identado_from(AVLNo *no, int level);

#endif // _AVL_H_
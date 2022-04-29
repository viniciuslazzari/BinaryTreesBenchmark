#include <stdio.h>
#include "main.h"
#include "avl.h"
#include "../profiling/profiling.h"

int main() {

    RESET_COMP;

    AVLNo *tree = (AVLNo*) malloc(sizeof(AVLNo));
    bool *ok = (bool*) malloc(sizeof(bool));

    printf("AVL\n");

    inicializarAVL(&tree);
    
    tree = InsereNo(tree, "teste", "prova", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "certo", "correto", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "pokemon", "digimon", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "vinicius", "lazzari", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "andorinha", "passarinho", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "dado", "sorte", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "123", "456", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    tree = InsereNo(tree, "rato", "rei", ok);
    printf("Insercao - %d comparacoes\n", GET_COMP);

    imprime_identado(tree);
}

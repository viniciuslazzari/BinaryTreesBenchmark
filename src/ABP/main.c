#include <stdio.h>
#include "main.h"
#include "abp.h"
#include "../profiling/profiling.h"
#include "../argParser.h"

int main(int argc, char *argv[]) {
    RESET_COMP;

    ParsedArgs args = parseArgs(argc, argv);
    verificarArquivos(args);

    printf("ABP\n");
    ABP tree;
    inicializarABP(&tree);

    inserirABP(&tree, "constante", "escola");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "indolente", "omisso");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "canhambola", "quilombola");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "constante", "freqüente");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "pretender", "visar");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "calar", "mentir");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "passadio", "vivenda");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "fixar", "mandar");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "bandear-se", "passar-se");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "persigal", "presepe");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "agoirar", "profetizar");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "lembrar-se", "relembrar-se");
    printf("Insercao - %d comparacoes\n", GET_COMP);
    inserirABP(&tree, "aproximar-se", "puxar");
    printf("Insercao - %d comparacoes\n", GET_COMP);

    pretty_print(tree);
    printf("Printing - %d comparacoes\n", GET_COMP);

}

#include <stdio.h>
#include "main.h"
#include "abp.h"


int main() {
    printf("ABP\n");
    ABP tree;
    inicializarABP(&tree);

    inserirABP(&tree, "constante", "escola");
    inserirABP(&tree, "indolente", "omisso");
    inserirABP(&tree, "canhambola", "quilombola");
    inserirABP(&tree, "constante", "freqüente");
    inserirABP(&tree, "pretender", "visar");
    inserirABP(&tree, "calar", "mentir");
    inserirABP(&tree, "passadio", "vivenda");
    inserirABP(&tree, "fixar", "mandar");
    inserirABP(&tree, "bandear-se", "passar-se");
    inserirABP(&tree, "persigal", "presepe");
    inserirABP(&tree, "agoirar", "profetizar");
    inserirABP(&tree, "lembrar-se", "relembrar-se");
    inserirABP(&tree, "aproximar-se", "puxar");

    pretty_print(tree);
}

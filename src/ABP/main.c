#include <stdio.h>
#include "main.h"
#include "abp.h"


int main() {
    printf("ABP\n");
    ABP tree;
    inicializarABP(&tree);

    inserirABP(&tree, "d", "1");
    inserirABP(&tree, "b", "2");
    inserirABP(&tree, "g", "3");
    inserirABP(&tree, "e", "4");

    pretty_print(tree);
}

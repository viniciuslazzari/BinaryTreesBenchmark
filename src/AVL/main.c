#include "main.h"

int main(int argc, char *argv[]) {
    RESET_COMP;

    ParsedArgs args = parseArgs(argc, argv);
    verificarArquivos(args);

    AVLNo *tree = (AVLNo *) malloc(sizeof(AVLNo));

    printf("AVL\n");
    inicializarAVL(&tree);
    lerDicionario(&tree, args);
    imprime_identado(tree);
    printf("Printing - %d comparacoes\n", GET_COMP);

}

void lerDicionario(AVLNo **arvore, ParsedArgs args) {
    int count = 0;
    char bufferWord[WORD_BUFFERS_SIZE];
    char bufferSino[WORD_BUFFERS_SIZE];

    FILE *dicio = openDict(args);

    if (!dicio) {
        printf("Não foi possivel abrir o dicionario;");
        exit(1);
    }

    while (getNextWordDicio(dicio, bufferWord, bufferSino) == DICIO_OK) {
        // Copia a palavra para evitar que todas os itens da arvore tenham um ponteiro para o mesmo texto (aconteceu...)
        char *word = malloc(strlen(bufferWord) + 1);
        char *sino = malloc(strlen(bufferSino) + 1);
        strcpy(word, bufferWord);
        strcpy(sino, bufferSino);
        bool ok = 0;
        // +----
        *arvore = InsereNo(*arvore, word, sino, &ok);

        count++;
        if (count % 250 == 0) {
            printf("Lendo %d palavras do dicionário.\n", count);
        }
    }

    printf("Foram lidas %d palavras do dicionário.\n", count);
    printf("Insercao - %d comparacoes\n", GET_COMP);
    fclose(dicio);
}
#include "main.h"

int main(int argc, char *argv[]) {
    RESET_COMP;

    ParsedArgs args = parseArgs(argc, argv);
    verificarArquivos(args);

    AVLNo *tree = (AVLNo *) malloc(sizeof(AVLNo));

    printf("AVL\n");
    inicializarAVL(&tree);
    lerDicionario(&tree, args);

    printf("\n========= ESTATISTICAS AVL =========\n");
    printf("\nINSERCAO\n\n");

    printf("Comparacoes: %d \n", GET_COMP);
    printf("Rotacoes: %d \n", GET_ROTATIONS);
    printf("Altura: %d \n", retornaAltura(tree));

    RESET_COMP;
    RESET_ROTATIONS;

    substituteWords(&tree, args);

    printf("\nTRADUCAO\n\n");
    printf("Comparacoes: %d \n", GET_COMP);

    printf("\n====================================\n");

    printf("\nArquivo escrito!\n");

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
        if (count % 1000 == 0) {
            printf("Lendo %d palavras do dicionário.\n", count);
        }
    }

    printf("Foram lidas %d palavras do dicionário.\n", count);
    fclose(dicio);
}


void substituteWords(AVLNo **arvore, ParsedArgs args) {
    FILE *input = openInput(args);
    FILE *output = openOutput(args);

    char initial[WORD_BUFFERS_SIZE];
    char *substitute;
    AVLNo *found;
    int status;

    // https://www.wikiwand.com/en/Comma_operator
    while (status = getWordFromInput(input, initial), status == FILE_OK) {
        if (isSeparator(initial[0])) {
            substitute = initial;
        } else if (found = consultaNo(*arvore, initial), found != NULL) {
            substitute = found->sinonimo;
        } else {
            substitute = initial;
        }

        status = addWordOutput(output, substitute);
        if (status != FILE_OK) {
            printf("Erro escrevendo arquivo!\n");
            exit(1);
        }
    }

    if (status != FILE_END) {
        printf("Erro lendo arquivo!\n");
        exit(1);
    }
}
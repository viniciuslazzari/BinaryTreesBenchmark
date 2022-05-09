#include "file.h"

FILE *openDict(ParsedArgs args) {
    return fopen(args.dicionario_path, "r");
}

int getNextWordDicio(FILE *dicio, char *word, char *sinonimo) {
    int stage = 0;
    int pos = 0;
    char ch;
    if (feof(dicio)) {
        return DICIO_END;
    }

    while (!feof(dicio)) {
        ch = fgetc(dicio);
        if (ch == '\t') {
            stage = 1;
            word[pos] = 0;
            pos = 0;
            continue;
        }
        if (ch == '\n' || ch == '\r') {
            break;
        }
        if (stage == 0) {
            word[pos] = ch;
            pos++;
        } else {
            sinonimo[pos] = ch;
            pos++;
        }
    }

    sinonimo[pos] = 0;
    return DICIO_OK;
}
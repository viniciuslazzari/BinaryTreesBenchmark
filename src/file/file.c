#include <stdlib.h>
#include <ctype.h>
#include "file.h"

FILE *openDict(ParsedArgs args) {
    FILE *dict = fopen(args.dicionario_path, "r");
    if (dict == NULL) {
        printf("ERRO: Não foi possível abrir o dicionário.");
        exit(1);
    }
    return dict;
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
        if (ch == '\n') {
            break;
        }
        if (ch == '\r') {
            fgetc(dicio);
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

    if (stage == 0) {
        return DICIO_END;
    }

    sinonimo[pos] = 0;
    return DICIO_OK;
}

FILE *openInput(ParsedArgs args) {
    FILE *pFile = fopen(args.input_path, "r");
    if (pFile == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo de entrada.");
        exit(1);
    }
    return pFile;
}

FILE *openOutput(ParsedArgs args) {
    FILE *pFile = fopen(args.saida_path, "w");
    if (pFile == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo de saída.");
        exit(1);
    }
    return pFile;
}

int isSeparator(char ch) {
    switch (ch) {
        case ' ':
        case ',':
        case '.':
        case ':':
        case ';':
        case '!':
        case '?':
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
        case '\n':
        case '\t':
        case '\r':
            return 1;

        default:
            return 0;
    }
}

int getWordFromInput(FILE *input, char *word) {
    char ch;
    int i = 0;
    if (feof(input)) {
        return FILE_END;
    }

    while (!feof(input)) {
        ch = fgetc(input);
        if (ch == 0) {
            return FILE_ERR;
        }
        if (isSeparator(ch)) {
            if (i == 0) {
                word[0] = ch;
                word[1] = 0;
                return FILE_OK;
            } else {
                // Volta um caractere
                fseek(input, -1, SEEK_CUR);
                word[i] = 0;
                return FILE_OK;
            }
        }
        word[i] = tolower(ch);
        i++;
    }

    word[++i] = 0;
    return FILE_OK;
}

int addWordOutput(FILE *output, char *word) {
    if (output == NULL) {
        return FILE_ERR;
    }

    int status = fputs(word, output);
    if (status == EOF)
        return FILE_ERR;
    return FILE_OK;
}

/*
 * argParser.c
 * Distributed under terms of the MIT license.
 */

#include "argParser.h"
#include <stdio.h>
#include <stdlib.h>

ParsedArgs parseArgs(int argc, char *argv[]) {
    // Os args estão com um a mais pois o nome do arquivo tbm é 
    // considerado um argumento
    if (argc < 4 || argc > 5) {
        printf("Número de argumentos inválido. Use 3 ou 4 argumentos\n "
               "Uso:\n"
               "\t parafraseABP/AVL dict.txt in.txt out.txt [profile.txt]\n");
        exit(1);
        return (ParsedArgs) {
                PARSE_ERROR,
                NULL,
                NULL,
                NULL,
                NULL
        };
    }


    ParsedArgs res = {
            PARSE_SUCCESS,
            argv[1],
            argv[2],
            argv[3],
            argc == 5 ? argv[4] : NULL
    };


    return res;

}

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

void verificarArquivos(ParsedArgs arquivos) {
    if (!file_exists(arquivos.dicionario_path)) {
        printf("O dicionario \"%s\" não existe.\n", arquivos.dicionario_path);
        exit(2);
    }
    if (!file_exists(arquivos.input_path)) {
        printf("O arquivo de entrada \"%s\" não existe.\n", arquivos.input_path);
        exit(2);
    }

    // TODO: Verificar se o arquivo out pode ser escrito

}

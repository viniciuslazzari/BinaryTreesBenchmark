/*
 * argParser.h
 * Distributed under terms of the MIT license.
 */

#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#define PARSE_SUCCESS 1
#define PARSE_ERROR   2
#define PARSE_NO_ARGS 3

struct SParsedArgs {
    int parse_status;
    char *dicionario_path;
    char *input_path;
    char *saida_path;
    char *profiling_path;
};

typedef struct SParsedArgs ParsedArgs;

/* Recebe os argumentos de um programa e retorna eles organizado em 
 * um struct. Sai do programa com erro caso não consiga. */
ParsedArgs parseArgs(int argc, char *argv[]);

/* Recebe os nomes dos arquivos, e verifica se eles existem e podem
 * ser acessados. Sai do programa com erro caso não*/
void verificarArquivos(ParsedArgs arquivos);

#endif // _ARGPARSER_H_

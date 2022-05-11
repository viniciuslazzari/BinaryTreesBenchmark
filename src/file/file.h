#include <stdio.h>
#include "../argParser.h"

#define WORD_BUFFERS_SIZE 300

#define DICIO_END 3
#define DICIO_OK 2
#define DICIO_ERROR_R 1

#define FILE_END 1
#define FILE_OK 0
#define FILE_ERR 3


FILE *openDict(ParsedArgs args);

FILE *openInput(ParsedArgs args);

FILE *openOutput(ParsedArgs args);

int getNextWordDicio(FILE *dicio, char *word, char *sinonimo);

int getWordFromInput(FILE *input, char *word);

int isSeparator(char ch);

int addWordOutput(FILE *output, char *word);
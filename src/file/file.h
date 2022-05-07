#include <stdio.h>
#include "../argParser.h"

#define WORD_BUFFERS_SIZE 300

#define DICIO_END 3
#define DICIO_OK 2
#define DICIO_ERROR_R 1

FILE *openDict(ParsedArgs args);

int getNextWordDicio(FILE *dicio, char *word, char *sinonimo);
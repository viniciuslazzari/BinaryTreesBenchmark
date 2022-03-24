/* ABP = Arvore Binaria de Pesquisa */

#include <stdbool.h>
#include <stdlib.h>


#ifndef _ABP_H_
#define _ABP_H_


typedef char* ABPDado;

struct S_ABPNo {
    ABPDado key;
    char*   sinonimo;
    struct S_ABPNo *esquerda, *direita;
};
typedef struct S_ABPNo ABPNo;
typedef ABPNo *ABP;

/* Retorna nó com valor igual a key*/
ABPNo*  consultaABP(ABP arvore, ABPDado key);

/* Inicializa a arvore vazia */
void    inicializarABP(ABP *arvore);

/* Insere novo nodo na ABP */
void    inserirABP(ABP *arvore, ABPDado key, char* res);

/* Remove nodo da ABP */
ABPNo*  removerABP(ABP *arvore, ABPDado key);

/* Verifica se o nodo passado é uma folha da arvore */
bool    isFolha(ABPNo *a);

/* Encontra o maior nodo de uma ABP */
ABPNo*  maiorNo(ABP arvore);

/* Verifica se a ABP está vazia */
bool    isVazia(ABP arvore);

/* Retorna um ptr para uma nova ABP */
ABP     novaArvore(ABPDado key, char *sinonimo);

ABPNo* _removerEsq(ABP *arvore);
ABPNo* _removerDir(ABP *arvore);



#endif // _ABP_H_

#ifndef _LISTA_H_
#define _LISTA_H_

//Nó de uma lista ligada
struct lista_lig_noh{
    int valor;
    struct lista_lig_noh *anterior, *proximo;
};

//Estrutura de uma lista ligada
struct lista_lig{
    struct lista_lig_noh *primeiro;
    struct lista_lig_noh *ultimo;
    unsigned int tamanho;
};

//Gera uma lista ligada
struct lista_lig *ll_gera();

//Destrói a lista e os nós
void ll_destroi(struct lista_lig *lista, struct lista_lig_noh *lista_noh);

//Insere no início
void ll_add_inicio(struct lista_lig *lista, int numero);

//Insere no fim
void ll_add_fim(struct lista_lig *lista, int numero);

//Inserir um número em um determinado índice da lista
void ll_add_ind(struct lista_lig *lista, int numero, int indice);

//Busca por elemento em um determinado índice
int ll_busca_ind(struct lista_lig *lista, int indice);

//Busca por elemento na lista
int ll_busca_num(struct lista_lig *lista, int numero);

//Remove do início
int ll_remove_inicio(struct lista_lig *lista);

//Remove do fim
int ll_remove_fim(struct lista_lig *lista);

//Tamanho da lista
unsigned int ll_tamanho(struct lista_lig *lista);

//Imprime a lista
void ll_imprime(struct lista_lig *lista);

#endif
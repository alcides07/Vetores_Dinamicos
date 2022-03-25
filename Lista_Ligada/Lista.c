#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista_lig *ll_gera(){
    struct lista_lig *lista = (struct lista_lig*)malloc(sizeof(struct lista_lig));
    lista -> primeiro = 0;
    lista -> ultimo = 0;
    lista -> tamanho = 0;
    return lista;
}

void ll_destroi(struct lista_lig *lista, struct lista_lig_noh *lista_noh){
    free(lista -> primeiro);
    free(lista -> ultimo);
    free(lista);
    free(lista_noh -> anterior);
    free(lista_noh -> proximo);
    free(lista_noh);
}

void ll_add_inicio(struct lista_lig *lista, int numero){
    struct lista_lig_noh *novo_noh = (struct lista_lig_noh*) malloc(sizeof(struct lista_lig_noh));
    novo_noh -> valor = numero;
    novo_noh -> proximo = lista -> primeiro;
    novo_noh -> anterior = 0;
    lista -> primeiro = novo_noh;

    if (lista -> tamanho == 0){ //Se o tamanho da lista é zero.
        lista -> ultimo = novo_noh; //O último também é esse que acabei de criar;
    }

    else{
        novo_noh -> proximo -> anterior = novo_noh; //O anterior ao segundo elemento é esse que eu acabei de criar.
    }
    lista -> tamanho++;
}

void ll_add_fim(struct lista_lig *lista, int numero){
    struct lista_lig_noh *novo_noh = (struct lista_lig_noh*) malloc(sizeof(struct lista_lig_noh));
    novo_noh -> valor = numero;
    novo_noh -> anterior = lista -> ultimo;
    novo_noh -> proximo = 0;
    lista -> ultimo = novo_noh; //O último elemento é o novo nó.

    if (lista -> tamanho == 0){ //Se a lista está vazia.
        lista -> primeiro = novo_noh; //O primeiro recebe o novo nó criado.
    }

    else{ //Se a lista não está vazia.
        novo_noh -> anterior -> proximo = novo_noh; //O próximo ao penúltimo elemento é esse que eu acabei de criar.
    }
    lista -> tamanho++;
}

//Inserir um número em um determinado índice da lista
void ll_add_ind(struct lista_lig *lista, int numero, int indice){
    if (indice >= 0 && indice < lista -> tamanho){ 
        struct lista_lig_noh *novo_noh = (struct lista_lig_noh*) malloc(sizeof(struct lista_lig_noh)); //Cria um novo nó
        struct lista_lig_noh *atual = lista -> primeiro; //Nó que representa o primeiro elemento
        for (int i = 0; i < indice; i++){
            atual = atual -> proximo; //Indo até onde quero inserir
        }   
        novo_noh -> valor = numero; //Atribuo o valor ao novo nó.
        if (indice != 0){ //Se quero inserir em qualquer posição sem ser a primeira.
            atual -> anterior -> proximo = novo_noh; //O próximo ao anterior onde quero inserir, aponta para o novo nó.
            novo_noh -> anterior = atual -> anterior; //O anterior ao novo nó é o anterior de onde eu quero inserir.
        }

        else{ //Se quero inserir na primeira posição
            lista -> primeiro = novo_noh; //O primeiro agora é o novo nó criado.
            novo_noh -> anterior = 0; //Se o índice de inserção é zero, o novo nó não possuirá anterior.
        }
        
        novo_noh -> proximo = atual; //O próximo ao novo nó será o número que estava onde eu quero inserir.
        atual -> anterior = novo_noh; //O anterior de onde eu quero inserir é o novo nó.
        lista -> tamanho++; //Tamanho da lista incrementado.
    }       
}

int ll_remove_inicio(struct lista_lig *lista){
    //Se a lista é vazia.
    if (lista -> primeiro == 0){ 
        return -1; //Retorna -1.
    }

    //Se a lista possui apenas um elemento.
    else if (lista -> tamanho == 1){ 
        int resposta = lista -> primeiro -> valor; //Armazeno o valor do primeiro elemento para retornar.
        struct lista_lig_noh *antigo_noh = lista -> primeiro; //Crio um ponteiro que aponta para o primeiro elemento.
        free(antigo_noh); //Libero a memória do primeiro elemento.
        lista -> primeiro = 0; //O primeiro aponta para nulo.
        lista -> ultimo = 0; //O último aponta para nulo.
        lista -> tamanho = 0; //O tamanho da lista agora é zero.
        return resposta; //Retorno do elemento removido.
    }

    //Se a lista tem mais de 1 elemento.
    int resposta = lista -> primeiro -> valor; //Armazeno o valor do primeiro elemento para retornar.
    struct lista_lig_noh *antigo_noh = lista -> primeiro; //Crio um ponteiro que aponta para o primeiro elemento.
    lista -> primeiro = lista -> primeiro -> proximo; //O novo primeiro agora é o próximo ao antigo primeiro.
    free(antigo_noh); //Libero a memória do primeiro elemento.
    lista -> tamanho--; //Diminui o tamanho da lista.
    return resposta; //Retorno do elemento removido.
}

int ll_remove_fim(struct lista_lig *lista){
    //Se a lista é vazia.
    if (lista -> tamanho == 0){ 
        return -1; //Retorna -1.
    }

    //Se a lista possui apenas um elemento.
    else if (lista -> tamanho == 1){ 
        int resposta = lista -> primeiro -> valor; //Armazeno o valor do único elemento para retornar.
        struct lista_lig_noh *antigo_noh = lista -> primeiro; //Crio um ponteiro que aponta para o único elemento.
        free(antigo_noh); //Libero a memória do único elemento.
        lista -> primeiro = 0; //O primeiro aponta para nulo.
        lista -> ultimo = 0; //O último aponta para nulo.
        lista -> tamanho = 0; //O tamanho da lista agora é zero.
        return resposta; //Retorno do elemento removido.
    }

    //Se a lista tem mais de 1 elemento.
    int resposta = lista -> ultimo -> valor; //Armazeno o valor do último elemento para retornar.
    lista -> ultimo -> anterior -> proximo = 0;       
    free(lista -> ultimo);
    lista -> ultimo = lista -> ultimo -> anterior;
    lista -> tamanho--; //Diminui o tamanho da lista.
    return resposta;
}

int ll_remove_ind(struct lista_lig *lista, int indice){
    int resposta = -1;
    if (lista -> tamanho == 0){
        return resposta;
    }

    if (indice >= 0 && indice < lista -> tamanho){
        struct lista_lig_noh *atual = lista -> primeiro; //Nó que representa o primeiro elemento
        for (int i = 0; i < indice; i++){
            atual = atual -> proximo;
        }
        resposta = atual -> valor; //Armazeno o valor do elemento a remover.

        if (lista -> tamanho == 1){
            free(atual);
            lista -> primeiro = 0;
            lista -> ultimo = 0;
        }

        else{
            if (indice == 0){ //Se quero remover o primeiro elemento
                lista -> primeiro = atual -> proximo; //O primeiro da lista passa a ser o segundo elemento.
                atual -> proximo -> anterior = 0; //O novo primeiro elemento não possui anterior.
                free(atual); //Libero a memória do elemento removido.
            }
            else if (indice == lista -> tamanho - 1){ //Se quero remover o último elemento
                atual -> anterior -> proximo = 0;
                lista -> ultimo = 0;
                free(atual);
            }
            else{
                atual -> anterior -> proximo = atual -> proximo;
                atual -> proximo -> anterior = atual -> anterior;
                free(atual);
            }
        }
        lista -> tamanho--;
    }
    return resposta;
}

unsigned int ll_tamanho(struct lista_lig *lista){
    return lista -> tamanho;
}

//Busca por elemento em um determinado índice
int ll_busca_ind(struct lista_lig *lista, int indice){
    if (indice >= 0 && indice < lista -> tamanho){ //Se é um índice válido.
        struct lista_lig_noh *atual = lista -> primeiro; //Crio um nó que começa no primeiro elemento.
        for (int i = 0; i < indice; i++){ //Percorro até o índice que quero.
            atual = atual -> proximo; //Avanço na lista.
        }
        return atual -> valor; //Retorno o valor no índice informado.
    }   
}

//Busca por elemento na lista
int ll_busca_num(struct lista_lig *lista, int numero){
    struct lista_lig_noh *atual = lista -> primeiro; //Crio um nó que começa no primeiro elemento.
    int resposta = -1;
    for (int i = 0; i < lista -> tamanho; i++){
        if (atual -> valor == numero){
            resposta = i;
            break;
        }
        atual = atual -> proximo;
    }
    return resposta;
}

void ll_imprime(struct lista_lig *lista){
    printf("[%d] Lista: ", lista -> tamanho);
    struct lista_lig_noh *atual = lista -> primeiro;
    while (atual != 0){
        printf("%d -> ", atual -> valor);
        atual = atual -> proximo;
    }
    printf("NULO\n");
}
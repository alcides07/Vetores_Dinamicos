#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
    struct lista_lig *lista = ll_gera();
    struct lista_lig_noh *lista_noh;
    ll_imprime(lista);

    printf("adição de  elementos ao final:\n");
    for (int i = 1; i < 1; i++){
        ll_add_fim(lista, i * 100);
    }
    ll_imprime(lista);

    printf("%d\n", ll_remove_fim(lista));
    ll_imprime(lista);
    printf(ll_tamanho(lista));

    //printf("Removi o elemento: %d\n", ll_remove_ind(lista, 18));
    //ll_imprime(lista);

    return 0;
}
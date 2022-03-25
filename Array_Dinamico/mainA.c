#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Vetor.h"

void imprime(lista *array, int *erro){
    for (int i = 0; i < lista_tamanho(array); i++){
        printf("%d ", lista_busca_ind(array, i, erro));
    }
    printf("[Tamanho: %d -> Capacidade: %d]\n", lista_tamanho(array), lista_capacidade(array));
}

int main(){
    clock_t inicio, fim;
    double tempo;
    int erro;

    int qtd_tot = 25000; //1600000
    //int qtd_sort = 23000; //800000
    
    lista *array_total = lista_gera(); //Gerando um array dinâmico total
    for (int i = 0; i < qtd_tot + 1; i++){
        lista_add_fim(array_total, i, &erro);
    }
    /*
    printf("\n");
    printf("Array total:     ");
    imprime(array_total, &erro);

    lista_remove_ind(array_total, 9, &erro);
    imprime(array_total, &erro);

    //

    lista *arrayAleatorios = lista_gera(); //Gerando um array dinâmico aleatório
    srand(time(NULL));
    for (int i = 0; i < qtd_sort + 1; i++){
        int numero_sorteado = rand() % qtd_tot + 1;
        lista_add_fim(arrayAleatorios, numero_sorteado, &erro); //Preenchendo um array com números aleatórios
    }
    /*
    printf("Array Aleatório: ");
    printf("ARRAY NOVO COM %d NÚMEROS ALETÓRIOS DE 1 A %d:\n", qtd_sort, qtd_tot);
    imprime(arrayAleatorios, &erro);
   
    printf("\n");
    printf("Array pós remoção aleatória:\n");
    
    inicio = clock();
    for (int i = 0; i < qtd_sort; i++){
        lista_remove_num(array_total, arrayAleatorios -> dados[i], &erro);
        //imprime(array_total, &erro);
    }
    fim = clock();
     */

    inicio = clock();
    for (int i = 0; i < qtd_tot / 2 + 1; i++){
        //printf("Removendo elemento %d da posição %d\n", array_total -> dados[i], i);
        lista_remove_ind(array_total, i, &erro);
        //imprime(array_total, &erro);
        //printf("\n");
    }
    fim = clock();
    //imprime(array_total, &erro);

    tempo = (fim - inicio)/(CLOCKS_PER_SEC/1.0);
    printf("Tempo decorrido para remoção de números aleatórios: %.3lfs\n", tempo);
    printf("Foram removidos %d elementos\n", qtd_tot - array_total -> tamanho);

    /*
    printf("\n");
    printf("[PERCENTUAL] preenchido do total (%u - %u): (%.2lf%%) - \n", lista_tamanho(array), lista_capacidade(array), lista_ocupacao(array));
    tempo = (fim - inicio)/(CLOCKS_PER_SEC/1.0);
    printf("Tempo decorrido: %.3lfs\n", tempo);
    */

    return 0;
}
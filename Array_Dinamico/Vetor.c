#include <stdlib.h>
#include "Vetor.h"

typedef struct array_din lista;

// Gera um array dinâmico.
lista *lista_gera(){
    lista *array = (lista*) malloc(sizeof(lista));     //Aloca o espaço necessário para uma estrutura lista.
    //array -> dados = (int*) malloc(sizeof(int) * 10);  //Aloca o espaço necessário inicialmente para um vetor de X números inteiros.
    //array -> dados = (int*) malloc(sizeof(int) * 10000);
    array -> dados = (int*) malloc(sizeof(int) * 2);
    array -> tamanho = 0;                              //Define o tamanho ocupado igual a zero.
    //array -> capacidade = 10;                          //Define a capacidade inicial igual a X.
    //array -> capacidade = 10000;
    array -> capacidade = 2;
    return array;                                      //Retorna o ponteiro para a estrutura.
}

// Destrói um array dinâmico liberando sua memória utilizada.
void lista_destroi(lista *array){
    free(array -> dados);                              //Libera os locais ocupados pelos dados do vetor.
    free(array);                                       //Libera o local ocupado pela estrutura.
}

// Adiciona um elemento ao final do array.
void lista_add_fim(lista *array, int valor, int *erro){
    *erro = 1;                                                              //Inicialmente guarda o estado de se ter um erro ao inserir o elemento.
    if (array -> tamanho == array -> capacidade){                           //Se o tamanho se tornou igual a capacidade máxima, o array precisa expandir.
        //array -> capacidade = array -> capacidade + 10;                     //A nova capacidade do array suporta X unidades a mais que a anterior.
        //array -> capacidade = array -> capacidade + 10000;
        array -> capacidade = array -> capacidade * 2;
        int *novo_arr = (int*) malloc(sizeof(int) * (array -> capacidade)); //Cria um novo ponteiro apontando para uma nova área com o tamanho da nova capacidade.
        int *antigo_arr = array -> dados;                                   //Um novo ponteiro aponta para os dados do array antigo para facilitar a liberação dele posteriormente.
        for (int i = 0; i < array -> tamanho; i++){ 
            *(novo_arr + i) = *(antigo_arr + i);                            //Realiza uma copia do array antigo para o novo.
        }
        array -> dados = novo_arr;                                          //Ponteiro dos dados do array aponta para o início do novo array.
        free(antigo_arr);                                                   //Libera o espaço que o array antigo ocupava.
    }

    array -> dados[array -> tamanho++] = valor;                             //Insere o valor recebido ao final da lista.
    *erro = 0;                                                              //Se o elemento foi inserido com êxito, não ocorreu erro.
}

// Adiciona um elemento em índice específico.
void lista_add_ind(lista *array, int valor, int indice, int *erro){
    *erro = 1;                                                             
    if (array -> tamanho == array -> capacidade){   //Utiliza-se as mesmas ideias de expansão do array explicadas na função acima.
        //array -> capacidade = array -> capacidade + 10;
        //array -> capacidade = array -> capacidade + 10000;
        //array -> capacidade = array -> capacidade * 2;
        int *novo_arr = (int*) malloc(sizeof(int) * (array -> capacidade)); 
        int *antigo_arr = array -> dados; 
        for (int i = 0; i < array -> tamanho; i++){
            *(novo_arr + i) = *(antigo_arr + i); 
        }
        array -> dados = novo_arr; 
        free(antigo_arr); 
    }

    for (int i = array -> tamanho; i > indice; i--){ //Percorre o vetor da direita para a esquerda, indo até o índice que se deseja acrescentar um elemento.
        array -> dados[i] = array -> dados [i - 1];  //Desloca os elementos do intervalo mencionado para a direita.
    }

    if (indice >= 0 && indice <= array -> tamanho){
        *erro = 0;
        (array -> tamanho)++;            //Aumenta o tamanho ocupado pelo vetor.          
        array -> dados[indice] = valor;  //Insere o elemento recebido por parâmetro no índice recebido, visto que agora pode-se considerar aquele local "livre".
    }
}

// Remove um valor de um determinado índice do vetor.
void lista_remove_ind(lista *array, int indice, int *erro){ 
    *erro = 1;
    if (indice >= 0 && indice < array -> tamanho){            //Verifica se o índice recebido é válido para o vetor em questão.
        *erro = 0;
        for (int i = indice + 1; i < array -> tamanho; i++){  //Percorre o vetor a partir da posição a direita do índice recebido até o final do vetor.
            array -> dados [i - 1] = array -> dados [i];      //Desloca os valores da direita para a esquerda, preenchendo o índice desejado para excluir com outro valor.
        }
        (array -> tamanho)--;                                 //O tamanho ocupado pelo array diminui.
    }
}

void lista_remove_num(lista *array, int numero, int *erro){      
        *erro = 1;
        int indice = -1;
        for (int i = 0; i < array -> tamanho; i++){  
            if (array -> dados[i] == numero){
                *erro = 0;
                indice = i;
                break;
            }
        }
        if (indice != -1){
            for (int i = indice + 1; i < array -> tamanho; i++){  
                array -> dados [i - 1] = array -> dados [i];      
            }
            (array -> tamanho)--;     
        }                            
}

// Remove um elemento do final da lista.
void lista_remove_fim(lista *array, int *erro){
    *erro = 1;
    if (array -> tamanho >= 1){ //Se o array possui ao menos um elemento, é possível excluir o último.
        *erro = 0;
        (array -> tamanho)--;   //Diminuição do tamanho ocupado pelo array.
    }
}

// Busca o valor presente em um determinado índice do array.
int lista_busca_ind(lista *array, int indice, int *erro){
    *erro = 1;                                      //Guarda o estado de erro p/ a situação em que a função não receba um índice válido.
    if (indice >= 0 && indice < array -> tamanho){  //Verifica se o índice recebido é válido para o vetor em questão.
        *erro = 0;
        return array -> dados[indice]; //Retorna o elemento encontrado.
    }
}

// Busca e verifica se um valor recebido por parâmetro existe no vetor.
int lista_busca_num(lista *array, int numero, int *erro){
    *erro = 1;
    int indice = -1;                            //Guarda o estado -1 para retornar se for o caso da função não encontrar o elemento que se procura.
    for (int i = 0; i < array -> tamanho; i++){ //Percorre o array do início ao fim.
        if (array -> dados[i] == numero){       //Se o elemento percorrido no momento é igual ao valor procurado.
            *erro = 0;
            indice = i;                         //Guarda o índice onde se encontrou o valor procurado.
            break;                              //Interrompe as demais verificações.
        }
    }
    return indice;                              //Retorna o índice em se encontra o valor procurado.
}

// Função para retornar o tamanho de um array.
unsigned int lista_tamanho(lista *array){
    return array -> tamanho;   //Retorna o tamanho de um array.
}

// Função para retornar a capacidade máxima de um array.
unsigned int lista_capacidade(lista *array){
    return array -> capacidade; //Retorna a capacidade de um array.
}

// Função para retornar o percentual efetivamente ocupado pelo array considerando sua capacidade total.
double lista_ocupacao(lista *array){
    return ((array -> tamanho * 100.0) / (array -> capacidade)) / 100.0; //Retorna o percentual ocupado pelo array em uma escala de 0.0 a 1.0.
}
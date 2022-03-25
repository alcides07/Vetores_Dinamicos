#ifndef _VETOR_H_
#define _VETOR_H_

struct array_din{
    int *dados;
    unsigned int tamanho, capacidade;
    /*
    Define a estrutura que qualquer array dinâmico gerado vai possuir.
    */
};

typedef struct array_din lista;

lista *lista_gera();
    /*
    Gera uma estrutura contendo uma estrutura que possui um array dinâmico e suas informações.
    */

void lista_destroi(lista *array);
    /*
    Libera da memória um espaço ocupado por uma estrutura que contém um array dinâmico e seus dados.
    */

void lista_add_fim(lista *array, int valor, int *erro);
    /*
    Insere um valor recebido como parâmetro ao final do array, aumentando o tamanho real 
    ocupado por elementos no array e aumentando sua capacidade caso seja necessário expandí-la.

    Notação O: O(n) -> Visto que no pior caso é feita uma transferência de elementos do vetor antigo para um novo vetor expandido.
    */

void lista_add_ind(lista *array, int valor, int indice, int *erro);
    /*
    Insere um valor recebido por parâmetro em um índice também recebido por parâmetro.
    Desloca para a direita todo o vetor a partir do índice inserido.

    Notação O: O(n) -> Visto que no pior caso é feita uma transferência de elementos do vetor antigo para um novo vetor expandido, 
    além do deslocamento dos elementos já existentes para abrir vaga para inserir o novo elemento.
    */

void lista_remove_ind(lista *array, int indice, int *erro);
    /*
    Remove do array um elemento presente em um índice recebido por parâmetro.
    Desloca para a esquerda todo o vetor a partir do índice recebido + 1.

    Notação O: O(n) -> Visto que é feito um deslocamento de alguns elementos para preencher o espaço do elemento a ser retirado.
    */

void lista_remove_num(lista *array, int numero, int *erro);


void lista_remove_fim(lista *array, int *erro);
    /*
    Remove o último elemento a direita do array caso se tenha um array maior ou igual a 1 elemento.

    Notação O: O(1) -> Visto que apenas é decrementado em um o tamanho efetivo ocupado pelo array.
    */

int lista_busca_ind(lista *array, int indice, int *erro);
    /*
    Busca e retorna um elemento presente em um índice recebido por parâmetro.
    Se o índice passado não for válido, retorna -1.

    Notação O: O(1) -> Visto que já se sabe em qual índice se deseja procurar o elemento contido.
    */

int lista_busca_num(lista *array, int numero, int *erro);
    /*
    Percorre o vetor a procura de um elemento que foi passado como parâmetro.
    Se o elemento existe no vetor, retorna-se o índice em que ele se encontra.
    Caso contário, retorna-se -1.

    Notação O: O(n) -> Visto que no pior caso pode-se percorrer todo o array a procura do número recebido por parâmetro.
    */

unsigned int lista_tamanho(lista *array);
    /*
    Retorna a quantidade de elementos existentes no array.

    Notação O: O(1) -> Visto que independente do tamanho do array, o tempo da função é sempre o mesmo.
    */

unsigned int lista_capacidade(lista *array);
    /*
    Retorna a capacidade total de elementos que o array suporta.

    Notação O: O(1) -> Visto que independente da capacidade do array, o tempo da função é sempre o mesmo.
    */

double lista_ocupacao(lista *array);
    /*
    Dentre a capacidade total de elementos suportada pelo array, retorna o percentual realmente preenchido.

    Notação O: O(1) -> Visto que independente do tamanho, da capacidade e da ocupação do array, o tempo da função é sempre o mesmo.
    */

#endif
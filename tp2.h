#ifndef TP2_H
#define TP2_H
#define TAM_MAX 100
#define TAM_HASH 31

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Implementação da Patricia
typedef struct NoPatricia {
    int bit;
    char chave[TAM_MAX];
    struct NoPatricia *esq, *dir;//esq = esquerda, dir = direita
} NoPatricia;

//Fu9nções da arvore Patricía
NoPatricia* inserir_patricia(NoPatricia *raiz, char *chave);
int pesquisar_Patricia(NoPatricia *raiz, char *chave);
void imprimir_pre_ordem(NoPatricia *raiz);

//TAD Hash table com duplo hash

//Funções da hash table
void inicializar_tabela();
void inserir_hash(char *chave);
int pesquisar_hash(char *chave);
void imprimir_hash();
#endif
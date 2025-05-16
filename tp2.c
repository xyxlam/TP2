#include "tp2.h"

int bit(char *chave, int i) {
    int byte = i / 8;
    int bit = 7 - (i % 8);
    return (chave[byte] >> bit) & 1;
}

NoPatricia *novoNo(char *chave, int bit){
    NoPatricia *no = (NoPatricia* ) malloc(sizeof(NoPatricia));
    strcpy(no->chave, chave);
    no->bit = bit;
    no->esq = no->dir = NULL;
    return no;
}

NoPatricia *inserir_patricia(NoPatricia *raiz, char *chave) {
    if (raiz == NULL) return novoNo(chave, -1);

    NoPatricia *p = raiz, *q = NULL;
    while (p->bit >= 0 && bit(chave, p->bit) == bit(p->chave, p->bit)) {
        q = p;
        p = bit(chave, p->bit) ? p->dir : p->esq;
    }
    
    int i;
    for(i = 0; i< strlen(chave) * 8; i++) {
        if (bit(chave, i) != bit(p->chave,i)) break;
    }

    NoPatricia *novo = novoNo(chave, i);
    if (bit(chave, i)) {
        novo->esq = p;
        novo->dir = novo;
    } else {
        novo->esq = novo;
        novo->dir = p;
    }

    if (q == NULL) return novo;

    if (bit(chave, q->bit))
        q->dir = novo;
    else
        q->esq = novo;
    return raiz;
}

int pesquisar_Patricia(NoPatricia *raiz, char *chave) {
    if (raiz == NULL) return 0;
    NoPatricia *p = raiz;
    while (p->bit >= 0) {
        p = bit(chave, p->bit) ? p->dir : p->esq;
    }
    return strcmp(p->chave, chave) == 0;
}

void imprimir_pre_ordem(NoPatricia *raiz) {
    if (raiz == NULL) return;
    printf("Chave: %s | Bit: %d\n", raiz->chave, raiz->bit);
    if(raiz->bit >= 0) {
        imprimir_pre_ordem(raiz->esq);
        imprimir_pre_ordem(raiz->dir);
    }
}

//Implementação da Hash Table
char* tabela[TAM_HASH];

void inicializar_tabela() {
    for (int i = 0; i <  TAM_HASH; i++) {
        tabela[i] = NULL;
    }
}

int hash1(char *chave) {
    int soma = 0;
    for (int i = 0; chave[i]; i++)
        soma += chave[i];
    return soma % TAM_HASH;
}

int hash2(char *chave) {
    int soma = 0;
    for (int  i = 0; chave[i]; i++)
        soma += chave[i];
    return 1 + (soma % (TAM_HASH - 1));
}

void inserir_hash(char *chave) {
    int h1 = hash1(chave);
    int h2 = hash2(chave);

    for (int i = 0; i < TAM_HASH; i++) {
        int pos = (h1 + i * h2) % TAM_HASH;
        if (tabela[pos] == NULL) {
            tabela[pos] = strdup(chave);
            return;
        }
    }
    printf("Tabela cheia. Não foi possível inserir.\n");
}

int pesquisar_hash(char *chave) {
    int h1 = hash1(chave);
    int h2 = hash2(chave);

    for (int i = 0; i < TAM_HASH; i++) {
        int pos = (h1 + i * h2 ) % TAM_HASH;
        if(tabela[pos] == NULL) return 0;
        if (strcmp(tabela[pos], chave) == 0) return 1;
    }
    return 0;
}

void imprimir_hash() {
    for(int i = 0; i < TAM_HASH; i++) {
        if (tabela[i] != NULL)
            printf("Posição %d: %s\n", i, tabela[i]);
    }
}
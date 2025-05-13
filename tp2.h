#ifndef TP2_H
#define TP2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// PATRICIA Tree Node Structure
typedef struct NoPatricia {
    char* key;
    int bitIndex;
    struct NoPatricia* left;
    struct NoPatricia* right;
} NoPatricia;
//Hash Table structure
typedef struct {
    char** keys;
    int size;
    int count;
} HashTable;

// PATRICIA Tree Functions
NoPatricia* createNoPatricia(const char* key, int bitIndex); //Está a dar erro de incompatilbilidade com a função NoPatricia* createNoPatricia(const char* key, int bitIndex);
void insertPatricia(NoPatricia** root, const char* key);
void removePatricia(NoPatricia** root, const char* key);
void printPreOrderPatricia(NoPatricia* root);
bool searchPatricia(NoPatricia* root, const char* key);
void freePatriciaTree(NoPatricia* root);


//Hash Table Functions
HashTable* createNoPatricia(int size); //Está a dar erro de incompatiibilidade com a função HashTable* createNoPatricia(int size);
void insertHash(HashTable* ht, const char* key);
void printHashTable(HashTable* ht);
bool searchHas(HashTable* ht, const char* key);
void freeHashTable(HashTable* ht);


// Helper Functions
int getBit(const char* key, int bitIndex);
int firstDifferentBit(const char* key1, const char* key2);
int hash1(const char* key, int size);
int hash2(const char* key, int size);
#endif // TP2_H

#include "tp2.h"

// Helper Functions
int getBit(const char* key, int bitIndex) {
    if (!key || bitIndex < 0) return -1;
    int byteIndex = bitIndex / 8;
    int bitOffset = bitIndex % 8;
    if (byteIndex >= strlen(key)) return 0;
    return (key[byteIndex] >> (7 - bitOffset)) & 1;
}

int firstDifferentBit(const char* key1, const char* key2) {
    if (!key1 || !key2) return -1;
    int i = 0;
    while (key1[i] == key2[i] && key1[i] != '\0' && key2[i] != '\0') {
        i++;
    }
    if (key1[i] == '\0' && key2[i] == '\0') return -1;
    
    int bit = 0;
    while (getBit(key1, i * 8 + bit) == getBit(key2, i * 8 + bit)) {
        bit++;
    }
    return i * 8 + bit;
}

// PATRICIA Tree Implementation
NoPatricia* createNoPatricia(const char* key, int bitIndex) {
    NoPatricia* node = (NoPatricia*)malloc(sizeof(NoPatricia));
    if (!node) return NULL;
    
    node->key = strdup(key);
    node->bitIndex = bitIndex;
    node->left = node->right = NULL;
    return node;
}

void insertPatricia(NoPatricia** root, const char* key) {
    if (!key) return;
    
    if (!*root) {
        *root = createNoPatricia(key, -1);
        return;
    }
    
    NoPatricia* current = *root;
    NoPatricia* parent = NULL;
    int direction = 0;
    
    while (current->bitIndex < current->left->bitIndex) {
        parent = current;
        direction = getBit(key, current->bitIndex);
        current = direction ? current->right : current->left;
    }
    
    if (strcmp(current->key, key) == 0) return; // Key already exists
    
    int diffBit = firstDifferentBit(current->key, key);
    NoPatricia* newNode = createNoPatricia(key, diffBit);
    
    if (!parent) {
        *root = newNode;
    } else {
        if (direction) parent->right = newNode;
        else parent->left = newNode;
    }
    
    int newDirection = getBit(key, diffBit);
    if (newDirection) {
        newNode->left = current;
        newNode->right = newNode;
    } else {
        newNode->left = newNode;
        newNode->right = current;
    }
}

void removePatricia(NoPatricia** root, const char* key) {
    if (!*root || !key) return;
    
    NoPatricia* current = *root;
    NoPatricia* parent = NULL;
    NoPatricia* grandparent = NULL;
    int parentDirection = 0;
    
    while (current->bitIndex < current->left->bitIndex) {
        grandparent = parent;
        parent = current;
        parentDirection = getBit(key, current->bitIndex);
        current = parentDirection ? current->right : current->left;
    }
    
    if (strcmp(current->key, key) != 0) return; // Key not found
    
    if (!parent) {
        free(current->key);
        free(current);
        *root = NULL;
        return;
    }
    
    NoPatricia* sibling = (parentDirection) ? parent->left : parent->right;
    
    if (!grandparent) {
        *root = sibling;
    } else {
        if (parentDirection) grandparent->right = sibling;
        else grandparent->left = sibling;
    }
    
    free(current->key);
    free(current);
    free(parent->key);
    free(parent);
}

void printPreOrderPatricia(NoPatricia* root) {
    if (!root) return;
    
    printf("%s ", root->key);
    if (root->left && root->left->bitIndex > root->bitIndex)
        printPreOrderPatricia(root->left);
    if (root->right && root->right->bitIndex > root->bitIndex)
        printPreOrderPatricia(root->right);
}

bool searchPatricia(NoPatricia* root, const char* key) {
    if (!root || !key) return false;
    
    NoPatricia* current = root;
    while (current->bitIndex < current->left->bitIndex) {
        current = getBit(key, current->bitIndex) ? current->right : current->left;
    }
    
    return strcmp(current->key, key) == 0;
}

void freePatriciaTree(NoPatricia* root) {
    if (!root) return;
    
    if (root->left && root->left->bitIndex > root->bitIndex)
        freePatriciaTree(root->left);
    if (root->right && root->right->bitIndex > root->bitIndex)
        freePatriciaTree(root->right);
    
    free(root->key);
    free(root);
}

// Menu Implementation
void printMenu() {
    printf("\n=== Menu PATRICIA Tree ===\n");
    printf("1. Inserir chave\n");
    printf("2. Remover chave\n");
    printf("3. Pesquisar chave\n");
    printf("4. Imprimir em pre-ordem\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    NoPatricia* root = NULL;
    char key[100];
    int choice;
    
    printf("Bem-vindo ao Teste da PATRICIA Tree\n");
    printf("==================================\n");
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Limpar o buffer do teclado
        
        switch (choice) {
            case 1:
                printf("Digite a chave para inserir: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove o \n do final
                insertPatricia(&root, key);
                printf("Chave inserida!\n");
                break;
                
            case 2:
                printf("Digite a chave para remover: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                removePatricia(&root, key);
                printf("Operacao de remocao concluida!\n");
                break;
                
            case 3:
                printf("Digite a chave para pesquisar: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                printf("Chave '%s': %s\n", key, searchPatricia(root, key) ? "Encontrada" : "Nao encontrada");
                break;
                
            case 4:
                printf("Arvore em pre-ordem: ");
                printPreOrderPatricia(root);
                printf("\n");
                break;
                
            case 0:
                printf("Saindo do programa...\n");
                freePatriciaTree(root);
                return 0;
                
            default:
                printf("Opcao invalida!\n");
        }
    }
    
    return 0;
}

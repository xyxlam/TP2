#include "tp2.h"

void printMenu() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Testar PATRICIA Tree\n");
    printf("2. Testar Hash Table\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void patriciaTreeMenu() {
    NoPatricia* root = NULL;
    char key[100];
    int choice;
    
    while (1) {
        printf("\n=== Menu PATRICIA Tree ===\n");
        printf("1. Inserir chave\n");
        printf("2. Remover chave\n");
        printf("3. Pesquisar chave\n");
        printf("4. Imprimir em pre-ordem\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
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
                freePatriciaTree(root);
                return;
                
            default:
                printf("Opcao invalida!\n");
        }
    }
}

void hashTableMenu() {
    HashTable* ht = createHashTable(10);
    char key[100];
    int choice;
    
    while (1) {
        printf("\n=== Menu Hash Table ===\n");
        printf("1. Inserir chave\n");
        printf("2. Pesquisar chave\n");
        printf("3. Imprimir tabela\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);
        getchar(); // Limpar o buffer do teclado
        
        switch (choice) {
            case 1:
                printf("Digite a chave para inserir: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                insertHash(ht, key);
                printf("Chave inserida!\n");
                break;
                
            case 2:
                printf("Digite a chave para pesquisar: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;
                printf("Chave '%s': %s\n", key,  searchHash(ht, key) ? "Encontrada" : "Nao encontrada");
                break;
                
            case 3:
                printHashTable(ht);
                break;
                
            case 0:
                freeHashTable(ht);
                return;
                
            default:
                printf("Opcao invalida!\n");
        }
    }
}

int main() {
    int choice;
    
    printf("Bem-vindo ao Teste de Estruturas de Dados\n");
    printf("=======================================\n");
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Limpar o buffer do teclado
        
        switch (choice) {
            case 1:
                patriciaTreeMenu();
                break;
                
            case 2:
                hashTableMenu();
                break;
                
            case 0:
                printf("Saindo do programa...\n");
                return 0;
                
            default:
                printf("Opcao invalida!\n");
        }
    }
    
    return 0;
}
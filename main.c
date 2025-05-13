#include "tp2.h"

void testPatriciaTree() {
    printf("\n=== Testing PATRICIA Tree ===\n");
    NoPatrica* root = NULL;
    
    // Test insertion
    printf("\nInserting keys: 'test', 'team', 'toast', 'taste'\n");
    insertPatricia(&root, "test");
    insertPatricia(&root, "team");
    insertPatricia(&root, "toast");
    insertPatricia(&root, "taste");
    
    // Test pre-order printing
    printf("\nPre-order traversal: ");
    printPreOrderPatricia(root);
    printf("\n");
    
    // Test search
    printf("\nSearching for keys:\n");
    printf("'test': %s\n", searchPatricia(root, "test") ? "Found" : "Not found");
    printf("'team': %s\n", searchPatricia(root, "team") ? "Found" : "Not found");
    printf("'toast': %s\n", searchPatricia(root, "toast") ? "Found" : "Not found");
    printf("'taste': %s\n", searchPatricia(root, "taste") ? "Found" : "Not found");
    printf("'none': %s\n", searchPatricia(root, "none") ? "Found" : "Not found");
    
    // Test removal
    printf("\nRemoving 'team'\n");
    removePatricia(&root, "team");
    printf("Pre-order traversal after removal: ");
    printPreOrderPatricia(root);
    printf("\n");
    
    // Cleanup
    freePatriciaTree(root);
}

void testHashTable() {
    printf("\n=== Testing Hash Table ===\n");
    HashTable* ht = createHashTable(10);
    
    // Test insertion
    printf("\nInserting keys: 'apple', 'banana', 'cherry', 'date'\n");
    insertHash(ht, "apple");
    insertHash(ht, "banana");
    insertHash(ht, "cherry");
    insertHash(ht, "date");
    
    // Test printing
    printf("\nHash Table contents:\n");
    printHashTable(ht);
    
    // Test search
    printf("\nSearching for keys:\n");
    printf("'apple': %s\n", searchHash(ht, "apple") ? "Found" : "Not found");
    printf("'banana': %s\n", searchHash(ht, "banana") ? "Found" : "Not found");
    printf("'cherry': %s\n", searchHash(ht, "cherry") ? "Found" : "Not found");
    printf("'date': %s\n", searchHash(ht, "date") ? "Found" : "Not found");
    printf("'none': %s\n", searchHash(ht, "none") ? "Found" : "Not found");
    
    // Cleanup
    freeHashTable(ht);
}

void printMenu() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Testar Patricia Tree\n");
    printf("2. Testar Hash Table\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void patricaTreeMenu(){
    NoPatrica* root = NULL;
    char key[100];
    int choice;

    printf("\n=== Menu PATRICIA Tree ===\n");
    printf("1. Inserir chave\n");
    printf("2. Remover chave\n");
    printf("3. Pesquisar chave\n");
    printf("4. Imprimir em pre-ordem\n");
    printf("0. Voltar ao menu principal\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);
    getchar(); // Limpar o buffer do teclado

    switch (choice)
    {
    case 1:
        printf("Digite a chave parainserir: ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = 0; // Remove o \n do final
        insertPatricia(&root, key);
        printf("Chave Inserida!\n");
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
        printf("Chave '%s':%s\n", key, searchPatricia(root, key) ? "Encontrada" : "Não Encontrada");

    case 4:
        printf("Arvore em pre-ordem: ");
        printPreOrderPatricia(root);
        printf("\n");

    case 0:
        freePatriciaTree(root);
        return;

    default:
        printf("Opção Inválida!\n");
        break;
    }
}

void HashTableMenu(){
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

    printf("Testing Data Structures Implementation\n");
    printf("===================================\n");
    
    testPatriciaTree();
    testHashTable();

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
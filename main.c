#include "tp2.h"

int main (){
    NoPatricia *arvore = NULL;
    int opcao_geral, opcao_sub;
    char chave[TAM_MAX];

    inicializar_tabela();

    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Operações com Árvore PATRICIA\n");
        printf("2. Operações com Tabela Hash\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao_geral);

        switch (opcao_geral) {
            case 1:
                do {
                    printf("\n--- Operações com PATRICIA ---\n");
                    printf("1. Inserir chave\n");
                    printf("2. Pesquisar chave\n");
                    printf("3. Imprimir em pré-ordem\n");
                    printf("0. Voltar ao menu principal\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao_sub);

                    switch (opcao_sub) {
                        case 1:
                            printf("Digite a chave a inserir: ");
                            scanf("%s", chave);
                            arvore = inserir_patricia(arvore, chave);
                            break;
                        case 2:
                            printf("Digite a chave a pesquisar: ");
                            scanf("%s", chave);
                            if (pesquisar_Patricia(arvore, chave))
                                printf("Chave encontrada!\n");
                            else
                                printf("Chave não encontrada.\n");
                            break;
                        case 3:
                            printf("Impressão da árvore em pré-ordem:\n");
                            imprimir_pre_ordem(arvore);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (opcao_sub != 0);
                break;

            case 2:
                do {
                    printf("\n--- Operações com Hash Table ---\n");
                    printf("1. Inserir chave\n");
                    printf("2. Pesquisar chave\n");
                    printf("3. Imprimir chaves\n");
                    printf("0. Voltar ao menu principal\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao_sub);

                    switch (opcao_sub) {
                        case 1:
                            printf("Digite a chave a inserir: ");
                            scanf("%s", chave);
                            inserir_hash(chave);
                            break;
                        case 2:
                            printf("Digite a chave a pesquisar: ");
                            scanf("%s", chave);
                            if (pesquisar_hash(chave))
                                printf("Chave encontrada!\n");
                            else
                                printf("Chave não encontrada.\n");
                            break;
                        case 3:
                            printf("Chaves na tabela hash:\n");
                            imprimir_hash();
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (opcao_sub != 0);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao_geral != 0);

    return 0;
}
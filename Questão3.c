#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct produto {
    char nome[500];
    float preco;
    int quantidade;
};

float valortotal(struct produto produto) {
    return produto.preco * produto.quantidade;
}

void compras(struct produto *produto, int quanti) {
    if (quanti <= produto->quantidade) {
        produto->quantidade -= quanti;
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Quantidade em estoque insuficiente.\n");
    }
}

void estoque(struct produto produto) {
    printf("Nome do produto: %s\n", produto.nome);
    printf("Preço do produto: %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Valor total em estoque: %.2f\n", valortotal(produto));
}

int main() {

    setlocale(LC_ALL, "portuguese");

    struct produto produto;
    int PRODUTO, QUANTIDADECOMPRA;

    printf("Informe o nome do produto: ");
    gets(produto.nome);
    printf("Informe o preço do produto: ");
    scanf("%f", &produto.preco);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &produto.quantidade);

    do {
        printf("\nEscolha uma das opções abaixo\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Realizar uma compra\n");
        printf("3 - Consultar estoque\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opcao desejada: ");
        scanf("%d", &PRODUTO);
        fflush(stdin);

        switch (PRODUTO) {
        case 1:
            printf("Digite o nome do produto: ");
            gets(produto.nome);
            fflush(stdin);
            printf("Digite o preco do produto: ");
            scanf("%f", &produto.preco);
            fflush(stdin);
            printf("Digite a quantidade em estoque: ");
            scanf("%d", &produto.quantidade);
            fflush(stdin);

            printf("\nO nome do produto desejado: %s\n", produto.nome);
            printf("Preco do produto: R$%.2f\n", produto.preco);
            printf("Quantidade em estoque: %d\n", produto.quantidade);
            break;
        case 2:
            printf("Digite a quantidade a ser comprada: ");
            scanf("%d", &QUANTIDADECOMPRA);
            compras(&produto, QUANTIDADECOMPRA);
            fflush(stdin);
            printf("\nQuantidade em estoque: %d\n", produto.quantidade);
        case 3:
            estoque(produto);
            break;
        case 4:
            printf("Programa encerrado...\n");
            break;
        default:
            printf("Opção inválida");
            break;
        }

    } while (PRODUTO != 4);

    return 0;
    
}
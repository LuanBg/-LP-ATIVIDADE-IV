#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct contabancaria {
    char nome[500], numero[500], tipoconta[500];
    float saldo, transferencia, depositado;
};

float dados_deposito(float valorinicial, float valordeposito) {
    return valorinicial + valordeposito;
}

float sacar(float valorinicial, float valorsaque) {
    return valorinicial - valorsaque;
}

int main() {

    setlocale(LC_ALL, "portuguese");

    int decisao;
    float deposito, saque;
    struct contabancaria contabancaria;

    do {
        printf("Conta Bancaria\n");
        printf("Escolha uma das opções abaixo \n");
        printf("1 - Entrar na minha conta \n2 - Depósitar \n3 - Saque\n4 - Sair do programa\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &decisao);
        printf("\n");

        switch (decisao) {
        case 1:
            fflush(stdin);
            printf("Nome do titular: ");
            gets(contabancaria.nome);
            printf("Número da conta: ");
            gets(contabancaria.numero);
            printf("Tipo de conta: ");
            gets(contabancaria.tipoconta);
            printf("Informe o saldo atual: ");
            scanf("%f", &contabancaria.saldo);
            printf("\n");
            break;
        case 2:
            printf("Informe o valor que deseja depositar: ");
            scanf("%f", &contabancaria.depositado);
            deposito = dados_deposito(contabancaria.saldo, contabancaria.depositado);
            printf("\n");
            printf("Nome do titular: %s\n", contabancaria.nome);
            printf("Número da conta: %s\n", contabancaria.numero);
            printf("Tipo da conta: %s\n", contabancaria.tipoconta);
            printf("Saldo anterior: %.2f\n", contabancaria.saldo);
            printf("Saldo atual da conta: %.2f\n\n", deposito);
            contabancaria.saldo = deposito;
            break;
        case 3:
            printf("Informe o valor de saque: ");
            scanf("%f", &contabancaria.transferencia);
            saque = sacar(contabancaria.saldo, contabancaria.transferencia);
            printf("\n");
            printf("Nome do titular: %s\n", contabancaria.nome);
            printf("Número da conta: %s\n", contabancaria.numero);
            printf("Tipo da conta: %s\n", contabancaria.tipoconta);
            printf("Saldo anterior: %.2f\n", contabancaria.saldo);
            printf("Saldo atual: %.2f\n", saque);
            break;
        case 4:
            printf("\n");
            printf("Operação encerrada!");
            break;
        default:
            break;

        }

    } while (decisao != 4);

    return 0;

}
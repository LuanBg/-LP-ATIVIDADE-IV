#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct dadosfuncionarios {
    char nome[200], cargo[200];
    float salario;
};

float calcularMediaSalario (struct dadosfuncionarios funcionario[], int quantidade, char cargo[]) {
    int contador = 0, somaSalario = 0, i;

     for (i = 0; i < quantidade; i++) {
        if (strcmp(funcionario[i].cargo, cargo) == 0) {
            somaSalario += funcionario[i].salario;
            contador++;
        }
    }

    if (contador > 0 ) {
        return somaSalario / (float)contador;
    } else {
        return 0.0;
    }
}
    
int main () {

    setlocale(LC_ALL, "portuguese");

    int quantidade, i;
    char cargodesejado[500];
    float mediaSalarial;

    printf("Informe o número de funcionários: ");
    scanf("%d", &quantidade);

    struct dadosfuncionarios funcionario[quantidade];

    for (i = 0; i < quantidade; i++) {
        printf("\n%dº Funcionário\n", i + 1);
        fflush(stdin);
        printf("Nome: ");
        gets(funcionario[i].nome);
        printf("Cargo: ");
        gets(funcionario[i].cargo);
        printf("Salário: ");
        scanf("%f", &funcionario[i].salario);
    }

    printf("\nCálculo da média salarial\n");
    printf("Escolha o cargo desejado: ");
    scanf("%s", cargodesejado);

    mediaSalarial = calcularMediaSalario(funcionario, quantidade, cargodesejado);

    printf("\nCargo escolhido: %s \n", cargodesejado);
    printf("Média salarial: R$%.2f \n", mediaSalarial);

    return 0;

}
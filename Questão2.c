#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define TAM_ALUNO 5
#define TAM_NOTA 2

struct aluno {
    char nome[200], datanascimento[200];
};
typedef struct aluno aluno;

float calcularMedia(float nota[]) {
    int i;
    float somanotas = 0, media;
    for (i = 0; i < TAM_NOTA; i++) {
        somanotas += nota[i];
    }
    media = somanotas / TAM_NOTA;

    return media;
}

char *situacao(float media) {
    char situacao[200];
    if (media >= 7) {
        strcpy(situacao, "Aprovado!");
    } else {
        strcpy(situacao, "Reprovado!");
    }

    return situacao;
}

int main() {

    setlocale(LC_ALL, "portuguese");

    float nota[TAM_NOTA], mediaTotal;
    int i, j;

    aluno aluno[TAM_ALUNO];

    for (i = 0; i < TAM_ALUNO; i++) {
        printf("\nDados do %dº aluno(a) \n", i + 1);
        printf("Informe o nome: ");
        scanf("%s", &aluno[i].nome);

        printf("Informe a data de nascimento: ");
        scanf("%s", &aluno[i].datanascimento);

        for (j = 0; j < TAM_NOTA; j++) {
            printf("Informe a nota: ");
            scanf("%f", &nota[j]);

            mediaTotal = calcularMedia(nota);
        }

        printf("\nAluno(a): %s \n", aluno[i].nome);
        printf("Data de nascimento: %s \n", aluno[i].datanascimento);
        printf("Média: %.1f \n ", mediaTotal);
        printf("%s\n", situacao(mediaTotal));

    }

    fflush(stdin);

    return 0;
    
}
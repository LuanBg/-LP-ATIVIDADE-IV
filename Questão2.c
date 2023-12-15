#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_ALUNOS 5
#define TAM_NOTAS 2

struct aluno {
    char nome[50], datanascimento[15];
    float nota1, nota2, media;
};

float calcularmedia(struct aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / TAM_NOTAS;
}

void situacao(struct aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("Aprovado!\n");
    } else {
        printf("Reprovado!\n");
    }
}

int main() {

    setlocale(LC_ALL, "portuguese");

    struct aluno alunos[TAM_ALUNOS]; 
    int i;
    
    for (i = 0; i < TAM_ALUNOS; ++i) {
        printf("\nDados do %dº aluno(a) \n", i + 1);
        printf("Informe o nome: ");
        scanf("%s", alunos[i].nome);
        printf("Informe a data de nascimento: ");
        scanf("%s", alunos[i].datanascimento); 
        printf("Informe a 1º nota: ");
        scanf("%f", &alunos[i].nota1);
        printf("Informe a 2º nota: ");
        scanf("%f", &alunos[i].nota2);
        
        alunos[i].media = calcularmedia(alunos[i]);

    }

    system("cls || clear");

    for (i = 0; i < TAM_ALUNOS; ++i) {
        printf("\nAluno(a): %s \n", alunos[i].nome);
        printf("Data de nascimento: %s \n", alunos[i].datanascimento);
        printf("Média: %.2f\n", alunos[i].media);
        situacao(alunos[i]);
    }

    return 0;
    
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM 3

struct dados_contatos {
    char nome[200], telefone[200], email[200];
};

void pesquisarContato(struct dados_contatos *contatos, char *contato) {
    int i;
    for (i = 0; i < TAM; i++) {
        if (strcmp(contatos[i].nome, contato) == 0) {
            printf("Nome: %s \n", contatos[i].nome);
            printf("Telefone: %s \n", contatos[i].telefone);
            return;
        }

    }

    printf("Esse contato não existe! \n");

}

int main() {

    setlocale(LC_ALL, "");
   
    struct dados_contatos contatos[TAM];
    char contato[200];
    int i;
   
    //
    for (i = 0; i < TAM; i++) {
        printf("\nInforme os dados do %dº contato: \n", i + 1);
        printf("Nome: ");
        gets(contatos[i].nome);
       
        printf("Telefone: ");
        gets(contatos[i].telefone);
       
        printf("E-mail: ");
        gets(contatos[i].email);
    }
   
    printf("\nInforme o nome do contato que deseja: ");
    gets(contato);
   
    printf("\n");
   
    pesquisarContato(contatos, contato);
   
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct livros{
    char titulo[100];    // Título do livro
    char autor[50];      // Autor do livro
    int anoPublicacao;   // Ano de publicação do livro
    char genero[30];     // Gênero do livro
    int numeroPaginas;   // Número de páginas do livro
    char disponibilidade[30];
    int quantidade;
    int codigo;
} Livros;

int menuprincipal (int op) {
    printf("1 - Funcionario\n2 - Cliente\n3 - Sair\n");
    printf("Informe sua Escolha: ");
    scanf("%d", &op);
    return op;
}

int menufuncionario (int op) {
    printf("1 - Adicionar Livro\n2 - Editar Livro\n3 - Apagar Livro\n4 - Voltar");
    printf("Informe sua Escolha: ");
    scanf("%d", &op);
    return op;
}

void funcionario () {
    int op;
    do
    {
        system("cls");
        op = menufuncionario(op);
        switch (op)
        {
        case 1:
            // Adicionar
            break;
        case 2:
            // Editar
            break;
        case 3:
            // Apagar
            break;
        case 4:
            printf("Saindo da Aplicacao...");
            break;
        default:
            printf("Dado Invalido!\nInsira um Dado Valido!\n");
            break;
        }
        
    } while (1);
    
}

int main () {
    int op;
    do {
        system("cls");
        op = menuprincipal(op);
        switch(op) {
        case 1:
            system("cls");
            funcionario();
            break;
            // Funcionario
        case 2:
            system("cls");
            printf("Cliente\n");
            break;
            // Cliente
        case 3:
            system("cls");
            printf("Saindo da Aplicacao...\n");
            break;
        default:
            system("cls");
            printf("Informacao Incorreta!\nInsira um Dado Valido!\n");
            break;
        }
    } while (op != 3);
    return 0;
}
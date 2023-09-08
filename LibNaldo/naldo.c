#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu (int op) {
    printf("1 - Funcionario\n2 - Cliente\n3 - Sair\n");
    printf("Informe sua Escolha: ");
    scanf("%d", &op);
    return op;
}

int main () {
    int op;
    do {
        system("cls");
        op = menu(op);
        switch(op) {
        case 1:
        system("cls");
        printf("Funcionario\n");
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
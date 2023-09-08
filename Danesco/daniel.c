#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100
struct Conta {
    char numero[MAX];
    char agencia[MAX];
    double saldo;
};

void criarConta(struct Conta *contas, int *numContas) {
    if (*numContas < MAX) { // Limite máximo de contas
        struct Conta novaConta;
        printf("\nDigite o número da conta: ");
        scanf("%s", novaConta.numero);
        printf("Digite a agência: ");
        scanf("%s", novaConta.agencia);
        printf("Digite o saldo inicial: ");
        scanf("%lf", &novaConta.saldo);
        contas[*numContas] = novaConta;
        (*numContas)++;
        printf("\nConta criada com sucesso!\n");
    } else {
        printf("\nLimite de contas atingido!\n");
    }
}
void transferir(struct Conta *contas, int numContas) {
    char origem[MAX], destino[MAX];
    double valor;
    printf("\nDigite o número da conta de origem: ");
    scanf("%s", origem);
    printf("Digite o número da conta de destino: ");
    scanf("%s", destino);
    printf("Digite o valor a ser transferido: ");
    scanf("%lf", &valor);

    struct Conta *contaOrigem = NULL, *contaDestino = NULL;
    for (int i = 0; i < numContas; i++) {
        if (strcmp(contas[i].numero, origem) == 0) {
            contaOrigem = &contas[i];
        }
        if (strcmp(contas[i].numero, destino) == 0) {
            contaDestino = &contas[i];
        }
    }

    if (contaOrigem != NULL && contaDestino != NULL) {
        if (contaOrigem->saldo >= valor) {
            contaOrigem->saldo -= valor;
            contaDestino->saldo += valor;
            printf("\nTransferência realizada com sucesso!\n");
        } else {
            printf("\nSaldo insuficiente na conta de origem!\n");
        }
    } else {
        printf("\nConta de origem ou destino não encontrada!\n");
    }
}

void depositar(struct Conta *contas, int numContas) {
    char numeroConta[MAX];
    double valor;
    printf("\nDigite o número da conta: ");
    scanf("%s", numeroConta);
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &valor);

    struct Conta *conta = NULL;
    for (int i = 0; i < numContas; i++) {
        if (strcmp(contas[i].numero, numeroConta) == 0) {
            conta = &contas[i];
        }
    }

    if (conta != NULL) {
        conta->saldo += valor;
        printf("\nDepósito realizado com sucesso!\n");
    } else {
        printf("\nConta não encontrada!\n");
    }
}

void sacar(struct Conta *contas, int numContas) {
    char numeroConta[MAX];
    double valor;
    printf("\nDigite o número da conta: ");
    scanf("%s", numeroConta);
    printf("Digite o valor a ser sacado: ");
    scanf("%lf", &valor);

    struct Conta *conta = NULL;
    for (int i = 0; i < numContas; i++) {
        if (strcmp(contas[i].numero, numeroConta) == 0) {
            conta = &contas[i];
        }
    }

    if (conta != NULL) {
        if (conta->saldo >= valor) {
            conta->saldo -= valor;
            printf("\nSaque realizado com sucesso!\n");
        } else {
            printf("\nSaldo insuficiente na conta!\n");
        }
    } else {
        printf("\nConta não encontrada!\n");
    }
}

void editarConta(struct Conta *contas, int numContas) {
    char numeroConta[MAX];
    printf("\nDigite o número da conta a ser editada: ");
    scanf("%s", numeroConta);

    struct Conta *conta = NULL;
    for (int i = 0; i < numContas; i++) {
        if (strcmp(contas[i].numero, numeroConta) == 0) {
            conta = &contas[i];
        }
    }

    if (conta != NULL) {
        printf("\nDigite o novo número da conta: ");
        scanf("%s", conta->numero);
        printf("Digite a nova agência: ");
        scanf("%s", conta->agencia);
        printf("Digite o novo saldo: ");
        scanf("%lf", &conta->saldo);
        printf("\nConta editada com sucesso!\n");
    } else {
        printf("\nConta não encontrada!\n");
    }
}

int main() {
    char key[MAX], user[MAX], keypad[MAX] = "admin", userpad[MAX] = "admin";
    int op, novo;

    do {
        printf("\n=======================================================\n");
        printf("\n==================== POSSUI CONTA? ====================\n");
        printf("\n=======================================================\n");
        printf("\nDigite uma opção: \n1 - Login\n2 - Novo aqui?\n3 - Sair -> ");
        scanf("%d", &novo);

        if (novo == 3) {
            break;
        } else if (novo != 1) {
            break;
        } else if (novo != 2) {
            break;
        }

        switch (novo) {
            case 1:
                system("cls");
                printf("\n=======================================================\n");
                printf("\n======================== LOGIN ========================\n");
                printf("\n=======================================================\n");

                printf("\nDigite o usuário: ");
                scanf("%s", user);
                printf("\nDigite a senha: ");
                scanf("%s", key);
                if (strcmp(user, userpad) == 0 && strcmp(key, keypad) == 0) {
                    int numContas = 0;
                    struct Conta contas[MAX];
                    do {
                        printf("\n=======================================================\n");
                        printf("\n===================== BANCO DANESCO ===================\n");
                        printf("\n=======================================================\n");
                        printf("\nDigite uma opção: \n1 - Criar Conta\n2 - Transferir\n3 - Depositar\n4 - Sacar\n5 - Editar Conta\n6 - Sair\n-> ");
                        scanf("%d", &op);

                        switch (op) {
                            case 1:
                                criarConta(contas, &numContas);
                                break;
                            case 2:
                                transferir(contas, numContas);
                                break;
                            case 3:
                                depositar(contas, numContas);
                                break;
                            case 4:
                                sacar(contas, numContas);
                                break;
                            case 5:
                                editarConta(contas, numContas);
                                break;
                            case 6:
                                printf("\nSaindo...\n");
                                break;
                            default:
                                printf("\nOpção inválida!\n");
                                break;
                        }

                    } while (op != 6);

                    system("pause");
                } else {
                    printf("\nUsuário ou senha incorretos!\n");
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                printf("\n=======================================================\n");
                printf("\n==================== NOVO CADASTRO ====================\n");
                printf("\n=======================================================\n");
                printf("\nDigite uma opção: \n1 - Cliente\n2 - Funcionário\n3 - Sair -> ");
                scanf("%d", &op);
                switch (op) {
                    case 1:
                        printf("\nDigite o usuário: ");
                        scanf("%s", user);
                        printf("\nDigite a senha: ");
                        scanf("%s", key);
                        strcpy(userpad, user);
                        strcpy(keypad, key);
                        printf("\nCadastro efetuado com sucesso!\n");
                        system("pause");
                        break;
                    case 2:
                        printf("\nDigite o usuário: ");
                        scanf("%s", user);
                        printf("\nDigite a senha: ");
                        scanf("%s", key);
                        strcpy(userpad, user);
                        strcpy(keypad, key);
                        printf("\nCadastro efetuado com sucesso!\n");
                        system("pause");
                        break;

                    default:
                        printf("\nOpção inválida!\n");
                        system("pause");
                        break;
                }
                break;
            case 3:
                printf("\nSaindo...\n");
                system("pause");
                break;
            default:
                printf("\nOpção inválida!\n");
                system("pause");
                break;
        }

    } while (op != 3);
    return 0;
}

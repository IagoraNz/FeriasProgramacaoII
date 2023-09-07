#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

int idA;
char senhaA[tamanho];

typedef struct produtos {
    char nome[tamanho];
    char codigo[tamanho];
    char quantidade[tamanho];
} Produtos;


void menufunc(Produtos lista[]){
    int opc, in, opc1, i = 0;
    char prod[tamanho];

    printf("_____ MENU DO FUNCIONARIO _____\n");
    printf("1 - Produtos\n");
    printf("2 - Numero de compras\n");
    printf("3 - Estoque\n");
    printf("Opcao desejada: ");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        printf("1.1 - Cadastrar\n");
        printf("1.2 - Armazenados\n");
        printf("Opcao: ");
        scanf("%d", &opc1);

        if(opc1 == 1){
           printf("Qual categoria de produto? (iPhone, Macbook, iPad, iPods, Acessorios): ");
           fflush(stdin);
           scanf(" %s", prod);

           const char cat1[] = "iPhone";

           if(strcmp(prod, cat1) == 0){
                printf("\nNovo iPhone\n");

                do{
                    printf("\nDigite o nome do produto: ");
                    fflush(stdin);
                    scanf("%s", lista[i].nome);

                    in = (strlen(lista[i].nome) <= 1);

                    if(in){
                        printf("Nome nao pode ser vazio! Digite novamente. \n");
                    }
                }while(in);

                do{
                    printf("\nDigite o codigo do produto: ");
                    fflush(stdin);
                    scanf("%s", lista[i].nome);

                    in = (strlen(lista[i].codigo) <= 1);

                    if(in){
                        printf("Codigo nao pode ser vazio! Digite novamente. \n");
                    }
                }while(in);

                do{
                    printf("\nDigite a quantidade do produto: ");
                    fflush(stdin);
                    scanf(" %s", lista[i].quantidade);

                    in = (strlen(lista[i].quantidade) <= 0);

                    if(in){
                        printf("Quantidade nao pode ser vazio! Digite novamente. \n");
                    }
                }while(in);
           }
        }
        break;
    
    default:
        break;
    }
}

void funcionario(){
    struct produtos lista[tamanho];
    int id;
    char senha[tamanho];

    printf("_____ ACESSO _____\n");
    printf("1 - Cadastrar acesso\n");
    printf("2 - Login\n");
    printf("Escolha a opcao desejada: ");
    int login;
    scanf("%d", &login);

    system("cls");

    FILE *arquivo;

    switch (login) 
    {
        case 1:
            printf("Bem-vindo ao cadastro do funcionario Apple!\n");
            printf("Digite o seu AppleId (O que voce recebeu no contrato): ");
            scanf("%d", &idA);

            do{
                printf("Digite uma senha com no minimo 8 digitos: ");
                scanf("%s", senhaA);

                if(strlen(senhaA) < 8){
                    printf("\nA senha deve ter pelo menos 8 caracteres. Tente novamente.\n\n");
                } 

                else{
                    arquivo = fopen("cadastrofunc.txt", "w");
                    
                    if(arquivo == NULL){
                        printf("Erro ao executar o arquivo. \n");
                        exit(1);
                    }

                    fprintf(arquivo, "%d\n%s\n", idA, senhaA);
                    fclose(arquivo);

                    printf("Cadastrado com sucesso!\n");

                    system("cls");
                    funcionario();
                }
            }while(strlen(senhaA) < 8);
            break;

        case 2:
            arquivo = fopen("cadastrofunc.txt", "r");

            if(arquivo == NULL){
                printf("Dados nao encontrados. Cadastra-se antes.\n");
                break;
            }
            
            fscanf(arquivo, "%d", &idA);
            fscanf(arquivo, "%s", senhaA);

            printf("AppleId: ");
            scanf("%d", &id);
            printf("Senha: ");
            scanf("%s", senha);

            if(strcmp(senha, senhaA) == 0 && id == idA){
                system("cls");
                menufunc(lista);
            } 
            else{
                printf("Login ou senha incorretos.\n");
            }

            fclose(arquivo);
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
    }
}

void cliente(){
    int opc;
    printf("_____ MENU _____\n");
    printf("1 - Produtos\n");
    printf("2 - Cesta de compras\n");
    printf("3 - Encontrar produto por palavra-chave\n");
    printf("Escolha a opcao desejada: ");
    scanf("%d", &opc);

    switch (opc) 
    {
        case 1:
            printf("_____ PRODUTOS _____\n");
            printf("1 - iPhones\n");
            printf("2 - Macbooks\n");
            printf("3 - iPads\n");
            printf("4 - iPods\n");
            printf("5 - Acessorios\n");
            printf("Informe a categoria desejada: ");
            
            int opc1;
            scanf("%d", &opc1);

            switch (opc1) 
            {
                case 1:
                    break;

                default:
                    printf("Opcao de categoria invalida!\n");
                    break;
            }
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }
}

int main(){
    int opcao;

    printf("Bem-vindo na Apple Store!\n");
    printf("\nCLIENTE\t\tFUNCIONARIO\t\n");
    printf("Para compras\tPara oficio\n");
    printf("\nSelecione a opcao desejada (1 ou 2): ");
    scanf("%d", &opcao);

    switch (opcao) 
    {
        case 1:
            cliente();
            break;

        case 2:
            funcionario();
            system("PAUSE");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}

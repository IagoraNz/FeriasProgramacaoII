#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 100

int idA;
char senhaA[tamanho];

typedef struct produtos {
    char nome[tamanho];
    int codigo;
    int quantidade;
} Produtos;

void troca(Produtos* a, Produtos* b){
    Produtos t = *a;
    *a = *b;
    *b = t;
}

int particao(Produtos arr[], int a, int b){
    int pivot = arr[a].codigo;
    int i = a;

    for(int j = a + 1; j <= b; j++){
        if(arr[j].codigo < pivot){
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i], &arr[a]);
    return i;
}

void QuickSort(Produtos vet[], int a, int b){
    if(b > a){
        int p = particao(vet, a, b);

        QuickSort(vet, a, p - 1);
        QuickSort(vet, p + 1, b);
    }
}

void troca1(Produtos* a, Produtos* b){
    Produtos t = *a;
    *a = *b;
    *b = t;
}

int particao1(Produtos arr[], int a, int b){
    int pivot = arr[a].quantidade;
    int i = a;

    for(int j = a + 1; j <= b; j++){
        if(arr[j].quantidade < pivot){
            i++;
            troca1(&arr[i], &arr[j]);
        }
    }
    troca1(&arr[i], &arr[a]);
    return i;
}

void QuickSort1(Produtos vet[], int a, int b){
    if(b > a){
        int p = particao1(vet, a, b);

        QuickSort1(vet, a, p - 1);
        QuickSort1(vet, p + 1, b);
    }
}

void menufunc(Produtos lista[], int *qP){
    int opc, opc1, i = *qP;
    char prod[tamanho];

    printf("_____ MENU DO FUNCIONARIO _____\n");
    printf("1 - Produtos\n");
    printf("2 - Numero de compras\n");
    printf("3 - Estoque\n");
    printf("Opcao desejada: ");
    scanf("%d", &opc);
    fflush(stdin);

    FILE *qPa;
    FILE *pArquivo;

    switch (opc) 
    {
        case 1:
            system("cls");
            printf("1.1 - Cadastrar\n");
            printf("1.2 - Armazenados\n");
            printf("1.3 - Voltar\n");
            printf("Opcao: ");
            scanf("%d", &opc1);
            fflush(stdin);

            if(opc1 == 1){
                printf("Qual categoria de produto? (iPhone, Macbook, iPad, iPod, Acessorios): ");
                scanf("%s", prod);
                fflush(stdin);

                const char cat1[] = "iPhone";
                const char cat2[] = "Macbook";
                const char cat3[] = "iPad";
                const char cat4[] = "iPod";
                const char cat5[] = "Acessorios";

                if(strcmp(prod, cat1) == 0 || strcmp(prod, cat2) == 0 || strcmp(prod, cat3) == 0 || strcmp(prod, cat4) == 0 || strcmp(prod, cat5) == 0){
                    printf("\nNovo Produto\n");

                    do{
                        printf("\nDigite o codigo do produto: ");
                        scanf("%d", &lista[i].codigo);
                        fflush(stdin);
                    }while(lista[i].codigo < 1);

                    do{
                        printf("Digite o nome do produto: ");
                        scanf("%[^\n]", lista[i].nome);
                        fflush(stdin);
                    }while(strlen(lista[i].nome) <= 1);

                    do{
                        printf("Digite a quantidade do produto: ");
                        scanf("%d", &lista[i].quantidade);
                        fflush(stdin);
                    }while(lista[i].quantidade < 1);

                    qPa = fopen("contador.txt", "w");

                    (*qP)++;

                    fprintf(qPa, "%d", *qP);
                    fclose(qPa);

                    pArquivo = fopen("ArquivoP2.txt", "a");

                    if(pArquivo == NULL){
                        printf("Erro ao executar o arquivo. \n");
                        exit(1);
                    }

                    fprintf(pArquivo, "%d\n%s\n%d\n", lista[i].codigo, lista[i].nome, lista[i].quantidade);
                    fclose(pArquivo);

                    system("cls");
                } 
                else{
                    printf("Categoria de produto inválida!\n");
                }
            } 
            else if(opc1 == 2){
                pArquivo = fopen("ArquivoP2.txt", "r");

                if(pArquivo == NULL){
                    printf("Dados nao encontrados. Cadastre produtos antes.\n");
                    break;
                }

                system("cls");

                printf("_____ ESTOQUE _____\n");
                printf("CODIGO\tNOME\t\t\tQUANTIDADE\n");

                qPa = fopen("contador.txt", "r");

                if(qPa == NULL){
                    printf("Contador nao encontrado\n");
                    break;
                }

                fscanf(qPa, "%d", qP);

                for(int j = 0; j < *qP; j++){
                    fscanf(pArquivo, "%d", &lista[j].codigo);
                    fgetc(pArquivo);
                    fgets(lista[j].nome, sizeof(lista[j].nome), pArquivo);
                    fscanf(pArquivo, "%d", &lista[j].quantidade);

                    lista[j].nome[strcspn(lista[j].nome, "\n")] = '\0';

                    printf("%d\t%-15.15s\t\t%d\n", lista[j].codigo, lista[j].nome, lista[j].quantidade);
                }
                fclose(pArquivo);
                fclose(qPa);
            } 
            else if(opc1 == 3){
                system("cls");
                menufunc(lista, qP);
            }
            break;

        case 3:
            system("cls");
            printf("_____ ESTOQUE _____\n");
            printf("1 - Por ordem de codigo\n");
            printf("2 - Por ordem de quantidade\n");
            printf("3 - Por categoria\n");
            printf("Escolha a opcao de ordenacao: ");
            int opc2;
            scanf("%d", &opc2);

            if(opc2 == 1){
                qPa = fopen("contador.txt", "r");
                if(qPa == NULL){
                    printf("Contador nao encontrado\n");
                    break;
                }

                fscanf(qPa, "%d", qP);
                fclose(qPa);

                pArquivo = fopen("ArquivoP2.txt", "r");

                if(pArquivo == NULL){
                    printf("Dados nao encontrados. Cadastre produtos antes.\n");
                    break;
                }

                for(i = 0; i < *qP; i++){
                    fscanf(pArquivo, "%d", &lista[i].codigo);
                    fgetc(pArquivo);
                    fgets(lista[i].nome, sizeof(lista[i].nome), pArquivo);
                    fscanf(pArquivo, "%d", &lista[i].quantidade);

                    lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';
                }
                fclose(pArquivo);

                QuickSort(lista, 0, *qP - 1);

                printf("_____ ESTOQUE POR CODIGO _____\n");
                printf("CODIGO\tNOME\t\t\tQUANTIDADE\n");
                for(i = 0; i < *qP; i++){
                    printf("%d\t%-15.15s\t\t%d\n", lista[i].codigo, lista[i].nome, lista[i].quantidade);
                }
            }
            else if(opc2 == 2){
                qPa = fopen("contador.txt", "r");
                if(qPa == NULL){
                    printf("Contador nao encontrado\n");
                    break;
                }

                fscanf(qPa, "%d", qP);
                fclose(qPa);

                pArquivo = fopen("ArquivoP2.txt", "r");

                if(pArquivo == NULL){
                    printf("Dados nao encontrados. Cadastre produtos antes.\n");
                    break;
                }

                for(i = 0; i < *qP; i++){
                    fscanf(pArquivo, "%d", &lista[i].codigo);
                    fgetc(pArquivo);
                    fgets(lista[i].nome, sizeof(lista[i].nome), pArquivo);
                    fscanf(pArquivo, "%d", &lista[i].quantidade);

                    lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';
                }
                fclose(pArquivo);

                QuickSort1(lista, 0, *qP - 1);

                printf("_____ ESTOQUE POR QUANTIDADE _____\n");
                printf("CODIGO\tNOME\t\t\tQUANTIDADE\n");
                for(i = 0; i < *qP; i++){
                    printf("%d\t%-15.15s\t\t%d\n", lista[i].codigo, lista[i].nome, lista[i].quantidade);
                }
            }
            else if(opc2 == 3){
                system("cls");
                printf("_____ CATEGORIAS _____\n");
                printf("3.1 - iPhone\n");
                printf("3.2 - iPad\n");
                printf("3.3 - iPod\n");
                printf("3.4 - Macbook\n");
                printf("3.5 - Acessorios\n");
                printf("Categoria desejada: ");
                int opc21;
                scanf("%d", &opc21);

                switch (opc21)
                {
                case 1:

                    break;
                
                default:
                    break;
                }
            }
            break;

        default:
            break;
    }

    system("PAUSE");
    menufunc(lista, qP);
}

void funcionario(){
    Produtos lista[tamanho];
    int id;
    char senha[tamanho];
    int qP = 0;

    printf("_____ ACESSO _____\n");
    printf("1 - Cadastrar acesso\n");
    printf("2 - Login\n");
    printf("Escolha a opcao desejada: ");
    int login;
    scanf("%d", &login);
    fflush(stdin);

    FILE *arquivo;

    switch (login)
    {
        case 1:
            system("cls");
            printf("Bem-vindo ao cadastro do funcionario Apple!\n");
            printf("Digite o seu AppleId (O que voce recebeu no contrato): ");
            scanf("%d", &idA);
            fflush(stdin);

            do{
                printf("Digite uma senha com no minimo 8 digitos: ");
                scanf("%s", senhaA);
                fflush(stdin);

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

                    system("PAUSE");
                    system("cls");
                    funcionario();
                }
            }while(strlen(senhaA) < 8);
            break;

        case 2:
            system("cls");
            arquivo = fopen("cadastrofunc.txt", "r");

            if(arquivo == NULL){
                printf("Dados nao encontrados. Cadastra-se antes.\n");
                break;
            }

            fscanf(arquivo, "%d", &idA);
            fscanf(arquivo, "%s", senhaA);

            printf("AppleId: ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Senha: ");
            scanf("%s", senha);
            fflush(stdin);

            if(strcmp(senha, senhaA) == 0 && id == idA){
                system("cls");
                menufunc(lista, &qP);
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

    system("PAUSE");
}

void cliente(){
    int opc;
    printf("_____ MENU _____\n");
    printf("1 - Produtos\n");
    printf("2 - Cesta de compras\n");
    printf("3 - Encontrar produto por palavra-chave\n");
    printf("Escolha a opcao desejada: ");
    scanf("%d", &opc);
    fflush(stdin);

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
            fflush(stdin);

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

    system("PAUSE");
}

int main(){

    int opcao;

    printf("Bem-vindo na Apple Store!\n");
    printf("\nCLIENTE\t\tFUNCIONARIO\t\n");
    printf("Para compras\tPara oficio\n");
    printf("\nSelecione a opcao desejada (1 ou 2): ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao) 
    {
        case 1:
            system("cls");
            cliente();
            break;

        case 2:
            system("cls");
            funcionario();
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

int totalcadastro, opcao;

struct funcionarios {
    int id;
    char departamento[30];
    char nome[50];
    char cargo[30];
    float salario;
    int idade;
};

struct funcionarios funcionario[MAX_FUNCIONARIOS];
int cont = 0;

void cadastrarF() {
    if(cont < MAX_FUNCIONARIOS){
        printf("Digite o ID do funcionário: ");
        scanf("%d", &funcionario[cont].id);
        getchar();
        printf("Digite o departamento: ");
        fgets(funcionario[cont].departamento, sizeof(funcionario[cont].departamento), stdin);
        funcionario[cont].departamento[strcspn(funcionario[cont].departamento, "\n")] = 0;
        printf("Digite o nome do funcionário: ");
        fgets(funcionario[cont].nome, sizeof(funcionario[cont].nome), stdin);
        funcionario[cont].nome[strcspn(funcionario[cont].nome, "\n")] = 0;
        printf("Digite o cargo do funcionário: ");
        fgets(funcionario[cont].cargo, sizeof(funcionario[cont].cargo), stdin);
        funcionario[cont].cargo[strcspn(funcionario[cont].cargo, "\n")] = 0;
        printf("Digite a idade do funcionário: ");
        scanf("%d", &funcionario[cont].idade);
        getchar();
        printf("Digite o salário: ");
        scanf("%f", &funcionario[cont].salario);
        cont++; 
    }else{
        printf("Limite de funcionários atingido! \nFavor deletar um funcionário.\n");
        printf("------------------------------");
    }
}

void listarF() {
    if(cont == 0){
        printf("SEM FUNCIONÁRIOS CADASTRADOS! \n");
        printf("-----------------------------");
    }else{
        int idL;
        printf("Digite o ID do funcionário: ");
        scanf("%d", &idL);

        for(int i = 0; i < cont; i++){
            if(idL == funcionario[i].id){
                printf("\nID: %d", funcionario[i].id);
                printf("\nNome: %s", funcionario[i].nome);
                printf("\nIdade: %d", funcionario[i].idade);
                printf("\nDepartamento: %s", funcionario[i].departamento);
                printf("\nCargo: %s", funcionario[i].cargo);
                printf("\nSalário: %.2f", funcionario[i].salario); 
                printf("\n------------------------------\n");
                return;
            }
        }
        printf("Funcionário com ID %d não encontrado.\n", idL);
    }
}

void atualizarF(){
    if (cont == 0){
        printf("Não há funcionário cadastrado!\n");
        printf("-------------------------------\n");
        printf("Cadastre um funcionário:\n");
        cadastrarF();   
    } else {
        int idU;
        printf("Digite o ID do funcionário a ser atualizado: ");
        scanf("%d", &idU);
        getchar();

        for (int i = 0; i < cont; i++) {
            if (funcionario[i].id == idU) {
                int opcao;
                printf("\nEscolha o que você quer atualizar: \n");
                printf("1. Departamento\n");
                printf("2. Nome\n");
                printf("3. Cargo\n");
                printf("4. Idade\n");
                printf("5. Salário\n");
                printf("Escolha: ");
                scanf("%d", &opcao);
                getchar();
                switch (opcao) {
                    case 1:
                        printf("\nNovo departamento: ");
                        fgets(funcionario[i].departamento, sizeof(funcionario[i].departamento), stdin);
                        funcionario[i].departamento[strcspn(funcionario[i].departamento, "\n")] = 0;
                        printf("Departamento atualizado com sucesso.\n");
                        break;
                    case 2:
                        printf("\nNovo nome: ");
                        fgets(funcionario[i].nome, sizeof(funcionario[i].nome), stdin);
                        funcionario[i].nome[strcspn(funcionario[i].nome, "\n")] = 0;
                        printf("Nome atualizado com sucesso.\n");
                        break;
                    case 3:
                        printf("\nNovo cargo: ");
                        fgets(funcionario[i].cargo, sizeof(funcionario[i].cargo), stdin);
                        funcionario[i].cargo[strcspn(funcionario[i].cargo, "\n")] = 0;
                        printf("Cargo atualizado com sucesso.\n");
                        break;
                    case 4:
                        printf("\nNova idade: ");
                        scanf("%d", &funcionario[i].idade);
                        printf("Idade atualizada com sucesso.\n");
                        break;
                    case 5:
                        printf("\nNovo salário: ");
                        scanf("%f", &funcionario[i].salario);
                        printf("Salário atualizado com sucesso.\n");
                        break;
                    default:
                        printf("\nOpção inválida\n");
                        break;
                }
                return;
            }
        }
        printf("Funcionário com ID %d não encontrado.\n", idU);
    }
}

void excluirF() {
    if (cont == 0) {
        printf("Não há funcionário cadastrado!\n");
        printf("-------------------------------\n");
    } else {
        int idD;
        printf("Digite o ID do funcionário a ser excluído: ");
        scanf("%d", &idD);

        for (int i = 0; i < cont; i++) {
            if (funcionario[i].id == idD) {
                for (int j = i; j < cont - 1; j++) {
                    funcionario[j] = funcionario[j + 1];
                }
                cont--;
                printf("Funcionário excluído com sucesso!\n");
                printf("------------------------------\n");
                return;
            }
        }
        printf("Funcionário com ID %d não encontrado.\n", idD);
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese_Brasil");

    while (1) {
        printf("Bem-vindo ao RH");
        printf("\n1. Criar funcionário");
        printf("\n2. Listar funcionários");
        printf("\n3. Atualizar funcionário");
        printf("\n4. Excluir funcionário");
        printf("\n5. Sair");

        printf("\nEscolha uma das opções: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarF();
                break;
            case 2:
                listarF();
                break;  
            case 3:
                atualizarF();
                break;
            case 4:
                excluirF();
                break;
            case 5:
                exit(0);
            default:
                printf("Número inválido!\n");
                printf("----------------\n");
        }
    }
    return 0;
}

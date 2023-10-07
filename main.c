#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

// Definindo uma estrutura para representar uma tarefa
struct Task {
    char name[100];
    char description[200];
    bool completed;
};

// Fun��o para adicionar uma nova tarefa
void addTask(struct Task tasks[], int *numTasks) {
    if (*numTasks < 100) {
        printf("Digite o nome da tarefa: ");
        scanf("%s", tasks[*numTasks].name);

        printf("Digite a descrição da tarefa: ");
        scanf("%s", tasks[*numTasks].description);

        tasks[*numTasks].completed = false;
        (*numTasks)++;
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("A lista de tarefas está cheia. Não é possível adicionar mais tarefas.\n");
    }
}

// Funçãoo para marcar uma tarefa como concluída e remove-la
void completeTask(struct Task tasks[], int *numTasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < *numTasks) {
        tasks[taskIndex].completed = true;
        printf("Tarefa '%s' marcada como concluída e removida da lista.\n", tasks[taskIndex].name);

        // Remova a tarefa movendo as tarefas restantes para preencher o espaço vazio.
        for (int i = taskIndex; i < (*numTasks - 1); i++) {
            strcpy(tasks[i].name, tasks[i + 1].name);
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }

        (*numTasks)--;
    } else {
        printf("Índice de tarefa inválido.\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    struct Task tasks[100];
    int numTasks = 0;


    char continuar;
    char entrada[100];

    printf("1-\t Adicionar nova tarefa\n");
    printf("2-\t Marcar tarefa como concluída\n");
    printf("3-\t Sair\n");
    
    do {
    
    printf("Digite a opção desejada: ");
    
    // Ler a linha inteira, incluindo o caractere de quebra de linha
    fgets(entrada, sizeof(entrada), stdin);

    // Analisar a opção
    sscanf(entrada, " %c", &continuar); 

        switch (continuar) {
            case '1':
                addTask(tasks, &numTasks);
                break;
            case '2':
                // Lógica para marcar uma tarefa como concluída
                printf("Tarefas disponoveis para marcação:\n");
                    for (int i = 0; i < numTasks; i++) {
                printf("%d - %s\n", i, tasks[i].name);
                }
                printf("Digite o índice da tarefa a ser marcada como concluída: ");
                int indexToComplete;
                scanf("%d", &indexToComplete);

                if (indexToComplete >= 0 && indexToComplete < numTasks) {
                    tasks[indexToComplete].completed = true;
                printf("Tarefa '%s' marcada como concluída.\n", tasks[indexToComplete].name);
            } else {
                printf("Índice de tarefa inválido.\n");
        }
                break;
            case '3':
                // Sair do loop
                printf("Saindo do programa. Digite o número três para ver a lista.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        getchar();
    } while (continuar != '3');
    
    // Exemplo de como exibir tarefas
    for (int i = 0; i < numTasks; i++) {
        printf("Tarefa #%d:\n", i + 1);
        printf("Nome: %s\n", tasks[i].name);
        printf("Descrição: %s\n", tasks[i].description);
        printf("Status: %s\n", tasks[i].completed ? "Concluída" : "Não concluída");
     }

    return 0;
}

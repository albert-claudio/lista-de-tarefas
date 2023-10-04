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

        printf("Digite a descri��o da tarefa: ");
        scanf("%s", tasks[*numTasks].description);

        tasks[*numTasks].completed = false;
        (*numTasks)++;
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("A lista de tarefas est� cheia. N�o � poss�vel adicionar mais tarefas.\n");
    }
}

// Fun��o para marcar uma tarefa como conclu�da e remov�-la
void completeTask(struct Task tasks[], int *numTasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < *numTasks) {
        tasks[taskIndex].completed = true;
        printf("Tarefa '%s' marcada como conclu�da e removida da lista.\n", tasks[taskIndex].name);

        // Remova a tarefa movendo as tarefas restantes para preencher o espa�o vazio.
        for (int i = taskIndex; i < (*numTasks - 1); i++) {
            strcpy(tasks[i].name, tasks[i + 1].name);
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }

        (*numTasks)--;
    } else {
        printf("�ndice de tarefa inv�lido.\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    struct Task tasks[100];
    int numTasks = 0;

    // Exemplo de como adicionar tarefas
    addTask(tasks, &numTasks);
    addTask(tasks, &numTasks);

    // Exemplo de como exibir tarefas
    for (int i = 0; i < numTasks; i++) {
        printf("Tarefa #%d:\n", i + 1);
        printf("Nome: %s\n", tasks[i].name);
        printf("Descri��o: %s\n", tasks[i].description);
        printf("Status: %s\n", tasks[i].completed ? "Conclu�da" : "N�o conclu�da");
    }

    // Exemplo de como marcar uma tarefa como conclu�da e remov�-la
    completeTask(tasks, &numTasks, 0); // Marcar a primeira tarefa como conclu�da

    return 0;
}

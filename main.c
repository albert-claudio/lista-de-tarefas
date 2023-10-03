#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>


//DEIFININDO UMA ESTRUTURA DE TAREFA PARA RE
 struct Task {
    char description [100];
    char name [200];
    bool completed;
    int i;
 };

 void addTask(struct Task tasks[], int *numTasks, const char *name, const char *description) {
    if (*numTasks < 100){
        strcpy(tasks[*numTasks].name, name);
        strcpy(tasks[*numTasks].description, description);
        tasks[*numTasks].completed = false;
        (*numTasks)++;
        printf("Tarefa adiconada com sucesso!\n");
    }else{
        printf("A lista esta cheia. Tire algo para esvaziar!\n");
    }


}
    
//FUNÇÃO PARA MARCAR UMA TAREFA COMO CONCLUIDA E REMOVÊ-LA
void completeTaks(struct Task tasks[], int *numTasks, int taksIndex) {
    if (taksIndex >= 0 && taksIndex <*numTasks) {
        tasks[taksIndex].completed = true;
        printf("Tarefa '%s' marcada como concluída e removida da lista.\n", tasks[taksIndex].name);

        //REMOVA A TAREFA MOVENDO AS TAREFAS RESTANTES PARA PREENCHER O ESPAÇO VAZIO.
        for (int i = taksIndex; i < *numTasks - 1; i++) {
            strcpy(tasks[i].name, tasks[i + 1].name);
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }
        (*numTasks)--;
    }else{
        printf("Indice de tarefa inavalida.\n",);
    }
    
}

int main(){
    setlocale(LC_ALL, "portuguese");
    struct Task tasks[100];
    int numTasks = 0;
    
    //EXEMPLO DE COMO ADICIONAR TAREFAS
    addTask(tasks, &numTasks, "Tarefa 1", "Descrição 1");
    addTask(tasks, &numTasks, "Tarefa 2", "Descrição 2");
    addTask(tasks, &numTasks, "Tarefa 3", "Descrição 3");
    addTask(tasks, &numTasks, "Tarefa 4", "Descrição 4");
    addTask(tasks, &numTasks, "Tarefa 5", "Descrição 5");
    addTask(tasks, &numTasks, "Tarefa 6", "Descrição 6");
    addTask(tasks, &numTasks, "Tarefa 7", "Descrição 7");
    addTask(tasks, &numTasks, "Tarefa 8", "Descrição 8");


    //EXEMPLO DE COMO EXEBIR TAREFAS
    for (int i = 0; i < numTasks; i++) {
        char foidaci[20] = tasks[i].completed? "Concluida" : "Não Concluida";
        char karaio[20] = tasks[i].description;
        char buceta[20] = tasks[i].name;
        printf("Tarefa #%d:\n", );
        printf("Nome: %s\n", buceta);
        printf("Descrição: %s\n", karaio);
        printf("Status: %s\n\n", foidaci);
    }

    //EXEMPLO DE COMO MARCAR UMA TAREFA COMO CONCLUIDA E REMOVÊ-LA
    completeTaks(tasks, &numTasks, 0); //MARCAR A PRIMEIRA TAREFA COMO CONCUÍDA


    return 0;
}   
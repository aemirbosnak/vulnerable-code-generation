//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define STACK_SIZE 4096

typedef struct task {
    char *name;
    void (*func)(void);
    int stack[STACK_SIZE];
} Task;

void run_task(Task *t) {
    printf("Running task %s...\n", t->name);
    t->func();
    printf("Task %s completed.\n", t->name);
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task name (or type 'exit' to finish): ");
        char input[256];
        fgets(input, 256, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        tasks[num_tasks].name = strdup(input);
        printf("Enter task function: ");
        tasks[num_tasks].func = (void (*)(void))atoi(fgets(input, 256, stdin));

        num_tasks++;
    }

    for (int i = 0; i < num_tasks; i++) {
        printf("Starting task %s...\n", tasks[i].name);
        pid_t pid = fork();

        if (pid == -1) {
            printf("Failed to fork task %s.\n", tasks[i].name);
        } else if (pid == 0) {
            run_task(&tasks[i]);
            exit(0);
        }
    }

    for (int i = 0; i < num_tasks; i++) {
        waitpid(0, NULL, 0);
    }

    return 0;
}
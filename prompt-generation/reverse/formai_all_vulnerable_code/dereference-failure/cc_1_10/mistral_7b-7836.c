//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[50];
    int priority;
    int status;
    struct Task *next;
} Task;

Task *task_list = NULL;
int num_tasks = 0;

void add_task(char *name, int priority) {
    Task *new_task = (Task *) malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->status = 0;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
        num_tasks++;
    } else {
        Task *current = task_list;
        while (current->next != NULL && current->next->priority > priority) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;
        num_tasks++;
    }
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    int pid = fork();
    if (pid == 0) {
        execlp(strtok(task->name, " "), strtok(task->name, " "), NULL);
        perror("Error executing task");
        exit(1);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        task->status = WIFEXITED(status) ? WEXITSTATUS(status) : WTERMSIG(status);
    } else {
        perror("Error forking process");
    }
}

void schedule() {
    Task *current = task_list;
    while (current != NULL) {
        if (current->status == 0) {
            execute_task(current);
            num_tasks--;
        }
        current = current->next;
    }
}

int main() {
    add_task("ls", 2);
    add_task("cat file.txt", 1);
    add_task("wc file.txt", 3);
    add_task("grep pattern file.txt", 5);

    while (num_tasks > 0) {
        schedule();
        sleep(1);
    }

    return 0;
}
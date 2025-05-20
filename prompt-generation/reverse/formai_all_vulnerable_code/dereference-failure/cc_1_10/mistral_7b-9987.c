//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

struct task {
    pid_t pid;
    char name[TASK_NAME_LENGTH];
    struct task *next;
};

struct task_list {
    struct task *head;
    int num_tasks;
};

void print_task_list(struct task_list *task_list) {
    struct task *current = task_list->head;
    printf("Task List:\n");
    while (current != NULL) {
        printf("%s (PID: %d)\n", current->name, current->pid);
        current = current->next;
    }
}

void add_task(struct task_list *task_list, char *task_name) {
    struct task *new_task = malloc(sizeof(struct task));
    strcpy(new_task->name, task_name);
    new_task->next = task_list->head;
    task_list->head = new_task;
    task_list->num_tasks++;
}

void execute_task(struct task *task) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process runs the task
        setsid();
        char task_name[TASK_NAME_LENGTH];
        strcpy(task_name, task->name);
        execlp("/bin/sh", "sh", "-c", task_name, NULL);
        perror("Error executing task");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process waits for child to finish
        int status;
        waitpid(pid, &status, 0);
        task->pid = pid;
    } else {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
}

void run_tasks(struct task_list *task_list) {
    if (task_list->num_tasks == 0) {
        printf("No tasks to run\n");
        return;
    }

    while (task_list->num_tasks > 0) {
        execute_task(task_list->head);
        struct task *current = task_list->head;
        task_list->head = task_list->head->next;
        free(current);
        task_list->num_tasks--;
    }
}

int main() {
    struct task_list task_list = {NULL, 0};

    add_task(&task_list, "task1");
    add_task(&task_list, "task2");
    add_task(&task_list, "task3");

    print_task_list(&task_list);
    printf("Running tasks...\n");
    run_tasks(&task_list);

    return 0;
}
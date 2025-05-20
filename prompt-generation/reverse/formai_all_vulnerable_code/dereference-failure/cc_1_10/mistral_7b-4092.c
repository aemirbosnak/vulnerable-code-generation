//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 32
#define MAX_ARGUMENTS 5

typedef struct Task {
    char name[MAX_NAME_LENGTH];
    pid_t pid;
    struct Task *next;
} Task;

Task *tasks = NULL;
Task *head = NULL;
Task *tail = NULL;

int circularQueue[MAX_TASKS];
int front = 0;
int rear = -1;

void addTask(char *name, char *arguments[]) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    strcpy(newTask->name, name);

    for (int i = 0; i < MAX_ARGUMENTS && arguments[i] != NULL; i++) {
        strcat(newTask->name, " ");
        strcat(newTask->name, arguments[i]);
    }

    newTask->next = NULL;

    if (rear == MAX_TASKS - 1) {
        rear = -1;
    }

    if (tail == NULL) {
        head = newTask;
        tail = newTask;
    } else {
        tail->next = newTask;
        tail = newTask;
    }

    circularQueue[++rear] = rear;
}

void executeTasks() {
    int index = front;

    while (index != rear || tasks != NULL) {
        if (tasks == NULL || circularQueue[index] == -1) {
            index = (index + 1) % MAX_TASKS;
            continue;
        }

        Task *task = tasks;
        tasks = tasks->next;

        pid_t pid = fork();

        if (pid == 0) {
            execlp(task->name, task->name, (char *)0);
            perror("Error executing task");
            exit(1);
        }

        wait(NULL);

        free(task);

        index = (index + 1) % MAX_TASKS;
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        char taskName[MAX_NAME_LENGTH];
        char *arguments[MAX_ARGUMENTS];

        if (i % 2 == 0) {
            sprintf(taskName, "echo %s", "Hello World");
            arguments[0] = "echo";
            arguments[1] = "Hello";
            arguments[2] = "World";
        } else {
            sprintf(taskName, "sleep %d", rand() % 5 + 1);
            arguments[0] = "sleep";
            arguments[1] = NULL;
        }

        addTask(taskName, arguments);
    }

    executeTasks();

    while (tasks != NULL) {
        Task *task = tasks;
        tasks = tasks->next;
        free(task);
    }

    return 0;
}
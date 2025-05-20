//FormAI DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INTERVAL 1000

typedef struct Task {
    char* name;
    int delay;
    void (*function)(void);
    struct Task *next;
} Task;

Task *head = NULL;

void addTask(char *name, int delay, void (*function)(void)) {
    Task *newTask = (Task*) malloc(sizeof(Task));
    newTask->name = name;
    newTask->delay = delay;
    newTask->function = function;
    newTask->next = head;
    head = newTask;
}

void removeTask(Task *task) {
    if (head == task) {
        head = head->next;
        free(task);
        return;
    }
    Task *current = head;
    while (current != NULL && current->next != task) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    current->next = current->next->next;
    free(task);

}

void executeTasks() {
    Task *current = head;
    while (current != NULL) {
        if (current->delay >= INTERVAL) {
            current->delay -= INTERVAL;
        } else {
            current->function();
            removeTask(current);
        }
        current = current->next;
    }
}

void taskA() {
    printf("Executing Task A...\n");
    //Do something
}

void taskB() {
    printf("Executing Task B...\n");
    //Do something
}

void taskC() {
    printf("Executing Task C...\n");
    //Do something
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        int delay = rand() % 15 + 1;
        char *name;
        switch (rand() % 3) {
            case 0:
                name = "Task A";
                addTask(name, delay * INTERVAL, taskA);
                break;
            case 1:
                name = "Task B";
                addTask(name, delay * INTERVAL, taskB);
                break;
            case 2:
                name = "Task C";
                addTask(name, delay * INTERVAL, taskC);
                break;
            default:
                break;
        }
    }

    while (head != NULL) {
        executeTasks();
        printf("\n");
    }

    return 0;
}
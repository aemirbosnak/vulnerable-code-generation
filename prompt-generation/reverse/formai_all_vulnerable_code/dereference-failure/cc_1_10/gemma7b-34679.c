//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task** head) {
    time_t now = time(NULL);
    Task* currentTask = *head;

    while (currentTask) {
        if (now >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* scheduler = NULL;

    addTask(&scheduler, "Task A", 5);
    addTask(&scheduler, "Task B", 3);
    addTask(&scheduler, "Task C", 2);
    addTask(&scheduler, "Task D", 4);

    scheduleTasks(&scheduler);

    return 0;
}
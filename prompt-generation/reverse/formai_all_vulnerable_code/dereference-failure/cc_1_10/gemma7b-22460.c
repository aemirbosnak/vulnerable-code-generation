//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* currentTask = *head;
        while (currentTask->next) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void scheduleTasks(Task** head) {
    time_t now = time(NULL);
    Task* currentTask = *head;
    while (currentTask) {
        if (currentTask->priority == now) {
            printf("Executing task: %s\n", currentTask->name);
            currentTask = currentTask->next;
        } else if (currentTask->priority < now) {
            printf("Task: %s completed.\n", currentTask->name);
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task** head = NULL;

    insertTask(head, "Task 1", 10);
    insertTask(head, "Task 2", 5);
    insertTask(head, "Task 3", 2);
    insertTask(head, "Task 4", 7);

    scheduleTasks(head);

    return 0;
}
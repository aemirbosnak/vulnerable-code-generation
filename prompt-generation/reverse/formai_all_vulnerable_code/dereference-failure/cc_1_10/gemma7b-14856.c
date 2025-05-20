//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

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
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (currentTask->priority < now) {
            printf("Task: %s, completed at: %s\n", currentTask->name, asctime(localtime(&now)));
            free(currentTask);
            currentTask = NULL;
        } else {
            currentTask = currentTask->next;
        }
    }

    printf("All tasks completed.\n");
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 5);
    insertTask(&head, "Task 2", 3);
    insertTask(&head, "Task 3", 2);
    insertTask(&head, "Task 4", 4);

    scheduleTasks(head);

    return 0;
}
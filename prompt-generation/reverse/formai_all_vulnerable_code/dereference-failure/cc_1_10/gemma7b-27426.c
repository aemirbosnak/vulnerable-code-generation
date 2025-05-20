//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int executionTime;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int executionTime) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->executionTime = executionTime;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

void executeTasks(Task* head) {
    time_t currentTime = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (currentTime >= currentTask->executionTime) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(currentTask->executionTime);
            currentTask = currentTask->next;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task* head = NULL;
    insertTask(&head, "Task 1", 1, 5);
    insertTask(&head, "Task 2", 2, 3);
    insertTask(&head, "Task 3", 1, 2);
    insertTask(&head, "Task 4", 2, 4);

    executeTasks(head);

    return 0;
}
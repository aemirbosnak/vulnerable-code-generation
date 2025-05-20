//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[50];
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
    time_t currentTime = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (currentTime >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(2);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;
    insertTask(&head, "Task 1", 5);
    insertTask(&head, "Task 2", 3);
    insertTask(&head, "Task 3", 7);
    insertTask(&head, "Task 4", 2);
    insertTask(&head, "Task 5", 4);

    scheduleTasks(head);

    return 0;
}
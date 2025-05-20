//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    int execution_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int execution_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->execution_time = execution_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* currentTask = *head;
        while (currentTask->next != NULL) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (currentTask->execution_time <= now) {
            printf("Task: %s, Priority: %d, Execution Time: %d seconds\n", currentTask->name, currentTask->priority, currentTask->execution_time);
            currentTask->execution_time += 10;
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, 5);
    insertTask(&head, "Task 2", 2, 10);
    insertTask(&head, "Task 3", 3, 15);
    insertTask(&head, "Task 4", 4, 20);
    insertTask(&head, "Task 5", 5, 25);

    scheduleTasks(head);

    return 0;
}
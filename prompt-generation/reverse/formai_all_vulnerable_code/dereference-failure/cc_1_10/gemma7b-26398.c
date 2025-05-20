//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: innovative
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
    time_t currentTime = time(NULL);
    Task* currentTask = *head;

    while (currentTask) {
        if (currentTime >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            // Simulate task execution
            sleep(2);
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* scheduler = NULL;

    insertTask(&scheduler, "Task 1", 10);
    insertTask(&scheduler, "Task 2", 5);
    insertTask(&scheduler, "Task 3", 15);
    insertTask(&scheduler, "Task 4", 2);

    scheduleTasks(&scheduler);

    return 0;
}
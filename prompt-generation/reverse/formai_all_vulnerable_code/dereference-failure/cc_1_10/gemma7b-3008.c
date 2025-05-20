//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: real-life
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
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task** head) {
    time_t currentTime = time(NULL);
    Task* currentTask = *head;

    while (currentTask) {
        time_t taskTime = currentTime + currentTask->priority;
        if (taskTime <= currentTime) {
            printf("Executing task: %s\n", currentTask->name);
            currentTask->next = (*head)->next;
            free(currentTask);
            *head = (*head)->next;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task* scheduler = NULL;

    insertTask(&scheduler, "Task 1", 5);
    insertTask(&scheduler, "Task 2", 3);
    insertTask(&scheduler, "Task 3", 7);
    insertTask(&scheduler, "Task 4", 2);

    scheduleTasks(&scheduler);

    return 0;
}
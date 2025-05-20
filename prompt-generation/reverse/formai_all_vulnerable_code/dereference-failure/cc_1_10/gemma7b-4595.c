//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: scientific
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
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* tail = *head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newTask;
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
            printf("Task %s has already passed.\n", currentTask->name);
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* scheduler = NULL;

    insertTask(&scheduler, "Task A", 10);
    insertTask(&scheduler, "Task B", 5);
    insertTask(&scheduler, "Task C", 2);
    insertTask(&scheduler, "Task D", 7);

    scheduleTasks(&scheduler);

    return 0;
}
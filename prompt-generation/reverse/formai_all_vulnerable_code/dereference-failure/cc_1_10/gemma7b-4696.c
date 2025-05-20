//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: imaginative
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
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        int taskTime = now + currentTask->priority;

        if (taskTime <= now) {
            printf("Executing task: %s\n", currentTask->name);
            currentTask->next = head;
            free(currentTask);
            currentTask = head;
        } else {
            currentTask = currentTask->next;
        }
    }

    printf("No tasks to execute\n");
}

int main() {
    Task* scheduler = NULL;

    insertTask(&scheduler, "Wash dishes", 3);
    insertTask(&scheduler, "Do laundry", 2);
    insertTask(&scheduler, "Clean the bathroom", 4);
    insertTask(&scheduler, "Mop the floor", 1);

    scheduleTasks(scheduler);

    return 0;
}
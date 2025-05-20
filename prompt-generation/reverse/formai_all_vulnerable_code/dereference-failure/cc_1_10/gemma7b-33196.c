//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    struct Task *next;
} Task;

void insertTask(Task **head, char *name, int priority) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task *tail = *head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newTask;
    }
}

void scheduleTasks(Task *head) {
    time_t now = time(NULL);
    Task *currentTask = head;

    while (currentTask) {
        if (now >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(1);
            printf("Task %s completed.\n", currentTask->name);
            free(currentTask);
            currentTask = NULL;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task *scheduler = NULL;

    insertTask(&scheduler, "Paint the living room", 10);
    insertTask(&scheduler, "Clean the kitchen", 8);
    insertTask(&scheduler, "Water the plants", 6);
    insertTask(&scheduler, "Do laundry", 4);
    insertTask(&scheduler, "Buy groceries", 2);

    scheduleTasks(scheduler);

    return 0;
}
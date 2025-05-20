//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int start_time;
    int end_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int start_time, int end_time) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task** head) {
    time_t now = time(NULL);
    Task* currentTask = *head;

    while (currentTask) {
        if (now >= currentTask->start_time && now < currentTask->end_time) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(currentTask->end_time - now);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, 10, 20);
    insertTask(&head, "Task 2", 2, 15, 25);
    insertTask(&head, "Task 3", 3, 20, 30);

    scheduleTasks(&head);

    return 0;
}
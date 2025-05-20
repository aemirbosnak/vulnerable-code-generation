//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
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

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (now >= currentTask->start_time && now < currentTask->end_time) {
            printf("%s is running...\n", currentTask->name);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, time(NULL) + 60, time(NULL) + 120);
    insertTask(&head, "Task 2", 2, time(NULL) + 90, time(NULL) + 150);
    insertTask(&head, "Task 3", 3, time(NULL) + 120, time(NULL) + 180);

    scheduleTasks(head);

    return 0;
}
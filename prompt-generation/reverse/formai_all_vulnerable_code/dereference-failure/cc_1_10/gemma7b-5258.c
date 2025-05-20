//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority) {
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
        time_t taskTime = now + currentTask->priority;
        if (taskTime >= now) {
            printf("Task: %s, Time: %ld\n", currentTask->name, taskTime);
            sleep(currentTask->priority);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 5);
    addTask(&head, "Task 2", 2);
    addTask(&head, "Task 3", 3);

    scheduleTasks(head);

    return 0;
}
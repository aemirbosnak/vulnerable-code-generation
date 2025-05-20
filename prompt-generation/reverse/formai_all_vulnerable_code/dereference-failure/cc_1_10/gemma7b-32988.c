//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int state;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->state = 0;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newTask;
    }
}

void scheduleTask(int seconds) {
    time_t now = time(NULL);
    time_t then = now + seconds;

    Task* current = head;
    while (current) {
        if (current->state == 0 && current->priority == 1) {
            printf("Task: %s, Start time: %ld\n", current->name, then);
            current->state = 1;
        }
        current = current->next;
    }
}

int main() {
    addTask("Task 1", 1);
    addTask("Task 2", 2);
    addTask("Task 3", 1);
    addTask("Task 4", 2);

    scheduleTask(5);

    return 0;
}
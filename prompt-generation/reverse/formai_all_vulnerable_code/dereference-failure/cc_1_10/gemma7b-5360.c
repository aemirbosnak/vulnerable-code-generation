//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, int priority) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_task;
    }
}

void schedule_tasks() {
    time_t now = time(NULL);
    Task* current_task = head;

    while (current_task) {
        if (current_task->priority < now) {
            printf("Executing task: %s\n", current_task->name);
            sleep(current_task->priority);
            current_task->priority = time(NULL);
        }
        current_task = current_task->next;
    }
}

int main() {
    add_task("Task 1", 5);
    add_task("Task 2", 2);
    add_task("Task 3", 4);
    add_task("Task 4", 3);

    schedule_tasks();

    return 0;
}
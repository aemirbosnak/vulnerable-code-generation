//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Task {
    char* name;
    int priority;
    struct Task* next;
} Task;

Task* head = NULL;

void schedule_task(char* name, int priority) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->next = head;
    head = new_task;
}

void print_tasks() {
    Task* current = head;
    while (current!= NULL) {
        printf("%s - Priority: %d\n", current->name, current->priority);
        current = current->next;
    }
}

void delete_task(char* name) {
    Task* current = head;
    Task* previous = NULL;
    while (current!= NULL && strcmp(current->name, name)!= 0) {
        previous = current;
        current = current->next;
    }
    if (current!= NULL) {
        if (previous == NULL) {
            head = current->next;
            free(current);
        } else {
            previous->next = current->next;
            free(current);
        }
    }
}

int main() {
    schedule_task("Clean the Castle", 5);
    schedule_task("Feed the Horses", 3);
    schedule_task("Train the Squires", 1);
    schedule_task("Defend the Castle", 4);
    print_tasks();
    delete_task("Train the Squires");
    print_tasks();
    delete_task("Defend the Castle");
    print_tasks();
    return 0;
}
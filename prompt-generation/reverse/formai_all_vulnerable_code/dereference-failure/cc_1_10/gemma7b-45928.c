//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task** head, char* name, int priority) {
    Task* newTask = createTask(name, priority);
    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newTask;
    }
}

void scheduleTasks(Task** head) {
    time_t now = time(NULL);
    Task* current = *head;
    while (current) {
        if (current->priority < now) {
            printf("%s is running\n", current->name);
            current = current->next;
        } else {
            printf("%s is waiting\n", current->name);
        }
    }
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 5);
    addTask(&head, "Task 2", 3);
    addTask(&head, "Task 3", 2);
    addTask(&head, "Task 4", 4);

    scheduleTasks(&head);

    return 0;
}
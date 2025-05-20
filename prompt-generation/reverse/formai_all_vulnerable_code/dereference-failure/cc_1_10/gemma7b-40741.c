//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* CreateTask(char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

void AddTask(Task* head, Task* newTask) {
    if (head == NULL) {
        head = newTask;
    } else {
        newTask->next = head;
        head = newTask;
    }
}

void ScheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (now >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(2); // Simulate execution time
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;
    AddTask(head, CreateTask("Task A", 5));
    AddTask(head, CreateTask("Task B", 3));
    AddTask(head, CreateTask("Task C", 7));
    AddTask(head, CreateTask("Task D", 2));

    ScheduleTasks(head);

    return 0;
}
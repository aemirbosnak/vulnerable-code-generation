//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

Task* task_create(char* name, int priority, int time_slot) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->time_slot = time_slot;
    new_task->next = NULL;
    return new_task;
}

void task_add(Task* head, Task* new_task) {
    if (head == NULL) {
        head = new_task;
    } else {
        new_task->next = head;
        head = new_task;
    }
}

void task_print(Task* head) {
    while (head) {
        printf("%s (priority: %d, time slot: %d)\n", head->name, head->priority, head->time_slot);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    // Create some tasks
    Task* task1 = task_create("Task 1", 1, 1);
    Task* task2 = task_create("Task 2", 2, 2);
    Task* task3 = task_create("Task 3", 3, 3);

    // Add tasks to the scheduler
    task_add(head, task1);
    task_add(head, task2);
    task_add(head, task3);

    // Print the scheduled tasks
    task_print(head);

    return 0;
}
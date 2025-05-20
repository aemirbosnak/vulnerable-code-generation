//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int execution_time;
    struct Task* next;
} Task;

void insert_task(Task* head, char* name, int priority, int execution_time) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* last_task = head;
        while (last_task->next) {
            last_task = last_task->next;
        }
        last_task->next = new_task;
    }
}

void print_tasks(Task* head) {
    Task* current_task = head;
    while (current_task) {
        printf("Name: %s, Priority: %d, Execution Time: %d\n", current_task->name, current_task->priority, current_task->execution_time);
        current_task = current_task->next;
    }
}

void execute_task(Task* head) {
    Task* current_task = head;
    while (current_task) {
        printf("Executing task: %s\n", current_task->name);
        sleep(current_task->execution_time);
        current_task = current_task->next;
    }
}

int main() {
    Task* head = NULL;
    insert_task(head, "Task 1", 1, 5);
    insert_task(head, "Task 2", 3, 2);
    insert_task(head, "Task 3", 2, 3);
    insert_task(head, "Task 4", 4, 4);

    print_tasks(head);

    execute_task(head);

    return 0;
}
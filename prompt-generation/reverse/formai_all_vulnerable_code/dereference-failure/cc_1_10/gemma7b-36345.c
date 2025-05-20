//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_execution_time;
    struct Task* next;
} Task;

void scheduler_add_task(Task** head, char* name, int priority, int estimated_execution_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_execution_time = estimated_execution_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        Task* current_task = *head;
        while (current_task->next) {
            current_task = current_task->next;
        }
        current_task->next = new_task;
    }
}

void scheduler_print_tasks(Task* head) {
    Task* current_task = head;
    while (current_task) {
        printf("%s (priority: %d, estimated execution time: %d)\n", current_task->name, current_task->priority, current_task->estimated_execution_time);
        current_task = current_task->next;
    }
}

void scheduler_execute_tasks(Task* head) {
    Task* current_task = head;
    while (current_task) {
        printf("Executing task: %s\n", current_task->name);
        sleep(current_task->estimated_execution_time);
        current_task = current_task->next;
    }
}

int main() {
    Task* head = NULL;
    scheduler_add_task(&head, "Task 1", 1, 5);
    scheduler_add_task(&head, "Task 2", 2, 3);
    scheduler_add_task(&head, "Task 3", 1, 2);
    scheduler_print_tasks(head);
    scheduler_execute_tasks(head);
    return 0;
}
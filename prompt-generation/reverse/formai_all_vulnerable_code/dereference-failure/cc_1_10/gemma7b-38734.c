//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int execution_time;
    struct Task* next;
} Task;

void scheduler_add(Task** head, char* name, int priority, int execution_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void scheduler_sort(Task** head) {
    Task* current = *head;
    Task* next = NULL;

    while (current) {
        next = current->next;
        while (next) {
            if (current->priority > next->priority) {
                int temp_priority = current->priority;
                current->priority = next->priority;
                next->priority = temp_priority;

                char temp_name[20];
                strcpy(temp_name, current->name);
                strcpy(current->name, next->name);
                strcpy(next->name, temp_name);

                int temp_execution_time = current->execution_time;
                current->execution_time = next->execution_time;
                next->execution_time = temp_execution_time;
            }
        }
        current = next;
    }
}

int main() {
    Task* head = NULL;

    scheduler_add(&head, "Task 1", 3, 5);
    scheduler_add(&head, "Task 2", 2, 3);
    scheduler_add(&head, "Task 3", 1, 2);
    scheduler_add(&head, "Task 4", 4, 4);

    scheduler_sort(&head);

    Task* current = head;
    while (current) {
        printf("Name: %s, Priority: %d, Execution Time: %d\n", current->name, current->priority, current->execution_time);
        current = current->next;
    }

    return 0;
}
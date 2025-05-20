//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

void insert_task(Task** head, char* name, int priority, int time_slot) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->time_slot = time_slot;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        Task* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void print_schedule(Task* head) {
    while (head) {
        printf("%s (priority: %d, time slot: %d)\n", head->name, head->priority, head->time_slot);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    insert_task(&head, "Task 1", 1, 10);
    insert_task(&head, "Task 2", 2, 12);
    insert_task(&head, "Task 3", 3, 14);
    insert_task(&head, "Task 4", 4, 16);

    print_schedule(head);

    return 0;
}
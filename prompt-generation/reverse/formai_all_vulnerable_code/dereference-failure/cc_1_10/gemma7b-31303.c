//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

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
        (*head)->next = new_task;
    }
}

void print_tasks(Task* head) {
    while (head) {
        printf("%s (priority: %d, time slot: %d)\n", head->name, head->priority, head->time_slot);
        head = head->next;
    }
}

void schedule_tasks(Task* head) {
    time_t now = time(NULL);
    int current_slot = now / 60;

    while (head) {
        if (head->time_slot == current_slot) {
            printf("Executing task: %s\n", head->name);
            head = head->next;
        }
    }
}

int main() {
    Task* head = NULL;

    insert_task(&head, "Macheath's Market Stall", 3, 1);
    insert_task(&head, "The Blacksmith's Forge", 2, 2);
    insert_task(&head, "The Weaver's Loom", 4, 3);
    insert_task(&head, "The Carpenter's Workshop", 1, 4);

    print_tasks(head);

    schedule_tasks(head);

    return 0;
}
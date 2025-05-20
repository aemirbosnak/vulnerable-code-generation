//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int time_slot;
    struct Task* next;
} Task;

void add_task(Task** head, char* name, int time_slot) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
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
        printf("%s (%d) ", head->name, head->time_slot);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Task* head = NULL;

    // Add some tasks
    add_task(&head, "Task 1", 8);
    add_task(&head, "Task 2", 10);
    add_task(&head, "Task 3", 12);

    // Print the tasks
    print_tasks(head);

    // Schedule the tasks
    time_t now = time(NULL);
    for (Task* task = head; task; task = task->next) {
        if (now >= task->time_slot) {
            printf("Executing task: %s\n", task->name);
        }
    }

    return 0;
}
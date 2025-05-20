//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    int id;
    int deadline;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(int id, int deadline) {
    Task *new_task = (Task *) malloc(sizeof(Task));
    new_task->id = id;
    new_task->deadline = deadline;
    new_task->next = head;
    head = new_task;
}

void delete_task(int id) {
    Task *current = head;
    Task *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void schedule() {
    time_t now = time(NULL);
    Task *current = head;

    while (current != NULL) {
        if (current->deadline <= now) {
            printf("Task %d with deadline %d is due!\n", current->id, current->deadline);
            delete_task(current->id);
        } else {
            current = current->next;
        }
    }
}

int main() {
    int choice, id, deadline;

    while (1) {
        printf("\n1. Add task\n2. Cancel task\n3. Schedule tasks\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task ID: ");
                scanf("%d", &id);
                printf("Enter deadline (in days): ");
                scanf("%d", &deadline);
                add_task(id, deadline * 24 * 60 * 60);
                break;
            case 2:
                printf("Enter task ID to cancel: ");
                scanf("%d", &id);
                delete_task(id);
                break;
            case 3:
                schedule();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
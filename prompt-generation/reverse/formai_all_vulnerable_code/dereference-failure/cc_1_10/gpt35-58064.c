//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char name[50];
    int priority;
    int time; // time in seconds
    int executed; // 1 if executed, else 0
} Task;

typedef struct Node {
    Task task;
    struct Node *next;
} Node;

Node *ready_queue = NULL;
Node *completed_queue = NULL;

void add_task() {
    Task task;
    printf("Enter task name: ");
    scanf("%s", task.name);
    printf("Enter task priority (1 highest, 5 lowest): ");
    scanf("%d", &task.priority);
    printf("Enter task time in seconds: ");
    scanf("%d", &task.time);
    task.executed = 0;

    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->task = task;
    new_node->next = NULL;

    if (ready_queue == NULL) {
        ready_queue = new_node;
        return;
    }

    // Insert in ready queue based on priority
    Node *current = ready_queue;
    Node *prev = NULL;

    while (current != NULL && current->task.priority >= task.priority) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        ready_queue = new_node;
    } else {
        prev->next = new_node;
    }
    new_node->next = current;

    printf("Task added to ready queue.\n");
}

void execute_task() {
    if (ready_queue == NULL) {
        printf("Ready queue is empty.\n");
        return;
    }

    Node *current = ready_queue;
    ready_queue = ready_queue->next;
    current->next = NULL;

    current->task.executed = 1;
    printf("Executing task %s for %d seconds.\n", current->task.name, current->task.time);
    sleep(current->task.time);

    if (completed_queue == NULL) {
        completed_queue = current;
        return;
    }

    // Add to completed queue based on execution order (FIFO)
    Node *temp = completed_queue;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = current;
    printf("Task %s completed.\n", current->task.name);
}

void display_queues() {
    printf("Ready Queue: ");
    Node *current = ready_queue;
    while (current != NULL) {
        printf("[%s, %d, %d]", current->task.name, current->task.priority, current->task.time);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");

    printf("Completed Queue: ");
    current = completed_queue;
    while (current != NULL) {
        printf("[%s, %d, %d]", current->task.name, current->task.priority, current->task.time);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void clear_queues() {
    Node *current = ready_queue;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    current = completed_queue;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    ready_queue = NULL;
    completed_queue = NULL;
    printf("Queues cleared.\n");
}


int main() {
    int choice;

    printf("Welcome to the Task Scheduler!\n");

    do {
        printf("\n1. Add Task\n2. Execute Task\n3. Display Queues\n4. Clear Queues\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task();
                break;

            case 2:
                execute_task();
                break;

            case 3:
                display_queues();
                break;

            case 4:
                clear_queues();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
//FormAI DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int id;
    char description[50];
    int priority;
    int execute_time;
} Task;

typedef struct node {
    Task task;
    struct node* next;
} Node;

Node* start = NULL;
Node* finish = NULL;

void print_tasks() {
    Node* current = start;
    while (current != NULL) {
        printf("Task ID: %d\n", current->task.id);
        printf("Task Description: %s\n", current->task.description);
        printf("Task Priority: %d\n", current->task.priority);
        printf("Task Execution Time: %d\n", current->task.execute_time);
        current = current->next;
    }
}

void add_task(Task new_task) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->task = new_task;
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
        finish = new_node;
    }
    else {
        finish->next = new_node;
        finish = new_node;
    }
}

void execute_task(Task task) {
    printf("Executing Task %d: %s\n", task.id, task.description);
    printf("Task Priority: %d\n", task.priority);
    printf("Task Execution Time: %d seconds\n", task.execute_time);
    printf("---------------\n");

    // Simulate execution time with sleep()
    sleep(task.execute_time);
}

void delete_task(int id) {
    Node* current = start;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->task.id == id) {
            if (current == start) {
                start = current->next;
            }
            else if (current == finish) {
                finish = previous;
                finish->next = NULL;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("Task %d has been deleted\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Task %d not found\n", id);
}

int main() {
    // Seed random number generator for random execution times
    srand(time(0));

    // Create tasks and add them to scheduler
    Task task1 = { 1, "Send email to John", 2, rand() % 10 + 1 };
    Task task2 = { 2, "Finish project proposal", 3, rand() % 10 + 1 };
    Task task3 = { 3, "Call client", 1, rand() % 10 + 1 };
    add_task(task1);
    add_task(task2);
    add_task(task3);

    // Print tasks in scheduler
    printf("Current Tasks in Scheduler:\n");
    print_tasks();

    // Execute tasks in order of priority
    for (int i = 1; i <= 3; i++) {
        Node* current = start;
        Node* highest_priority = NULL;

        // Find highest priority task
        while (current != NULL) {
            if (current->task.priority == i) {
                if (highest_priority == NULL || current->task.execute_time < highest_priority->task.execute_time) {
                    highest_priority = current;
                }
            }
            current = current->next;
        }

        // Execute highest priority task
        if (highest_priority != NULL) {
            execute_task(highest_priority->task);
            delete_task(highest_priority->task.id);
        }
    }

    // Print tasks in scheduler after execution
    printf("Remaining Tasks in Scheduler:\n");
    print_tasks();

    return 0;
}
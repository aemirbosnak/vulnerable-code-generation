//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRIORITY 10

typedef struct {
    int priority;
    char *task_name;
} Task;

typedef struct Node {
    Task task;
    struct Node *next;
} Node;

Node *head = NULL;

void add_task(char *task_name, int priority) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->task.priority = priority;
    new_node->task.task_name = strdup(task_name);
    new_node->next = head;
    head = new_node;
}

void execute_tasks() {
    Node *current = head;
    while (current != NULL) {
        printf("Executing task %s with priority %d\n", current->task.task_name, current->task.priority);
        free(current->task.task_name);
        Node *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    add_task("Task1", 5);
    add_task("Task2", 3);
    add_task("Task3", 8);
    add_task("Task4", 1);
    add_task("Task5", 6);

    printf("Executing tasks in the order of priority:\n");
    execute_tasks();

    return 0;
}
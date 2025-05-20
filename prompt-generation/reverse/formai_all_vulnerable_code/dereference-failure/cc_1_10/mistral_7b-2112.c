//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Task structure definition
typedef struct {
    char *name;
    int priority;
    int (*function)();
    struct Task *next;
} Task;

// Function prototype for tasks
int TaskA();
int TaskB();
int TaskC();

// Global variables
Task *head = NULL;
int num_tasks = 0;

// Function to create a new task
Task *create_task(char *name, int priority, int (*function)()) {
    Task *new_task = (Task *) malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->function = function;
    new_task->next = NULL;
    return new_task;
}

// Function to add a new task to the list
void add_task(Task *new_task) {
    if (head == NULL) {
        head = new_task;
        num_tasks++;
    } else {
        Task *current = head;
        while (current->next != NULL) {
            if (current->priority > new_task->priority) {
                new_task->next = current;
                head = new_task;
                num_tasks++;
                break;
            }
            current = current->next;
        }
        if (current->next == NULL) {
            current->next = new_task;
            num_tasks++;
        }
    }
}

// Function to execute the task list
void execute_tasks() {
    Task *current = head;
    while (current != NULL) {
        printf("Executing task '%s' with priority %d...\n", current->name, current->priority);
        int result = (current->function)();
        printf("Task '%s' completed with result %d\n", current->name, result);
        current = current->next;
        free(current->name);
        free(current);
        num_tasks--;
    }
}

// Main function
int main() {
    // Define tasks
    Task *task_a = create_task("Task A", 3, &TaskA);
    Task *task_b = create_task("Task B", 5, &TaskB);
    Task *task_c = create_task("Task C", 1, &TaskC);

    // Add tasks to the list
    add_task(task_a);
    add_task(task_b);
    add_task(task_c);

    // Execute the task list
    execute_tasks();

    // Free memory
    while (head != NULL) {
        Task *current = head;
        head = head->next;
        free(current->name);
        free(current);
    }

    return 0;
}

// Task functions
int TaskA() {
    sleep(1);
    return 42;
}

int TaskB() {
    sleep(2);
    return 7;
}

int TaskC() {
    sleep(3);
    return 13;
}
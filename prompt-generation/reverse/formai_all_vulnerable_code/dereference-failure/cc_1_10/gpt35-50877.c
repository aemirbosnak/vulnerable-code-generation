//FormAI DATASET v1.0 Category: Task Scheduler ; Style: introspective
/* This program implements a unique task scheduler using a linked-list based queue system.
 * Tasks are stored in the queue and a task is executed every second.
 * The program also allows users to add new tasks to the scheduler at runtime.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// Define task structure
typedef struct Task {
    char* name;
    int priority;
    int duration;
    struct Task* next;
} Task;

// Declare functions
void add_task(Task** head, char* name, int priority, int duration);
void execute_task(Task** head);
void print_tasks(Task* head);
void free_tasks(Task** head);

int main() {
    Task* task_queue = NULL;  // Initialize queue of tasks
    char task_name[20];
    int priority, duration, choice;
    bool running = true;

    // Prompt user to add initial tasks to the scheduler
    printf("*** Welcome to the Task Scheduler! ***\n\n");
    while (running) {
        printf("Add a task to the scheduler:\n");
        printf("Task name: ");
        scanf("%s", task_name);
        printf("Priority (1-10): ");
        scanf("%d", &priority);
        printf("Duration (in seconds): ");
        scanf("%d", &duration);
        add_task(&task_queue, task_name, priority, duration);
        printf("\nTask added!\n");
        printf("1. Add another task\n");
        printf("2. Start the scheduler\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        if (choice != 1) {
            running = false;
        }
    }

    // Begin the scheduler loop
    printf("*** Starting the scheduler! ***\n");
    while (task_queue) {
        printf("\nExecuting next task...\n\n");
        execute_task(&task_queue);
        print_tasks(task_queue);
        sleep(1);
    }

    // Free memory and exit
    printf("\nAll tasks completed! Exiting...\n");
    free_tasks(&task_queue);
    return 0;
}

// Add a new task to the queue
void add_task(Task** head, char* name, int priority, int duration) {
    Task* new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->priority = priority;
    new_task->duration = duration;
    new_task->next = NULL;

    Task* current = *head;
    if (!current || priority > current->priority) {
        new_task->next = current;
        *head = new_task;
    }
    else {
        while (current->next && priority <= current->next->priority) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;
    }
}

// Execute the next task in the queue
void execute_task(Task** head) {
    Task* temp = (*head)->next;
    free(*head);
    *head = temp;
}

// Print all tasks currently in the queue
void print_tasks(Task* head) {
    printf("Tasks remaining in queue:\n");
    while (head) {
        printf("Task name: %s, Priority: %d, Duration: %d\n", head->name, head->priority, head->duration);
        head = head->next;
    }
}

// Free memory of all tasks in the queue
void free_tasks(Task** head) {
    Task* current = *head;
    while (current) {
        Task* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
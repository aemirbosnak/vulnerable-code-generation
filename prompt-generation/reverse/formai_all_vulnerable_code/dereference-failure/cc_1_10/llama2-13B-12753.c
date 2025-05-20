//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a task
typedef struct {
    char *name;
    void (*function)(void);
    struct task *next;
} task_t;

// Linked list to store tasks
task_t *task_list = NULL;

// Function to schedule a task
void schedule_task(task_t *task) {
    // Add the task to the end of the list
    task->next = task_list;
    task_list = task;

    // Recursively schedule the next task
    schedule_task(task->next);
}

// Example task functions
void task1(void) {
    printf("Task 1 is running\n");
    sleep(2);
    printf("Task 1 is finished\n");
}

void task2(void) {
    printf("Task 2 is running\n");
    sleep(3);
    printf("Task 2 is finished\n");
}

int main(void) {
    // Create a task list
    task_t *task1 = (task_t *)malloc(sizeof(task_t));
    task1->name = "Task 1";
    task1->function = task1;

    task_t *task2 = (task_t *)malloc(sizeof(task_t));
    task2->name = "Task 2";
    task2->function = task2;

    // Schedule the tasks
    schedule_task(task1);
    schedule_task(task2);

    // Wait for the tasks to finish
    while (task_list != NULL) {
        // Print the currently running task
        printf("Currently running task: %s\n", task_list->name);

        // Sleep for a short period of time to simulate work
        sleep(1);
    }

    return 0;
}
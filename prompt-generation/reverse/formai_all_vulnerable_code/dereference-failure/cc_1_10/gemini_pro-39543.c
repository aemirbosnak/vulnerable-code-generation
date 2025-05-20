//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 32

typedef struct task {
    char name[MAX_NAME_LENGTH];
    int priority;
    int execution_time;
    struct task *next;
} task_t;

task_t *head = NULL;
task_t *tail = NULL;

void add_task(char *name, int priority, int execution_time) {
    task_t *new_task = malloc(sizeof(task_t));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
        tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }
}

void print_tasks() {
    task_t *current = head;

    while (current != NULL) {
        printf("Task: %s, Priority: %d, Execution Time: %d\n", current->name, current->priority, current->execution_time);
        current = current->next;
    }
}

void schedule_tasks() {
    task_t *current = head;

    while (current != NULL) {
        // Execute the task
        printf("Executing task: %s\n", current->name);
        sleep(current->execution_time);

        // Remove the task from the list
        if (current == head) {
            head = current->next;
        } else {
            task_t *prev = head;
            while (prev->next != current) {
                prev = prev->next;
            }
            prev->next = current->next;
        }

        // Free the task
        free(current);

        // Move to the next task
        current = current->next;
    }
}

int main() {
    // Add some tasks to the scheduler
    add_task("Task 1", 1, 1);
    add_task("Task 2", 2, 2);
    add_task("Task 3", 3, 3);
    add_task("Task 4", 4, 4);
    add_task("Task 5", 5, 5);

    // Print the tasks
    print_tasks();

    // Schedule the tasks
    schedule_tasks();

    return 0;
}
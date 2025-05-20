//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TIME 1000

typedef struct task {
    char *name;
    int time;
    struct task *next;
} task_t;

task_t *head = NULL;
task_t *tail = NULL;

void add_task(char *name, int time) {
    task_t *new_task = malloc(sizeof(task_t));
    new_task->name = strdup(name);
    new_task->time = time;
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
        printf("%s %d\n", current->name, current->time);
        current = current->next;
    }
}

void run_tasks() {
    task_t *current = head;
    while (current != NULL) {
        // Run the task
        printf("Running task %s\n", current->name);
        sleep(current->time);

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
        free(current->name);
        free(current);

        // Move to the next task
        current = current->next;
    }
}

int main() {
    // Add some tasks
    add_task("Task 1", 10);
    add_task("Task 2", 20);
    add_task("Task 3", 30);

    // Print the tasks
    print_tasks();

    // Run the tasks
    run_tasks();

    return 0;
}
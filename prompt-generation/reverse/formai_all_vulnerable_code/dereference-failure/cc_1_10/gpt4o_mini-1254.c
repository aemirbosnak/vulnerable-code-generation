//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t execute_time;
    void (*task_function)(void);
} Task;

Task *task_list[MAX_TASKS];
int task_count = 0;

void example_task() {
    printf("Task executed at %ld\n", time(NULL));
}

void add_task(char *name, time_t execute_time, void (*task_function)(void)) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    Task *new_task = (Task *)malloc(sizeof(Task));
    strncpy(new_task->name, name, TASK_NAME_LENGTH);
    new_task->execute_time = execute_time;
    new_task->task_function = task_function;

    task_list[task_count++] = new_task;
    printf("Added task: %s to be executed at %s", new_task->name, ctime(&execute_time));
}

void execute_tasks() {
    time_t current_time;
    for (int i = 0; i < task_count; i++) {
        current_time = time(NULL);
        if (difftime(task_list[i]->execute_time, current_time) <= 0) {
            printf("Executing task: %s\n", task_list[i]->name);
            task_list[i]->task_function();
            free(task_list[i]);  // Free up memory after execution
            task_list[i] = NULL; // Mark as executed
        }
    }

    // Clean up NULL tasks
    for (int i = 0; i < task_count; i++) {
        if (task_list[i] == NULL) {
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--;
        }
    }
}

void display_tasks() {
    printf("Scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task: %s, Scheduled Time: %s", task_list[i]->name, ctime(&task_list[i]->execute_time));
    }
}

int main() {
    time_t t1, t2, t3;

    t1 = time(NULL) + 5; // Execute in 5 seconds
    t2 = time(NULL) + 10; // Execute in 10 seconds
    t3 = time(NULL) + 15; // Execute in 15 seconds

    add_task("Task 1", t1, example_task);
    add_task("Task 2", t2, example_task);
    add_task("Task 3", t3, example_task);

    while (task_count > 0) {
        execute_tasks();
        sleep(1); // Poll every second
    }

    printf("All tasks executed. Exiting...\n");
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char *name;
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task *next;
} Task;

Task *tasks = NULL;

void add_task(char *name, int priority, time_t start_time, time_t end_time) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = tasks;
    tasks = new_task;
}

void remove_task(char *name) {
    Task *prev = NULL;
    Task *task = tasks;
    while (task != NULL) {
        if (strcmp(task->name, name) == 0) {
            if (prev == NULL) {
                tasks = task->next;
            } else {
                prev->next = task->next;
            }
            free(task->name);
            free(task);
            return;
        }
        prev = task;
        task = task->next;
    }
}

void print_tasks() {
    Task *task = tasks;
    while (task != NULL) {
        printf("%s (%d): %s - %s\n", task->name, task->priority, ctime(&task->start_time), ctime(&task->end_time));
        task = task->next;
    }
}

int main() {
    add_task("Task 1", 1, time(NULL), time(NULL) + 3600);
    add_task("Task 2", 2, time(NULL) + 3600, time(NULL) + 7200);
    add_task("Task 3", 3, time(NULL) + 7200, time(NULL) + 10800);

    print_tasks();

    remove_task("Task 2");

    print_tasks();

    return 0;
}
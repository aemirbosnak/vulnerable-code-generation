//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    int execution_time;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(char *name, int priority, int execution_time) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_task;
    }
}

void execute_tasks() {
    Task *current_task = head;
    time_t now = time(NULL);

    while (current_task) {
        if (now >= current_task->execution_time) {
            printf("Executing task: %s\n", current_task->name);
            sleep(current_task->execution_time);
            current_task = current_task->next;
        } else {
            break;
        }
    }
}

int main() {
    add_task("Task 1", 1, 5);
    add_task("Task 2", 2, 3);
    add_task("Task 3", 1, 8);
    add_task("Task 4", 2, 2);

    execute_tasks();

    return 0;
}
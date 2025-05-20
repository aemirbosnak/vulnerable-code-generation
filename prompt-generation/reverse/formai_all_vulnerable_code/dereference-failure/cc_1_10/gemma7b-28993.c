//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 20

typedef struct Task {
    char name[20];
    int priority;
    time_t scheduled_time;
    struct Task* next;
} Task;

Task* head = NULL;

void schedule_task(char* name, int priority, time_t scheduled_time) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->scheduled_time = scheduled_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void check_schedule() {
    time_t now = time(NULL);
    Task* current = head;

    while (current) {
        if (now >= current->scheduled_time) {
            printf("Task: %s, completed!\n", current->name);
            free(current);
            current = head;
        } else {
            current = current->next;
        }
    }
}

int main() {
    schedule_task("Pay bills", 1, time(NULL) + 60 * 60);
    schedule_task("Do laundry", 2, time(NULL) + 60 * 30);
    schedule_task("Buy groceries", 3, time(NULL) + 60 * 15);

    check_schedule();

    return 0;
}
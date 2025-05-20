//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

Task* create_task(char* name, int priority, int estimated_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_time = estimated_time;
    new_task->next = NULL;
    return new_task;
}

void add_task(Task* head, Task* new_task) {
    if (head == NULL) {
        head = new_task;
    } else {
        new_task->next = head;
        head = new_task;
    }
}

void schedule_tasks(Task* head) {
    time_t now = time(NULL);
    int i = 0;
    for (Task* current_task = head; current_task; current_task = current_task->next) {
        int estimated_time = current_task->estimated_time;
        if (estimated_time - now >= 0) {
            printf("Task: %s, Priority: %d, Estimated Time: %d\n", current_task->name, current_task->priority, estimated_time);
            i++;
        }
    }

    if (i == 0) {
        printf("No tasks are scheduled.\n");
    }
}

int main() {
    Task* head = NULL;
    add_task(head, create_task("Task 1", 1, 10));
    add_task(head, create_task("Task 2", 2, 20));
    add_task(head, create_task("Task 3", 3, 30));

    schedule_tasks(head);

    return 0;
}
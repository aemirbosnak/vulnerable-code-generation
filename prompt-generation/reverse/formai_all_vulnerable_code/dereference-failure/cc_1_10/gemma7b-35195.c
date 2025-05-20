//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* scheduler_insert(Task* head, char* name, int priority) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_task;
    }

    return head;
}

void scheduler_execute(Task* head) {
    while (head) {
        printf("Executing task: %s (priority: %d)\n", head->name, head->priority);
        sleep(head->priority);
        head = head->next;
    }
}

int main() {
    Task* scheduler = NULL;

    scheduler = scheduler_insert(scheduler, "Task 1", 3);
    scheduler = scheduler_insert(scheduler, "Task 2", 2);
    scheduler = scheduler_insert(scheduler, "Task 3", 4);
    scheduler = scheduler_insert(scheduler, "Task 4", 1);

    scheduler_execute(scheduler);

    return 0;
}
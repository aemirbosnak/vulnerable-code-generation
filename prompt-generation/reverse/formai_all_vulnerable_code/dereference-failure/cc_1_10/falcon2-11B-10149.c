//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_TASK_COUNT 1000

typedef struct Task {
    char name[20];
    struct Task *next;
    int start_time;
    int end_time;
} Task;

Task *new_task(char *name, int start_time, int end_time) {
    Task *task = (Task *) malloc(sizeof(Task));
    strcpy(task->name, name);
    task->next = NULL;
    task->start_time = start_time;
    task->end_time = end_time;
    return task;
}

void print_tasks(Task *head) {
    if (head == NULL) {
        return;
    }
    printf("%s %d %d\n", head->name, head->start_time, head->end_time);
    print_tasks(head->next);
}

void schedule_tasks(Task *head) {
    if (head == NULL) {
        return;
    }
    printf("%s %d %d\n", head->name, head->start_time, head->end_time);
    schedule_tasks(head->next);
}

int main() {
    srand(time(NULL));

    Task *head = NULL;

    for (int i = 0; i < MAX_TASK_COUNT; i++) {
        char name[20];
        int start_time = rand() % 1000;
        int end_time = rand() % 1000;
        sprintf(name, "Task %d", i+1);
        Task *task = new_task(name, start_time, end_time);

        if (head == NULL) {
            head = task;
        } else {
            Task *curr = head;
            while (curr->next!= NULL) {
                curr = curr->next;
            }
            curr->next = task;
        }
    }

    print_tasks(head);
    schedule_tasks(head);

    return 0;
}
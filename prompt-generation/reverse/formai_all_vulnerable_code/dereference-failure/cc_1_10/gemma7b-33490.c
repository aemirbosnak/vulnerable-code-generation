//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    int estimated_time;
    struct task* next;
} task;

void add_task(task** head, char* name, int priority, int estimated_time) {
    task* new_task = malloc(sizeof(task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_time = estimated_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void print_tasks(task* head) {
    while (head) {
        printf("%s (priority %d, estimated time %d)\n", head->name, head->priority, head->estimated_time);
        head = head->next;
    }
}

void schedule_tasks(task* head) {
    time_t now = time(NULL);
    int i = 0;

    printf("Scheduled tasks for today:\n");

    for (head = head; head; head = head->next) {
        int estimated_time = head->estimated_time;
        int time_diff = estimated_time - now;

        if (time_diff > 0) {
            printf("%s will start in %d minutes.\n", head->name, time_diff / 60);
        } else {
            printf("%s is already started.\n", head->name);
        }
    }
}

int main() {
    task* head = NULL;

    add_task(&head, "Do homework", 3, 60);
    add_task(&head, "Buy groceries", 2, 30);
    add_task(&head, "Clean the house", 1, 90);

    print_tasks(head);

    schedule_tasks(head);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    int status;
    struct task* next;
} task_t;

void add_task(task_t** head, char* name, int priority) {
    task_t* new_task = malloc(sizeof(task_t));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->status = 0;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void print_tasks(task_t* head) {
    while (head) {
        printf("%s (priority: %d, status: %d)\n", head->name, head->priority, head->status);
        head = head->next;
    }
}

void execute_tasks(task_t* head) {
    while (head) {
        if (head->status == 0) {
            printf("Executing task: %s\n", head->name);
            sleep(head->priority);
            head->status = 1;
        }
        head = head->next;
    }
}

int main() {
    task_t* head = NULL;

    add_task(&head, "Task 1", 3);
    add_task(&head, "Task 2", 2);
    add_task(&head, "Task 3", 4);
    add_task(&head, "Task 4", 1);

    print_tasks(head);

    execute_tasks(head);

    print_tasks(head);

    return 0;
}
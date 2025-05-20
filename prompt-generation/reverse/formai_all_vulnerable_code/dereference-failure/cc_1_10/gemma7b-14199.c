//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASK_NUMBER 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

void add_task(Task** head) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    printf("Enter task name: ");
    scanf("%s", new_task->name);
    printf("Enter task priority (1-5): ");
    scanf("%d", &new_task->priority);
    printf("Enter task estimated time (in minutes): ");
    scanf("%d", &new_task->estimated_time);
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void display_tasks(Task* head) {
    while (head) {
        printf("Task name: %s\n", head->name);
        printf("Task priority: %d\n", head->priority);
        printf("Task estimated time: %d minutes\n", head->estimated_time);
        printf("\n");
        head = head->next;
    }
}

void schedule_tasks(Task* head) {
    time_t now = time(NULL);
    for (Task* current_task = head; current_task; current_task = current_task->next) {
        time_t estimated_time = now + current_task->estimated_time * 60;
        printf("Task name: %s\n", current_task->name);
        printf("Estimated time of completion: %s\n", asctime(localtime(estimated_time)));
        printf("\n");
    }
}

int main() {
    Task* head = NULL;
    add_task(&head);
    add_task(&head);
    add_task(&head);
    display_tasks(head);
    schedule_tasks(head);

    return 0;
}
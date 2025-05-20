//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_execution_time;
    struct Task* next;
} Task;

void insert_task(Task** head, char* name, int priority, int estimated_execution_time) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_execution_time = estimated_execution_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void schedule_tasks(Task* head) {
    time_t now = time(NULL);
    int i = 0;

    while (head) {
        if (head->estimated_execution_time >= now) {
            printf("Task: %s, Priority: %d, Estimated Execution Time: %d\n", head->name, head->priority, head->estimated_execution_time);
            now = head->estimated_execution_time;
            i++;
        }
        head = head->next;
    }

    printf("Total tasks scheduled: %d\n", i);
}

int main() {
    Task* head = NULL;

    insert_task(&head, "Task 1", 1, 10);
    insert_task(&head, "Task 2", 2, 20);
    insert_task(&head, "Task 3", 3, 30);
    insert_task(&head, "Task 4", 4, 40);

    schedule_tasks(head);

    return 0;
}
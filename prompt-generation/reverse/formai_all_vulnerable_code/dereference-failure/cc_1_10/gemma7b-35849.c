//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <time.h>

#define NUM_TASKS 5

struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
};

void add_task(struct Task** head, char* name, int priority, int estimated_time) {
    struct Task* new_task = malloc(sizeof(struct Task));
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

void schedule_tasks(struct Task* head) {
    struct Task* current_task = head;
    time_t now = time(NULL);

    while (current_task) {
        int estimated_time = current_task->estimated_time;
        int remaining_time = estimated_time - (now - current_task->estimated_time);

        if (remaining_time > 0) {
            printf("%s is running. Estimated completion time: %d minutes.\n", current_task->name, remaining_time);
        } else {
            printf("%s is complete.\n", current_task->name);
        }

        current_task = current_task->next;
    }
}

int main() {
    struct Task* head = NULL;

    add_task(&head, "Task 1", 1, 30);
    add_task(&head, "Task 2", 3, 20);
    add_task(&head, "Task 3", 2, 10);
    add_task(&head, "Task 4", 4, 40);
    add_task(&head, "Task 5", 1, 25);

    schedule_tasks(head);

    return 0;
}
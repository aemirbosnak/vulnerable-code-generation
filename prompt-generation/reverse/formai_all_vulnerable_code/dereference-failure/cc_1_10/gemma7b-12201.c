//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASK_NUMBER 10

typedef struct task_node {
    char name[20];
    int priority;
    struct task_node* next;
} task_node;

task_node* head = NULL;

void add_task(char* name, int priority) {
    task_node* new_task = (task_node*)malloc(sizeof(task_node));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        task_node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void schedule_tasks() {
    time_t now = time(NULL);
    task_node* current = head;

    while (current) {
        if (now >= current->priority) {
            printf("Task: %s, completed at: %ld\n", current->name, now);
            free(current);
            current = NULL;
        } else {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No tasks are scheduled.\n");
    }
}

int main() {
    add_task("Wash dishes", 10);
    add_task("Do laundry", 8);
    add_task("Clean the kitchen", 6);
    add_task("Sweep the floor", 4);
    add_task("Vacuum the carpet", 2);

    schedule_tasks();

    return 0;
}
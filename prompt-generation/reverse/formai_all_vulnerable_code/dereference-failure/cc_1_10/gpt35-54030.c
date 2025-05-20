//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef void (*func_ptr)();

typedef struct task {
    int id;
    int delay;
    int priority;
    func_ptr task_func;
    struct task *next;
} Task;

Task *root = NULL; 

void insert_task(int id, int delay, int priority, func_ptr task_func) {
    Task *new_task = (Task*)malloc(sizeof(Task));
    new_task->id = id;
    new_task->delay = delay;
    new_task->priority = priority;
    new_task->task_func = task_func;
    new_task->next = NULL;
    if (root == NULL) {
        root = new_task;
    } else {
        Task *temp = root;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_task;
    }
}

void schedule() {
    int tick = 0;
    Task *prev = NULL;
    Task *curr = root;
    while(curr != NULL) {
        if (curr->delay == tick) {
            printf("Executing Task %d, with priority %d\n", curr->id, curr->priority);
            if (curr == root) {
                root = curr->next;
                curr->task_func();
                free(curr);
                curr = root;
                continue;
            } else {
                prev->next = curr->next;
                curr->task_func();
                free(curr);
                curr = prev->next;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
        tick++;
    }
}

void task1() {
    printf("Running task 1\n");
}

void task2() {
    printf("Running task 2\n");
}

int main() {
    insert_task(1, 2, 1, task1);
    insert_task(2, 5, 2, task2);
    insert_task(3, 3, 3, task1);
    insert_task(4, 4, 1, task2);
    insert_task(5, 1, 2, task1);
    schedule();
    return 0;
}
//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_TASKS 5
#define TASK_DELAY 2

struct task_t {
    char name[20];
    int (*func)(int);
    int delay;
    struct task_t* next;
};

void add_task(struct task_t** head, char* name, int delay, int (*func)(int)) {
    struct task_t* new_task = malloc(sizeof(struct task_t));
    strcpy(new_task->name, name);
    new_task->func = func;
    new_task->delay = delay;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void run_tasks(struct task_t* head) {
    time_t start_time = time(NULL);
    struct task_t* current = head;

    while (current) {
        time_t current_time = time(NULL);
        if (current_time - start_time >= current->delay) {
            current->func(current->delay);
            start_time = current_time;
        }
        current = current->next;
    }
}

int task_one(int delay) {
    printf("Task One has started, waiting for %d seconds...\n", delay);
    sleep(delay);
    printf("Task One has completed!\n");
    return 0;
}

int task_two(int delay) {
    printf("Task Two has started, waiting for %d seconds...\n", delay);
    sleep(delay);
    printf("Task Two has completed!\n");
    return 0;
}

int main() {
    struct task_t* tasks = NULL;

    add_task(&tasks, "Task One", TASK_DELAY, task_one);
    add_task(&tasks, "Task Two", TASK_DELAY, task_two);
    add_task(&tasks, "Task Three", TASK_DELAY, task_one);
    add_task(&tasks, "Task Four", TASK_DELAY, task_two);
    add_task(&tasks, "Task Five", TASK_DELAY, task_one);

    run_tasks(tasks);

    return 0;
}
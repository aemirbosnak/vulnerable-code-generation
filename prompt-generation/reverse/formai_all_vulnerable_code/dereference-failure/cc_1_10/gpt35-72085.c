//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct task {
    int id;
    char description[100];
    int priority;
    int frequency; // in seconds
    time_t last_run; // time of last run
    void (*func)();
} Task;

void task_hello_world() {
    printf("Hello, World!\n");
}

void task_print_time() {
    time_t current_time = time(NULL);
    printf("Current time is: %s", ctime(&current_time));
}

Task* create_task(int id, char* description, int priority, int frequency, void (*func)()) {
    Task* task = (Task*) malloc(sizeof(Task));
    task->id = id;
    sprintf(task->description, "%s", description);
    task->priority = priority;
    task->frequency = frequency;
    task->last_run = time(NULL);
    task->func = func;
    return task;
}

bool should_run(Task* task, time_t current_time) {
    return (difftime(current_time, task->last_run) >= task->frequency);
}

void run_task(Task* task) {
    printf("Running Task %d: %s\n", task->id, task->description);
    task->func();
    task->last_run = time(NULL);
}

int cmpfunc(const void* a, const void* b) {
    Task* task_a = *(Task**)a;
    Task* task_b = *(Task**)b;
    if (task_a->priority < task_b->priority) {
        return -1;
    } else if (task_a->priority > task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Task* task1 = create_task(1, "Say Hello World", 2, 5, &task_hello_world);
    Task* task2 = create_task(2, "Print Time", 1, 10, &task_print_time);
    Task* task3 = create_task(3, "Say Hello World Again", 2, 10, &task_hello_world);
    Task* task4 = create_task(4, "Print Time Again", 1, 20, &task_print_time);

    Task* tasks[] = {task1, task2, task3, task4};
    int num_tasks = 4;
    time_t start_time = time(NULL);

    while (true) {
        qsort(tasks, num_tasks, sizeof(Task*), cmpfunc);
        time_t current_time = time(NULL);
        for (int i = 0; i < num_tasks; i++) {
            Task* task = tasks[i];
            if (should_run(task, current_time)) {
                run_task(task);
            }
        }
        double elapsed_time = difftime(current_time, start_time);
        if (elapsed_time >= 60) {
            printf("Scheduler has been running for %d minutes. Exiting.\n", (int)elapsed_time / 60);
            break;
        }
    }

    for (int i = 0; i < num_tasks; i++) {
        free(tasks[i]);
    }

    return 0;
}
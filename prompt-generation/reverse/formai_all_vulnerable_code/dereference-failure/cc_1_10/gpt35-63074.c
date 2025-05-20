//FormAI DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define maximum number of tasks */
#define MAX_TASKS 10

/* Struct to represent a task */
typedef struct task {
    int id;
    int priority;
    int time;
    int executed;
} Task;

/* Function to generate a random integer between min and max */
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to initialize a task */
Task* init_task(int id, int priority, int time) {
    Task* new_task = malloc(sizeof(Task));
    new_task->id = id;
    new_task->priority = priority;
    new_task->time = time;
    new_task->executed = 0;
    return new_task;
}

/* Function to print a task */
void print_task(Task* task) {
    printf("Task %d | Priority: %d | Time: %d | Executed: %d\n",
           task->id, task->priority, task->time, task->executed);
}

/* Function to select the next task to execute based on priority */
Task* get_next_task(Task* tasks[MAX_TASKS], int num_tasks) {
    Task* next_task = NULL;
    int max_priority = -1;
    for (int i = 0; i < num_tasks; i++) {
        Task* task = tasks[i];
        if (!task->executed && task->priority > max_priority) {
            max_priority = task->priority;
            next_task = task;
        }
    }
    return next_task;
}

int main() {
    srand(time(NULL));
    int num_tasks = random_int(1, MAX_TASKS);
    Task* tasks[MAX_TASKS];
    printf("Generated %d tasks.\n", num_tasks);
    /* Populate array with random tasks */
    for (int i = 0; i < num_tasks; i++) {
        int priority = random_int(1, 10);
        int time = random_int(1, 10);
        tasks[i] = init_task(i+1, priority, time);
        print_task(tasks[i]);
    }
    printf("Running tasks...\n");
    int num_executed = 0;
    /* Execute tasks in order of priority */
    while (num_executed < num_tasks) {
        Task* next_task = get_next_task(tasks, num_tasks);
        if (next_task == NULL) {
            /* No executable tasks left */
            break;
        }
        next_task->executed = 1;
        print_task(next_task);
        num_executed++;
    }
    printf("Finished executing tasks.\n");
    /* Free memory */
    for (int i = 0; i < num_tasks; i++) {
        free(tasks[i]);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    char *name;
    int priority;
    int due_time;   // in msec
    int estimated_time; // in msec
    int remaining_time; // in msec
} Task;

Task *task_list[MAX_TASKS];
int num_tasks = 0;

// Add a new task to the task list
void add_task(int id, char *name, int priority, int due_time, int estimated_time) {
    Task *task = (Task *) malloc(sizeof(Task));
    task->id = id;
    task->name = name;
    task->priority = priority;
    task->due_time = due_time;
    task->estimated_time = estimated_time;
    task->remaining_time = estimated_time;
    task_list[num_tasks++] = task;
}

// Sort the task list based on priority (higher priority comes first)
void sort_tasks() {
    int i, j;
    Task *temp;
    for (i = 0; i < num_tasks; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (task_list[i]->priority < task_list[j]->priority) {
                temp = task_list[i];
                task_list[i] = task_list[j];
                task_list[j] = temp;
            }
        }
    }
}

// Execute a task for specified amount of time
void execute_task(Task *task, int time_ms) {
    printf("Task %s started...\n", task->name);
    task->remaining_time -= time_ms;
    if (task->remaining_time <= 0) {
        printf("Task %s completed.\n", task->name);
        num_tasks--;
        free(task);
    } else {
        printf("Task %s paused. Remaining time: %d msec\n", task->name, task->remaining_time);
    }
}

// Infinite loop that processes tasks based on their priority (higher priority first)
int main() {
    add_task(1, "Task 1", 3, 2000, 500); // priority 3, due in 2 sec, estimated time 500 ms
    add_task(2, "Task 2", 2, 1500, 1000); // priority 2, due in 1.5 sec, estimated time 1000 ms
    add_task(3, "Task 3", 1, 3000, 2000); // priority 1, due in 3 sec, estimated time 2000 ms
    
    while (num_tasks > 0) {
        sort_tasks();
        execute_task(task_list[0], 100); // execute the first task for 100 ms
    }
    
    return 0;
}
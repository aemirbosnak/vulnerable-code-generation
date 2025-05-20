//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Task struct
typedef struct {
    int id;
    int priority;
    int time_to_execute;
} Task;

// Task list struct
typedef struct {
    Task* tasks;
    int num_tasks;
} TaskList;

// Function that returns a TaskList with a given number of random tasks
TaskList generate_tasks(int num_tasks) {
    TaskList task_list;
    task_list.tasks = malloc(num_tasks * sizeof(Task));
    task_list.num_tasks = num_tasks;

    for (int i = 0; i < num_tasks; i++) {
        task_list.tasks[i].id = i;
        task_list.tasks[i].priority = rand() % 10 + 1; // Random priority from 1 to 10
        task_list.tasks[i].time_to_execute = rand() % 5 + 1; // Random time to execute from 1 to 5 seconds
    }

    return task_list;
}

// Function that takes in a TaskList and sorts the tasks by priority (highest to lowest)
void sort_tasks_by_priority(TaskList* task_list) {
    for (int i = 0; i < task_list->num_tasks - 1; i++) {
        for (int j = 0; j < task_list->num_tasks - i - 1; j++) {
            if (task_list->tasks[j].priority < task_list->tasks[j+1].priority) {
                Task temp = task_list->tasks[j];
                task_list->tasks[j] = task_list->tasks[j+1];
                task_list->tasks[j+1] = temp;
            }
        }
    }
}

// Function that executes a given task and returns the execution time in seconds
int execute_task(Task task) {
    printf("Executing task %d with priority %d for %d seconds...\n", task.id, task.priority, task.time_to_execute);
    clock_t start_time = clock();
    while ((double)(clock() - start_time) / CLOCKS_PER_SEC < task.time_to_execute);
    printf("Task %d completed.\n", task.id);
    return task.time_to_execute;
}

// Function that takes in a TaskList and executes the tasks in priority order
void run_tasks(TaskList task_list) {
    sort_tasks_by_priority(&task_list);
    int total_execution_time = 0;
    for (int i = 0; i < task_list.num_tasks; i++) {
        total_execution_time += execute_task(task_list.tasks[i]);
    }
    printf("All tasks completed. Total execution time: %d seconds.\n", total_execution_time);
}

int main() {
    srand(time(NULL));

    // Generate 10 random tasks
    TaskList task_list = generate_tasks(10);

    // Run the tasks in priority order
    run_tasks(task_list);

    // Free the memory allocated for the tasks
    free(task_list.tasks);

    return 0;
}
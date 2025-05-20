//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define struct for holding task information
typedef struct Task {
    int id;
    char name[50];
    int priority;
    int frequency;
    int last_executed;
} Task;

// Define struct for holding list of tasks
typedef struct TaskList {
    Task *tasks;
    int num_tasks;
    int max_tasks;
} TaskList;

// Function to initialize task list
TaskList* createTaskList(int max_tasks) {
    TaskList *task_list = malloc(sizeof(TaskList));
    task_list->tasks = malloc(sizeof(Task) * max_tasks);
    task_list->num_tasks = 0;
    task_list->max_tasks = max_tasks;
    return task_list;
}

// Function to add task to task list
bool addTask(TaskList *task_list, char name[], int priority, int frequency) {
    if (task_list->num_tasks == task_list->max_tasks) {
        printf("Task list is full.");
        return false;
    }
    Task *new_task = &(task_list->tasks[task_list->num_tasks]);
    new_task->id = task_list->num_tasks + 1;
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->frequency = frequency;
    new_task->last_executed = 0;
    task_list->num_tasks++;
    return true;
}

// Function to get current time in milliseconds
unsigned long long getTime() {
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return ((unsigned long long) tp.tv_sec * 1000) + (tp.tv_nsec / 1000000);
}

// Function to run tasks
void runTasks(TaskList *task_list) {
    for (int i = 0; i < task_list->num_tasks; i++) {
        Task *task = &(task_list->tasks[i]);
        unsigned long long current_time = getTime();
        if (current_time > task->last_executed + task->frequency) {
            printf("Running task #%d - %s\n", task->id, task->name);
            task->last_executed = current_time;
        }
    }
}

// Main function
int main() {
    TaskList *task_list = createTaskList(10);
    addTask(task_list, "Task 1", 1, 1000);
    addTask(task_list, "Task 2", 2, 2000);
    addTask(task_list, "Task 3", 3, 5000);
    addTask(task_list, "Task 4", 4, 10000);

    while (true) {
        runTasks(task_list);
    }
    return 0;
}
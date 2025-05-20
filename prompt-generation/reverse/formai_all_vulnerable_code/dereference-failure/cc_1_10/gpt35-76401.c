//FormAI DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a task struct that contains task name, function pointer, and the time interval
typedef struct Task {
    char* name;
    void (*task_func)(void);
    int interval;
    time_t last_execution_time;
} Task;

// Define the tasks
void task1() {
    printf("Task 1 executed! \n");
}

void task2() {
    printf("Task 2 executed! \n");
}

void task3() {
    printf("Task 3 executed! \n");
}

void task4() {
    printf("Task 4 executed! \n");
}

// Define the task scheduler
void task_scheduler(Task** tasks, int num_tasks) {
    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            time_t current_time = time(NULL);

            // Check if it's time for the task to execute
            if (difftime(current_time, tasks[i]->last_execution_time) >= tasks[i]->interval) {
                // Execute the task
                printf("Executing Task %d: %s \n", i+1, tasks[i]->name);
                (*tasks[i]->task_func)();

                // Update the last execution time
                tasks[i]->last_execution_time = time(NULL);
            }
        }
    }
}

int main() {
    // Create the tasks
    Task* task1_ptr = (Task*) malloc(sizeof(Task));
    task1_ptr->name = "Task 1";
    task1_ptr->task_func = task1;
    task1_ptr->interval = 2;
    task1_ptr->last_execution_time = time(NULL);

    Task* task2_ptr = (Task*) malloc(sizeof(Task));
    task2_ptr->name = "Task 2";
    task2_ptr->task_func = task2;
    task2_ptr->interval = 5;
    task2_ptr->last_execution_time = time(NULL);

    Task* task3_ptr = (Task*) malloc(sizeof(Task));
    task3_ptr->name = "Task 3";
    task3_ptr->task_func = task3;
    task3_ptr->interval = 10;
    task3_ptr->last_execution_time = time(NULL);

    Task* task4_ptr = (Task*) malloc(sizeof(Task));
    task4_ptr->name = "Task 4";
    task4_ptr->task_func = task4;
    task4_ptr->interval = 1;
    task4_ptr->last_execution_time = time(NULL);

    // Create an array of task pointers
    Task* tasks[4] = {task1_ptr, task2_ptr, task3_ptr, task4_ptr};

    // Start the task scheduler
    task_scheduler(tasks, 4);

    return 0;
}
//FormAI DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the maximum number of tasks to be scheduled
#define MAX_NUM_TASKS 10

/* Define the Task structure */
typedef struct task_t {
    int task_id; // Unique ID of the task
    int task_priority; // Priority of the task
    void (*function)(void*); // Function pointer to function that will be executed
    void* argument; // Argument for the function that will be executed
    int start_time; // The expected start time of the task
    int end_time; // The expected end time of the task
} Task;

/* Define the Task Scheduler structure */
typedef struct task_scheduler_t {
    Task tasks[MAX_NUM_TASKS]; // Array of tasks to be scheduled
    int num_tasks; // The number of tasks in the task list
    int current_time; // The current time of the task scheduler
} TaskScheduler;

/* Initialize a new Task Scheduler */
TaskScheduler* task_scheduler_init() {
    TaskScheduler* task_scheduler = (TaskScheduler*)malloc(sizeof(TaskScheduler));
    task_scheduler->num_tasks = 0;
    task_scheduler->current_time = 0;
    return task_scheduler;
}

/* Add a task to the Task Scheduler */
void task_scheduler_add_task(TaskScheduler* task_scheduler, Task task) {
    if (task_scheduler->num_tasks == MAX_NUM_TASKS) {
        printf("Max number of tasks reached!\n");
        return;
    }
    task_scheduler->tasks[task_scheduler->num_tasks] = task;
    task_scheduler->num_tasks++;
}

/* Execute the task */
void execute_task(Task task) {
    printf("Task with ID %d started executing.\n", task.task_id);
    task.function(task.argument);
    printf("Task with ID %d finished executing.\n", task.task_id);
}

/* Run the task scheduler */
void task_scheduler_run(TaskScheduler* task_scheduler) {
    printf("Task Scheduler started running.\n");
    while (task_scheduler->num_tasks > 0) {
        for (int i = 0; i < task_scheduler->num_tasks; i++) {
            if (task_scheduler->tasks[i].start_time <= task_scheduler->current_time) {
                execute_task(task_scheduler->tasks[i]);
                for (int j = i; j < task_scheduler->num_tasks - 1; j++) {
                    task_scheduler->tasks[j] = task_scheduler->tasks[j + 1];
                }
                task_scheduler->num_tasks--;
                i--;
            }
        }
        task_scheduler->current_time++;
        usleep(1000);
    }
    printf("Task Scheduler finished running.\n");
}

/* Destroy the Task Scheduler */
void task_scheduler_destroy(TaskScheduler* task_scheduler) {
    free(task_scheduler);
}

/* Sample function to be executed by the task */
void sample_function(void* argument) {
    int* num = (int*)argument;
    printf("Argument passed to task: %d\n", *num);
}

/* Sample main function to test the Task Scheduler */
int main() {
    /* Create a new Task Scheduler */
    TaskScheduler* task_scheduler = task_scheduler_init();
    
    /* Schedule some tasks */
    Task task1 = {1, 2, sample_function, (void*)malloc(sizeof(int)), 0, 2};
    *((int*)task1.argument) = 1;
    Task task2 = {2, 1, sample_function, (void*)malloc(sizeof(int)), 1, 4};
    *((int*)task2.argument) = 2;
    Task task3 = {3, 3, sample_function, (void*)malloc(sizeof(int)), 2, 6};
    *((int*)task3.argument) = 3;
    task_scheduler_add_task(task_scheduler, task1);
    task_scheduler_add_task(task_scheduler, task2);
    task_scheduler_add_task(task_scheduler, task3);
    
    /* Run the Task Scheduler */
    task_scheduler_run(task_scheduler);
    
    /* Destroy the Task Scheduler */
    task_scheduler_destroy(task_scheduler);
    
    return 0;
}
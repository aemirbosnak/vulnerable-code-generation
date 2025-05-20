//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Task structure
typedef struct {
    void (*func)(void);    // Function pointer
    time_t time;          // Execution time
} Task;

// Task queue
Task *task_queue = NULL;
int task_queue_count = 0;

// Task comparator function
int task_cmp(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;
    return task1->time - task2->time;
}

// Add a task to the queue
void add_task(void (*func)(void), time_t time) {
    // Allocate memory for the new task
    Task *new_task = malloc(sizeof(Task));
    new_task->func = func;
    new_task->time = time;

    // Add the new task to the queue
    task_queue = realloc(task_queue, sizeof(Task) * ++task_queue_count);
    task_queue[task_queue_count - 1] = *new_task;

    // Sort the task queue based on execution time
    qsort(task_queue, task_queue_count, sizeof(Task), task_cmp);
}

// Execute the tasks in the queue
void execute_tasks() {
    // Get the current time
    time_t now = time(NULL);

    // Iterate over the task queue
    for (int i = 0; i < task_queue_count; i++) {
        // If the task's execution time is less than or equal to the current time, execute it
        if (task_queue[i].time <= now) {
            // Execute the task
            task_queue[i].func();

            // Remove the task from the queue
            for (int j = i; j < task_queue_count - 1; j++) {
                task_queue[j] = task_queue[j + 1];
            }
            task_queue_count--;
        }
    }
}

// Example task functions
void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

void task3() {
    printf("Task 3 executed\n");
}

int main() {
    // Add tasks to the queue
    add_task(task1, time(NULL) + 1);
    add_task(task2, time(NULL) + 3);
    add_task(task3, time(NULL) + 5);

    // Execute the tasks
    while (task_queue_count > 0) {
        execute_tasks();
        sleep(1);
    }

    return 0;
}
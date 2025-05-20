//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Task structure
typedef struct task {
    void (*func)(void*);
    void* arg;
    time_t start_time;
    struct task* next;
} task_t;

// Task queue
task_t* head = NULL;
task_t* tail = NULL;

// Task scheduler
void task_scheduler() {
    while (head) {
        // Get the current task
        task_t* task = head;

        // Execute the task
        task->func(task->arg);

        // Remove the task from the queue
        head = head->next;
        free(task);
    }
}

// Add a task to the queue
void add_task(void (*func)(void*), void* arg, time_t start_time) {
    // Create a new task
    task_t* task = malloc(sizeof(task_t));
    task->func = func;
    task->arg = arg;
    task->start_time = start_time;
    task->next = NULL;

    // Add the task to the queue
    if (head == NULL) {
        head = task;
    } else {
        tail->next = task;
    }
    tail = task;
}

// Task 1: Print "Hello, world!"
void task1(void* arg) {
    printf("Hello, world!\n");
}

// Task 2: Print "Goodbye, world!"
void task2(void* arg) {
    printf("Goodbye, world!\n");
}

// Main function
int main() {
    // Add tasks to the queue
    add_task(task1, NULL, time(NULL));
    add_task(task2, NULL, time(NULL) + 5);

    // Start the task scheduler
    task_scheduler();

    return 0;
}
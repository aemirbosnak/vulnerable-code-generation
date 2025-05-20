//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_TASKS 10

// Task struct
typedef struct {
    int id;
    int delay;
    void (*func)(void*);
    void *args;
} Task;

// Task queue
static Task* task_queue[NUM_TASKS];
static int task_queue_head = 0;
static int task_queue_tail = 0;

// Task scheduler thread
static pthread_t scheduler_thread;

// Task scheduling function
static void* task_scheduler(void* args) {
    while (1) {
        // Check if the task queue is empty
        if (task_queue_head == task_queue_tail) {
            continue;
        }

        // Get the next task from the queue
        Task* task = task_queue[task_queue_head];

        // Increment the queue head
        task_queue_head = (task_queue_head + 1) % NUM_TASKS;

        // Sleep for the specified delay
        sleep(task->delay);

        // Call the task function
        task->func(task->args);

        // Free the task
        free(task);
    }

    return NULL;
}

// Task 1 function
static void task1(void* args) {
    printf("Task 1 running\n");
}

// Task 2 function
static void task2(void* args) {
    printf("Task 2 running\n");
}

// Task 3 function
static void task3(void* args) {
    printf("Task 3 running\n");
}

// Main function
int main() {
    // Create the task queue
    for (int i = 0; i < NUM_TASKS; i++) {
        task_queue[i] = NULL;
    }

    // Create the task scheduler thread
    pthread_create(&scheduler_thread, NULL, task_scheduler, NULL);

    // Add some tasks to the queue
    Task* task1 = malloc(sizeof(Task));
    task1->id = 1;
    task1->delay = 1;
    task1->func = task1;
    task1->args = NULL;
    task_queue[task_queue_tail] = task1;
    task_queue_tail = (task_queue_tail + 1) % NUM_TASKS;

    Task* task2 = malloc(sizeof(Task));
    task2->id = 2;
    task2->delay = 2;
    task2->func = task2;
    task2->args = NULL;
    task_queue[task_queue_tail] = task2;
    task_queue_tail = (task_queue_tail + 1) % NUM_TASKS;

    Task* task3 = malloc(sizeof(Task));
    task3->id = 3;
    task3->delay = 3;
    task3->func = task3;
    task3->args = NULL;
    task_queue[task_queue_tail] = task3;
    task_queue_tail = (task_queue_tail + 1) % NUM_TASKS;

    // Sleep for a while to let the tasks run
    sleep(10);

    // Exit the program
    return 0;
}
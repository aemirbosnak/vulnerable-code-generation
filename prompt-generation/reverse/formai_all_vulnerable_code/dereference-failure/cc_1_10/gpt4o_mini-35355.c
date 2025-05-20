//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

typedef struct Task {
    void (*function)(void); // Pointer to the task function
    int interval;           // Time interval in seconds
    time_t last_run;        // Last run timestamp
    struct Task* next;      // Pointer to the next task
} Task;

typedef struct Scheduler {
    Task* head;             // Head of the task list
    pthread_mutex_t mutex;  // Mutex for thread safety
} Scheduler;

// Function to create a new task
Task* create_task(void (*function)(void), int interval) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->function = function;
    new_task->interval = interval;
    new_task->last_run = time(NULL);
    new_task->next = NULL;
    return new_task;
}

// Function to add a task to the scheduler
void add_task(Scheduler* scheduler, Task* task) {
    pthread_mutex_lock(&scheduler->mutex);
    task->next = scheduler->head;
    scheduler->head = task;
    pthread_mutex_unlock(&scheduler->mutex);
}

// Function to execute scheduled tasks
void* execute_tasks(void* arg) {
    Scheduler* scheduler = (Scheduler*)arg;
    while (1) {
        pthread_mutex_lock(&scheduler->mutex);
        Task* current = scheduler->head;
        time_t now = time(NULL);
        while (current != NULL) {
            if (difftime(now, current->last_run) >= current->interval) {
                current->function();
                current->last_run = now;
            }
            current = current->next;
        }
        pthread_mutex_unlock(&scheduler->mutex);
        sleep(1);
    }
    return NULL;
}

// Sample task functions
void task_1() {
    printf("Task 1 executed at %ld\n", time(NULL));
}

void task_2() {
    printf("Task 2 executed at %ld\n", time(NULL));
}

void task_3() {
    printf("Task 3 executed at %ld\n", time(NULL));
}

// Main function
int main() {
    Scheduler scheduler;
    scheduler.head = NULL;
    pthread_mutex_init(&scheduler.mutex, NULL);

    // Create and add tasks to the scheduler
    add_task(&scheduler, create_task(task_1, 3)); // Every 3 seconds
    add_task(&scheduler, create_task(task_2, 5)); // Every 5 seconds
    add_task(&scheduler, create_task(task_3, 10)); // Every 10 seconds

    // Execute tasks in a separate thread
    pthread_t executor_thread;
    pthread_create(&executor_thread, NULL, execute_tasks, (void*)&scheduler);

    // Simulate the main application running
    while (1) {
        printf("Main application running... %ld\n", time(NULL));
        sleep(1);
    }

    // Cleanup (not reached in this example)
    pthread_cancel(executor_thread);
    pthread_join(executor_thread, NULL);
    pthread_mutex_destroy(&scheduler.mutex);
    
    // Free allocated tasks
    Task* current = scheduler.head;
    while (current != NULL) {
        Task* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
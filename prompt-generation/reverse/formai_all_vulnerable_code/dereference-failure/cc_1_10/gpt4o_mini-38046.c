//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TASKS 10
#define STACK_SIZE 4096

typedef struct {
    void (*function)(void);
    int interval; // in seconds
    int next_run; // in seconds (timestamp)
    int id; // task identifier
} Task;

Task* tasks[MAX_TASKS];
int task_count = 0;

sem_t semaphore;

void* task_scheduler(void* arg) {
    while (1) {
        sem_wait(&semaphore);
        time_t current_time = time(NULL);
        
        for (int i = 0; i < task_count; i++) {
            if (tasks[i] != NULL && current_time >= tasks[i]->next_run) {
                tasks[i]->function();
                tasks[i]->next_run = current_time + tasks[i]->interval;
            }
        }
        
        sem_post(&semaphore);
        sleep(1); // Sleep for a short time to avoid busy waiting
    }
    return NULL;
}

void add_task(void (*task_function)(void), int interval) {
    if (task_count < MAX_TASKS) {
        Task* new_task = (Task*)malloc(sizeof(Task));
        new_task->function = task_function;
        new_task->interval = interval;
        new_task->next_run = time(NULL) + interval;
        new_task->id = task_count;
        tasks[task_count++] = new_task;
        printf("Task %d added: runs every %d seconds.\n", new_task->id, new_task->interval);
    } else {
        printf("Max task limit reached. Cannot add more tasks.\n");
    }
}

void sample_task_1() {
    printf("Executing Task 1 at %ld\n", time(NULL));
}

void sample_task_2() {
    printf("Executing Task 2 at %ld\n", time(NULL));
}

void sample_task_3() {
    printf("Executing Task 3 at %ld\n", time(NULL));
}

void cleanup() {
    for (int i = 0; i < task_count; i++) {
        free(tasks[i]);
    }
    printf("All tasks cleaned up!\n");
}

int main() {
    // Initialize semaphore
    sem_init(&semaphore, 0, 1);

    // Create the scheduler thread
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, task_scheduler, NULL);

    // Add some example tasks
    add_task(sample_task_1, 2); // Runs every 2 seconds
    add_task(sample_task_2, 3); // Runs every 3 seconds
    add_task(sample_task_3, 5); // Runs every 5 seconds

    // Allow the scheduler to run for 30 seconds before cleanup
    sleep(30);
    
    // Cleanup
    cleanup();

    // Exit the scheduler thread
    pthread_cancel(scheduler_thread);
    pthread_join(scheduler_thread, NULL);
    
    // Destroy semaphore
    sem_destroy(&semaphore);
    
    return 0;
}
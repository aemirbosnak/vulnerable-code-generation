//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

typedef struct Task {
    char name[50];
    int interval; // in seconds
    int repeat; // number of times to repeat; -1 for infinite
    int elapsed_time; // time already executed
    struct Task* next;
} Task;

Task* head = NULL;
pthread_mutex_t lock;

void add_task(const char* name, int interval, int repeat) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strncpy(new_task->name, name, 50);
    new_task->interval = interval;
    new_task->repeat = repeat;
    new_task->elapsed_time = 0;
    new_task->next = NULL;

    pthread_mutex_lock(&lock);
    
    // Insert task at the head of the list
    new_task->next = head;
    head = new_task;
    
    pthread_mutex_unlock(&lock);
}

void* execute_task(void* arg) {
    Task* task = (Task*)arg;
    while (task->repeat != 0) {
        // Wait for the specified interval
        sleep(task->interval);
        
        // Execute the task
        pthread_mutex_lock(&lock);
        task->elapsed_time++;
        printf("Executing task: %s (executed %d times)\n", task->name, task->elapsed_time);
        
        // Update repeat count
        if (task->repeat > 0) {
            task->repeat--;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void start_scheduler() {
    Task* current_task = NULL;

    pthread_mutex_lock(&lock);
    current_task = head;
    pthread_mutex_unlock(&lock);

    while (current_task != NULL) {
        pthread_t thread;
        pthread_create(&thread, NULL, execute_task, (void*)current_task);
        pthread_detach(thread); // detach the thread to run independently
        current_task = current_task->next;
    }
}

void cleanup_tasks() {
    while (head != NULL) {
        Task* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    pthread_mutex_init(&lock, NULL);
    
    add_task("Task 1", 2, 5); // Run Task 1 every 2 seconds, for 5 times
    add_task("Task 2", 3, -1); // Run Task 2 every 3 seconds, indefinitely
    add_task("Task 3", 1, 10); // Run Task 3 every 1 second, for 10 times

    printf("Starting the task scheduler...\n");
    start_scheduler();

    // Run the scheduler for 30 seconds and then shutdown
    sleep(30);
    printf("Stopping the task scheduler...\n");

    cleanup_tasks();
    pthread_mutex_destroy(&lock);
    
    return 0;
}
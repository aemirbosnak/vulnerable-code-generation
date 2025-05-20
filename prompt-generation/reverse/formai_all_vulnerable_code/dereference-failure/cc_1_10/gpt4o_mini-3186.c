//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50
#define SCHEDULER_INTERVAL 1 // seconds

typedef struct {
    char name[MAX_NAME_LENGTH];
    int interval; 
    void (*task_function)(void);
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
    pthread_mutex_t lock;
    bool running;
} TaskScheduler;

void example_task_1() {
    printf("Executing Task 1: Time = %ld\n", time(NULL));
}

void example_task_2() {
    printf("Executing Task 2: Time = %ld\n", time(NULL));
}

void example_task_3() {
    printf("Executing Task 3: Time = %ld\n", time(NULL));
}

void scheduler_run(TaskScheduler *scheduler) {
    while (scheduler->running) {
        pthread_mutex_lock(&scheduler->lock);
        
        for (int i = 0; i < scheduler->task_count; i++) {
            static int counters[MAX_TASKS] = {0}; // static to retain state between calls

            counters[i]++;
            if (counters[i] % scheduler->tasks[i].interval == 0) {
                scheduler->tasks[i].task_function();
            }
        }
        
        pthread_mutex_unlock(&scheduler->lock);
        sleep(SCHEDULER_INTERVAL);
    }
}

void scheduler_add_task(TaskScheduler *scheduler, const char *name, int interval, void (*task_function)(void)) {
    pthread_mutex_lock(&scheduler->lock);

    if (scheduler->task_count < MAX_TASKS) {
        Task new_task;
        snprintf(new_task.name, MAX_NAME_LENGTH, "%s", name);
        new_task.interval = interval;
        new_task.task_function = task_function;

        scheduler->tasks[scheduler->task_count++] = new_task;
        printf("Added Task: %s with interval %d\n", new_task.name, new_task.interval);
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }

    pthread_mutex_unlock(&scheduler->lock);
}

void scheduler_remove_task(TaskScheduler *scheduler, const char *name) {
    pthread_mutex_lock(&scheduler->lock);
    
    for (int i = 0; i < scheduler->task_count; i++) {
        if (strncmp(scheduler->tasks[i].name, name, MAX_NAME_LENGTH) == 0) {
            printf("Removing Task: %s\n", scheduler->tasks[i].name);
            for (int j = i; j < scheduler->task_count - 1; j++) {
                scheduler->tasks[j] = scheduler->tasks[j + 1];
            }
            scheduler->task_count--;
            break;
        }
    }
    
    pthread_mutex_unlock(&scheduler->lock);
}

void scheduler_start(TaskScheduler *scheduler) {
    scheduler->running = true;
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, (void *(*)(void *))scheduler_run, (void *)scheduler);
}

void scheduler_stop(TaskScheduler *scheduler) {
    scheduler->running = false;
}

int main() {
    TaskScheduler scheduler = { .task_count = 0, .running = false };
    pthread_mutex_init(&scheduler.lock, NULL);

    scheduler_add_task(&scheduler, "Example Task 1", 1, example_task_1);
    scheduler_add_task(&scheduler, "Example Task 2", 2, example_task_2);
    scheduler_add_task(&scheduler, "Example Task 3", 3, example_task_3);

    scheduler_start(&scheduler);

    sleep(10); // Let tasks run for a while

    scheduler_stop(&scheduler);
    pthread_mutex_destroy(&scheduler.lock);

    printf("Scheduler stopped. Exiting program.\n");
    return 0;
}
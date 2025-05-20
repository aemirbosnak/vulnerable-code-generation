//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 50

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int interval; // Interval in seconds
    int duration; // Duration in seconds
    void (*task_function)(void);
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskScheduler;

void print_current_time() {
    time_t now;
    time(&now);
    printf("Current time: %s", ctime(&now));
}

void sample_task_1() {
    printf("Executing Task 1\n");
    print_current_time();
}

void sample_task_2() {
    printf("Executing Task 2\n");
    print_current_time();
}

void sample_task_3() {
    printf("Executing Task 3\n");
    print_current_time();
}

TaskScheduler* create_scheduler() {
    TaskScheduler *scheduler = (TaskScheduler *)malloc(sizeof(TaskScheduler));
    scheduler->task_count = 0;
    return scheduler;
}

int add_task(TaskScheduler *scheduler, char *name, int interval, int duration, void (*task_function)(void)) {
    if (scheduler->task_count >= MAX_TASKS) {
        printf("Task limit reached, cannot add more tasks.\n");
        return -1;
    }
    Task new_task;
    strncpy(new_task.name, name, MAX_TASK_NAME_LENGTH);
    new_task.interval = interval;
    new_task.duration = duration;
    new_task.task_function = task_function;
    
    scheduler->tasks[scheduler->task_count++] = new_task;
    return 0;
}

void* execute_tasks(void* arg) {
    TaskScheduler *scheduler = (TaskScheduler *)arg;

    while (1) {
        time_t start_time = time(NULL);
        
        for (int i = 0; i < scheduler->task_count; i++) {
            Task *task = &scheduler->tasks[i];
            printf("Checking Task: %s\n", task->name);
            if (frequency_reached(start_time, task->interval)) {
                task->task_function();

                sleep(task->duration); // Mimic work being done
            }
        }

        sleep(1); // Wait before checking again
    }
    return NULL;
}

int frequency_reached(time_t start_time, int interval) {
    return (time(NULL) - start_time) % interval == 0;
}

int main() {
    TaskScheduler *scheduler = create_scheduler();
    if (scheduler == NULL) {
        fprintf(stderr, "Failed to create scheduler.\n");
        return -1;
    }

    add_task(scheduler, "Task 1", 5, 2, sample_task_1);
    add_task(scheduler, "Task 2", 10, 3, sample_task_2);
    add_task(scheduler, "Task 3", 15, 1, sample_task_3);

    pthread_t scheduler_thread;
    if (pthread_create(&scheduler_thread, NULL, execute_tasks, (void *)scheduler)) {
        fprintf(stderr, "Error creating thread\n");
        return -1;
    }

    printf("Task Scheduler started.\n");
    pthread_join(scheduler_thread, NULL);
    
    free(scheduler);
    return 0;
}
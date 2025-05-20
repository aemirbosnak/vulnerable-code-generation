//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

// Define structure for task
typedef struct {
    char *name;
    int priority;
    int start_time;
    int end_time;
} Task;

// Define structure for task scheduler
typedef struct {
    Task *tasks;
    int num_tasks;
    pthread_mutex_t mutex;
} TaskScheduler;

TaskScheduler create_scheduler() {
    TaskScheduler scheduler;
    scheduler.tasks = NULL;
    scheduler.num_tasks = 0;
    pthread_mutex_init(&scheduler.mutex, NULL);
    return scheduler;
}

void destroy_scheduler(TaskScheduler *scheduler) {
    if (scheduler->tasks!= NULL) {
        free(scheduler->tasks);
    }
    pthread_mutex_destroy(&scheduler->mutex);
    free(scheduler);
}

void add_task(TaskScheduler *scheduler, char *name, int priority, int start_time, int end_time) {
    Task *task = (Task *)malloc(sizeof(Task));
    task->name = strdup(name);
    task->priority = priority;
    task->start_time = start_time;
    task->end_time = end_time;
    scheduler->tasks = realloc(scheduler->tasks, (scheduler->num_tasks + 1) * sizeof(Task));
    scheduler->tasks[scheduler->num_tasks++] = *task;
    pthread_mutex_lock(&scheduler->mutex);
}

void remove_task(TaskScheduler *scheduler, int index) {
    if (index >= 0 && index < scheduler->num_tasks) {
        Task *task = &scheduler->tasks[index];
        free(task->name);
        free(task);
        scheduler->tasks[index] = scheduler->tasks[--scheduler->num_tasks];
        pthread_mutex_unlock(&scheduler->mutex);
    }
}

void update_task(TaskScheduler *scheduler, int index, char *name, int priority, int start_time, int end_time) {
    if (index >= 0 && index < scheduler->num_tasks) {
        Task *task = &scheduler->tasks[index];
        free(task->name);
        task->name = strdup(name);
        task->priority = priority;
        task->start_time = start_time;
        task->end_time = end_time;
        pthread_mutex_unlock(&scheduler->mutex);
    }
}

void run_scheduler(TaskScheduler *scheduler) {
    while (1) {
        pthread_mutex_lock(&scheduler->mutex);
        for (int i = 0; i < scheduler->num_tasks; i++) {
            Task *task = &scheduler->tasks[i];
            if (task->start_time == time(NULL)) {
                printf("Starting task: %s\n", task->name);
                task->start_time = task->end_time;
            }
            if (task->end_time == time(NULL)) {
                printf("Ending task: %s\n", task->name);
                remove_task(scheduler, i);
            }
        }
        pthread_mutex_unlock(&scheduler->mutex);
        sleep(1);
    }
}

int main() {
    TaskScheduler scheduler = create_scheduler();
    add_task(&scheduler, "Task 1", 1, 0, 10);
    add_task(&scheduler, "Task 2", 2, 5, 15);
    add_task(&scheduler, "Task 3", 3, 10, 20);
    add_task(&scheduler, "Task 4", 4, 15, 25);
    add_task(&scheduler, "Task 5", 5, 20, 30);
    run_scheduler(&scheduler);
    destroy_scheduler(&scheduler);
    return 0;
}
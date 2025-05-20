//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    int interval; // in seconds
    void (*task_function)(void);
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
    pthread_mutex_t mutex;
} TaskScheduler;

void print_current_time() {
    time_t now = time(NULL);
    printf("Current time: %s", ctime(&now));
}

void hello_world_task() {
    printf("Hello World! ");
    print_current_time();
}

void countdown_task() {
    static int count = 5; // Static to retain value across calls
    if (count > 0) {
        printf("Countdown: %d\n", count);
        count--;
    } else {
        printf("Countdown complete!\n");
        count = 5; // Reset countdown 
    }
}

void weather_report_task() {
    printf("Weather Update: It's sunny with a 20% chance of rain. ");
    print_current_time();
}

void* task_runner(void* scheduler_ptr) {
    TaskScheduler* scheduler = (TaskScheduler*)scheduler_ptr;
    while (1) {
        pthread_mutex_lock(&scheduler->mutex);
        
        for (int i = 0; i < scheduler->task_count; i++) {
            if (scheduler->tasks[i].interval <= 0) {
                scheduler->tasks[i].task_function();
                scheduler->tasks[i].interval = scheduler->tasks[i].interval; // Resetting interval
                // Decrease the interval for cyclic scheduling
                scheduler->tasks[i].interval = scheduler->tasks[i].interval - 1; 
            } else {
                scheduler->tasks[i].interval--;
            }
        }

        pthread_mutex_unlock(&scheduler->mutex);
        sleep(1);
    }
    return NULL;
}

void add_task(TaskScheduler *scheduler, const char *name, int interval, void (*task_function)(void)) {
    pthread_mutex_lock(&scheduler->mutex);
    if (scheduler->task_count < MAX_TASKS) {
        Task new_task = { .interval = interval, .task_function = task_function };
        snprintf(new_task.name, TASK_NAME_LEN, "%s", name);
        scheduler->tasks[scheduler->task_count++] = new_task;
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&scheduler->mutex);
}

int main() {
    TaskScheduler scheduler = { .task_count = 0 };
    pthread_mutex_init(&scheduler.mutex, NULL);

    add_task(&scheduler, "Hello World", 5, hello_world_task);
    add_task(&scheduler, "Countdown", 1, countdown_task);
    add_task(&scheduler, "Weather Report", 10, weather_report_task);

    pthread_t task_thread;
    pthread_create(&task_thread, NULL, task_runner, (void*)&scheduler);

    // Let the scheduler run for a specific duration
    sleep(60); // Run for 60 seconds
    pthread_cancel(task_thread); // Clean up
    pthread_join(task_thread, NULL);
    pthread_mutex_destroy(&scheduler.mutex);

    printf("Scheduler stopped. Exiting program.\n");
    return 0;
}
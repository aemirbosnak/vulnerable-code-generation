//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int interval; // in seconds
    int run_count;
    pthread_mutex_t mutex;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void* execute_task(void* arg) {
    Task *task = (Task*) arg;
    while (task->run_count > 0) {
        sleep(task->interval);
        pthread_mutex_lock(&task->mutex);
        printf("Executing task: %s\n", task->name);
        task->run_count--;
        pthread_mutex_unlock(&task->mutex);
    }
    return NULL;
}

void add_task(const char* name, int interval, int run_count) {
    if (task_count >= MAX_TASKS) {
        printf("Maximum task limit reached. Cannot add more tasks.\n");
        return;
    }
    strncpy(tasks[task_count].name, name, TASK_NAME_LENGTH);
    tasks[task_count].interval = interval;
    tasks[task_count].run_count = run_count;
    pthread_mutex_init(&tasks[task_count].mutex, NULL);
    pthread_t thread;
    pthread_create(&thread, NULL, execute_task, (void*)&tasks[task_count]);
    pthread_detach(thread); // Detaching thread to avoid memory leaks
    task_count++;
}

void print_usage() {
    printf("Usage: task_scheduler <task_name> <interval> <run_count>\n");
    printf("Example: task_scheduler MyTask 2 5\n");
    printf("This will execute MyTask, every 2 seconds, for 5 times.\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    const char* task_name = argv[1];
    int interval = atoi(argv[2]);
    int run_count = atoi(argv[3]);

    if (interval <= 0 || run_count <= 0) {
        printf("Interval and run count must be positive integers.\n");
        return 1;
    }

    add_task(task_name, interval, run_count);

    // Main loop to keep the scheduler alive
    while (1) {
        sleep(1); // Sleep for a while to keep the main thread idle
    }

    return 0;
}
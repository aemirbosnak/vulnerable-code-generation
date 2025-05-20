//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 5

typedef struct {
    void (*task)(void);
    char name[30];
    int interval; // in seconds
    time_t last_run;
} Task;

Task *tasks[MAX_TASKS];
int task_count = 0;

void task_a() {
    printf("Task A is running... Whoa! Did I just blink? 👀\n");
}

void task_b() {
    printf("Task B is executing... My lights just flickered! ⚡\n");
}

void task_c() {
    printf("Task C is in action... Is that a ghost? 👻\n");
}

void task_d() {
    printf("Task D has started... What was that noise? 🥴\n");
}

void task_e() {
    printf("Task E is underway... My heart just skipped a beat! 💓\n");
}

void add_task(void (*task)(void), const char *name, int interval) {
    if (task_count < MAX_TASKS) {
        Task *new_task = (Task *)malloc(sizeof(Task));
        new_task->task = task;
        strncpy(new_task->name, name, 29);
        new_task->name[29] = '\0'; // ensure null-termination
        new_task->interval = interval;
        new_task->last_run = time(NULL);
        tasks[task_count++] = new_task;
    } else {
        printf("Warning: Cannot add more tasks! Maximum limit reached! 😱\n");
    }
}

void run_tasks() {
    time_t now = time(NULL);
    
    for (int i = 0; i < task_count; i++) {
        if (now - tasks[i]->last_run >= tasks[i]->interval) {
            tasks[i]->task();
            tasks[i]->last_run = now; // Update last run time
        }
    }
}

void cleanup_tasks() {
    for (int i = 0; i < task_count; i++) {
        free(tasks[i]);
    }
}

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nCaught SIGINT! Cleaning up and exiting! 💥\n");
        cleanup_tasks();
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);

    printf("Initializing Task Scheduler... Ready or not, here we go! 🚀\n");

    add_task(task_a, "Task A", 1);
    add_task(task_b, "Task B", 2);
    add_task(task_c, "Task C", 3);
    add_task(task_d, "Task D", 4);
    add_task(task_e, "Task E", 5);

    while (1) {
        run_tasks();
        sleep(1);
        printf("Sleeping... Could something surprise me? 😨\n");
    }

    cleanup_tasks();
    return 0;
}
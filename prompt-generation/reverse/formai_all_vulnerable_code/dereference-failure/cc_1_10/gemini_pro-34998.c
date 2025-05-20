//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    int id;
    time_t scheduled_time;
    void (*function)(void*);
    void* arg;
};

struct task_scheduler {
    struct task* tasks[MAX_TASKS];
    int num_tasks;
};

void task_scheduler_init(struct task_scheduler* scheduler) {
    scheduler->num_tasks = 0;
}

void task_scheduler_add_task(struct task_scheduler* scheduler, struct task* task) {
    if (scheduler->num_tasks >= MAX_TASKS) {
        fprintf(stderr, "Error: task scheduler is full!\n");
        return;
    }

    scheduler->tasks[scheduler->num_tasks++] = task;
}

void task_scheduler_run(struct task_scheduler* scheduler) {
    while (scheduler->num_tasks > 0) {
        time_t current_time = time(NULL);

        for (int i = 0; i < scheduler->num_tasks; i++) {
            struct task* task = scheduler->tasks[i];

            if (task->scheduled_time <= current_time) {
                task->function(task->arg);

                memmove(&scheduler->tasks[i], &scheduler->tasks[i + 1], sizeof(struct task*) * (scheduler->num_tasks - i - 1));
                scheduler->num_tasks--;
                i--;
            }
        }
    }
}

void task_function(void* arg) {
    printf("Task %d executed!\n", (int) arg);
}

int main() {
    struct task_scheduler scheduler;

    task_scheduler_init(&scheduler);

    for (int i = 0; i < 10; i++) {
        struct task* task = malloc(sizeof(struct task));

        task->id = i;
        task->scheduled_time = time(NULL) + i;
        task->function = task_function;
        task->arg = (void*) i;

        task_scheduler_add_task(&scheduler, task);
    }

    task_scheduler_run(&scheduler);

    return 0;
}
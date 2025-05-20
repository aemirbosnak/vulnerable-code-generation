//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 3

struct task {
    int pid;
    int prio;
    char name[50];
    void (*function)(void);
    struct timespec start, due;
};

struct sched_context {
    int running;
    struct task *tasks[MAX_TASKS];
};

struct sched_context *sched_ctx;

void init_sched_ctx(void) {
    sched_ctx = malloc(sizeof(struct sched_context));
    memset(sched_ctx, 0, sizeof(struct sched_context));
}

void add_task(struct task *task) {
    if (sched_ctx->running) {
        printf("Can't add task while running\n");
        return;
    }
    if (task->prio > MAX_PRIORITY) {
        printf("Priority %d is out of range\n", task->prio);
        return;
    }
    if (sched_ctx->tasks[task->prio] != NULL) {
        printf("Task with priority %d already exists\n", task->prio);
        return;
    }
    sched_ctx->tasks[task->prio] = task;
}

void run_tasks(void) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        if (sched_ctx->tasks[i] != NULL) {
            if (now.tv_sec >= sched_ctx->tasks[i]->due.tv_sec) {
                sched_ctx->tasks[i]->function();
                sched_ctx->tasks[i] = NULL;
            }
        }
    }
}

void sched_yield(void) {
    if (sched_ctx->running) {
        sched_ctx->running = 0;
        sched_ctx->tasks[0] = NULL;
        run_tasks();
        sched_ctx->running = 1;
    }
}

int main(void) {
    init_sched_ctx();
    struct task task1 = {
        .pid = 1,
        .prio = 1,
        .name = "Task 1",
        .function = printf,
        .start = {
            .tv_sec = 0,
            .tv_nsec = 0,
        },
        .due = {
            .tv_sec = 10,
            .tv_nsec = 0,
        },
    };
    struct task task2 = {
        .pid = 2,
        .prio = 2,
        .name = "Task 2",
        .function = printf,
        .start = {
            .tv_sec = 15,
            .tv_nsec = 0,
        },
        .due = {
            .tv_sec = 25,
            .tv_nsec = 0,
        },
    };
    add_task(&task1);
    add_task(&task2);
    while (1) {
        sched_yield();
    }
    return 0;
}
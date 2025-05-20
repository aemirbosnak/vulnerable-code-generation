//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_DELAY 3600 // 1 hour

typedef struct {
    char name[20];
    int delay;
    int started;
} task_t;

typedef struct {
    task_t tasks[MAX_TASKS];
    int num_tasks;
} scheduler_t;

void init_scheduler(scheduler_t *s) {
    s->num_tasks = 0;
}

void add_task(scheduler_t *s, char *name, int delay) {
    task_t *task = (task_t *) malloc(sizeof(task_t));
    strcpy(task->name, name);
    task->delay = delay;
    task->started = 0;
    s->tasks[s->num_tasks++] = *task;
}

void run_scheduler(scheduler_t *s) {
    int i;
    for (i = 0; i < s->num_tasks; i++) {
        if (!s->tasks[i].started) {
            s->tasks[i].started = 1;
            printf("Starting task %s...\n", s->tasks[i].name);
            // Do the task
            sleep(s->tasks[i].delay);
            s->tasks[i].started = 0;
            printf("Task %s finished\n", s->tasks[i].name);
        }
    }
}

void pause_scheduler(scheduler_t *s) {
    int i;
    for (i = 0; i < s->num_tasks; i++) {
        if (s->tasks[i].started) {
            s->tasks[i].started = 0;
            printf("Pausing task %s...\n", s->tasks[i].name);
        }
    }
}

void resume_scheduler(scheduler_t *s) {
    int i;
    for (i = 0; i < s->num_tasks; i++) {
        if (!s->tasks[i].started) {
            s->tasks[i].started = 1;
            printf("Resuming task %s...\n", s->tasks[i].name);
        }
    }
}

void cancel_task(scheduler_t *s, char *name) {
    int i;
    for (i = 0; i < s->num_tasks; i++) {
        if (strcmp(s->tasks[i].name, name) == 0) {
            s->tasks[i].started = 0;
            printf("Cancelled task %s\n", name);
            break;
        }
    }
}

int main() {
    scheduler_t s;
    init_scheduler(&s);

    // Add some tasks
    add_task(&s, "Task 1", 5);
    add_task(&s, "Task 2", 10);
    add_task(&s, "Task 3", 15);

    // Run the scheduler
    run_scheduler(&s);

    // Pause the scheduler
    pause_scheduler(&s);

    // Resume the scheduler
    resume_scheduler(&s);

    // Cancel a task
    cancel_task(&s, "Task 2");

    return 0;
}
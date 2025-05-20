//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct task {
    char *name;
    int priority;
    int arrival_time;
    int burst_time;
    int remaining_time;
    bool completed;
} task;

typedef struct scheduler {
    int num_tasks;
    task *tasks;
    int current_time;
    int num_completed_tasks;
    task *running_task;
} scheduler;

scheduler *create_scheduler(int num_tasks) {
    scheduler *s = malloc(sizeof(scheduler));
    s->num_tasks = num_tasks;
    s->tasks = malloc(sizeof(task) * num_tasks);
    s->current_time = 0;
    s->num_completed_tasks = 0;
    s->running_task = NULL;
    return s;
}

void destroy_scheduler(scheduler *s) {
    for (int i = 0; i < s->num_tasks; i++) {
        free(s->tasks[i].name);
    }
    free(s->tasks);
    free(s);
}

void add_task(scheduler *s, task t) {
    s->tasks[s->num_tasks++] = t;
}

void sort_tasks(scheduler *s) {
    for (int i = 0; i < s->num_tasks; i++) {
        for (int j = i + 1; j < s->num_tasks; j++) {
            if (s->tasks[i].priority > s->tasks[j].priority) {
                task temp = s->tasks[i];
                s->tasks[i] = s->tasks[j];
                s->tasks[j] = temp;
            }
        }
    }
}

void schedule(scheduler *s) {
    while (s->num_completed_tasks < s->num_tasks) {
        s->running_task = NULL;
        for (int i = 0; i < s->num_tasks; i++) {
            if (!s->tasks[i].completed && (s->running_task == NULL || s->tasks[i].priority > s->running_task->priority)) {
                s->running_task = &s->tasks[i];
            }
        }
        if (s->running_task != NULL) {
            s->running_task->remaining_time--;
            if (s->running_task->remaining_time == 0) {
                s->running_task->completed = true;
                s->num_completed_tasks++;
            }
        }
        s->current_time++;
    }
}

void print_schedule(scheduler *s) {
    printf("Schedule:\n");
    for (int i = 0; i < s->num_tasks; i++) {
        printf("%s: %d %d %d %d\n", s->tasks[i].name, s->tasks[i].priority, s->tasks[i].arrival_time, s->tasks[i].burst_time, s->tasks[i].remaining_time);
    }
}

int main() {
    scheduler *s = create_scheduler(5);
    add_task(s, (task) { .name = "A", .priority = 1, .arrival_time = 0, .burst_time = 5 });
    add_task(s, (task) { .name = "B", .priority = 2, .arrival_time = 0, .burst_time = 3 });
    add_task(s, (task) { .name = "C", .priority = 3, .arrival_time = 0, .burst_time = 1 });
    add_task(s, (task) { .name = "D", .priority = 4, .arrival_time = 0, .burst_time = 2 });
    add_task(s, (task) { .name = "E", .priority = 5, .arrival_time = 0, .burst_time = 4 });
    sort_tasks(s);
    schedule(s);
    print_schedule(s);
    destroy_scheduler(s);
    return 0;
}
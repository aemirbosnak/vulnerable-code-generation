//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

#define MAX_TASKS 10

struct task {
    int id;
    char *name;
    int priority;
    int time_to_complete;
    int time_remaining;
};

struct task_scheduler {
    struct task tasks[MAX_TASKS];
    int num_tasks;
};

struct task_scheduler *scheduler;

void add_task(char *name, int priority, int time_to_complete) {
    if (scheduler->num_tasks >= MAX_TASKS) {
        fprintf(stderr, "Error: too many tasks\n");
        return;
    }

    struct task new_task;
    new_task.id = scheduler->num_tasks;
    new_task.name = name;
    new_task.priority = priority;
    new_task.time_to_complete = time_to_complete;
    new_task.time_remaining = time_to_complete;

    scheduler->tasks[scheduler->num_tasks] = new_task;
    scheduler->num_tasks++;
}

void remove_task(int id) {
    if (id < 0 || id >= scheduler->num_tasks) {
        fprintf(stderr, "Error: invalid task ID\n");
        return;
    }

    for (int i = id; i < scheduler->num_tasks - 1; i++) {
        scheduler->tasks[i] = scheduler->tasks[i + 1];
    }

    scheduler->num_tasks--;
}

void print_tasks() {
    printf("Tasks:\n");
    for (int i = 0; i < scheduler->num_tasks; i++) {
        printf("%d: %s (priority %d, time remaining %d)\n",
               scheduler->tasks[i].id,
               scheduler->tasks[i].name,
               scheduler->tasks[i].priority,
               scheduler->tasks[i].time_remaining);
    }
}

void update_tasks() {
    for (int i = 0; i < scheduler->num_tasks; i++) {
        scheduler->tasks[i].time_remaining--;

        if (scheduler->tasks[i].time_remaining == 0) {
            printf("Task %s completed\n", scheduler->tasks[i].name);
            remove_task(i);
        }
    }
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("Exiting\n");
        exit(0);
    }
}

int main() {
    scheduler = malloc(sizeof(struct task_scheduler));
    scheduler->num_tasks = 0;

    signal(SIGINT, signal_handler);

    add_task("Scavenge for food", 1, 10);
    add_task("Build shelter", 2, 20);
    add_task("Find water", 1, 5);
    add_task("Repair weapons", 2, 10);
    add_task("Craft medicine", 1, 5);

    while (1) {
        update_tasks();
        print_tasks();
        sleep(1);
    }

    return 0;
}
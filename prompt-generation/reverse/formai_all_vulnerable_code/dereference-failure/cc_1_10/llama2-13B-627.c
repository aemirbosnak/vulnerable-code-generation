//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_DESCRIPTION_LENGTH 100

typedef struct task {
    int pid;
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} task_t;

typedef struct schedule {
    task_t tasks[MAX_TASKS];
    int num_tasks;
} schedule_t;

void add_task(schedule_t* schedule, char* description, time_t start_time, time_t end_time);
void remove_task(schedule_t* schedule, int pid);
void print_schedule(schedule_t* schedule);

int main() {
    schedule_t* schedule = (schedule_t*)malloc(sizeof(schedule_t));
    int i;

    // Add some tasks to the schedule
    add_task(schedule, "Task 1", 10, 20);
    add_task(schedule, "Task 2", 20, 30);
    add_task(schedule, "Task 3", 30, 40);

    // Remove a task from the schedule
    remove_task(schedule, 1);

    // Print the updated schedule
    print_schedule(schedule);

    return 0;
}

void add_task(schedule_t* schedule, char* description, time_t start_time, time_t end_time) {
    int i = schedule->num_tasks;

    schedule->tasks[i].pid = getpid();
    strcpy(schedule->tasks[i].description, description);
    schedule->tasks[i].start_time = start_time;
    schedule->tasks[i].end_time = end_time;

    schedule->num_tasks++;
}

void remove_task(schedule_t* schedule, int pid) {
    int i;

    for (i = 0; i < schedule->num_tasks; i++) {
        if (schedule->tasks[i].pid == pid) {
            break;
        }
    }

    if (i != schedule->num_tasks) {
        // Remove the task from the array
        memmove(schedule->tasks + i, schedule->tasks + i + 1, (schedule->num_tasks - i - 1) * sizeof(task_t));
        schedule->num_tasks--;
    }
}

void print_schedule(schedule_t* schedule) {
    int i;

    for (i = 0; i < schedule->num_tasks; i++) {
        printf("%d: %s (%s - %s)\n", schedule->tasks[i].pid, schedule->tasks[i].description, ctime(&schedule->tasks[i].start_time), ctime(&schedule->tasks[i].end_time));
    }
}
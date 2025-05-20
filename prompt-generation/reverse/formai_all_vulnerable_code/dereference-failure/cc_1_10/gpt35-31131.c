//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_TASKS 100

struct Task {
    int task_id;
    int priority;
    char *task_name;
    void (*execute)();
    struct tm start_time;
    struct tm end_time;
} task_table[MAX_TASKS];

int task_count = 1;

void task_one() {
    printf("Executing task one...\n");
}

void task_two() {
    printf("Executing task two...\n");
}

void task_three() {
    printf("Executing task three...\n");
}

void schedule_task(struct Task *task) {
    printf("Scheduling task %d (%s)...\n", task->task_id, task->task_name);
    task->execute();
    printf("Task %d (%s) completed.\n", task->task_id, task->task_name);
}

void add_task(int priority, char *task_name, void (*execute)(), struct tm start_time, struct tm end_time) {
    struct Task *new_task = (struct Task*)malloc(sizeof(struct Task));
    new_task->task_id = task_count++;
    new_task->priority = priority;
    new_task->task_name = task_name;
    new_task->execute = execute;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    task_table[new_task->task_id] = *new_task;
    printf("Task added.\n");
}

int main() {
    struct tm task_1_start_time = {0, 0, 12, 1, 1, 120};
    struct tm task_1_end_time = {0, 30, 12, 1, 1, 120};
    struct tm task_2_start_time = {0, 0, 13, 1, 1, 120};
    struct tm task_2_end_time = {0, 30, 13, 1, 1, 120};
    struct tm task_3_start_time = {0, 0, 14, 1, 1, 120};
    struct tm task_3_end_time = {0, 30, 14, 1, 1, 120};

    add_task(2, "Task 1", task_one, task_1_start_time, task_1_end_time);
    add_task(1, "Task 2", task_two, task_2_start_time, task_2_end_time);
    add_task(3, "Task 3", task_three, task_3_start_time, task_3_end_time);

    int i, j;
    // insertion sort to prioritize tasks
    for (i = 1; i < task_count; i++) {
        j = i;
        while (j > 0 && task_table[j-1].priority < task_table[j].priority) {
            struct Task temp = task_table[j];
            task_table[j] = task_table[j-1];
            task_table[j-1] = temp;
            j--;
        }
    }

    // execute scheduled tasks
    for (i = 0; i < task_count; i++) {
        // check if task is within time frame
        time_t current_time;
        time(&current_time);
        if (current_time >= mktime(&task_table[i].start_time) && current_time <= mktime(&task_table[i].end_time)) {
            schedule_task(&task_table[i]);
        }
    }

    return 0;
}
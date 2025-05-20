//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10
#define MAX_TASK_SIZE 20

typedef struct Task {
    char name[MAX_TASK_SIZE];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

typedef struct Scheduler {
    Task** tasks;
    int size;
    int current_task_index;
} Scheduler;

void scheduler_init(Scheduler* scheduler) {
    scheduler->tasks = NULL;
    scheduler->size = 0;
    scheduler->current_task_index = -1;
}

void scheduler_add_task(Scheduler* scheduler, Task* task) {
    scheduler->tasks = realloc(scheduler->tasks, (scheduler->size + 1) * sizeof(Task*));
    scheduler->tasks[scheduler->size++] = task;
}

void scheduler_start(Scheduler* scheduler) {
    time_t current_time = time(NULL);
    int i = 0;

    for (i = 0; i < scheduler->size; i++) {
        Task* task = scheduler->tasks[i];

        if (task->start_time <= current_time && task->end_time >= current_time) {
            printf("Task: %s started at %s\n", task->name, ctime(task->start_time));
            printf("Task: %s completed at %s\n", task->name, ctime(task->end_time));
        }
    }
}

int main() {
    Scheduler scheduler;
    scheduler_init(&scheduler);

    Task* task1 = malloc(sizeof(Task));
    strcpy(task1->name, "Task 1");
    task1->start_time = time(NULL) + 60 * 5;
    task1->end_time = time(NULL) + 60 * 10;
    scheduler_add_task(&scheduler, task1);

    Task* task2 = malloc(sizeof(Task));
    strcpy(task2->name, "Task 2");
    task2->start_time = time(NULL) + 60 * 10;
    task2->end_time = time(NULL) + 60 * 15;
    scheduler_add_task(&scheduler, task2);

    scheduler_start(&scheduler);

    return 0;
}
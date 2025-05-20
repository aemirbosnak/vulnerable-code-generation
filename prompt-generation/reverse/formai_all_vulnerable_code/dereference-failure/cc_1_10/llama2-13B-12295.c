//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 5
#define MAX_DELAY 10000

typedef struct task {
    int pid;
    int prio;
    int delay;
    char name[50];
} task_t;

typedef struct schedule {
    task_t tasks[MAX_TASKS];
    int head;
    int tail;
} schedule_t;

void init_schedule(schedule_t *schedule) {
    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        schedule->tasks[i].pid = -1;
        schedule->tasks[i].prio = 0;
        schedule->tasks[i].delay = 0;
        strcpy(schedule->tasks[i].name, "NULL");
    }
    schedule->head = 0;
    schedule->tail = 0;
}

void enqueue_task(schedule_t *schedule, task_t *task) {
    if (schedule->head == MAX_TASKS) {
        printf("Error: Queue full\n");
        return;
    }
    schedule->tasks[schedule->head].pid = task->pid;
    schedule->tasks[schedule->head].prio = task->prio;
    schedule->tasks[schedule->head].delay = task->delay;
    strcpy(schedule->tasks[schedule->head].name, task->name);
    schedule->head++;
}

void dequeue_task(schedule_t *schedule) {
    if (schedule->tail == -1) {
        printf("Error: Queue empty\n");
        return;
    }
    task_t task;
    task.pid = schedule->tasks[schedule->tail].pid;
    task.prio = schedule->tasks[schedule->tail].prio;
    task.delay = schedule->tasks[schedule->tail].delay;
    strcpy(task.name, schedule->tasks[schedule->tail].name);
    schedule->tail++;
}

void run_task(schedule_t *schedule, task_t *task) {
    if (task->prio > getpriority()){
        printf("Error: Priority %d is higher than current priority %d\n", task->prio, getpriority());
        return;
    }
    if (task->delay > 0) {
        usleep(task->delay * 1000);
    }
    printf("Running task %s with priority %d and delay %d\n", task->name, task->prio, task->delay);
}

int main() {
    schedule_t schedule;
    init_schedule(&schedule);

    task_t task1 = {
        .pid = 1,
        .prio = 1,
        .delay = 5000,
        .name = "Task 1"
    };

    task_t task2 = {
        .pid = 2,
        .prio = 2,
        .delay = 10000,
        .name = "Task 2"
    };

    task_t task3 = {
        .pid = 3,
        .prio = 3,
        .delay = 15000,
        .name = "Task 3"
    };

    enqueue_task(&schedule, &task1);
    enqueue_task(&schedule, &task2);
    enqueue_task(&schedule, &task3);

    while (1) {
        dequeue_task(&schedule);
        run_task(&schedule, &task1);
        run_task(&schedule, &task2);
        run_task(&schedule, &task3);
    }

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TASK_QUEUE_SIZE 10
#define TASK_DELAY_MIN 1
#define TASK_DELAY_MAX 60

struct task {
    int pid;
    int delay;
    char *name;
    void (*function)(void);
};

static int task_queue[TASK_QUEUE_SIZE];
static int task_head = 0;
static int task_tail = 0;

void enqueue_task(char *name, void (*function)(void), int delay) {
    struct task *task = malloc(sizeof(struct task));
    task->pid = getpid();
    task->delay = delay;
    task->name = name;
    task->function = function;
    if (task_head == TASK_QUEUE_SIZE) {
        task_tail += (task_head - task_tail) % TASK_QUEUE_SIZE;
    }
    task_queue[task_tail] = task;
    task_tail += 1;
    if (task_tail >= TASK_QUEUE_SIZE) {
        task_tail = 0;
    }
}

void dequeue_task() {
    if (task_head == task_tail) {
        return;
    }
    struct task *task = task_queue[task_head];
    task_head += 1;
    if (task_head >= TASK_QUEUE_SIZE) {
        task_head = 0;
    }
    task->function();
    free(task);
}

void print_tasks() {
    printf("Tasks in queue:\n");
    for (int i = task_head; i != task_tail; i += 1) {
        struct task *task = task_queue[i];
        printf("- %d (%s, %d secs)\n", task->pid, task->name, task->delay);
    }
}

int main() {
    srand(time(NULL));
    char *tasks[] = {"Task 1", "Task 2", "Task 3", "Task 4", "Task 5"};
    void (*functions[])(void) = {
        [0] = print_tasks,
        [1] = sleep,
        [2] = print_tasks,
        [3] = exit,
        [4] = print_tasks
    };
    for (int i = 0; i < 5; i++) {
        enqueue_task(tasks[i], functions[i], rand() % (TASK_DELAY_MIN + 1) + TASK_DELAY_MIN);
    }
    while (1) {
        dequeue_task();
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int task_id;
    int priority;
    int execution_time;
    void (*task_function)(void *param);
    void *param;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void task_scheduler() {
    int i;
    for(i = 0; i < task_count; i++) {
        printf("Task %d scheduled\n", tasks[i].task_id);
        tasks[i].task_function(tasks[i].param);
    }
}

int add_task(int task_id, int priority, int execution_time, void (*task_function)(void *param), void *param) {
    if(task_count >= MAX_TASKS) {
        printf("Maximum task limit reached\n");
        return -1;
    }

    tasks[task_count].task_id = task_id;
    tasks[task_count].priority = priority;
    tasks[task_count].execution_time = execution_time;
    tasks[task_count].task_function = task_function;
    tasks[task_count].param = param;

    task_count++;

    return 0;
}

void *task_thread(void *param) {
    Task *task = (Task *) param;

    sleep(task->execution_time / 1000);

    printf("Task %d completed\n", task->task_id);

    pthread_exit(0);
}

int main() {
    int i;

    srand(time(0));

    for(i = 0; i < 10; i++) {
        add_task(i, rand() % 10, rand() % 10, task_thread, (void *) i);
    }

    task_scheduler();

    return 0;
}
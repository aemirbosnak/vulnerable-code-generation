//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_TASKS 10
#define STACK_SIZE 4096

typedef struct task {
    void (*func)(void *param);
    void *param;
    struct task *next;
} task_t;

task_t *task_list = NULL;
pthread_t thread_id[NUM_TASKS];
int task_count = 0;

void add_task(void (*func)(void *), void *param) {
    task_t *new_task = malloc(sizeof(task_t));
    if (new_task == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_task->func = func;
    new_task->param = param;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        task_t *curr_task = task_list;
        while (curr_task->next!= NULL) {
            curr_task = curr_task->next;
        }
        curr_task->next = new_task;
    }

    task_count++;
}

void *task_thread(void *param) {
    task_t *task = (task_t *) param;
    task->func(task->param);
    free(task);
    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_TASKS; i++) {
        add_task(task_thread, NULL);
    }

    while (task_count > 0) {
        usleep(100000); // Sleep for a short time to allow tasks to complete
    }

    return 0;
}
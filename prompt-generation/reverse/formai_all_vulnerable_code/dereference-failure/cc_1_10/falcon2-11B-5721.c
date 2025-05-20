//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct task_info {
    int id;
    int priority;
    int execute_time;
    void (*function)(void*);
    void* arg;
} TaskInfo;

void* execute_task(void* arg) {
    TaskInfo* info = (TaskInfo*)arg;
    printf("Task %d with priority %d started at %d\n", info->id, info->priority, info->execute_time);
    // execute the function
    info->function(info->arg);
    printf("Task %d with priority %d completed at %d\n", info->id, info->priority, info->execute_time);
}

void* task_scheduler(void* arg) {
    TaskInfo* tasks = (TaskInfo*)arg;
    int num_tasks = 10;
    int task_count = 0;
    int task_index;
    int i;
    int wait_time = 0;

    for (i = 0; i < num_tasks; i++) {
        TaskInfo task = {0};
        task.id = i + 1;
        task.priority = 100;
        task.execute_time = rand() % 1000 + 1;
        task.function = execute_task;
        task.arg = &task;
        task_count++;

        pthread_t thread;
        pthread_create(&thread, NULL, execute_task, (void*)&task);

        while (task_count > 1) {
            pthread_join(thread, NULL);
            task_count--;
        }

        wait_time = rand() % 1000 + 1;
        task_index = 0;
        for (i = 1; i < task_count; i++) {
            if (tasks[task_index].priority < tasks[i].priority) {
                task_index = i;
            }
        }

        pthread_create(&thread, NULL, execute_task, (void*)&tasks[task_index]);
        pthread_join(thread, NULL);

        wait_time = rand() % 1000 + 1;
        task_index = 0;
        for (i = 1; i < task_count; i++) {
            if (tasks[task_index].priority < tasks[i].priority) {
                task_index = i;
            }
        }

        pthread_create(&thread, NULL, execute_task, (void*)&tasks[task_index]);
        pthread_join(thread, NULL);

        wait_time = rand() % 1000 + 1;
        task_index = 0;
        for (i = 1; i < task_count; i++) {
            if (tasks[task_index].priority < tasks[i].priority) {
                task_index = i;
            }
        }

        pthread_create(&thread, NULL, execute_task, (void*)&tasks[task_index]);
        pthread_join(thread, NULL);
    }

    pthread_exit(NULL);
}

int main() {
    TaskInfo* tasks = (TaskInfo*)malloc(sizeof(TaskInfo) * 10);

    srand(time(NULL));

    int i;
    for (i = 0; i < 10; i++) {
        tasks[i].id = i + 1;
        tasks[i].priority = rand() % 100 + 1;
        tasks[i].execute_time = rand() % 1000 + 1;
        tasks[i].function = execute_task;
        tasks[i].arg = &tasks[i];
    }

    pthread_t thread;
    pthread_create(&thread, NULL, task_scheduler, (void*)tasks);

    pthread_join(thread, NULL);

    return 0;
}
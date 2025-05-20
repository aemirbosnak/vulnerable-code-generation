//FormAI DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int task_id;
    int priority;
    int execution_time;
} task;

typedef struct {
    task **task_list;
    int num_tasks;
} task_queue;

int compare_tasks(const void *task1, const void *task2) {
    return ((task*)task1)->priority - ((task*)task2)->priority;
}

task_queue *init_queue() {
    task_queue *queue = malloc(sizeof(task_queue));
    queue->task_list = malloc(sizeof(task*));
    queue->num_tasks = 0;
    return queue;
}

task *create_task(int id, int priority, int execution_time) {
    task *new_task = malloc(sizeof(task));
    new_task->task_id = id;
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    return new_task;
}

void enqueue_task(task_queue *queue, task *new_task) {
    queue->num_tasks++;
    queue->task_list = realloc(queue->task_list, sizeof(task*) * queue->num_tasks);
    queue->task_list[queue->num_tasks - 1] = new_task;
    qsort(queue->task_list, queue->num_tasks, sizeof(task*), compare_tasks);
}

void execute_tasks(task_queue *queue) {
    int i, j, time_elapsed;
    for (i = 0; i < queue->num_tasks; i++) {
        time_elapsed = 0;
        for (j = i; j < queue->num_tasks; j++) {
            if (queue->task_list[j]->execution_time + time_elapsed <= 8) {
                printf("Executing task %d for %d seconds\n", queue->task_list[j]->task_id, queue->task_list[j]->execution_time);
                time_elapsed += queue->task_list[j]->execution_time;
            } else {
                break;
            }
        }
        i = j - 1;
    }
}

int main() {
    task_queue *queue = init_queue();

    // create and enqueue tasks
    enqueue_task(queue, create_task(1, 1, 2));
    enqueue_task(queue, create_task(2, 3, 1));
    enqueue_task(queue, create_task(3, 2, 3));
    enqueue_task(queue, create_task(4, 5, 2));
    enqueue_task(queue, create_task(5, 4, 1));

    // execute tasks
    execute_tasks(queue);

    return 0;
}
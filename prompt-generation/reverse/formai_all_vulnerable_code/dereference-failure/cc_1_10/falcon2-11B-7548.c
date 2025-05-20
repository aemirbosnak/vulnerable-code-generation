//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>

#define MAX_TASKS 100

typedef struct task_info {
    int task_id;
    char task_name[100];
    char output[1000];
} task_info;

typedef struct task_queue {
    int size;
    task_info *tasks;
} task_queue;

void* run_task(void* args) {
    task_info* task = (task_info*) args;
    printf("%s\n", task->task_name);
    strcpy(task->output, "This is the output for task ");
    strcat(task->output, task->task_name);
    printf("%s\n", task->output);
    return NULL;
}

void add_task(task_queue* queue, const char* task_name) {
    task_info* new_task = (task_info*) malloc(sizeof(task_info));
    strcpy(new_task->task_name, task_name);
    new_task->task_id = queue->size + 1;
    strcpy(new_task->output, "");
    queue->tasks = realloc(queue->tasks, (queue->size + 1) * sizeof(task_info));
    queue->tasks[queue->size] = *new_task;
    queue->size++;
}

void delete_task(task_queue* queue, int task_id) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->tasks[i].task_id == task_id) {
            for (int j = i; j < queue->size - 1; j++) {
                queue->tasks[j] = queue->tasks[j + 1];
            }
            queue->size--;
            free(queue->tasks[i].task_name);
            free(queue->tasks[i].output);
            break;
        }
    }
}

void print_task_info(task_queue* queue) {
    for (int i = 0; i < queue->size; i++) {
        printf("Task %d: %s\n", queue->tasks[i].task_id, queue->tasks[i].task_name);
        printf("Output: %s\n", queue->tasks[i].output);
    }
}

int main() {
    task_queue queue;
    queue.size = 0;
    queue.tasks = NULL;

    pthread_t threads[MAX_TASKS];

    char task_name[100];

    while (1) {
        printf("Enter task name or 'q' to quit: ");
        fgets(task_name, sizeof(task_name), stdin);
        if (strcmp(task_name, "q") == 0) {
            break;
        }
        add_task(&queue, task_name);
    }

    printf("Task queue:\n");
    print_task_info(&queue);

    for (int i = 0; i < MAX_TASKS; i++) {
        if (i < queue.size) {
            task_info* task = &queue.tasks[i];
            pthread_create(&threads[i], NULL, run_task, (void*) task);
        } else {
            pthread_create(&threads[i], NULL, NULL, NULL);
        }
    }

    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Task queue:\n");
    print_task_info(&queue);

    return 0;
}
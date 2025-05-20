//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int *numbers;
    int length;
} NumberList;

typedef struct {
    NumberList *list;
    int start;
    int end;
    bool done;
} Task;

void *sum_task(void *arg) {
    Task *task = (Task *) arg;
    int sum = 0;
    for (int i = task->start; i < task->end; i++) {
        sum += task->list->numbers[i];
    }
    printf("Sum of range %d to %d is %d\n", task->start, task->end, sum);
    task->done = true;
    pthread_exit(NULL);
}

int main() {
    // Generate random list of numbers
    srand(time(NULL));
    int length = 1000;
    int *numbers = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % 100;
    }
    NumberList list = {numbers, length};

    // Define tasks
    int num_tasks = 10;
    Task *tasks = malloc(num_tasks * sizeof(Task));
    for (int i = 0; i < num_tasks; i++) {
        int start = i * (length / num_tasks);
        int end = (i + 1) * (length / num_tasks);
        tasks[i] = (Task) {&list, start, end, false};
    }

    // Create threads for each task
    pthread_t *threads = malloc(num_tasks * sizeof(pthread_t));
    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, sum_task, (void *) &tasks[i]);
    }

    // Wait for all threads to complete
    while (true) {
        bool all_done = true;
        for (int i = 0; i < num_tasks; i++) {
            if (!tasks[i].done) {
                all_done = false;
                break;
            }
        }
        if (all_done) {
            break;
        }
        usleep(1000);
    }

    // Clean up
    free(numbers);
    free(tasks);
    free(threads);
    return 0;
}
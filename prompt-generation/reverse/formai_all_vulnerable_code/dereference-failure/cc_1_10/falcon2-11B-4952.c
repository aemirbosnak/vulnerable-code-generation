//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 5
#define MAX_THREADS 4

void* task_func(void* arg) {
    // simulate task execution
    int task_id = *(int*)arg;
    for (int i=0; i<100; i++) {
        sleep(1);
        printf("Task %d executing...\n", task_id);
    }
    pthread_exit(NULL);
}

void schedule_tasks() {
    // generate a list of tasks to be executed
    srand(time(NULL));
    int tasks[MAX_TASKS];
    for (int i=0; i<MAX_TASKS; i++) {
        tasks[i] = i;
    }

    // sort the tasks by execution time
    for (int i=0; i<MAX_TASKS-1; i++) {
        for (int j=0; j<MAX_TASKS-i-1; j++) {
            if (rand() % 2 == 0) {
                int temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }

    // create threads for each task
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    for (int i=0; i<MAX_TASKS; i++) {
        pthread_create(&threads[thread_count], NULL, task_func, (void*)&tasks[i]);
        thread_count++;
    }

    // wait for all threads to finish
    for (int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    schedule_tasks();
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int num_tasks;
int task_count[100];
int task_start_time[100];
int task_end_time[100];
int task_priority[100];
int task_cpu_time[100];
int task_io_time[100];
int task_mem_usage[100];
int task_name[100][100];
int task_status[100];

void *task_func(void *arg) {
    int task_id = *((int*)arg);
    printf("Task %d started at %d\n", task_id, clock());
    task_start_time[task_id] = clock();
    task_cpu_time[task_id] = task_io_time[task_id] = task_mem_usage[task_id] = 0;
    task_status[task_id] = 1;
    while (task_status[task_id] == 1) {
        // simulate task execution
        task_cpu_time[task_id] += (clock() - task_start_time[task_id]);
        task_io_time[task_id] += (clock() - task_start_time[task_id]);
        task_mem_usage[task_id] += (clock() - task_start_time[task_id]);
        sleep(1);
    }
    printf("Task %d ended at %d\n", task_id, clock());
    task_end_time[task_id] = clock();
}

void print_task_info(int task_id) {
    printf("Task ID: %d\n", task_id);
    printf("Start Time: %d\n", task_start_time[task_id]);
    printf("End Time: %d\n", task_end_time[task_id]);
    printf("CPU Time: %d\n", task_cpu_time[task_id]);
    printf("IO Time: %d\n", task_io_time[task_id]);
    printf("Memory Usage: %d\n", task_mem_usage[task_id]);
    printf("Priority: %d\n", task_priority[task_id]);
    printf("Name: %s\n", task_name[task_id]);
    printf("Status: %d\n", task_status[task_id]);
    printf("\n");
}

int main() {
    srand(time(NULL));
    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d name: ", i+1);
        fflush(stdin);
        scanf("%s", task_name[i]);
        task_count[i] = rand() % 100;
        task_priority[i] = rand() % 10;
        task_start_time[i] = task_end_time[i] = clock();
        task_cpu_time[i] = task_io_time[i] = task_mem_usage[i] = 0;
        task_status[i] = 0;
    }
    pthread_t threads[num_tasks];
    int task_id;
    for (int i = 0; i < num_tasks; i++) {
        if (task_count[i] > 0) {
            task_id = i + 1;
            printf("Task %d starting...\n", task_id);
            task_count[i]--;
            task_status[i] = 1;
            pthread_create(&threads[i], NULL, task_func, (void*)&task_id);
            pthread_join(threads[i], NULL);
            task_count[i]++;
            task_status[i] = 0;
        }
    }
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i+1);
        print_task_info(i);
    }
    return 0;
}
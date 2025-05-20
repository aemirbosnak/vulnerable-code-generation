//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PROCESSES 10
#define MAX_PRIORITY 100

typedef struct process {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];
int num_processes;

void* execute_process(void* arg) {
    int process_id = *(int*) arg;
    int burst_time = processes[process_id].burst_time;
    int waiting_time = 0;
    int turnaround_time = 0;

    printf("Process %d starts execution with burst time %d\n", process_id, burst_time);

    for (int i = 0; i < burst_time; i++) {
        printf("Process %d is executing\n", process_id);
        sleep(1);
    }

    printf("Process %d completes execution\n", process_id);

    processes[process_id].waiting_time = waiting_time;
    processes[process_id].turnaround_time = turnaround_time;
}

void add_process(int id, int priority, int burst_time) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached\n");
        return;
    }

    processes[num_processes].id = id;
    processes[num_processes].priority = priority;
    processes[num_processes].burst_time = burst_time;
    processes[num_processes].waiting_time = 0;
    processes[num_processes].turnaround_time = 0;

    num_processes++;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        int id, priority, burst_time;
        printf("Enter process details for thread %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Priority: ");
        scanf("%d", &priority);
        printf("Burst time: ");
        scanf("%d", &burst_time);

        add_process(id, priority, burst_time);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, execute_process, (void*) i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Processes completed execution\n");

    return 0;
}
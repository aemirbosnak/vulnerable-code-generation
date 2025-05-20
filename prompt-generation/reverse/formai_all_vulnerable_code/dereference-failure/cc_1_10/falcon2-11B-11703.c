//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_JOBS 10

typedef struct job {
    int id;
    int priority;
    int time_required;
} Job;

typedef struct process {
    int id;
    int priority;
    int time_required;
    pthread_t thread;
} Process;

void* process_function(void* args) {
    Process* process = (Process*) args;
    printf("Process %d started at %d\n", process->id, (int) clock());
    sleep(process->time_required);
    printf("Process %d completed at %d\n", process->id, (int) clock());
    pthread_exit(NULL);
}

void* job_function(void* args) {
    Job* job = (Job*) args;
    printf("Job %d started at %d\n", job->id, (int) clock());
    sleep(job->time_required);
    printf("Job %d completed at %d\n", job->id, (int) clock());
    pthread_exit(NULL);
}

void create_jobs(Job* jobs, int num_jobs) {
    for (int i = 0; i < num_jobs; i++) {
        jobs[i].id = i + 1;
        jobs[i].priority = rand() % 10 + 1;
        jobs[i].time_required = rand() % 20 + 1;
    }
}

void create_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        processes[i].priority = rand() % 10 + 1;
        processes[i].time_required = rand() % 20 + 1;
        pthread_create(&(processes[i].thread), NULL, process_function, &(processes[i]));
    }
}

int main() {
    srand(time(NULL));
    Job jobs[MAX_JOBS];
    Process processes[MAX_PROCESSES];
    int num_jobs = rand() % (MAX_JOBS + 1);
    int num_processes = rand() % (MAX_PROCESSES + 1);

    create_jobs(jobs, num_jobs);
    create_processes(processes, num_processes);

    pthread_t thread;
    pthread_create(&thread, NULL, job_function, (void*) jobs);

    pthread_join(thread, NULL);

    return 0;
}
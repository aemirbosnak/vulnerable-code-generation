//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct job {
    int arrival_time;
    int burst_time;
    int finish_time;
} Job;

typedef struct process {
    Job *job_list;
    int current_job;
    int remaining_time;
} Process;

void shortest_job_first(Process *process) {
    int current_time = 0;
    int i;

    while (process->current_job < process->job_list->finish_time) {
        for (i = 0; i < process->job_list->burst_time; i++) {
            current_time++;
        }
        process->remaining_time = process->job_list->burst_time - current_time;
        process->current_job++;
    }
}

void print_job_list(Job *job_list) {
    int i;

    printf("Job List:\n");
    for (i = 0; i < job_list->burst_time; i++) {
        printf("Job %d: %d\n", i, job_list->arrival_time);
    }
}

int main() {
    srand(time(0));

    Job *job_list = (Job *)malloc(sizeof(Job));
    job_list->arrival_time = rand() % 100;
    job_list->burst_time = rand() % 100;
    job_list->finish_time = job_list->arrival_time + job_list->burst_time;

    Process process;
    process.job_list = job_list;
    process.current_job = 0;
    process.remaining_time = process.job_list->burst_time;

    printf("Job List:\n");
    print_job_list(job_list);

    shortest_job_first(&process);

    printf("Remaining Time: %d\n", process.remaining_time);

    free(job_list);
    return 0;
}
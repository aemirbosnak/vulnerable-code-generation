//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Job;

void swap(Job* a, Job* b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    Job* job_a = (Job*) a;
    Job* job_b = (Job*) b;

    return job_a->burst_time - job_b->burst_time;
}

int main() {
    int num_jobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &num_jobs);

    Job jobs[num_jobs];

    for (int i = 0; i < num_jobs; i++) {
        jobs[i].pid = i + 1;
        printf("Enter arrival time and burst time for job %d: ", jobs[i].pid);
        scanf("%d%d", &jobs[i].arrival_time, &jobs[i].burst_time);
        jobs[i].waiting_time = 0;
        jobs[i].turnaround_time = 0;
    }

    qsort(jobs, num_jobs, sizeof(Job), compare);

    int current_time = 0;
    int completed_jobs = 0;

    while (completed_jobs < num_jobs) {
        Job* current_job = NULL;

        for (int i = 0; i < num_jobs; i++) {
            if (jobs[i].arrival_time <= current_time && jobs[i].burst_time > 0) {
                current_job = &jobs[i];
                break;
            }
        }

        if (current_job == NULL) {
            current_time++;
            continue;
        }

        int time_used = current_job->burst_time < (20 - current_time) ? current_job->burst_time : (20 - current_time);
        current_job->burst_time -= time_used;
        current_time += time_used;

        current_job->waiting_time = current_job->waiting_time + time_used;
        current_job->turnaround_time = current_job->waiting_time + current_job->burst_time;
        completed_jobs++;
    }

    printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");

    for (int i = 0; i < num_jobs; i++) {
        printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", jobs[i].pid, jobs[i].arrival_time, jobs[i].burst_time, jobs[i].waiting_time, jobs[i].turnaround_time);
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int job_id;
    int arrival_time;
    int processing_time;
} Job;

typedef struct {
    Job *jobs;
    int num_jobs;
    int queue_size;
    int cpu_time;
    int waiting_time;
    int total_waiting_time;
} Server;

void print_jobs(Server *server) {
    printf("Job ID: Arrival Time: Processing Time:\n");
    for(int i = 0; i < server->num_jobs; i++) {
        printf("%d: %d: %d\n", server->jobs[i].job_id, server->jobs[i].arrival_time, server->jobs[i].processing_time);
    }
}

void print_server_stats(Server *server) {
    printf("CPU time: %d\n", server->cpu_time);
    printf("Waiting time: %d\n", server->waiting_time);
    printf("Total waiting time: %d\n", server->total_waiting_time);
}

void enqueue_job(Server *server, int job_id, int arrival_time, int processing_time) {
    Job new_job;
    new_job.job_id = job_id;
    new_job.arrival_time = arrival_time;
    new_job.processing_time = processing_time;
    server->jobs = (Job *)realloc(server->jobs, (server->num_jobs + 1) * sizeof(Job));
    server->jobs[server->num_jobs] = new_job;
    server->num_jobs++;
}

int dequeue_job(Server *server) {
    int job_id;
    int arrival_time;
    int processing_time;
    if(server->num_jobs == 0) {
        return -1;
    }
    job_id = server->jobs[0].job_id;
    arrival_time = server->jobs[0].arrival_time;
    processing_time = server->jobs[0].processing_time;
    server->jobs[0] = server->jobs[server->num_jobs - 1];
    server->num_jobs--;
    return job_id;
}

void process_jobs(Server *server) {
    int job_id;
    int waiting_time = 0;
    int total_waiting_time = 0;
    while(server->num_jobs > 0) {
        job_id = dequeue_job(server);
        if(job_id!= -1) {
            server->cpu_time += server->jobs[job_id].processing_time;
            server->waiting_time += server->jobs[job_id].arrival_time - server->jobs[job_id].processing_time;
            total_waiting_time += server->jobs[job_id].arrival_time - server->jobs[job_id].processing_time;
            enqueue_job(server, job_id, 0, 0);
        }
    }
    server->total_waiting_time = total_waiting_time;
}

int main() {
    srand(time(NULL));

    Server server;
    server.jobs = (Job *)malloc(10 * sizeof(Job));
    server.num_jobs = 0;
    server.queue_size = 10;
    server.cpu_time = 0;
    server.waiting_time = 0;
    server.total_waiting_time = 0;

    for(int i = 0; i < 10; i++) {
        int arrival_time = rand() % 100;
        int processing_time = rand() % 100;
        enqueue_job(&server, i + 1, arrival_time, processing_time);
    }

    printf("Initial server stats:\n");
    print_jobs(&server);
    print_server_stats(&server);

    process_jobs(&server);

    printf("\nFinal server stats:\n");
    print_jobs(&server);
    print_server_stats(&server);

    return 0;
}